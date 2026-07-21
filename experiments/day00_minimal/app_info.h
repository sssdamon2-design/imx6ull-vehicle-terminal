#ifndef APP_INFO_H
#define APP_INFO_H

/*
 * 当这个头文件被C++代码包含时，
 * extern "C"告诉C++编译器按照C语言规则寻找函数。
 */
#ifdef __cplusplus
extern "C" {
#endif

const char *app_name(void);
const char *app_version(void);

#ifdef __cplusplus
}
#endif

#endif