#include <stdio.h>
#include <stdlib.h>

#define elemType int
#define INITSIZE 10
#define INCREASESIZE 10

/**
 * @brief 定义每个表元素
 * 
 */
typedef struct {
    elemType* data;
    int length;
    int maxSize;
}sqList;

/**
 * @brief 当表满了，分配新的长度
 * 
 * @param L 
 * @return true 分配成功
 * @return false 分配失败
 */
bool increaseMemory(sqList &L){
    sqList T;
    T.data = (elemType*)malloc(sizeof(elemType) * (L.maxSize + INCREASESIZE));
    T.data = L.data;
    L = T;
    return true;
}

/**
 * @brief 初始化顺序表
 * 
 * @param L 
 * @return true 
 * @return false 
 */
bool initSqList(sqList &L){
    if(!(L.data = (elemType*)malloc(sizeof(elemType) * INITSIZE)))
        return false;
    L.length = 0;
    L.maxSize = INITSIZE;
    return true;
}

/**
 * @brief 制定位置插入元素
 * 
 * @param L 
 * @param index 位置
 * @param e 元素
 * @return true 
 * @return false 
 */
bool insert(sqList &L,int index,int e){
    if(L.length == L.maxSize)
        increaseMemory(L);
    if(index <= 0 || index > L.maxSize)
        return false;
       
    if(index <= L.length + 1){
        elemType t = e;

    for(int a = L.length;a >= index;a--){
        L.data[a] = L.data[a - 1];
    }
    L.data[index - 1] = t;

    L.length++;
    printf("插入成功！\n");
        return true;
    }
    
    if(index > L.length + 1){
        printf("插入位置错误！\n");
        return false;
    }
    
}

/**
 * @brief 制定位置删除元素
 * 
 * @param L 
 * @param index 位置
 * @return elemType 返回元素
 */
elemType deleteElem(sqList &L,int index){
    if(index <= 0 || index > L.length)
        return false;;
    int t = L.data[index - 1];
    for(int a = index;a <= L.length;a++){
        L.data[a - 1] = L.data[a];
    }
    L.length--;
    printf("删除成功！\n");
    return t;
    
}

/**
 * @brief 遍历顺序表
 * 
 * @param L 
 */
void traverse(sqList L){
    if(L.length == 0){
        printf("表为空!\n");
        return;
    }

    printf("开始遍历: ");
    for(int i = 1; i <= L.length;i++){
        printf("%d ",L.data[i - 1]);
    }   
    printf("\n");
}

/**
 * @brief 返回表长
 * 
 * @param L 
 * @return int 
 */
int length(sqList L){
    return L.length;
}

/**
 * @brief 按照位置查找元素
 * 
 * @param L 
 * @param index 查找位置
 * @return elemType 结果
 */
elemType searchByIndex(sqList L,int index){
    if(index >= 0 && index <= L.length && L.length != 0)
        return L.data[index - 1];
}

/**
 * @brief 按照元素返回位置
 * 
 * @param L 
 * @param elem 元素
 */
void searchByElem(sqList L,elemType elem){ //输出所有遇到的elem
    printf("searching by Elem …… \n");
    if(L.length != 0){
        for(int i = 1;i <= L.length;i++){
            if(L.data[i - 1] == elem){
                printf("%d位置为元素%d\n",i,elem);
            }
        }
    }
}

/**
 * @brief 清空顺序表
 * 
 * @param L 
 * @return true 
 * @return false 
 */
bool clearSqList(sqList &L){
    L.data = NULL;
    L.length = 0;
    printf("清空表成功！\n");
    return true;
}

/**
 * @brief 销毁顺序表
 * 
 * @param L 
 * @return true 
 * @return false 
 */
bool destroySqList(sqList &L){
    L.data = NULL;
    L.length = 0;
    free(L.data);
    printf("销毁表成功！\n");
    return true;
        
}

/**
 * @brief 测试方法，测试各个方法的正确性，健壮性
 * 
 */
void test(){
    sqList L;
    if(initSqList(L))
        printf("初始化成功！\n");
    insert(L,1,2);
    insert(L,2,3);
    insert(L,3,4);
    insert(L,4,5);
    insert(L,2,6);
    traverse(L);
    deleteElem(L,2);
    insert(L,6,3);
    traverse(L);
    printf("%d位置调用search方法返回： %d\n",3,searchByIndex(L,3));
    searchByElem(L,3);
    clearSqList(L);
    traverse(L);
    destroySqList(L);
}

int main(){
    test();
    return 0;
}
