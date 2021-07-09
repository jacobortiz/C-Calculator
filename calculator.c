#include <stdio.h>
#define MAX 100

int output_queue[MAX];
int output_identifier[MAX];
int front = -1;
int rear = -1;
int size = -1;

// identifier - 0 is num, 1 is operator;
void enqueue(int value, int identifier) {
    // check if queue is not full
    if(size < MAX) {
        // check if queue is initialized
        if(size < 0) {
            output_queue[0] = value;
            output_identifier[0] = identifier;
            front = rear = 0;
            size = 1;
        // if rear is last element, add new element at index 0
        } else if(rear == MAX - 1) {
            output_queue[0] = value;
            output_identifier[0] = identifier;
            rear = 0;
            size++;
        } else {
            output_queue[rear + 1] = value;
            output_identifier[rear + 1] = identifier;
            rear++;
            size++;
        }
    } else {
        printf("Queue is full.\n");
    }
}

void dequeue() {
    if(size < 0) {
        printf("Queue is empty.\nMake a new one.\n");
    } else {
        size--;
        front++;
    }
}

int isFull() {
    return size == MAX;
}

int isEmpty() {
    return size < 0;
}

int getFront() {
    return output_queue[front];
}

void displayQueue() {
    printf("Postfix: ");
    int i;
    if(rear >= front) {
        for(i = front; i <= rear; i++) {
            if(output_identifier[i] == 0) {
                printf("%d ", output_queue[i]);
            } else {
                printf("%c ", output_queue[i]);
            }
        }
    } else {
        for(i = front; i < MAX; i++) {
            if(output_identifier[i] == 0) {
                printf("%d ", output_queue[i]);
            } else {
                printf("%c ", output_queue[i]);
            }
        }

        for(i = 0; i <= rear; i++) {
            if(output_identifier[i] == 0) {
                printf("%d ", output_queue[i]);
            } else {
                printf("%c ", output_queue[i]);
            }
        }
    }
    printf("\n");
}

int toInt(char* string) {
    int i = 0;
    int num = 0;
    while(string[i] != 0) {
        num = (string[i] - '0') + (num * 10);
        i++; 
    }
    return num;
}

char operator_stack[MAX];
int top = -1;

int isEmptyStack() {
    return top == -1;
}

int isFullStack() {
    return top == MAX;
}

int getTop() {
    return operator_stack[top];
}

char pop() {
    char operator;

    if(!isEmptyStack()) {
        operator = getTop();
        top -= 1;
        return operator;
    } else {
        printf("Stack is empty.\n");
    }
    return 0;
}

void push(char operator) {
    if(!isFullStack()) {
        top += 1;
        operator_stack[top] = operator;
    } else {
        printf("Stack is full.\n");
    }
}

void clearStack() {
    printf("\nOperator Stack: ");
    while(!isEmptyStack()) {
        char operator = pop();
        printf("%c ", operator);
    }
    printf("\n");
}

int modulo(int base, int divisor) {
    return (base - divisor * (base / divisor));
}

int power(int base, int exponent) {
    int i;
    int number = 1;
    for(i = 0; i < exponent; i++) {
        number *= base;
    }
    return number;
}

int evaluatePostfix() {
    // check it
    int temp_nums[MAX];
    int temp_top = -1;
    int var1, var2;

    int i;
    if(rear >= front) {
        for(i = front; i <= rear; i++) {
            if(output_identifier[i] == 0) {
                temp_top += 1;
                temp_nums[temp_top] = output_queue[i];
            } else {
                // an operator
                var1 = temp_nums[temp_top];
                temp_top -= 1;
                var2 = temp_nums[temp_top];
                temp_top -= 1;

                if(output_queue[i] == '+') {
                    temp_top += 1;
                    temp_nums[temp_top] = var2 + var1;
                } else if(output_queue[i] == '-') {
                    temp_top += 1;
                    temp_nums[temp_top] = var2 - var1;
                } else if(output_queue[i] == '*') {
                    temp_top += 1;
                    temp_nums[temp_top] = var2 * var1;
                    
                } else if(output_queue[i] == '/') {
                    temp_top += 1;
                    temp_nums[temp_top] = var2 / var1;
                } else if(output_queue[i] == '^') {
                    temp_top += 1;
                    temp_nums[temp_top] = power(var2, var1);
                } else if(output_queue[i] == '%') {
                    temp_top += 1;
                    temp_nums[temp_top] = modulo(var2, var1);
                }
            }
        }
    } else {
        for(i = front; i < MAX; i++) {
            if(output_identifier[i] == 0) {
                temp_top += 1;
                temp_nums[temp_top] = output_queue[i];
            } else {
                // an operator
                var1 = temp_nums[temp_top];
                temp_top -= 1;
                var2 = temp_nums[temp_top];
                temp_top -= 1;
                
                if(output_queue[i] == '+') {
                    temp_top += 1;
                    temp_nums[temp_top] = var2 + var1;
                } else if(output_queue[i] == '-') {
                    temp_top += 1;
                    temp_nums[temp_top] = var2 - var1;
                } else if(output_queue[i] == '*') {
                    temp_top += 1;
                    temp_nums[temp_top] = var2 * var1;
                    
                } else if(output_queue[i] == '/') {
                    temp_top += 1;
                    temp_nums[temp_top] = var2 / var1;
                } else if(output_queue[i] == '^') {
                    temp_top += 1;
                    temp_nums[temp_top] = power(var2, var1);
                } else if(output_queue[i] == '%') {
                    temp_top += 1;
                    temp_nums[temp_top] = modulo(var2, var1);
                }
            }
        }

        for(i = 0; i <= rear; i++) {
            if(output_identifier[i] == 0) {
                temp_top += 1;
                temp_nums[temp_top] = output_queue[i];
            } else {
                // an operator
                var1 = temp_nums[temp_top];
                temp_top -= 1;
                var2 = temp_nums[temp_top];
                temp_top -= 1;
                
                if(output_queue[i] == '+') {
                    temp_top += 1;
                    temp_nums[temp_top] = var2 + var1;
                } else if(output_queue[i] == '-') {
                    temp_top += 1;
                    temp_nums[temp_top] = var2 - var1;
                } else if(output_queue[i] == '*') {
                    temp_top += 1;
                    temp_nums[temp_top] = var2 * var1;
                } else if(output_queue[i] == '/') {
                    temp_top += 1;
                    temp_nums[temp_top] = var2 / var1;
                } else if(output_queue[i] == '^') {
                    temp_top += 1;
                    temp_nums[temp_top] = power(var2, var1);
                } else if(output_queue[i] == '%') {
                    temp_top += 1;
                    temp_nums[temp_top] = modulo(var2, var1);
                }
            }
        }
    }
    return temp_nums[temp_top];
}


int main(void) {
    char toks[MAX];
    fgets(toks, MAX, stdin);

    char nums[MAX];
    int previous_num = 0; 
    int total = 0;

    int counter = 0;
    for(int i = 0; i < MAX; i++) {
        // check for numbers
        if(toks[i] >= 48 && toks[i] <= 57) {
            previous_num = 1;
            nums[counter] = toks[i];
            counter++;
        } else {
            if(previous_num == 1) {
                nums[counter] = '\0';
                counter = 0;
                previous_num = 0;
                int temp_num = toInt(nums);
                enqueue(temp_num, 0);
            }

            // push operators on stack
            if(toks[i] == 40) {
                // opening parenthesis
                push(toks[i]);
            } else if(toks[i] == 41) {
                // closing parenthesis
                // push top operator to queue

                // keep adding operators to queue until opening parenthesis is found
                while(getTop() != 40) {
                    enqueue(getTop(), 1);
                    pop();
                }
                pop();

            } else if(toks[i] == 43) {
                // addition, 2 precedence
                if(getTop() == 42 || getTop() == 47 || getTop() == 43 || getTop() == 45 || getTop() == 37) {
                    enqueue(getTop(), 1);
                    pop();
                }

                push(toks[i]);
            } else if(toks[i] == 45) {
                // subtraction, 2 precedence
                if(getTop() == 42 || getTop() == 47 || getTop() == 43 || getTop() == 45 || getTop() == 37) {
                    enqueue(getTop(), 1);
                    pop();
                }
                push(toks[i]);

            } else if(toks[i] == 42) {
                // multiplication, 3 precedence
                if(getTop() == 47 || getTop() == 42 || getTop() == 94 || getTop() == 37)  {
                    enqueue(getTop(), 1);
                    pop();
                }
                push(toks[i]);

            } else if(toks[i] == 47) {
                // division, 3 precedence
                if(getTop() == 42 || getTop() == 47 || getTop() == 94 || getTop() == 37) {
                    enqueue(getTop(), 1);
                    pop();
                }
                push(toks[i]);
            } else if(toks[i] == 94) {
                // exponential op, 4 precedence
                push(toks[i]);

            } else if(toks[i] == 37) {
                // modulo, 3 precedence , %
                if(getTop() == 42 || getTop() == 47 || getTop() == 94 || getTop() == 37) {
                    enqueue(getTop(), 1);
                    pop();
                }
                push(toks[i]);                
            }
        }

        if(toks[i] == '\0') {
            break;
        }
    }
    // after reading input, output expression in postfix
    
    // 1. pop operators off the stack and add them to output_queue;
    while(!isEmptyStack()) {
        enqueue(pop(), 1);
    }

    displayQueue();
    printf("\nResult: %d\n", evaluatePostfix());


}