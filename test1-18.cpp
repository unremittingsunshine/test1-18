#include<stdio.h>
#include<string.h>
//自己写qsort函数进行冒泡泡排序，可以排序不同数据类型
typedef struct stduent
{
	char name[10];
	int age;
}stdu;
int cmp(void*e1, void*e2)
{
	return  *(int*)e1-*(int*)e2;
}
int cmp2(void*e1, void*e2)
{
	return  *(float*)e1 - *(float*)e2;
}
int cmp3(void*e1, void*e2)
{
	return  ((stdu*)e1)->age - ((stdu*)e2)->age;
}
int cmp4(void*e1, void*e2)
{
	return  strcmp(((stdu*)e1)->name , ((stdu*)e2)->name);
}
//交换
void swp(char*base1, char*base2,int withen)
{
	int i;
	char swp;
	for ( i=0;i<withen;i++)
	{
		
		swp = *base2;
		*base2 = *base1;
		*base1 = swp;
		base2++;
		base1++;

	}
}
void my_qsort(void*base,int sz,int withen,int(*cmp)(void *e1,void *e2))
{
	int i,j;
	//趟数
	for (i = 0; i < sz - 1; i++)
	{
		//进行排序
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (cmp((char*)base+j*withen,(char*)base+(j+1)*withen) >0)
			{
				swp((char*)base + j * withen,(char*)base + (j + 1)*withen, withen);

			}
		}
	}
}
void test1()
{
	int arr[] = { 5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	my_qsort(arr, sz, sizeof(arr[0]), cmp);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
void test2()
{
	float arr[] = { 5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	my_qsort(arr, sz, sizeof(arr[0]), cmp2);
	for (int i = 0; i < sz; i++)
	{
		printf("%.2f ", arr[i]);
	}
}

void test3()
{
	stdu s[] = { {"xiaohai",14} ,{"boye",23},{"zhangshan",44} };
	int sz = sizeof(s) / sizeof(s[0]);
	my_qsort(s, sz, sizeof(s[0]), cmp3);
	for (int i = 0; i < sz; i++)
	{
		printf("%-10s %-10d\n", s[i].name,s[i].age);
	}
}
void test4()
{
	stdu s[] = { {"xiaohai",14} ,{"boye",23},{"zhangshan",44} };
	int sz = sizeof(s) / sizeof(s[0]);
	my_qsort(s, sz, sizeof(s[0]), cmp4);
	for (int i = 0; i < sz; i++)
	{
		printf("%-10s %-10d\n", s[i].name, s[i].age);
	}
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	return 0;
}