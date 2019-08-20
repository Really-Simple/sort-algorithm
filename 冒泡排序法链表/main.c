#include <stdio.h>
#include <stdlib.h>

typedef struct bubbleSort
{
	int data;
	struct bubbleSort * next;
}BUBBLESORT;


void BubbleSort(BUBBLESORT * head)
{
	BUBBLESORT *p,*q,*tail;
	tail = NULL;
	while((head->next->next)!=tail)
	{
		p = head;
		q = head->next;
		while(q->next != tail)
		{
			if((q->data)>(q->next->data))
			{
				p->next = q->next;
				q->next = q->next->next;
				p->next->next=q;
				q=p->next;
			}
			q=q->next;
			p=p->next;
		}
		tail=q;
	}
}

BUBBLESORT * createLink()//����һ��ͷ���
{
	BUBBLESORT * h=(BUBBLESORT *)malloc(sizeof(BUBBLESORT));
	if(h==NULL)
	{
		printf("��������ʧ��\n");
		return NULL;
	}
	h->next=NULL;
	return h;
}

BUBBLESORT * newNode()
{
	BUBBLESORT * p=(BUBBLESORT *)malloc(sizeof(BUBBLESORT));
	if(p==NULL)
	{
		printf("�����½ڵ�ʧ��\n");
		return NULL;
	}

	return p;
}

BUBBLESORT * getEndNode(BUBBLESORT * h)
{
	BUBBLESORT * p = h;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	return p;
}

void putDataToLink(BUBBLESORT * h,int num)
{
	//1.�½�һ�����
	BUBBLESORT * p;//�½ڵ�
	BUBBLESORT * q;//����ĩβ���
	p = newNode();
	//2.��������������
	p->data=num;
	p->next=NULL;
	//3.�ҵ���ǰ����ĩβ
	q = getEndNode(h);
	//4.���½ڵ���ӵ�����ĩβ
	q->next = p;
}

void putLink(BUBBLESORT * h)
{
	BUBBLESORT * p=h;
	while(p->next!=NULL)
	{
		p=p->next;
		printf("%d   ",p->data);
	}
	printf("\n");
}

void arrToLink(int * arr,BUBBLESORT * h,int len)
{
	int i = 0;
	for(i = 0;i<len;i++)
	{
		putDataToLink(h,arr[i]);
	}
}

int main()
{
	BUBBLESORT * head;
	int arr[] = {10,20,8,13,35,65,45,2,36};
	head = createLink();
	arrToLink(arr,head,sizeof(arr)/sizeof(arr[0]));
	BubbleSort(head);
	putLink(head);
	return 0;
}