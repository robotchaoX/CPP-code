#include <stdio.h>

// 封装
struct Animal {
    // 属性
    char *name; //姓名
    char color; //颜色
    char addr[30]; //栖息地
    int weight; //体重
    int other; //属性

    // 方法
    // 函数指针
    void (*print)(void *p);
};

// 继承
struct Dog {
    struct Animal p;

    // 新增属性
    char fly[20]; //飞翔
    int scream; //鸣叫
};

void hir() {
    struct Dog s;
    s.p.name = "bird";
    s.p.color = 'b';
    s.p.other = 25;
    s.p.weight = 65;

    // s.fly = "0618";
    s.scream = 90;
}

// 多态
struct Bird {
    void (*print)(void *p);
};

struct fBird {
    struct Bird p;
};

void printBird(void *Bird) {
    if (NULL == Bird)
        return;
    struct Bird *p = (struct Bird *)Bird;
    printf("run in the Bird!!\n");
}
void printfBird(void *Bird) {
    if (NULL == Bird)
        return;
    struct Bird *p = (struct Bird *)Bird;
    printf("run in the fBird!!\n");
}

void print(void *Bird) {
    if (NULL == Bird)
        return;
    struct Bird *p = (struct Bird *)Bird;
    p->print(Bird);
}

int main() {
    struct Bird bird;
    struct fBird fbird;
    bird.print = printBird;
    fbird.p.print = printfBird;

    print(&bird); //实参为Bird的对象
    print(&fbird); //实参为fBird的对象

    return 0;
}