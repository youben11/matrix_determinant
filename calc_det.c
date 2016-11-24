#include <stdio.h>
#include <stdlib.h>
#include "calc_mat.h"


int main(){

	int size;
	int** matrice;

	puts("");
	puts("[-]Calcul of determinent :");
	printf("Enter the size of the matrice: ");
	scanf("%5d",&size);
	
	matrice=malloc_mat(size,size);

	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			printf("a(%d,%d)=",i+1,j+1);
			scanf("%5d",&matrice[i][j]);
		}
	}
	
	puts("");
	print_mat(matrice,size);
	puts("");

	puts("    (It can take a while)");
	puts("");
    printf("\tA=%d\n\n",det(matrice,size));

	for(int i;i<size;i++)free(matrice[i]);
	free(matrice);
	return 0;
}
