#include "stdio.h"

void bubble_sort(int arr[], int len) {
 int i, j, temp;
 for(i = 0; i < len - 1; i++)
   for(j = 0; j < len - 1 - i; j++)
	    if(arr[j] > arr[j + 1]) {
			   temp = arr[j];
			   arr[j] = arr[j + 1];
			   arr[j + 1] = temp;
			}	
}
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
//bubble_sort(arr,len);
quick_sort(arr,0,len);
for(int i=0; i<len; i++){
 printf("%d ",arr[i]);
}
printf("\nlength:%d", len);	
return 0;
} 