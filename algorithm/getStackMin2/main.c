#include <stdio.h>
#include <stdlib.h>

#define len 10

typedef struct stack{
    int top1;
    int top2;
    int arr1[len];
    int arr2[len];

} stack;

void push(stack *st,int val){
    st->arr1[++st->top1] = val;
    if(st->top2 == -1)
        st->arr2[++st->top2] = val;
    else if(val <= getMin(st)){
        st->arr2[++st->top2] = val;
    }
}

void exception(){
    printf("Your stack is empty!\n");
}

int pop(stack *st){
    if(st->top2 == -1){
        atexit(exception);
    }
    int data = st->arr1[st->top1--];

    if(data == getMin(st)){
        --st->top2;
    }

    return data;
}



int getMin(stack *st){
    if(st->top2 == -1){
        atexit(exception);
    }
    return st->arr2[st->top2];
}
int main()
{

    stack st={-1,-1};

    push(&st,3);
    printf("%d\n",getMin(&st));
    push(&st,4);
    printf("%d\n",getMin(&st));
    push(&st,1);
    printf("%d\n",getMin(&st));
    push(&st,2);
    printf("%d\n",getMin(&st));
    return 0;
}
