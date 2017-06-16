#include"stdio.h"
#include"stdlib.h"

//左节点 2*n+1
//右节点 2*n+2 

//交换 
void swap(int* a, int* b) {
	int temp = *b;
	*b = *a;
	*a = temp;
}
//调整成最大堆 
void max_heapify(int arr[], int start, int end) {
	
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) { 	
	
		if (son + 1 <= end && arr[son] < arr[son + 1]) //选择最大的子节点 
			son++;
		if (arr[dad] > arr[son]) //父节点大于子节点，跳出此次循环 
			return;
		else { //否则交换父子节点继续比较 
			swap(&arr[dad], &arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

void heap_sort(int arr[], int len) {
	int i;
	//初始化成最大堆，i=n/2-1是序号最大的父节点 
	for (i = len / 2 - 1; i >= 0; i--)
		max_heapify(arr, i, len - 1);
	//a[1]已经是最大值，将a[1]和a[n]交换，再进行a[1]到a[n-1]的交换 
	for (i = len - 1; i > 0; i--) {
		swap(&arr[0], &arr[i]);
		max_heapify(arr, 0, i - 1);
	}
}


int main(){

int arr[] = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
int len = (int)sizeof(arr)/sizeof(*arr);

heap_sort(arr, len);

for(int i	=	0; i < len; i++)
	printf("%d ", arr[i]);
printf("\nLength:%d", len);
return 0;
}