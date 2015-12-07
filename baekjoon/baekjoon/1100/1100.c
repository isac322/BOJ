#include <stdio.h>
main(){
	int i,j,a,count=0;
	for(i=1;i<=8;i++){
		for(j=1;j<=9;j++){
			if(i%2){
				a=getchar();
				if(a=='F'&&j%2)
					count++;
			}else{
				a=getchar();
				if(a=='F'&&!(j%2))
					count++;
			}
		}
	}
	printf("%d",count);
}