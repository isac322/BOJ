#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct data
{
	int height;
	int width;
	int namelen;
	char name[MAX+1];
};

int height, width;
char e[MAX][MAX+1];

int winnum;
struct data p[MAX];

void inputmethod (void)
{
	int i;
	
	scanf("%d %d", &height, &width);
	for (i=0; i<height; i++)
		scanf("%s", e[i]);
}

void get_data (int x, int y)
{
	int i;

	if ((e[x][y]!='+') || (e[x][y+1]!='-') || (e[x+1][y]!='|')) return ;

	i=1;
	while (e[x][y+i]=='-')
		i++;
	if (e[x][y+i]!='|') return ;

	p[winnum].width=1;
	while (e[x][y+p[winnum].width]!='+')
		p[winnum].width++;

	p[winnum].height=1;
	while (e[x+p[winnum].height][y]!='+')
		p[winnum].height++;

	i=y+1;
	while (e[x][i]!='|')
		i++;
	i++;

	p[winnum].namelen=0;
	while (e[x][i]!='|')
		p[winnum].name[p[winnum].namelen++]=e[x][i++];
	p[winnum].name[p[winnum].namelen]=0;

	winnum++;
}

void scan (void)
{
	int i, j;

	winnum=0;
	for (i=0; i<height-1; i++)
		for (j=0; j<width-1; j++)
			get_data(i, j);
}

int cmp (const void *a, const void *b)
{
	struct data *aa=(struct data *) a;
	struct data *bb=(struct data *) b;
	return strcmp(aa->name, bb->name);
}

void rerwrite (void)
{
	int i, j, k;
	int start;

	qsort(p, winnum, sizeof p[0], cmp);

	for (i=0; i<height; i++)
		for (j=0; j<width; j++)
			e[i][j]='.';

	for (i=0; i<winnum; i++)
	{
		e[i][i]=e[i+p[i].height][i]=e[i][i+p[i].width]=e[i+p[i].height][i+p[i].width]='+';

		for (j=1; j<p[i].width; j++)
			e[i][i+j]=e[i+p[i].height][i+j]='-';

		for (j=1; j<p[i].height; j++)
			e[i+j][i]=e[i+j][i+p[i].width]='|';

		start=(p[i].width-p[i].namelen+1)/2;
		e[i][i+start-1]=e[i][i+start+p[i].namelen]='|';
		for (j=0; j<p[i].namelen; j++)
			e[i][i+start+j]=p[i].name[j];

		for (j=1; j<p[i].height; j++)
			for (k=1; k<p[i].width; k++)
				e[i+j][i+k]='.';
	}

	for (i=0; i<height; i++)
		printf("%s\n", e[i]);
}
 
int main (void)
{
	inputmethod();
	scan();
	rerwrite();

	return 0;
}