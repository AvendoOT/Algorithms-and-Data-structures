#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

#define STACK_INC 10 // stack increment if full

typedef struct {
	int location; // location of an push element
	int size; // size of stack
	int* map; // array of stack
} Stack;

void stack_init(Stack* mystack, int size) {
	mystack->location = -1;
	mystack->size = size;
	mystack->map = (int*)malloc(sizeof(int)*size); // memory allocation for stack array
	if (mystack->map == NULL) {
		mystack->size = 0;
	}
}

int stack_push(Stack* mystack, int element) {
	int *added; // if memory reallocation is needed
	if (mystack->location == (mystack->size - 1)) {
		printf("Increment\n");
		// if stack is full, reallocate memory with stack increment
		added = (int*)realloc(mystack->map, mystack->size + STACK_INC);
		if (added != NULL) {
			mystack->map = added;
			mystack->size += STACK_INC;
		}
		else return 0;
	}
	mystack->location++;
	mystack->map[mystack->location] = element; // pushing element into stack
	printf("Push: %d\n", element);
	printf("Peek %d\n", mystack->location);
	return 1;
}

int stack_pop(Stack *mystack, int* element) {
	if (mystack->location < 0) {
		return 0;
	}
	*element = mystack->map[mystack->location];
	mystack->location--;
	printf("Pop: %d\n", *element);
	printf("Peek %d\n", mystack->location);
	return 1;
}

int peek_find(Stack *mystack, int *element) {
	if (!stack_pop(mystack, element)) {
		return 0;
	}
	stack_push(mystack, *element);
	printf("Peek %d\n", mystack->location);
	return 1;
}

int find_specific(Stack *mystack, int *element, int indeks) {
	Stack proxy;
	stack_init(&proxy, mystack->size);
	int i=0,j;
	int found = 0;
	while (stack_pop(mystack, &j)) {
		stack_push(&proxy, j);
		i++;
		if (i == indeks) {
			*element = j;
			found = 1;
			printf(" Found peek: %d\n", proxy.location);
			break;
		}
	}
	while (stack_pop(&proxy, &j)) {
		stack_push(mystack, j);
	}
	return found;
}
