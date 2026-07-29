/*
 * vehicle_dht11_test.c
 *
 * 基于原dht11_test.c编写。
 * 驱动每次read固定返回2字节：
 *   buf[0]：湿度整数
 *   buf[1]：温度整数
 *
 * 用法：
 *   ./vehicle_dht11_test /dev/vehicle_dht11
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv)
{
	int fd;
	int ret;
	unsigned char buf[2];

	if (argc != 2)
	{
		printf("Usage: %s <dev>\n", argv[0]);
		return 1;
	}

	fd = open(argv[1], O_RDWR | O_NONBLOCK);
	if (fd == -1)
	{
		fprintf(stderr,
			"can not open file %s: %s\n",
			argv[1],
			strerror(errno));
		return 1;
	}

	while (1)
	{
		ret = read(fd, buf, sizeof(buf));

		if (ret == (int)sizeof(buf))
		{
			printf("get Humidity: %u, Temperature: %u\n",
			       (unsigned int)buf[0],
			       (unsigned int)buf[1]);
			fflush(stdout);
		}
		else if (ret < 0)
		{
			fprintf(stderr,
				"read %s failed: %s\n",
				argv[1],
				strerror(errno));
		}
		else
		{
			fprintf(stderr,
				"short read: expected 2 bytes, got %d\n",
				ret);
		}

		/*
		 * DHT11不适合连续高速采样。
		 * 每次读取后等待1秒，再进行下一次读取。
		 */
		sleep(1);
	}

	close(fd);
	return 0;
}
