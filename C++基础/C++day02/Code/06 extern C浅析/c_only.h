#pragma once

// 头文件声明即使C++中调用也以C语言执行
//如果定义了__cplusplus(即如果是cpp文件)，则采用C语言方式进行编译
// 被extern "C"修饰的变量和函数是按照C语言方式进行编译和链接的
#ifdef __cplusplus
extern "C" {
#endif // !__cplusplus

#include <stdio.h>

void only_C_exe(); // 声明

#ifdef __cplusplus //两个_下划线
}
#endif // !__cplusplus
