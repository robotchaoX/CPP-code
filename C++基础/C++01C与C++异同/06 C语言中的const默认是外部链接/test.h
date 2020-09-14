// C语言中默认是外部链接

/*
// extern声明+定义?? warning
// extern外部const全局变量
extern const int g_extern_const_var = 1; // const
// warning : ‘g_extern_const_var’ initialized and declared ‘extern’
// extern外部全局变量
extern int g_extern_var = 2; // 全局   warning
// warning : ‘g_extern_var’ initialized and declared ‘extern’
*/

// const全局变量
const int g_const_var = 10; // const

// 全局变量
int g_var_comm = 10; // 全局