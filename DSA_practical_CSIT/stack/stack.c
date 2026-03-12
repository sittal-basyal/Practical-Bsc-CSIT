#include <stdio.h>
#define MAX 30

struct stack
{
    int data[MAX];
    int tos;
};

int isFull(struct stack *s)
{
    if (s->tos == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct stack *s)
{
    if (s->tos == -1){
        return 1;
    }else{
        return 0;
    }
}

void push(struct stack *s, int data)
{
    if (isFull(s))
    {
        printf("Stack overflow.. Data cannot be pushed");
    }
    else
    {
        s->tos++;
        s->data[s->tos] = data;
    }
}

void pop(struct stack *s)
{
    if (isEmpty(s)){
        print("Stack underflown... nothing to pop");
    }else{
       int poppedData = s->data[s->tos];
       s->tos--;
    }
}

int top(struct stack *s)
{
   int top = s->data[s->tos];
   print("The top of the stack is: %d", top);
}

void display(struct stack *s)
{

}

int main()
{
    struct stack s1;
    s1.tos = -1;
    push(&s1, 45);
    return 0;
}
