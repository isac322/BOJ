#include <stdio.h>
main(){
	int i,j,c=0,N,M,a[150000]={0};
	scanf("%d%d",&N,&M);
	for(i=0;i<N;i++)
		scanf("%d",&a[i]);
	for(i=0;i<N-1;i++){
		for(j=i+1;j<N;j++){
			if(a[i]+a[j]==M&&a[i]&&a[j]){
				c++;
				a[j]=a[i]=0;
				break;
			}
		}
	}
	printf("%d",c);
}