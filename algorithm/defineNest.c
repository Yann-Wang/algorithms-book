#include<stdio.h>
#define TO_STRING2(x) #x
#define TO_STRING(x) TO_STRING1(x)
#define TO_STRING1(x) #x
#define PARAM(x) #x
#define ADDPARAM(x) INT_##x

/*
首先，C语言的宏是允许嵌套的，其嵌套后，一般的展开规律像函数的参数一样：先展开参数，再分析函数，即由内向外展开。但是，注意：
(1) 当宏中有#运算符时，参数不再被展开；
(2) 当宏中有##运算符时，则先展开函数，再展开里面的参数；

PS:
##运算符用于把参数连接到一起。预处理程序把出现在##两侧的参数合并成一个符号（非字符串）。

*/
int main(){
    const char * str = TO_STRING(PARAM(ADDPARAM(1)));
    printf("%s\n",str);
    str = TO_STRING2(PARAM(ADDPARAM(1)));
    printf("%s\n",str);
    return 0;
}

/*
对于宏TO_STRING，它的定义中没有#，所以先展开里面的“PARAM( ADDPARAM( 1 ) )”，
由于PARAM中有#，所以里面展开的结果为ADDPARAM( 1 )，然后外面再展开，其结果为"ADDPARAM( 1 )"
而对于TO_STRING2，其定义中有#，所以直接展开，其结果为PARAM( ADDPARAM( 1 ) )
*/
