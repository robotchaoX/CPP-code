#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

void test01() {

    // 一维数组
    int arr1[3]; // 定义了数组array，并未对数组进行初始化
    int arr2[5] = {0, 1}; //定义并部分初始化
    int arr3[5] = {0, 1, 2, 3, 4}; //定义并初始化了数组array
    int arr4[] = {0, 1, 2, 3, 4}; // b和a的效果是一样
    int len = 5;
    int arr5[5] = {0, 1, 2, 3, 4}; // C++矩阵维度可以为变量

    // 动态一维数组
    int *array1 = new int[100]; //分配了长度为100的数组array
    delete[] array1;
    int *array2 = new int[100]{1, 2}; //分配为长度为100的数组,初始化前两个元素
    delete[] array2;
    len = 100;
    int *array3 = new int[len]; //分配了长度为100的数组array
    delete[] array3;

    // 二维数组
    int arr2D1[3][4]; // 定义了二维数组，并未初始化
    int arr2D2[3][4] = {-1, -2}; //初始化前两个元素
    int arr2D3[3][4] = {
        {0, 1, 2, 3}, /*  初始化索引号为 0 的行 */
        {4, 5, 6, 7}, /*  初始化索引号为 1 的行 */
        {8, 9, 10, 11} /*  初始化索引号为 2 的行 */
    }; //按行初始化
    int arr2D4[3][2] = {1, 1, 2, 2, 3, 3}; //顺序初始化
    // 省略第一维的大小
    int arr2D5[][2] = {1, 1, 2, 2, 3, 3};
    int rows = 4;
    int cols = 5;
    int arr2D6[rows][cols]; // C++矩阵维度可以为变量

    // 一个带有 5 行 2 列的数组
    int a[5][2] = {{0, 0}, {1, 2}, {2, 4}, {3, 6}, {4, 8}};
    // 输出数组中每个元素的值
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "a[" << i << "][" << j << "]: ";
            cout << a[i][j] << endl;
        }
    }
    // 二维数组转化成一维数组
    // a[x][y] = b[x * 列数 + y]

    //动态二维数组
    // 1.指针数组
    int M1 = 3;
    int(*n2Arr1)[5] = new int[M1][5]; // 列必须为常量
    delete[] n2Arr1;

    // 2.多次析构
    // 第一维长度为m， 第二维长度为n
    int M = 3, N = 5;
    //申请空间
    int **n2Arr2 = new int *[M]; // 每行的头
    for (int i = 0; i < M; i++) { // 申请每行的空间
        n2Arr2[i] = new int[N];
    }
    //释放空间
    for (int i = 0; i < M; i++) { //释放每行的空间
        delete[] n2Arr2[i];
    }
    delete[] n2Arr2; //释放每行的头

    // vector创建二维数组
    int Mm = 3, Nn = 5;
    vector<vector<int>> mat(Mm, vector<int>(Nn));
    for (int i = 0; i < Mm; i++) { //初始化
        for (int j = 0; j < Nn; j++) {
            mat[i][j] = i * j;
        }
    }

    //三维数组
    int arr3D1[2][3][2];
    int arr3D2[2][3][2] = {1, -1, 2, -2, 3, -3, 4, -4, 5, -5, 6, -6};
    // initializing the array
    int arr3D3[2][3][2] = {{{1, -1}, {2, -2}, {3, -3}}, {{4, -4}, {5, -5}, {6, -6}}};
    // displaying array values
    for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 3; y++) {
            for (int z = 0; z < 2; z++) {
                cout << arr3D3[x][y][z] << " ";
            }
        }
    }

    // // 多维数组
    // M = 2;
    // int *array = new int[M][3][4]; // 只有第一维可以是变量，其他维数必须是常量，否则会报错
    // delete[] array; // 必须进行内存释放，否则内存将泄漏
}

void test02() {
    // 数组与指针
    int arr[10]; // 数组
    int *ptr = arr; // 指针

    //! arr是数组首地址,但sizeof(arr)是数组总空间大小
    cout << sizeof(arr[0]) << endl; // 4
    cout << sizeof(arr) << endl; // 40,数组总空间大小
    cout << sizeof(ptr) << endl; // 64位机器上为8,指针变量空间大小
}

// 数组作为函数形参传递
// 一维数组传递：
void func(int *array); //指针
void func(int array[]);
void func(int array[3]); //说明元素个数
// 二维数组传递：
void func(int **array); //二维指针
void func(int (*array)[5]); // 列已知

int main() {

    test01();

    test02();

    // system("pause");
    return EXIT_SUCCESS;
}