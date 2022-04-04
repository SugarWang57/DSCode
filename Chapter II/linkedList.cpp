#include <stdio.h>
#include <stdlib.h>

#define elemType int

/**
 * @brief 定义节点
 * 
 */
typedef struct node{
	elemType data;
	struct node *next; 
}node,*linkedList;
/* node *Node == linkedList L */
/* *Node 和 L都表示第一个结点，前者强调结点，后者强调L为一个单链表，后者可读性高 */

/**
 * @brief 初始化链表
 * 
 * @param L 
 * @return true 初始化成功
 * @return false 初始化失败
 */
bool initList(linkedList &L){
	L = (node*)malloc(sizeof(node));
	
	if(L == NULL)           
		return false;
		
	L -> next = NULL;
	printf("带头节点的单链表 初始化成功！\n");
	return true;
}

/**
 * @brief 插入元素到连表i位置
 * 
 * @param L 
 * @param i 插入位置
 * @param e 插入元素
 * @return true 插入成功
 * @return false 插入失败
 */
bool insert(linkedList &L,int i,elemType e){
	if(i < 1)
		return false;
		
	if(i ==1){
		node *s = (node*)malloc(sizeof(node));

		// 插入交换三部曲
		s -> data = e;
		s -> next = L;
		L = s;
		
		return true;
	}
		
	node *p;
	int j = 1;
	p = L;
	
	while(p != NULL && j < i - 1){
		p = p -> next;
		j++;
	}
	
	if(p == NULL) //i不合法
		return false;
		
	node *s = (node*)malloc(sizeof(node));
	
	s -> data = e;
	s -> next = p -> next;
	p -> next = s;
	
	return true;
}

/**
 * @brief 插入到指定结点下一个节点，元素为e（后差）
 * 
 * @param p 指定结点
 * @param e 插入结点的数据元素
 * @return true 插入成功
 * @return false 插入失败
 */
bool insertNextNode(node *p,elemType e){
	if(p == NULL)
		return false;
		
	node *s = (node*)malloc(sizeof(node));
	
	if(s == NULL)//内存分配失败
		return false;
		
	s -> data = e;
	s -> next = p -> next;
	p -> next = s;
	
	return true;
}

/**
 * @brief 插入到指定结点上一个节点，元素为e（前差）
 * 
 * @param p 指定结点
 * @param e 插入结点的数据元素
 * @return true 插入成功
 * @return false 插入失败
 */
bool insertPriorNode(node *p,node *s){
	if(p == NULL || s == NULL)
		return false;
		
	s -> next = p -> next;
	p -> next = s;
	elemType temp = p -> data;
	p -> data = s -> data;
	s -> data = temp;

	return true;
}

/**
 * @brief 删除制定位置的结点，返回数据元素
 * 
 * @param L 
 * @param i 删除结点的位置
 * @param e 用来返回删除的数据元素
 * @return true 删除成功
 * @return false 删除失败
 */
bool deleteByIndex(linkedList L,int i,elemType &e){
	if(i < 1)
		return false;
		
	node *p;
	int j = 0;
	p = L;
	
	while(p != NULL && j < i - 1){
		p = p -> next;
		j++;
	}
	
	if(p == NULL)
		return false;
		
	if(p -> next == NULL)
		return false;
		
	node *q = p -> next;
	e = q -> data;
	p -> next = q -> next;
	
	free(q);
	
	return true;
	/* 时间复杂度： 最好O(1),最坏and平均O(n) */
}


/**
 * @brief 删除节点
 * 
 * @param p 要删除的结点
 * @return true 删除成功
 * @return false 删除失败
 */
bool deleteNode(node *p){
	if(p == NULL)
		return false;
		
	node *q = p -> next;//如果删除最后一个就有bug
	p -> data = p -> next -> data; 
	p -> next = q -> next;
	
	free(q);
	
	return true;
}

/**
 * @brief 尾插法建立单链表
 * 
 * @param L 
 * @return linkedList 建立的单链表
 */
linkedList list_TailInsert(linkedList &L){
	int x;
	
	L = (linkedList)malloc(sizeof(node));
	
	node *s;
	node *r = L;
	
	scanf("%d",&x);
	while(x != 9999){
		s = (node*)malloc(sizeof(node));
		
		s -> data = x;
		r -> next = s;
		r = s;
		
		scanf("%d",&x);
	}
	
	r -> next = NULL;
	
	return L;
}

/**
 * @brief 头插法建立单链表
 * 
 * @param L 
 * @return linkedList 
 */
linkedList list_HeadInsert(linkedList &L){
	int x;
	
	L = (linkedList)malloc(sizeof(node));
	
	node *s;
	L -> next = NULL;
	
	scanf("%d",&x);
	while(x != 9999){
		s = (node*)malloc(sizeof(node));
		
		s -> data = x;
		s -> next = L -> next;
		L -> next = s;
		
		scanf("%d",&x);
	}
	return L;
}

void traverse(linkedList L){
    node *p = L;
    while(p -> next != NULL){
        printf("%d ",p -> data);
		p = p -> next;
        
	}
    printf("\n");
}

/**
 * @brief 测试方法
 * 
 */
void test(){
    linkedList L;
    initList(L);
    insert(L,1,1);
    insert(L,2,2);
    insert(L,3,3);
    insert(L,4,5);
    insert(L,5,7);
    traverse(L);
    int e;
    deleteByIndex(L,4,e);
    traverse(L);

}

int main(){
    test();
    return 0;
}

