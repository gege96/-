#include"stdio.h"

int binary_search(int arr[], int num, int length)
{
	int low = 0;
	int high= length-1;
	int mid;
	while(low <= high)
	{
		mid = (low+high)/2;
		if(arr[mid] > num)
			high = mid -1;
		else if(arr[mid] < num)
		  low = mid + 1;
    else{
			//printf("find");
			return mid;
		}
		
	}
		//printf("failed");
		return -1;
}
	
int main(){
	
int x;  
int arr[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  
int len = sizeof(arr) / sizeof(arr[0]);
x = binary_search(arr, 11, len);

printf("%d", x);
}