#include <stdio.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
typedef int ElemType;
/*顺序存储结构线性表的定义*/
typedef struct
 {
	char data[MAXSIZE]; 
	int length;	
 }SqList; 
 /*
 GetElem 将线性表L的第i个元素返回给e 
 */
 ElemType GetElem(SqList L,ElemType i,char *e)
 {
 	if (i>0 && i<=L.length)
 		*e=L.data[i-1];//数组是从0开始计算，所以要获得第i个元素是data[i-1] 
 	else
 		return ERROR;
 	return OK;
 }
 int main(void)
 {
 	SqList List={"hello word",10};
 	char e; 
 	ElemType i;
 	printf("请输入需要查找的位置：\n");
 	scanf("%d",&i);
 	if(GetElem(List,i,&e)==OK)		// 将结构体List作为参数发送，函数GetElem获得List副本L。接收参数char *e是指针类型，要发送地址值，用&符 
 		printf ("当前线性表L的第%d个元素是%c\n",i,e);//char类型数据只能用%c输出，不能用%s输出，只有char数组才可以，否则会内存溢出 
 	else 
 		printf("数值不合法\n");
 	return 0;
 }
