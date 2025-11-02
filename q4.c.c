#include <stdio.h>
void push(int stack[],int *top,int max) {
	int value;
	if(*top >= max-1) {
		printf("Cannot add, will overflow");
	}
	 else {
        printf("Enter value to push: ");
        scanf("%d", &value);
        (*top)++;
        stack[*top] = value;
        printf("%d pushed to stack.\n", value);
    }
	
}

void pop(int stack[],int *top) {
	if(*top == -1) {
		printf("No value , cant remove");
	}
	else {
        printf("%d is the popped element.\n", stack[*top]);
        (*top)--;
    }
	}

void peek(int stack[],int *top) {
	if(*top == -1) {
		printf("No value , cant peek");
	}
	else {
        printf("%d is the top element \n", stack[*top]);
    }
	}
void display(int stack[],int *top) {
	int i;
	if(*top == -1) {
		printf("No value , cant display");
	}
	else {
        for (i = 0 ; i<= *top ; i++) {
        	printf("%d ", stack[i]);
		}
    }
}

int main() {
	int max = 5;
	int stack[max];
	int top = -1;
    int choice;
    while (1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        	case 1: 
        	push (stack,&top,max);
        	break;
        	case 2:
        		pop (stack,&top);
        	    break;
        	case 3:
        	peek(stack,&top);
        	break;
        	case 4: 
        	display (stack,&top);
        	case 5:
        		return 0;
        	default: 
				break;
		}
}
return 0;
}

