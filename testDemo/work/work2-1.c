/*
 * 五子棋危险判断
 *
 * 已知两人分别执白棋和黑棋在一个围棋棋盘上下五子棋，若同一颜色的棋子在同一条横行、纵行或斜线上连成5个棋子，则执该颜色棋子的人获胜。编写程
序读入某一时刻下棋的状态，并判断是否有人即将获胜，即：同一颜色的棋子在同一条横行、纵列或斜线上连成4个棋子，且该4个棋子的两端至少有一端
为空位置。
输入的棋盘大小是19×19，用数字0表示空位置（即没有棋子），用数字1表示该位置下了一白色棋子，用数字2表示该位置下了一黑色棋子。假设同一颜色
的棋子在同一条横行、纵列或斜线上连成的棋子个数不会超过4个，并且最多有一人连成线的棋子个数为4。
 * */
#include<stdio.h>

int judge(int A[][19],int a,int b){
    int flag = 0;
    int n = 0;
    int i,j;
    if(A[a][b] == 0)
        return flag;
    else
        flag = A[a][b];
    for( i=a,j=b; i>=0&&i<19&&j>=0&&j<19 ;i++,j--){
        if(A[i][j] == flag)
            n++;
        else
            break;
    }
    if(n>4)
    {return flag;}
    else if(n == 4){
        if(i>=0 && i<19 && j>=0 && j<19 && A[i][j] == 0)
            return flag;
        else if(a-1>=0 && a-1<19 && b+1>=0 && b+1<19 &&A[a-1][b+1] == 0)
            return flag;
    }
    n=0;
    for( i=a,j=b; i>=0&&i<19&&j>=0&&j<19 ;j++){
        if(A[i][j] == flag)
            n++;
        else
            break;
    }
    if(n>4)
        return flag;
    else if(n ==4){
        if(i>=0 && i<19 && j>=0 && j<19 &&A[i][j] == 0)
            return flag;
        else if(a>=0 && a<19 && b-1>=0 && b-1<19 &&A[a][b-1] == 0)
            return flag;
    }
    n=0;
    for( i=a,j=b; i>=0&&i<19&&j>=0&&j<19 ;i++,j++){
        if(A[i][j] == flag)
            n++;
        else
            break;
    }
    if(n>4)
        return flag;
    else if(n == 4){
        if(i>=0 && i<19 && j>=0 && j<19 &&A[i][j] == 0)
            return flag;
        else if(a-1>=0 && a-1<19 && b-1>=0 && b-1<19 &&A[a-1][b-1] == 0)
            return flag;
    }
    n=0;
    for( i=a,j=b; i>=0&&i<19&&j>=0&&j<19 ;i++){
        if(A[i][j] == flag)
            n++;
        else
            break;
    }
    if(n>4)
        return flag;
    else if(n == 4){
        if(i>=0 && i<19 && j>=0 && j<19 &&A[i][j] == 0)
            return flag;
        else if(a-1>=0 && a-1<19 && b>=0 && b<19 &&A[a-1][b] == 0)
            return flag;
    }
    return 0;

}


int main(){
    int A[19][19] = {0};
    int flag = 0;
    int i,j;
    for( i = 0;i<19;i++)
        for( j = 0;j<19;j++)
            scanf("%d",&A[i][j]);

    for( i = 0;i<19;i++)
    {
        for( j = 0;j<19;j++)
        {
            flag = judge(A,i,j);
            if(flag > 0)
                break;
        }
        if(flag > 0)
            break;
    }
    if(flag > 0)
        printf("%d:%d,%d",flag,i+1,j+1);
    else
        printf("No");
    return 0;
}