#include <errno.h>
#include <fcntl.h>
#include <linux/input.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static void print_abs_range(int fd, unsigned int code, const char *name)
{
    struct input_absinfo info;

    if (ioctl(fd, EVIOCGABS(code), &info) == 0) {
        printf("%s: min=%d max=%d fuzz=%d flat=%d resolution=%d\n",
               name,
               info.minimum,
               info.maximum,
               info.fuzz,
               info.flat,
               info.resolution);
    }
}

int main(int argc, char *argv[])
{
    const char *device = "/dev/input/event1";
    struct input_event event;
    char device_name[128] = "unknown";
    int fd;
    int x = -1;
    int y = -1;
    int coordinate_changed = 0;

    if (argc >= 2) {
        device = argv[1];
    }

    fd = open(device, O_RDONLY);

    if (fd < 0) {
        fprintf(stderr,
                "Failed to open %s: %s\n",
                device,
                strerror(errno));
        return 1;
    }

    if (ioctl(fd, EVIOCGNAME(sizeof(device_name)), device_name) >= 0) {
        printf("Device: %s\n", device_name);
    }

    printf("Node: %s\n\n", device);

    print_abs_range(fd, ABS_X, "ABS_X");
    print_abs_range(fd, ABS_Y, "ABS_Y");
    print_abs_range(fd, ABS_MT_POSITION_X, "ABS_MT_POSITION_X");
    print_abs_range(fd, ABS_MT_POSITION_Y, "ABS_MT_POSITION_Y");

    printf("\nTouch the screen. Press Ctrl+C to stop.\n");

    while (read(fd, &event, sizeof(event)) == sizeof(event)) {
        if (event.type == EV_ABS) {
            if (event.code == ABS_X ||
                event.code == ABS_MT_POSITION_X) {
                x = event.value;
                coordinate_changed = 1;
            } else if (event.code == ABS_Y ||
                       event.code == ABS_MT_POSITION_Y) {
                y = event.value;
                coordinate_changed = 1;
            }
        }

        if (event.type == EV_SYN &&
            event.code == SYN_REPORT &&
            coordinate_changed &&
            x >= 0 &&
            y >= 0) {
            printf("x=%d, y=%d\n", x, y);
            fflush(stdout);
            coordinate_changed = 0;
        }
    }

    close(fd);
    return 0;
}
