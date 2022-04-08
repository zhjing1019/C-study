/*
 * 连续线段 ?
 *
 * */
#include<stdio.h>
//using namespace std;

typedef struct Coordinate{
    int x;
    int y;
}Coordinate;

typedef struct line{
    Coordinate left;
    Coordinate right;
    int flag;
}line;

int main(){
    int N;
    scanf("%d",&N);
    line L[100];
    int i = 0;
    while(N--){
        scanf("%d%d%d%d",&L[i].left.x,&L[i].left.y,&L[i].right.x,&L[i].right.y);
        L[i].flag = 0;
        i++;
    }
    N = i;

    int number = 0;
    Coordinate out = {0,0};


    for(int i=0;i<N;i++){
        if(L[i].flag == 1)
            continue;
        else{
            //printf("%d",i+1);
            L[i].flag = 1;
            line leftmost = L[i];
            line rightmost = L[i];
            int tempnum = 1;

            for(int j=0;j<N;j++){
                if(L[j].flag == 1)
                    continue;
                if(L[j].right.x==leftmost.left.x && L[j].right.y==leftmost.left.y){
                    L[j].flag = 1;
                    tempnum++;
                    leftmost = L[j];
                    //printf("%d",j+1);
                    j = 0;
                }
                else if(L[j].left.x==rightmost.right.x && L[j].left.y==rightmost.right.y){
                    L[j].flag = 1;
                    tempnum++;
                    rightmost = L[j];
                    //printf("%d",j+1);
                    j = 0;
                }
            }
            if(tempnum > number){
                number = tempnum;
                out = leftmost.left;
            }
            //printf("\n");
        }
    }

    printf("%d %d %d",number,out.x,out.y);
}
