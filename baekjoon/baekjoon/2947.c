#include <stdio.h>
main(){
	int a[5]={0},c,i,j;
	for(i=0;i<5;i++)
		scanf("%d",&a[i]);
	while(a[0]!=1||a[1]!=2||a[2]!=3||a[3]!=4||a[4]!=5){
		for(i=0;i<4;i++){
			if(a[i]>a[i+1]){
				c=a[i];
				a[i]=a[i+1];
				a[i+1]=c;
				for(j=0;j<5;printf("%d ",a[j++]));
				putchar(10);
			}
		}
	}
}