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
			int temp; //��Ż�׼Ԫ��
			
		  temp = arr[left];
			i = left;
		  j = right; 
		  
			//�������1ʱ��ſ�ʼ���� 
			if(i > j)return;
			
			while(i != j)
		 {
		 	//���Ҳ࿪ʼ̽�� 
			while(arr[j] >= temp && j > i)
             j--;
      //����࿪ʼ̽�� 
			while(arr[i] <= temp && j > i)
  				   i++;
      //���ֱȻ�׼Ԫ�ش�ĺ�С��Ԫ�أ����н��� 
			if(i < j)
			{
			 t = arr[i];
			 arr[i] = arr[j];
			 arr[j] = t;
			}		
    }
   //��׼Ԫ�غ�arr[i]����λ�� 
   arr[left] = arr[i]; //��׼Ԫ�ع�λ 
	 arr[i] = temp; 
	 //�ݹ� 
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