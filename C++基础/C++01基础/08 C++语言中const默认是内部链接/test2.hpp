// C++中的const默认内部链接,extern提高作用域
// extern声明+定义??warning
extern const int x_c = 1; // const
extern int y_g = 2; // 全局   warning

//?? C++中的const默认内部链接 ?? 还是外部的吧？？
const int a_c = 10; // const

int b_g = 20; // 全局