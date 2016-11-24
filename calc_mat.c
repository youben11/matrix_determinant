int** malloc_mat(int col,int line){
	int** mat=malloc(col*sizeof(int*));
	if (mat==NULL) return NULL;

	for(int i=0;i<col;i++){
		mat[i]=malloc(line*sizeof(int));
		if(mat[i]==NULL){
			puts("[-]Can't allocate memory");
			exit(EXIT_FAILURE);
		}
	}

	return mat;
}

int** sub_mat(int** mat,int size,int col_off){
	
	int i=0;
	int** sub_mat=malloc((size)*sizeof(int*));

	if(sub_mat==NULL){
			puts("[-]Can't allocate memory");
			exit(EXIT_FAILURE);
		}

	for(int j=0;j<size+1;j++){
		if(j!=col_off){
			sub_mat[i]=&mat[j][1];
			i++;
		}
	}
	return sub_mat;

}

int det(int** mat,int size){
	int s=0,j,k;
	int** submat;

	if(size==2){
		return mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0];
	}
	
	for(int i=0;i<size;i++){
		submat=sub_mat(mat,size-1,i);
		if(mat[i][0]!=0)s=s+((i%2==0)?1:-1)*mat[i][0]*det(submat,size-1);
		
		free(submat);
	}
	return s;
}

void print_elem(int elem,int space){
	int p=10,i=1;
	while(elem>p){
		i++;
		p*=10;
	}
	for(int j=0;j<(space-i)/2+(space-i)%2;j++) printf(" ");
	printf("%d",elem);
	for(int j=0;j<(space-i)/2;j++) printf(" ");	
}

void print_mat(int** mat,int size){
	for(int i=0;i<size;i++){
		printf("    |");
		for (int j = 0; j < size; j++)
		{
			print_elem(mat[i][j],5);
		}
		printf("|");
		if(i==size/2) puts(" = A"); else puts("");
	}
}