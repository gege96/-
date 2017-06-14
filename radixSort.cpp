/*
*基数排序 
*/ 

#include "stdio.h"

//获取数组最大值，来确定进行几轮排序 
int getMax(int arr[], int len){
		int i, max;
		max = arr[0];
		for(i=1;i<len;i++)
		{
			if(arr[i]>max)
				max	=	arr[i];
		}
   	return max;
}

void count_Sort(int arr[], int len, int exp)
{
	int i;
	int	temp[len];//临时数组 
	//类似十个桶 
	int bucket[10] = { 0 };
	
	for(i = 0; i < len; i++)
			bucket[(arr[i] / exp) % 10]++;
			
	// 计算在temp中元素的位置 
	for(i = 1; i < 10; i++)
 			bucket[i] += bucket[i - 1];
 			//从后往前，抛出到temp数组中 
	for(i = len-1; i >= 0; i--)
	{
			temp[bucket[(arr[i] / exp) % 10 ] - 1] = arr[i];
			bucket[(arr[i] / exp) % 10]--;
	}
	//赋值给原来数组 
	for(i = 0; i < len; i++)
	   arr[i] = temp[i];

}	
	
void radixSort(int arr[], int len) {
		int exp;
	  int max = getMax(arr,	len);
	  for(exp = 1; max / exp > 0; exp *= 10)
	  		count_Sort(arr, len, exp);
}


int main(){
	
     int arr[] = {2,1,9,5,3,2,1,0};
     int len = (int)sizeof(arr)/sizeof(*arr);
	   printf("排序前:\n");	 
     for(int i = 0; i < len; i++) {
      printf("%d ", arr[i]);
     }   
     radixSort(arr, len);
     printf("\n排序后:\n");	 
     for(int i = 0; i < len; i++) {
      printf("%d ", arr[i]);
     }
    
		printf("\nlength:%d\n", len);	 
   
	 return 0;
}