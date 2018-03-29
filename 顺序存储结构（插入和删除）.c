#include<stdio.h>
#define ERROR 0
#define RIGHT 1
/* 顺序线性表L已存在，1<=i<=ListLength（L）*/
typedef int ElemType; 
typedef struct List
{
	int data[20];
	int length;
}SqList;


/*ListInsert函数，在L中第i个位置之前插入新的数据元素e，L的长度加1*/ 
int ListInsert(SqList *L,int i,ElemType e)
{
	int j=L->length;
	if (i<=0||i>L->length)//数据位置不合法时直接返回 
		return ERROR;
	L->length++;//输入合法，线性表长度加一 
	for (;j>=i;j--)//当前移动位置为j-1，即第j个元素，也就是当j>=i时就说明还需要移动，当j<i说明第i个元素已经被移动完成，数组位置空缺 
	{
		L->data[j]=L->data[j-1];//从后往前移动元素，第i个位置，在数组中下标为i-1，所以最后一个元素为j-1。
	}
	L->data[j]=e;//在空缺的位置上插入数据元素e
	return RIGHT;
}


/*删除L的第i个数据元素，用e返回其值，L的长度减一*/
int ListDelete(SqList *L,int i,ElemType *e)
{
	if (i<=0||i>L->length)//位置不合法则返回 
		return ERROR;
	for (L->length--;i<=L->length;i++) //数组下标只到L->Length-1，所以要先减一再判断 
	{
		L->data[i-1]=L->data[i];//正在移动的是第i+1个元素，填补到第i个元素上 
	}
	return RIGHT;
}


int main()
{
	int i,j,e; 
	SqList List={{1,2,3,4,5,6,7,8,9},9};
	
	//插入前数组元素 
	printf("插入前数据元素如下：\n");
	for(j=0;j<List.length;j++)
		printf("%d  ",List.data[j]);
	printf("\n");
	printf("线性表长度： %d\n",List.length);
	
	//调用插入函数并输出结果 
	printf("输入要插入的位置和元素(空格分割)：\n");
	scanf("%d %d",&i,&e);
	if (ListInsert(&List,i,e)==ERROR)
		printf("输入有误\n");
	else 
	{
		printf("插入后数据元素如下：\n");
		for(j=0;j<List.length;j++)
			printf("%d  ",List.data[j]);
		printf("\n");
		printf("线性表长度： %d\n",List.length);
	}
	
	//调用删除函数并输出结果 
	printf("输入要删除的位置：\n");
	scanf("%d",&i);
	if (!ListDelete(&List,i,&e))
		printf("输入有误\n");
	else
	{
		printf("删除后数据元素如下：\n");
		for(j=0;j<List.length;j++)
			printf("%d  ",List.data[j]);
		printf("\n");
		printf("线性表长度： %d\n",List.length);
	}
		
		
			
	return 0;
}
