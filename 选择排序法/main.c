#include<stdio.h>


void SelectSort(int *arr,int n)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	for(i = 0;i<n;i++)
	{
		int max = i;
		for(j = i+1;j<n;j++)//������СԪ������λ��
		{
			if(arr[j]<arr[max])
			{
				max = j;
			}
		}
		temp=arr[max];
		arr[max]=arr[i];
		arr[i]=temp;
	}
}


int main()
{
	int i = 0;
	int arr[] = {1,20,15,3,28,32,12,25,20,9};
	int n = sizeof(arr)/sizeof(int);
	SelectSort(arr,n);
	printf("����������Ϊ��\n");
	for(i = 0;i<n;i++)
	{
		printf("   %d",arr[i]);
	}
	printf("\n");
	return 0;
}