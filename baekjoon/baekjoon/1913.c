#include <stdio.h>
#include <malloc.h>
#include <memory.h>
main(){
	int max,**matrix,i,j,temp,temp2,find;
	scanf("%d",&max);
	scanf("%d",&find);
	temp=max*max;
	matrix=(int**)malloc(sizeof(int)*max);
	for(i=0;i<max;i++)
		matrix[i]=(int*)malloc(sizeof(int)*max);
	for(i=0;i<max-1;i++){
		if(!(i%2)){
			for(j=i/2;j<max-i/2;j++)
				matrix[j][i/2]=temp--;
			for(j=i/2+1;j<max-i/2;j++)
				matrix[max-i/2-1][j]=temp--;
		}else{
			for(j=max-i/2-2;j>i/2-1;j--)
				matrix[j][max-i/2-1]=temp--;
			for(j=max-i/2-2;j>i/2;j--)
				matrix[i/2][j]=temp--;
		}
	}
	matrix[max/2][max/2]=1;
	for(i=0;i<max;i++){
		for(j=0;j<max;j++){
			printf("%d ",matrix[i][j]);
			if(find==matrix[i][j]){
				temp=i;
				temp2=j;
			}
		}
		putchar(10);
	}
	printf("%d %d",temp+1,temp2+1);
	for(i=0;i<max;i++)
		free(matrix[i]);
	free(matrix);
}