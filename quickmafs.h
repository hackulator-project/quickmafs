#ifndef QUICKMAFS_H
#define QUICKMAFS_H
#define MAX 50
typedef struct stack
{
    int data[MAX];
    int top;
}stack;
 

void infix_to_postfix(char infix[],char postfix[]);
void push(stack *s,int x);
int pop(stack *s);
int full(stack *s);
int empty(stack *s);
void init(stack *s);
int precedence(char x);
int top(stack *p);
#endif
