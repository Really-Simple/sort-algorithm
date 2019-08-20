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

void insertSort(INSERT * h)//���ģ�����һ����������������ĵ�һ����ʼ�������������Ƚϣ��ҵ������б�����ĵ�һ��Ԫ�ش�������嵽��֮ǰ
{
	INSERT *p,*pre,*q;
	p = h->next->next;		// �ȱ�����L�ĵڶ���Ԫ�أ���Ϊ��һ��Ҫ��L���ֻ��һ��Ԫ�ص������  
	h->next->next = NULL;	// ��L���ֻ��һ��Ԫ�ص������
	// ��L�ĵڶ���Ԫ�ؿ�ʼ��������Lֱ����β 
	while(p != NULL){
		q = p->next;
		pre = h;	// ����pre������L��
		while(pre->next !=NULL && pre->next->data < p->data) // ����pre��ָ��������L��ֱ���ҵ���p��Ľڵ� 
			pre = pre->next; 
		p->next = pre->next;
		pre->next = p;
		p = q;	
	} 
}

INSERT * createLink()//����һ��ͷ���
{
	INSERT * h=(INSERT *)malloc(sizeof(INSERT));
	if(h==NULL)
	{
		printf("��������ʧ��\n");
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
		printf("�����½ڵ�ʧ��\n");
		return NULL;
	}

	return p;
}


void putDataToLink(INSERT * h,int num)
{
	//1.�½�һ�����
	INSERT * p;//�½ڵ�
	INSERT * q;//����ĩβ���
	p = newNode();
	//2.��������������
	p->data=num;
	p->next=NULL;
	//3.�ҵ���ǰ����ĩβ
	q = getEndNode(h);
	//4.���½ڵ���ӵ�����ĩβ
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