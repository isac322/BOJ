#include <stdio.h>
#include <malloc.h>
#include <memory.h>
main(){
	int k,i,j,**mat,x,y,num,sum,temp;
	scanf("%d %d",&y,&x);
	mat=(int**)malloc(sizeof(int)*(y+1));
	for(i=0;i<=y;i++)
		mat[i]=(int*)malloc(sizeof(int)*(x+1));
	for(i=1;i<=y;i++)
		for(j=1;j<=x;j++)
			scanf("%d",&mat[i][j]);
	scanf("%d",&num);
	while(num--)
	{
		sum=0;
		i=j=x=y=0;
		scanf("%d %d %d %d",&j,&i,&y,&x);
		for(j;j<=y;j++)
			for(temp=i;temp<=x;temp++)
				sum+=mat[j][temp];
		printf("%d\n",sum);
	}
}