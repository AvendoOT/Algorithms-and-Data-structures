#include <stdio.h>
#include "funct_queue.c"

int main(void) {
	Queue queue;
	int input = 5;
	queue_init(&queue);
	queue_in(&queue, input);
	queue_out(&queue, &input);
	return 0;
}