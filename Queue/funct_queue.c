#include <stdio.h>
#include <malloc.h>

struct at {
	float element;
	struct at *next;
} typedef atom;

typedef struct {
	atom *in;
	atom *out;
} Queue;

void init_queue(Queue *myqueue) {
	myqueue->in = NULL;
	myqueue->out = NULL;
}

int queue_add(double input, Queue *myqueue) {
	atom *proxy;
	if (proxy = (atom*)malloc(sizeof(atom))) {
		proxy->element = input;
		proxy->next = NULL;
		if (myqueue->in == NULL) {
			myqueue->in = proxy;
			myqueue->out = proxy;
			printf("%.2lf", myqueue->in->element);
		}
		else {
			myqueue->in->next = proxy;
			myqueue->in = proxy;
			printf("%.2lf", myqueue->in->element);
		}
		return 1;
	}
	else {
		printf("\nMemory could not be allocated");
		return 0;
	}
}