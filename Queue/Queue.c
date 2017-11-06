#include <stdio.h>
#define MAXSIZE 10   


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

int isFull(Queue *q){
	if(MAXSIZE-1 == q->rear ){
		printf("==> Queue is Full\n") ; 
		return 1 ; 
	}

	return 0 ; 
}


int insertData(Queue *q, int input){
	if(isFull(q)){
		return 0 ;
	}
	q->arr[++q->rear] = input ;
	printArray(q) ; 
	return 1 ; 
}




int isEmpty(Queue *q){
	if (q->front == q->rear){
		printf("Queue is Empty\n") ; 
		return 1 ; 
	}
	return 0 ; 
}

int deleteData(Queue *q){
	int retValue ; 
	if(isEmpty(q)){
		return 0 ; 
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


	return 0 ; 
}