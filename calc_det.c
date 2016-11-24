#include <stdio.h>
#include <stdlib.h>
#include "calc_mat.h"


int main(){

	int size;
	int** matrix;

	puts("");
	puts("[-]Calcul of determinant :");
	printf("Enter the size of the matrix: ");
	scanf("%5d",&size);
	
	matrix=malloc_mat(size,size);

	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			printf("a(%d,%d)=",i+1,j+1);
			scanf("%5d",&matrix[i][j]);
		}
	}
	
	puts("");
	print_mat(matrix,size);
	puts("");

	puts("    (It can take a while)");
	puts("");
    printf("\tA=%d\n\n",det(matrix,size));

	for(int i;i<size;i++)free(matrix[i]);
	free(matrix);
	return 0;
}
