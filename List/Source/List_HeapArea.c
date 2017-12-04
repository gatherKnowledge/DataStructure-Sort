#include "MyStruct.h"
#include <windows.h>
#define null 0


typedef struct _node{
	struct Node *next ;
	char data ;
} Node ;

typedef struct _head{
	struct Node *next ;
} Head ;
/*
	1. 노드 생성 [v]
	2. 노드 추가/중간 추가 [v]
	3. 노드 삭제/중간 삭제
		- 헤드 다음부분 삽입 [v]/삭제 [v]
	4. 삭제 검사

*/
void clearBuff(){
	while(getchar() != '\n') ;
}
//최초 노드 생성
Head* makeHead(){
	Head *head = (Head*) malloc(sizeof(Head)) ;
	head->next = null ;
	return head ;
}


//노드 생성, 값입력 받는 방식
Node* makeManualNode(){
	Node *node ;
	char input ;
	node = (Node*) malloc(sizeof(Node)) ;
	printf("값을 입력해주세요.\n") ;
	input = getchar() ;
	node->data = input ;
	//
	clearBuff() ;
	return node ;
}

//노드 생성만 담당, 링크 분리
Node* makeNode(char nodeData){
	Node *node = (Node*) malloc(sizeof(Node)) ;
	node->data = nodeData ;
	node->next = null ;
	//
	return node ;
}



void linkNode(Node *pr, Node *nx){
	pr->next = nx ;
}

//last node
Node* getLastNode(Head *head){
	Node *node ;
	int i ;
	i = 0 ;
	if( head->next == null ){
		printf("There is no Node \n") ;
		return null ;
	}
	node = head->next ;
	while( node->next != null ){
		node = node->next ;
		i++ ;
	}
	printf("Last Node\n ==> %c \n", node->data) ;
	return node ;
}

//last node
void travelNode(Head *head){
	Node *node ;
	int i ;
	i = 0 ;
	if( head->next == null ){
		printf("There is no Node \n") ;
		return ;
	}

	node = head->next ;
	printf("Node Travel \n ==> ") ;
	while( node != null ){
		if( i != 0 ){
			printf("-") ;
		}
		printf(" [%c] ", node->data) ;
		node = node->next ;
		i++ ;
	}
	printf("\n") ;
}
//첫번째 요소 삽입
void insertHead(Head *head, Node *node){
	Node *f_node ;
	f_node = head->next ;
	head->next = node  ;
	node->next = f_node ;
}
// 첫번째가 아닌 요소에 삽입
void insert(Head *head, Node *pNode, int n){
	//첫번째(n-1) = 0
	int i ;
	Node *node, *tmpNode ;
	if( n == 0 ){
		printf("Not Available") ;
		return ;
	}else if( n == 1 ){
		insertHead(head, pNode) ;
		return ;
	}
	node = head->next ;
	for(i = 0 ; i < n-2 ; i++){
		if(node == null){
			printf("Out of index range \n") ;
			return ;
		}
		node = node->next ;
	}
	tmpNode = node->next ;
	node->next = pNode   ;
	pNode->next = tmpNode ;
}

// 첫 번째 요소를 삭제하는 함수
Node* deleteHead(Head *head){
	Node *node ;
	if ( head->next == null ){
		printf("There's no Node") ;
		return null ;
	}
	node = head->next ;
	head->next = node->next ;
	return node ;

}
// 2번째 요소부터 삭제 가능한 함수
Node* deleteNode(Head *head, int n){
	//n 번째를 삭제
	int i ;
	Node *node, *prevNode ;
	i = 1 ;
	node = head->next ;
	while(node != null){
		node = node->next ;
		if( i == n-1){
			prevNode = node ;
		}else if( i == n ){
			prevNode->next = node->next ;
			return node ;
		}
		i++ ;
	}
	printf("N번째 노드가 없습니다") ;
	node = null ;
	return node ;
}


int main(){
	Head *head ;
	Node *node,*tmpNode ;

	head = makeHead() ;
	node = makeNode('a') ;
	head->next = node ;
	node = head->next ;
	//printf("실제 값 : %c  \n",  node->data) ;

	tmpNode = makeNode('b') ;

	//이전 노드와 다음 노드 삽입
	linkNode(node, tmpNode) ;
	//printf("주소 값 : %x  \n", node->next ) ;
	//printf("현재 노드 주소 값 : %x  \n", tmpNode ) ;
	node = head->next ;
	//printf("실제 값 : %c  \n",  tmpNode->data) ;

	//getLastNode(head) ;
	//travelNode(head) ;
	tmpNode = makeNode('c') ;
	insertHead(head, tmpNode) ;
	tmpNode = makeNode('d') ;
	insertHead(head, tmpNode) ;
	tmpNode = makeNode('e') ;
	insertHead(head, tmpNode) ;

	travelNode(head) ;
	tmpNode = makeNode('g') ;
	insert(head, tmpNode, 3) ;
	travelNode(head) ;

	tmpNode = makeNode('h') ;
	insert(head, tmpNode, 9) ;
	insert(head, tmpNode, 3) ;
	travelNode(head) ;
	tmpNode = makeNode('i') ;
	insert(head, tmpNode, 1) ;
	travelNode(head) ;
	node = deleteHead(head) ;
	//printf(" * [delete node] : %c \n", node->data) ;
	travelNode(head) ;

	//메모리 해제
	free(node) ;
	node = deleteNode(head, 2) ;
	travelNode(head) ;
	free(node) ;

	node = deleteNode(head, 2) ;
	travelNode(head) ;
	free(node) ;

	node = deleteNode(head, 2) ;
	travelNode(head) ;
	free(node) ;

	node = deleteNode(head, 10) ;
	travelNode(head) ;
	free(node) ;

	system("pause") ;
	return 0 ;
}
