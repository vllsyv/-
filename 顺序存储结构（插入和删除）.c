#include<stdio.h>
#define ERROR 0
#define RIGHT 1
/* ˳�����Ա�L�Ѵ��ڣ�1<=i<=ListLength��L��*/
typedef int ElemType; 
typedef struct List
{
	int data[20];
	int length;
}SqList;


/*ListInsert��������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1*/ 
int ListInsert(SqList *L,int i,ElemType e)
{
	int j=L->length;
	if (i<=0||i>L->length)//����λ�ò��Ϸ�ʱֱ�ӷ��� 
		return ERROR;
	L->length++;//����Ϸ������Ա��ȼ�һ 
	for (;j>=i;j--)//��ǰ�ƶ�λ��Ϊj-1������j��Ԫ�أ�Ҳ���ǵ�j>=iʱ��˵������Ҫ�ƶ�����j<i˵����i��Ԫ���Ѿ����ƶ���ɣ�����λ�ÿ�ȱ 
	{
		L->data[j]=L->data[j-1];//�Ӻ���ǰ�ƶ�Ԫ�أ���i��λ�ã����������±�Ϊi-1���������һ��Ԫ��Ϊj-1��
	}
	L->data[j]=e;//�ڿ�ȱ��λ���ϲ�������Ԫ��e
	return RIGHT;
}


/*ɾ��L�ĵ�i������Ԫ�أ���e������ֵ��L�ĳ��ȼ�һ*/
int ListDelete(SqList *L,int i,ElemType *e)
{
	if (i<=0||i>L->length)//λ�ò��Ϸ��򷵻� 
		return ERROR;
	for (L->length--;i<=L->length;i++) //�����±�ֻ��L->Length-1������Ҫ�ȼ�һ���ж� 
	{
		L->data[i-1]=L->data[i];//�����ƶ����ǵ�i+1��Ԫ�أ������i��Ԫ���� 
	}
	return RIGHT;
}


int main()
{
	int i,j,e; 
	SqList List={{1,2,3,4,5,6,7,8,9},9};
	
	//����ǰ����Ԫ�� 
	printf("����ǰ����Ԫ�����£�\n");
	for(j=0;j<List.length;j++)
		printf("%d  ",List.data[j]);
	printf("\n");
	printf("���Ա��ȣ� %d\n",List.length);
	
	//���ò��뺯���������� 
	printf("����Ҫ�����λ�ú�Ԫ��(�ո�ָ�)��\n");
	scanf("%d %d",&i,&e);
	if (ListInsert(&List,i,e)==ERROR)
		printf("��������\n");
	else 
	{
		printf("���������Ԫ�����£�\n");
		for(j=0;j<List.length;j++)
			printf("%d  ",List.data[j]);
		printf("\n");
		printf("���Ա��ȣ� %d\n",List.length);
	}
	
	//����ɾ�������������� 
	printf("����Ҫɾ����λ�ã�\n");
	scanf("%d",&i);
	if (!ListDelete(&List,i,&e))
		printf("��������\n");
	else
	{
		printf("ɾ��������Ԫ�����£�\n");
		for(j=0;j<List.length;j++)
			printf("%d  ",List.data[j]);
		printf("\n");
		printf("���Ա��ȣ� %d\n",List.length);
	}
		
		
			
	return 0;
}
