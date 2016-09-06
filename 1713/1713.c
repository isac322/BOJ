#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int c;
	int d;
	int e;
}j;
int l(const void *a,const void *b){
	j p=*(j*)a;
	j q=*(j*)b;
	int o=p.d-q.d;
	if(!o)return q.e-p.e;
	return o;
}
int m(const void *a,const void *b){return (*(j*)a).c-(*(j*)b).c;}
void n(j *f,int d){
	f->c=d;
	f->e=0;
	f->d=1;
}
main(){
	int g,h,d,i=0,k,ck;
    j f[20]={0};
	scanf("%d%d",&g,&h);
	for(;i<h;i++){
		scanf("%d",&d);
		qsort(f,g,sizeof(j),l);
		for(ck=0,k=0;k<g;k++){
			if(f[k].c==d){
				f[k].d++;
				ck=1;
				break;
			}
		}
		if(!ck)n(f,d);
		for(k=0;k<g;k++)f[k].e++;
	}
	qsort(f,g,sizeof(j),m);
	for(i=0;i<g;i++)if(f[i].c)printf("%d ",f[i].c);
}