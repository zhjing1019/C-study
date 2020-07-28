#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
}SqList, *LinkList;

// 单链表插入
bool InsertNextNode(LinkList &L, int i, int e) {
    if(i < 1) 
        return false;
    LNode *p;
    int j = 0;
    while(p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if(p == NULL) {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->next = p->next;
    s->data = e;
    p->next = s;
    return true;
}
int main() {
    LinkList L;
    int e = 3;
    InsertNextNode(L, 6, e);
}