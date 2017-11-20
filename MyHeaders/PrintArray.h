void addUpguard(int cnt){
	int count = cnt ; 
	int j,i ; 
	for(j = 0 ; j < count ; j ++){
		printf(" 式式式式") ;
	}
	printf("\n") ; 
	for( i = 0 ; i < 2 ; i++){
		for(j = 0 ; j < count ; j ++){
			printf("|        ") ; 
		}
		printf("|") ; 
		if( i < 2 ) {
			printf("\n") ; 
		}
	}

}
void addDownguard(int cnt){
	int count = cnt ; 
	int j,i ; 
	for( i = 0 ; i < 2 ; i++){
		for(j = 0 ; j < count ; j ++){
			printf("|        ") ; 
		}
		printf("|") ; 
		if( i < 2 ) {
			printf("\n") ; 
		}
	}

	for(j = 0 ; j < count ; j ++){
		printf(" 式式式式") ;
	}
	printf("\n") ; 
}

void printIntArray(int arr[]){
	int i, j, count ; 
	i = 0 ; 
	j = 0 ; 
	count = MAXSIZE ; 
	printf("\n") ;
	addUpguard(count) ; 
	for(j = 0 ; j < count ; j ++){
		printf("|     %d   ", arr[j]) ;
	}
	printf("|\n") ; 
	addDownguard(count) ; 
}


void printCharArray(char arr[]){
	int i, j, count ; 
	i = 0 ; 
	j = 0 ; 
	count = MAXSIZE-1 ; 
	printf("\n") ;

	addUpguard(count) ; 
	for(j = 0 ; j < count ; j ++){
		printf("|    %-4c", arr[j]) ;
	}
	printf("|\n") ; 
	addDownguard(count) ; 
}