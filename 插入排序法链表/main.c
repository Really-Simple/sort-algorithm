#include <stdio.h>
#include <stdlib.h>

typedef struct insert
{
	int data;
	struct insert * next;
}INSERT;

INSERT * getEndNode(INSERT * h)
{
	INSERT * p = h;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	return p;
}

INSERT * getLastNode(INSERT * h,INSERT * currentNode)
{
	INSERT * p = h;
	while(p!=currentNode)
	{
		p = p->next;
	}
	return p;
}

void insertSort(INSERT * h)//核心，先有一个有序链表，从无序的第一个开始和有序链表做比较，找到有序中比无序的第一个元素大的数，插到他之前
{
	INSERT *p,*pre,*q;
	p = h->next->next;		// 先保存下L的第二个元素，因为下一步要将L变成只有一个元素的有序表。  
	h->next->next = NULL;	// 将L变成只有一个元素的有序表
	// 从L的第二个元素开始遍历整个L直至表尾 
	while(p != NULL){
		q = p->next;
		pre = h;	// 先用pre来保存L。
		while(pre->next !=NULL && pre->next->data < p->data) // 遍历pre所指向的有序表L，直至找到比p大的节点 
			pre = pre->next; 
		p->next = pre->next;
		pre->next = p;
		p = q;	
	} 
}

INSERT * createLink()//分配一个头结点
{
	INSERT * h=(INSERT *)malloc(sizeof(INSERT));
	if(h==NULL)
	{
		printf("创建链表失败\n");
		return NULL;
	}
	h->next=NULL;
	return h;
}

INSERT * newNode()
{
	INSERT * p=(INSERT *)malloc(sizeof(INSERT));
	if(p==NULL)
	{
		printf("创建新节点失败\n");
		return NULL;
	}

	return p;
}


void putDataToLink(INSERT * h,int num)
{
	//1.新建一个结点
	INSERT * p;//新节点
	INSERT * q;//链表末尾结点
	p = newNode();
	//2.往结点里添加数据
	p->data=num;
	p->next=NULL;
	//3.找到以前结点的末尾
	q = getEndNode(h);
	//4.将新节点添加到链表末尾
	q->next = p;
}

void putLink(INSERT * h)
{
	INSERT * p=h;
	while(p->next!=NULL)
	{
		p=p->next;
		printf("%d   ",p->data);
	}
	printf("\n");
}

void arrToLink(int * arr,INSERT * h,int len)
{
	int i = 0;
	for(i = 0;i<len;i++)
	{
		putDataToLink(h,arr[i]);
	}
}

int main()
{
	INSERT * head;
	int arr[] = {10,20,8,13,35,65,45,2,36};
	head = createLink();
	arrToLink(arr,head,sizeof(arr)/sizeof(arr[0]));
	insertSort(head);
	putLink(head);
	return 0;
}