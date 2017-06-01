int iNum = 123;
int *ptr = &iNum;

**pPtr = &ptr;
*pPtr == *(&ptr)==ptr
**pPtr == *ptr ==*(&iNum)==iNum==123
数组
int a[2]

从规约层次上来看，除了在声明中或数组名当做sizeof或&的操作数之外，表达式中的数组名a被解释为指向该数组首元素的指针。
使用指针运算规则，当将一个整形变量i和一个数组名相加时，将得到指向第i个元素的指针，即a+i = &a[i]或 *(a+i) ==*(&a[i])==a[i]








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