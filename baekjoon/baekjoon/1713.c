#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int num;
	int vote;
	int times;
}Frame;

int cmp(const void *a, const void *b) {
	Frame f1 = *(Frame *)a;
	Frame f2 = *(Frame *)b;
	int tmp = f1.vote - f2.vote;
	
	if (!tmp) return f2.times - f1.times;
	return tmp;
}

int cmp1(const void *a, const void *b) {
	return (*(Frame *)a).num - (*(Frame *)b).num;
}

void init(Frame *frame, int vote) {
	frame->num = vote;
	frame->times = 0;
	frame->vote = 1;
}

int main(char args[], int argc) {
	int frameNum = 0;
	int voteNum = 0;
	int vote = 0;
	int i = 0, ck = 0;
	Frame *frame = NULL;

	scanf("%d\n%d", &frameNum, &voteNum);
	frame = (Frame *)calloc(frameNum, sizeof(Frame));

	while (voteNum--) {
		scanf("%d", &vote);
		qsort(frame, frameNum, sizeof(Frame), cmp);

		for (ck = 0, i = 0; i < frameNum; i++) {
			if (frame[i].num == vote) {
				frame[i].vote++;
				ck = 1;
				break;
			}
		}
		if (!ck) {
			init(frame, vote);
		}

		for (i = 0; i < frameNum; i++) {
			frame[i].times++;
		}
	}

	qsort(frame, frameNum, sizeof(Frame), cmp1);
	for (i = 0; i < frameNum; i++) {
		if(frame[i].num) printf("%d ", frame[i].num);
	}
}