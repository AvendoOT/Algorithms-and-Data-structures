#include <stdio.h>
#include <malloc.h>

struct at {
	int element;
	struct at *next;
} typedef atom;

typedef struct {
	atom *in;
	atom *out;
} Queue;

void queue_init(Queue *queue) {
	queue->in = NULL;
	queue->out = NULL;
}

int queue_in(Queue *queue, int input) {
	atom *proxy;
	if (proxy = (atom*)malloc(sizeof(atom))) {
		proxy->element = input;
		proxy->next = NULL;
		if (queue->out == NULL) {
			queue->out = proxy;
		}
		else {
			(queue->in)->next = proxy;
		}
		queue->in = proxy;
		return 1;
	}
	else return 0;
}

int queue_out(Queue *queue, int *input) {
	atom *proxy;
	if (proxy = (atom*)malloc(sizeof(atom))) {
		*input = queue->out->element;
		proxy = queue->out;
		queue->out = proxy->next;
		free(proxy);
		if (!queue->out) {
			queue->in = NULL;
			return 1;
		}
		return 0;
	}
}