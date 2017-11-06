#include <stdio.h>
#define MAXSIZE 10

typedef struct _Stack{
	int top ;
	int data[MAXSIZE] ;
} Stack;


void create(Stack *s){
	int i = 0 ;
	s->top = -1 ;
	while ( i  < MAXSIZE ){
		s->data[i] = 0 ;
		i++ ;
	}
}

void printArray(Stack *s){
	int i,k ;
	printf("\n * Stack Status *\n") ;
	printf("───────") ;
	for(i = 0 ; i  < MAXSIZE ; i++){

		printf("\n|     ") ;
		printf("%d", s ->data[i] ) ;
		if (s->top == i){
			printf("[top] |") ;
		}else{
		// 글자 length생각을 해서 적용해야 하지만 이 이상은 배보다 배꼽이 커지는 꼴이
			if( s ->data[i]  > 9){
				printf("     |");

			}else{
				printf("      |");
			}
		}
		printf("\n───────") ;

	}
	printf("\n") ;
}

int isEmpty(Stack *s){
	if ( s->top  < 0 ){
		printf("Stack Empty. \n") ;
		return 0 ;
	}
	return 1 ;
}

int isFull(Stack *s){
	if ( s->top  > MAXSIZE - 2 ){
		printf("Stack Full. \n") ;
		return 0 ;
	}
	return -1 ;
}

int push(Stack *s, int sData){
	if (!isFull(s)){
		return  0 ;
	}
	s->top ++ ;
	s->data[s->top] = sData ;
	printArray(s) ;
	return 1 ;
}

int pop(Stack *s){
	int popData ;
	if(!isEmpty(s)){
		return 0 ;
	}
	popData = s->data[s->top]  ;
	s->data[s->top]  = 0 ;
	s->top -- ;
	printf("\n -->>  PopData : %d ", popData) ;
	printArray(s) ;
	return popData ;
}


int main(){
	Stack s,s2, *stack ;
	int popData ;
	stack = &s ;
	create(stack) ;
	printArray(stack) ;

	push(stack, 20) ;
	push(stack, 5) ;
	push(stack, 8) ;
	push(stack, 1) ;
	push(stack, 8) ;

	pop(stack) ;
	push(stack, 22) ;
	pop(stack) ;
	pop(stack) ;
	pop(stack) ;
	pop(stack) ;
	pop(stack) ;
	pop(stack) ;
	pop(stack) ;
	pop(stack) ;
	pop(stack) ;
	pop(stack) ;
	pop(stack) ;
	pop(stack) ;
	push(stack, 1) ;
	push(stack, 2) ;
	push(stack, 3) ;
	push(stack, 4) ;
	push(stack, 5) ;
	push(stack, 6) ;
	push(stack, 7) ;
	push(stack, 8) ;
	push(stack, 9) ;
	push(stack, 10) ;
	push(stack, 11) ;
	push(stack, 12) ;
	push(stack, 13) ;
	pop(stack)  ;

	stack = &s2 ;
	create(stack) ;
	printArray(stack) ;
	push(stack, 11) ;
	return 0 ;
}
