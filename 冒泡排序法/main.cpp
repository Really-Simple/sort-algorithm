#include<stdio.h>

void bubbleSort(int *arr,int n)
{
	for(int i = 0;i < n-1;i++)
	{
		for(int j = 0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}

		}
	}
}

int main()
{
	int arr[] = {5,2,8,6,9,12,4,0,10};
	int n = sizeof(arr)/sizeof(int);
	bubbleSort(arr,n);
	printf("排序后的数组为：\n");
	for(int i = 0;i<n;i++)
	{
		printf("   %d",arr[i]);
	}
	printf("\n");
	return 0;
}