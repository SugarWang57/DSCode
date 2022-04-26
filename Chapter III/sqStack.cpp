#include<stdio.h>
#include<stdlib.h>

#define INITSIZE 5
#define INCREASESIZE 5
#define elemType int

typedef struct{
    elemType *data;
    int top;
    int maxSize;
}sqStack;

bool increaseSize(sqStack& S){
    sqStack T;
    T.data = (elemType*)malloc(sizeof(elemType) * (S.maxSize + INCREASESIZE));
    S.maxSize += INCREASESIZE;
    T.data = S.data;
    S.data = T.data;
    free(T.data);
    return true;
}

bool initStack(sqStack &S){
    S.data = NULL;
    S.maxSize = INITSIZE;
    S.top = -1;
    printf("初始化成功！\n");
    return true;
}

bool isEmpty(sqStack S){
    return S.top == -1;
}

bool isFull(sqStack S){
    return S.top == S.maxSize - 1;
}

bool push(sqStack& S,elemType d){
    if(isFull(S))
        increaseSize(S); 
    S.data[++S.top] = d;
    return true;
}

elemType pop(sqStack &S){
    if(isEmpty(S)){
        return false;
    }
    else{
        elemType x = S.data[S.top--];
        printf("%d出栈成功",x);
        return x;
    }
}

void test(){
    sqStack S;
    if(initStack(S)){
        push(S,1);
        push(S,2);
        push(S,3);
        push(S,4);
        push(S,5);
        push(S,9);

        pop(S);
        pop(S);
        pop(S);
        pop(S);
        pop(S);
        pop(S);
        pop(S);
    }
    else{
        printf("Error in initiating the stack\n");
    }
}


int main(){
    test();
    return 0;
}