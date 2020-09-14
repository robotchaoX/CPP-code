// C++中的const默认内部链接,extern提高作用域

/*
// extern声明+定义?? warning
// extern外部const全局变量
extern const int g_extern_const_var = 1; // const
// extern外部全局变量
extern int g_extern_var = 2; // 全局   warning
// warning: ‘g_extern_var’ initialized and declared ‘extern’
*/

//?? C++中的const默认内部链接 ?? 还是外部的吧？？
// const全局变量
const int g_const_var = 10;
// 全局变量
int g_var_comm = 20;