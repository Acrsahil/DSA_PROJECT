#include<stdio.h>
#include <stdlib.h>


struct stack {
    int size;
    int top;
    int *arr;
}typedef stack;


int is_empty(stack *  st){
    return st->top == -1;
}

int is_full(stack *  st){
    return st->top == st->size-1;
}

void push(stack * st, int data){
    if(is_full(st)){
        printf("Stack Overflow!\n");
    }else{
        st->top++;
        st->arr[st->top] = data;
    }
}


void pop(stack * st){
    if(is_empty(st)){
        printf("Stack Underflow!\n");
    }else{
        st->top--;
    }
}

int peek(stack * st){
    if(is_empty(st)){
        printf("Stack Underflow!\n");
    }
        int data = st->arr[st->top];
        return data;
    
}

void display(stack * st){
    if(is_empty(st)){
        printf("Can't Display Stack is Empty!\n");
    }else{
        for(int i = 0; i<=st->top; i++){
            printf("%d ",st->arr[i]);
        }
            printf("\n");
    }
}

stack *  make_stack(int num){
    stack * st = (stack *) malloc(sizeof(stack));
    st->arr = (int *) malloc(sizeof(int)*num);
    st->size = num;
    st->top = -1;
    return st;
}



int main(){
    stack * st = make_stack(10);
    push(st,10);
    push(st,100);
    push(st,1000);
    push(st,10000);
    display(st);
    printf("Top of the stack is %d\n",peek(st));
    pop(st);
    pop(st);
    pop(st);
    pop(st);
    pop(st);
    display(st);
    push(st,10);
    display(st);
}
