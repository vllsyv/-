#include <stdio.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
typedef int ElemType;
/*˳��洢�ṹ���Ա�Ķ���*/
typedef struct
 {
	char data[MAXSIZE]; 
	int length;	
 }SqList; 
 /*
 GetElem �����Ա�L�ĵ�i��Ԫ�ط��ظ�e 
 */
 ElemType GetElem(SqList L,ElemType i,char *e)
 {
 	if (i>0 && i<=L.length)
 		*e=L.data[i-1];//�����Ǵ�0��ʼ���㣬����Ҫ��õ�i��Ԫ����data[i-1] 
 	else
 		return ERROR;
 	return OK;
 }
 int main(void)
 {
 	SqList List={"hello word",10};
 	char e; 
 	ElemType i;
 	printf("��������Ҫ���ҵ�λ�ã�\n");
 	scanf("%d",&i);
 	if(GetElem(List,i,&e)==OK)		// ���ṹ��List��Ϊ�������ͣ�����GetElem���List����L�����ղ���char *e��ָ�����ͣ�Ҫ���͵�ֵַ����&�� 
 		printf ("��ǰ���Ա�L�ĵ�%d��Ԫ����%c\n",i,e);//char��������ֻ����%c�����������%s�����ֻ��char����ſ��ԣ�������ڴ���� 
 	else 
 		printf("��ֵ���Ϸ�\n");
 	return 0;
 }
