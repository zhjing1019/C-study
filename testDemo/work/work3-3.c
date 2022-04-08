/*
 * 多项式相乘
 * */
#include<stdio.h>
#include<stdlib.h>

// 定义结构体
typedef struct Item{
    int factor;
    int index;
    struct Item *link;
}Item,*linklist;

linklist creat(){
    char c = 0;
    linklist list = NULL,p,q;
    while(c != '\n'){
        int f,i;
        scanf("%d%d",&f,&i);
        q = (linklist)malloc(sizeof(Item));
        q->factor = f;
        q->index = i;
        q->link = NULL;
        if(list == NULL)
            list = p = q;
        else{
            p->link = q;
            p = p->link;
        }

        c = getchar();
    }

    return list;
}

linklist getNode(linklist result,linklist q){
    linklist p = result;
    if(p == NULL)
        return result;
    while(p != NULL){
        if(p->index == q->index)
            return p;
        p = p->link;
    }

    return NULL;
}

linklist insert(linklist result,int f,int i){
    linklist p,q,position;
    q = (linklist)malloc(sizeof(Item));
    q->factor = f;
    q->index = i;
    q->link = NULL;

    position = getNode(result,q);
    if(position != NULL)
        position->factor = position->factor + f;
    else{
        p = result;
        if(p == NULL)
            result = p = q;
        else if(q->index > p->index){
            q->link = result;
            result = p = q;
        }
        else{
            while(p->link != NULL){
                linklist temp = p->link;
                if(temp->index < q->index){
                    p->link = q;
                    q->link = temp;
                    break;
                }
                p = p->link;
            }
            if(p->link == NULL){
                p->link = q;
            }
        }
    }
    return result;
}


int main(){
    linklist list1,list2,result = NULL;
    list1 = creat();
    list2 = creat();

    int f = 0,i = 0;
    linklist l1,l2;
    l1 = list1;

    while(l1 != NULL){
        int f1 = l1->factor;
        int i1 = l1->index;
        l2 = list2;
        while(l2 != NULL){
            int f2 = l2->factor;
            int i2 = l2->index;

            f = f1 * f2;
            i = i1 + i2;

            result = insert(result,f,i);
            l2 = l2->link;
        }
        l1 = l1->link;
    }

    while(result != NULL){
        printf("%d %d ",result->factor,result->index);
        result = result->link;
    }
    return 0 ;
}