#include <errno.h>
#include <fcntl.h>
#include <linux/input.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

static int set_axis_range(int fd,
                          unsigned int axis,
                          const char *axis_name,
                          int minimum,
                          int maximum)
{
    struct input_absinfo info;

    if (ioctl(fd, EVIOCGABS(axis), &info) < 0) {
        fprintf(stderr,
                "Failed to read %s: %s\n",
                axis_name,
                strerror(errno));
        return -1;
    }

    printf("%s before: min=%d max=%d\n",
           axis_name,
           info.minimum,
           info.maximum);

    info.minimum = minimum;
    info.maximum = maximum;

    if (ioctl(fd, EVIOCSABS(axis), &info) < 0) {
        fprintf(stderr,
                "Failed to update %s: %s\n",
                axis_name,
                strerror(errno));
        return -1;
    }

    if (ioctl(fd, EVIOCGABS(axis), &info) < 0) {
        fprintf(stderr,
                "Failed to verify %s: %s\n",
                axis_name,
                strerror(errno));
        return -1;
    }

    printf("%s after : min=%d max=%d\n",
           axis_name,
           info.minimum,
           info.maximum);

    return 0;
}

int main(int argc, char *argv[])
{
    const char *device =
        argc >= 2 ? argv[1] : "/dev/input/event1";

    int fd = open(device, O_RDWR);

    if (fd < 0) {
        fprintf(stderr,
                "Failed to open %s: %s\n",
                device,
                strerror(errno));
        return 1;
    }

    if (set_axis_range(fd,
                       ABS_MT_POSITION_X,
                       "ABS_MT_POSITION_X",
                       0,
                       1024) < 0) {
        close(fd);
        return 1;
    }

    if (set_axis_range(fd,
                       ABS_MT_POSITION_Y,
                       "ABS_MT_POSITION_Y",
                       0,
                       600) < 0) {
        close(fd);
        return 1;
    }

    close(fd);

    printf("Touch coordinate ranges updated temporarily.\n");
    return 0;
}
