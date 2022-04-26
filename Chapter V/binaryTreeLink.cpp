#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct BTNode{
    ElemType data;
    struct BTNode *lChild,*rChild;
}BTNode,*BTree;
