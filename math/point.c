int iNum = 123;
int *ptr = &iNum;

**pPtr = &ptr;
*pPtr == *(&ptr)==ptr
**pPtr == *ptr ==*(&iNum)==iNum==123
数组
int a[2]

从规约层次上来看，除了在声明中或数组名当做sizeof或&的操作数之外，表达式中的数组名a被解释为指向该数组首元素的指针。
使用指针运算规则，当将一个整形变量i和一个数组名相加时，将得到指向第i个元素的指针，即a+i = &a[i]或 *(a+i) ==*(&a[i])==a[i]


函数指针也是指针数组，该数组的每个元素是一个函数的地址，声明如下：
typedef int (*PF)(int,int);
其中PF是一个指向返回值为int的函数的指针类型，该函数有两个int型参数。假设需要声明一个包含4个元素的数组变量oper_func，用于存储4个函数的地址，即可用PF定义一个存储函数指针的数组。
PF oper_func[4];







/******************************************************/
输入a/b/c个整数，按大小顺序输出
/******************************************************/

#include <stdio.h>
int swapValue(int *a;int *b; int *c);
int swapValue(int *a;int *b; int *c)
{
		
}

main()
{
	int a,b,c;
	scanf("%d,%d,%d",&a,&b,&c);

	swapValue(&a,&b,&c);


}