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

BUBBLESORT * createLink()//分配一个头结点
{
	BUBBLESORT * h=(BUBBLESORT *)malloc(sizeof(BUBBLESORT));
	if(h==NULL)
	{
		printf("创建链表失败\n");
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
		printf("创建新节点失败\n");
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
	//1.新建一个结点
	BUBBLESORT * p;//新节点
	BUBBLESORT * q;//链表末尾结点
	p = newNode();
	//2.往结点里添加数据
	p->data=num;
	p->next=NULL;
	//3.找到以前结点的末尾
	q = getEndNode(h);
	//4.将新节点添加到链表末尾
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