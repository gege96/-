/*
快速排序

原理：
“分治”的策略
选择一个基准元素，从左右两侧开始探测（从右侧开始）比基准值小的元素摆放在基准前面，所有比基准值大的元素摆在基准后面。
，递归把小于基准值元素的子数列和大于基准值元素的子数列排序

复杂度：
平均：O(nlogn)
最优：O(nlogn)
最坏：O(n^2)

稳定度：
不稳定（快速排序是跳跃式的）

相比冒泡排序，快速排序每次交换是跳跃式的，所以跳跃的越大，交换的距离就越大。总的比较和交换次数就少，速度就提高
最坏情况就是相邻的两个元素进行交换，那样的话就为O(n^2)
*/

#include "stdio.h"

void quick_sort(int arr[], int left, int right) {
			
	int i,j,t;
	int temp; //存放基准元素
			
        temp = arr[left];
	i = left;
	j = right; 
		  
	//数组大于1时候才开始交换 
	if(i > j)return;
			
	while(i != j)
	{
	   //从右侧开始探测 
	   while(arr[j] >= temp && j > i)
                j--;
           //从左侧开始探测 
	   while(arr[i] <= temp && j > i)
  		i++;
           //发现比基准元素大的和小的元素，进行交换 
	   if(i < j)
	   {
	      t = arr[i];
	      arr[i] = arr[j];
	      arr[j] = t;
	   }		
       }
   //基准元素和arr[i]交换位置 
   arr[left] = arr[i]; //基准元素归位 
	 arr[i] = temp; 
	 //递归 
	 quick_sort(arr, left, i-1);
	 quick_sort(arr, i+1, right);
}


int main() {
int arr[] = {3, 1, 2, 5, 4, 6, 9, 7, 10};
int len = (int)sizeof(arr)/sizeof(*arr);

quick_sort(arr,0,len-1);
for(int i=0; i<len; i++){
 printf("%d ",arr[i]);
}
printf("\nlength:%d", len);	
return 0;
} 
