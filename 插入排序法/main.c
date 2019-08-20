#include <stdio.h>

void insertSort(int *arr,int n)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	for(i = 1;i<n;i++)
	{
		temp = arr[i];
		for(j=i-1;j>=0;j--)
		{
			if(arr[j]>temp)
			{
				arr[j+1]=arr[j];
			}
			else
			{
				break;
			}
		}
		arr[j+1]=temp;
	}
}

int main()
{
	int i = 0;
	int arr[] = {5,2,8,6,9,12,4,0,10};
	int n = sizeof(arr)/sizeof(int);
	insertSort(arr,n);
	printf("排序后的数组为：\n");
	for(i = 0;i<n;i++)
	{
		printf("   %d",arr[i]);
	}
	printf("\n");
	return 0;
}