/*
*�������� 
*/ 

#include "stdio.h"

//��ȡ�������ֵ����ȷ�����м������� 
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
	int	temp[len];//��ʱ���� 
	//����ʮ��Ͱ 
	int bucket[10] = { 0 };
	
	for(i = 0; i < len; i++)
			bucket[(arr[i] / exp) % 10]++;
			
	// ������temp��Ԫ�ص�λ�� 
	for(i = 1; i < 10; i++)
 			bucket[i] += bucket[i - 1];
 			//�Ӻ���ǰ���׳���temp������ 
	for(i = len-1; i >= 0; i--)
	{
			temp[bucket[(arr[i] / exp) % 10 ] - 1] = arr[i];
			bucket[(arr[i] / exp) % 10]--;
	}
	//��ֵ��ԭ������ 
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
	   printf("����ǰ:\n");	 
     for(int i = 0; i < len; i++) {
      printf("%d ", arr[i]);
     }   
     radixSort(arr, len);
     printf("\n�����:\n");	 
     for(int i = 0; i < len; i++) {
      printf("%d ", arr[i]);
     }
    
		printf("\nlength:%d\n", len);	 
   
	 return 0;
}