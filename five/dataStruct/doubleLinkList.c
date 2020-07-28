#include <stdio.h>
#include <stdlib.h>

// 初始化双链表
typedef struct DNode {
    int data;           //数据
    struct DNode *prior, *next;    //前驱和后驱
}DNode, *DouLinkList;

// 初始化双链表
void InitDouList(DouLinkList &D) {
    D = (DNode *)malloc(sizeof(DNode));
    if(D == NULL)
        return ;
    D->data = 0;
    D->prior = NULL;
    D->next = NULL;
};
bool InsertDouList(DNode *p, DNode *s) {
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
};

int main() {
    DouLinkList L;
    InitDouList(L);
    DouLinkList s;
    InsertDouList(L, s);
};