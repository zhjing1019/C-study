/*
 * 树叶节点遍历（树-基础题)
 *
 * 从标准输入中输入一组整数，在输入过
程中按照左子结点值小于根结点值、右
子结点值大于等于根结点值的方式构造
一棵二叉查找树，然后从左至右输出所
有树中叶结点的值及高度（根结点的高
度为1）。例如，若按照以下顺序输入一
组整数：50、38、30、64、58、40、1
0、73、70、50、60、100、35，则生成
下面的二叉查找树：
 * */

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int level;
    int data;
    struct node *lchild;
    struct node *rchild;
}Bnode,*Btree;

Btree insert(Btree p,int data,int level){
    if(p == NULL){
        p = (Btree)malloc(sizeof(Bnode));
        p->data = data;
        p->lchild = NULL;
        p->rchild = NULL;
        level++;
        p->level = level;
    }
    else if(data < p->data){
        level++;
        p->lchild = insert(p->lchild,data,level);
    }
    else if(data >= p->data){
        level++;
        p->rchild = insert(p->rchild,data,level);
    }
    return p;
}

void visit(Btree T){
    if(T == NULL)
        return;
    else if(T->lchild == NULL && T->rchild == NULL)
        printf("%d %d\n",T->data,T->level);
}

void perorder(Btree T){
    if(T != NULL){
        visit(T);
        perorder(T->lchild);
        perorder(T->rchild);
    }
}

int main(){
    Btree root = NULL;
    int data = 0,level = 0;
    int N;
    scanf("%d",&N);
    while(N--){
        scanf("%d",&data);
        root = insert(root,data,level);
    }
    perorder(root);
    return 0;
}