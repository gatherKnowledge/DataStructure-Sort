/*==============================================
* 모듈러 연산을 이용하지 않는 CIRCULAR-QUEUE
* 
**==============================================
*/


#include <stdio.h>
#define MAXSIZE 10   
#define FALSE 0 
#define TRUE !FALSE

typedef struct _Queue{
	int rear ; 
	int front ; 
	int arr[10] ; 
} Queue ; 

//검증용 
void printArray(Queue *s){
	int i,j,k ;
	printf("\n * Queue Status *\n") ;
	printf("    ─────\n") ;
	for(i = 0 ; i  < MAXSIZE ; i++){
		printf("    "); 
		printf("|   ") ; // 고정
		printf("%2d", s->arr[i]) ; 

		if(s->front == i && s->rear == i ){
			printf("<fr") ; 
		}else if (s->front != i && s->rear == i ){
			printf("< r") ; 
		}else if(s->front == i && s->rear != i ){
			printf("< f") ; 
		}else{
			printf("   ") ; 
		}
		printf("|\n") ; 
	}
	printf("    ─────\n") ;
}
void createQ(Queue *q){
	int i = 0 ; 
	q->rear = -1 ; 
	q->front = -1 ;
	for(; i < MAXSIZE ; i++){
		q->arr[i] = 0 ; 
	}
	printArray(q) ; 
	printf("==> CREATE QUEUE\n") ; 

}

// /
int isFull(Queue *q){
	if(q->rear+1 == MAXSIZE){
		if(q->arr[0] == 0){
			q->rear = -1 ; 
			return FALSE ;
		}else{
			printf("==> Queue is Full\n") ; 
			return TRUE ; 
		}
	}
	if(q->arr[q->rear+1]==0){
		return FALSE ; 
	}
}


int insertData(Queue *q, int input){
	if(isFull(q)){
		return FALSE ;
	}

	q->arr[++q->rear] = input ;
	printArray(q) ; 
	return TRUE ; 
}


//
int isEmpty(Queue *q){
	if(MAXSIZE -1 == q->front ){
		if(q->arr[0] == 0){
			printf("Queue is Empty\n") ; 
			return TRUE ;
		}else{
			q->front = -1 ; 
		}
	}

	if(q->arr[q->front+1] == 0){
		printf("Queue is Empty\n") ; 
		return TRUE ;
	}

	return FALSE ; 
}

int deleteData(Queue *q){
	int retValue ; 
	if(isEmpty(q)){
		return FALSE ; 
	}
	retValue = q->arr[++q->front] ;
	q->arr[q->front] = 0 ; 
	printf("==> OutputData : %d\n", retValue) ; 
	printArray(q) ; 
}

int main(){
	Queue q, *pQ ; 
	pQ = &q ;
	createQ(pQ) ; 

	insertData(pQ, 10) ; 
	deleteData(pQ) ; 

	insertData(pQ, 20) ; 
	deleteData(pQ) ; 

	insertData(pQ, 50) ; 
	insertData(pQ, 50) ; 
	insertData(pQ, 50) ; 
	insertData(pQ, 50) ; 
	insertData(pQ, 50) ; 
	insertData(pQ, 50) ; 
	insertData(pQ, 50) ; 
	insertData(pQ, 50) ; 
	insertData(pQ, 50) ; 
	insertData(pQ, 50) ; 
	insertData(pQ, 50) ; 
	insertData(pQ, 50) ; 
	insertData(pQ, 50) ; 
	insertData(pQ, 50) ; 
	insertData(pQ, 50) ; 
	insertData(pQ, 50) ; 
	insertData(pQ, 50) ; 
	insertData(pQ, 50) ; 

	deleteData(pQ) ; 
	deleteData(pQ) ; 
	deleteData(pQ) ; 
	deleteData(pQ) ; 
	deleteData(pQ) ; 
	deleteData(pQ) ; 
	deleteData(pQ) ; 
	deleteData(pQ) ; 
	deleteData(pQ) ; 
	deleteData(pQ) ; 
	deleteData(pQ) ; 
	deleteData(pQ) ; 
	deleteData(pQ) ; 
	deleteData(pQ) ; 
	deleteData(pQ) ; 
	deleteData(pQ) ; 
	deleteData(pQ) ; 
	deleteData(pQ) ; 
	deleteData(pQ) ; 

	insertData(pQ, 50) ;
	insertData(pQ, 50) ; 
	insertData(pQ, 50) ; 
	insertData(pQ, 50) ; 
	insertData(pQ, 50) ; 

	deleteData(pQ) ; 
	deleteData(pQ) ; 
	deleteData(pQ) ; 
	deleteData(pQ) ; 
	deleteData(pQ) ; 
	deleteData(pQ) ; 
	deleteData(pQ) ; 
	deleteData(pQ) ; 
	deleteData(pQ) ; 
	deleteData(pQ) ; 
	deleteData(pQ) ; 


	return FALSE ; 
}