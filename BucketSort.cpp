/*
简易版桶排序(bucket sort)

原理：
设置一个定量的数组当作空桶子。
寻访序列，并且把项目一个一个放到对应的桶子去。
对每个不是空的桶子进行排序。
从不是空的桶子里把项目再放回原来的序列中。

时间复杂度：
最坏：O(n^2）
平均：O(n+k) 

桶排序不是比较排序，不受到O(nlogn)下限的影响。
*/
#include"stdio.h"

int main()
{
	int i, j, n, temp;
	int book[1001]; //设置1001个桶存放元素;
	
	for(int i=0;i <= 1000;i++)
		book[i] = 0;   //初始化 
	
	scanf("%d", &n);  //输入元素个数 
	
	for(int i=1;i<=n;i++)
	{
	 scanf("%d", &temp);
	 book[temp]++;		//计数
	} 
	
	for(int i=0;i <= 1000;i++)
	   for(int j=1;j<=book[i];j++)
    		printf("%d ", i);  //把该桶中的元素打印出来 
	
} 