#include <stdio.h>
#include <malloc.h>
#include <memory.h>
main(){
	int max,*a,*b,*c,i,j,temp,sum=0,temp2,check;
	scanf("%d",&max);
	a=(int*)malloc(sizeof(int)*max);
	b=(int*)malloc(sizeof(int)*max);
	c=(int*)malloc(sizeof(int)*max);
	for(i=0;i<max;i++)
		c[i]=-1;
	for(i=0;i<max;i++)
		scanf("%d",&a[i]);
	for(i=0;i<max;i++)
		scanf("%d",&b[i]);
	for(i=0;i<max;i++){
		check=0;
		for(j=0;j<max-1-i;j++){
			if(a[j]<a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				check=1;
			}
		}
		if(!check) break;
	}
	for(i=0;i<max;i++){
		for(j=0;j<max;j++){
			if(c[j]==-1){
				temp=a[i]*b[j];
				check=j;
			}
		}
		for(j=0;j<max;j++){
			if(temp>a[i]*b[j]&&c[j]==-1){
				temp=a[i]*b[j];
				check=j;
			}
		}
		sum+=a[i]*b[check];
		c[check]=i;
	}
	printf("%d",sum);
}