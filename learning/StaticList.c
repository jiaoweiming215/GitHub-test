/******************************************************************************
* ��������: void main()
* ��������:static list_test
* �������: ��
* �������: ��
* �� �� ֵ: ��
* ����˵��: 
**************************************************************************************/
#include<stdio.h>

typedef struct time
{
	int year;
	int hour;
	struct time *next;
}TIME;
void main()
{
	TIME a,b,c,*head,*p;
	a.year=2017;
	a.hour=23;	 
	b.year = 2018;
	b.hour = 1;
	c.year = 2019;
	c.hour = 1;
	head = &a;
	a.next = &b;
	b.next = &c;
	c.next = NULL;
	p = head;
	while(p!=NULL)
	{
		printf("%d,%d\n",p->year,p->hour);//why->
		p=p->next;
	}
	getch();
	return 0;
}


