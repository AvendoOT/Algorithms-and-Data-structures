#include <stdio.h>
#include "funct_queue.c"
#define MAXNUM 10
int main(void) {
	Queue myqueue;
	init_queue(&myqueue);
	int n,i;
	float input;
	printf("Number of float numbers (less than 10) > ");
	do {
		scanf_s("%d", &n);
	} while (n > MAXNUM);
	for (i = 0; i < n; i++) {
		printf("\nEnter float number > ");
		scanf_s("%f", &input);
		if (queue_add(input, &myqueue)) {
			printf("\n%.2f was added into queue", input);
		}
	}
	return 0;
}