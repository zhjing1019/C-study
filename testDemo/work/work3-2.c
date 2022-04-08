/*
 * 猴子选大王 ?
 * */
#include<stdio.h>
#include<stdlib.h>

typedef struct monkey{
    int number;
    struct monkey *link;
}monkey,*linklist;

linklist creat(int n){
    linklist list = NULL,p,q;
    for(int i=1;i<=n;i++){
        q = (linklist)malloc(sizeof(monkey));
        q->number = i;
        q->link = NULL;

        if(list == NULL)
            list = p = q;
        else{
            p->link = q;
            p = p->link;
        }
    }
    p->link = list;
    return list;
}

linklist find_q(linklist list,int q){
    linklist p = list;
    while(p->number != q){
        p = p->link;
    }
    return p;
}

void Delete(linklist list,linklist p){
    linklist r = list;
    while(r->link != p){
        r = r->link;
    }
    r->link = p->link;
    free(p);
}

int main(){
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    linklist list,p;
    list = creat(n);
    p = find_q(list,q);
    while(p->link != p){
        for(int i=1;i<m;i++){
            p = p->link;
        }
        linklist temp = p->link;
        Delete(temp,p);//Delete(list,p)Wrong��list�Ѿ�û���ˡ�
        p = temp;
    }
    printf("%d",p->number);
    return 0;
}