h,s,i,j;
main(){for(;i<4;i++,getchar())for(j=0;j<4&&(h=getchar());j++)if(h!='.')s+=abs((h-65)/4-i)+abs(((h-65)%4)-j);printf("%d",s);}