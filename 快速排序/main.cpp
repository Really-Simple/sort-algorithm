#include<stdio.h>

void quickSort(int *arr, int left, int right)
{
	if(left >= right)
	{
		return;
	}
	int i = left;
	int j = right;
	int index = arr[i];//取最左边的数作为基准数
	while(i < j)
	{
		while(i < j && arr[j] > index)
		{
			j--;
		}
		if(i < j)
		{
			arr[i++] = arr[j];
		}
		while(i < j && arr[i] < index)
		{
			i++;
		}
		if(i < j)
		{
			arr[j--] = arr[i];
		}
	}
	arr[i] = index;
	quickSort(arr, left, i - 1);
	quickSort(arr, i + 1, right);
}


int main()
{
	int arr[] = {12,5,8,9,15,34,25,16,24,18,29};
	for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++ )
	{
		printf("   %d",arr[i]);
	}
	printf("\n");
	quickSort(arr, 0 , sizeof(arr)/sizeof(arr[0])-1);
	for(i = 0; i < sizeof(arr)/sizeof(arr[0]); i++ )
	{
		printf("   %d",arr[i]);
	}
	printf("\n");
	return 0;
}