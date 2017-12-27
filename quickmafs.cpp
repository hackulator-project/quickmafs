#include "quickmafs.h"
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 50
 
void infix_to_postfix(char infix[],char postfix[]) { //give a buffer for the infix (such as 2+2-1) and get the output in a postfix buffer (such as 2 2 + 1 -)
    stack s;
    char x,token;
    int i,j;    //i-index of infix,j-index of postfix
    init(&s);
    j=0;
    int nexttime = 123;
    for(i=0;infix[i]!='\0';i++)
    {
        token=infix[i];
        if(isalnum(token) || token == '.') { //numeric
            postfix[j++]=token;
            //postfix[j++]=' ';
        } else if(token=='(') { //parenthisis
               push(&s,'(');
        }
        else if(token==')') { //parenthisisisisis
               while((x=pop(&s))!='(') {
                   if(x != ' ') {
                       postfix[j++]=' ';
                   }
                   postfix[j++]=x;
               }
        } else { //operator
                    postfix[j++]=' ';
                    while(precedence(token)<=precedence(top(&s))&&!empty(&s)) {
                        x=pop(&s);
                        postfix[j++]=' ';postfix[j++]=x;
                    }
                    push(&s, ' ');
                    push(&s,token);
        }
    }
 
    while(!empty(&s))
    {
        x=pop(&s);
        postfix[j++]=x;
    }
 
    postfix[j]='\0';
}
 
int precedence(char x)
{
    if(x=='(')
        return(0);
    if(x=='+'||x=='-')
        return(1);
    if(x=='*'||x=='/'||x=='%')
        return(2);
 
    return(3);
}
 
void init(stack *s)
{
    s->top=-1;
}
 
int empty(stack *s)
{
    if(s->top==-1)
        return(1);
 
    return(0);
}
 
int full(stack *s)
{
    if(s->top==MAX-1)
        return(1);
 
    return(0);
}
 
void push(stack *s,int x)
{
    s->top=s->top+1;
    s->data[s->top]=x;
}
 
int pop(stack *s)
{
    int x;
    x=s->data[s->top];
    s->top=s->top-1;
    return(x);
}
 
int top(stack *p)
{
    return (p->data[p->top]);
}
