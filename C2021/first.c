// 要用到输入输出函数！
# include <stdio.h>
// hello world C program
int main()
{
  printf("hello world C program \n");

  // 求俩个数之和
  int a, b, sum;
  a = 123;
  b = 321;
  sum = a + b;
  printf("sum is %d\n", sum);  //输出格式字符串，%d是指定输出格式

   // 求俩个整数中的较大者
   int max(int x, int y);  //定义函数
   int c, d, e;
   scanf("%d, %d", &c, &d);
   e = max(c, d);
   printf("max is %d", e);

  // 求5的阶乘 5!
  int t, i;
  t = 1;
  i = 2;
  while (i <= 5)
  {
    t *= i;
    i++;
  }
  printf("%d\n", t);

  //给定一个大写字母，要求用小写字母输出
  char c1, c2;
  c1 = 'A';
  c2 = c1 + 32;
  printf("%c\n", c1);
  printf("%c\n", c2);

  // 输入一个大于3的整数n，判定他是否为素数
  int n, i;
  printf("please enter a integer number, n=?");
  scanf("%d", &n);
  for(i = 2;i < n-1; i++) {
    if(n%i == 0) break;
  }
  if(i < n) printf("%d is not prime number. \n", n);
  else printf("%d is a prime number.\n", n);
  return 0;

  // 对10个数组元素依次赋值为0，1，2，3，4，5，6，7，8，9，要求逆序输出
  int i, a[10];
  for(i = 0;i <= 9; i++)
    a[i] = i;
  for(i = 9; i >= 0; i--)
    printf("%d", a[i]);
  printf("\n");

  // 一维数组初始化
  int a[10] = {0,1,2,3,4,5,6,7,8,9}

  // 定义二维数组
  float pay[3][6]

  //二维数组的初始化
  int a[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,0,1,2}}

  return 0;
}

//求俩个整数中较大者，max函数
int max(int x, int y)
{
  int z;
  if(x > y) z = x;
  else z = y;
  return z;
}

//求一个数是不是质数
int main()
{
   int i, n = 13;
   for(i = 2; i <= n-1; i++) {
     if(n%i == 0) break;
   }
   if(i < n) printf("%d is not a prime number \n", n);
   else printf("%d is a prime number \n", n);

   return 0;
}

// C语言的斐波那契数列
int main()
{
   int f1 = 1, f2 = 1, f3, i;
	printf("%d\n%d\n",f1,f2);
	for(i = 1; i < 38; i++)
	{
		f3 = f1 + f2;
		printf("%d\n",f3);
		f1 = f2;
		f2 = f3;
	}
	return 0;

}

// *****对一个数组从小到大的排列 （冒泡排序,俩俩比较，俩俩交换，大的往后冒泡）
// *****冒泡排序要经过俩次循环
void sort()
{
    int i, j;
    for(j = 0; j < 9; j++ )    //进行9次循环，9躺比较
    {
        for(i = 0; i < 9-j; i++)  //每一趟都要进行9-i次比较
        {
            if(a[i]>a[i+1])     //相邻俩个数比较
                t = a[i]; a[i] = a[i+1]; a[i+1] = t;
        }
    }
}

// ****统计有多少个单词，单词之间用空格隔开
int getWord()
{
    char string[81];
    int i, num = 0, word=0;
    char c;
    gets(string)
    for(i = 0; (c=string[i]) != '\0'; i++)
    {
        if(c == '') word = 0;  //word是判断是否是新开始的单词
        else if(word == 0)
        {
            word = 1; num++;
        }
    }
    printf("%d", num);
    return 0;
}

// 将数组a中n个整数按相反顺序存放
void inv(int *x,int n)    //形参X是指针变量
{
    int *p, temp, *i, *j, m=(n-1)/2;
    i = x; j = x+n-1; p=x+m;
    for(; i <= p; i++; j--)
    {
        temp=*i; *i = *j; *j = temp;  //*i与*j交换
    }
    return;
}

// 已知二叉树采用二叉链表存储结构，根结点的地址为T，请写出一非递归算法，统计出该二叉树中度为1的节点数目，要求用到堆栈采用链式存储结构
// 利用二叉树的遍历操作，前序遍历，在遍历的过程中每访问一个节点就判断该节点是否只存在一颗子树，同时记录
typedef struct node{
    BTREE data;
    struct node *link;
}BLNode, *BLinkList;   //定义链接堆栈的结构
int COUNT(BTREE T)
{
//    利用前序遍历的非递归算法统计度为1的节点数目
    // p为当前节点
    BTREE p=T;
    // q为链式堆栈，top为栈顶元算
    BlinkList q, top = NULL;
    int n = 0;  //记录度为1的节点数目
    if(T!=NULL)
    {
        do{
            while(p!=NULL){
                // 度为1的时候记录数据
                if(p->lchild !=NULL && p->rchild == NULL || p->lchild == NULL && p->rchild != NULL)
                    n++;
                // 让其左孩子进栈
                q = (BLinkList)malloc(sizeif(BLNode));
                q -> data = p;
                q -> link = top;
                top = q;              //以上三条语句将P所指节点的地址进栈
                p = p -> lchild;      //将p移动到其左孩子节点
            }
            // 退栈
            p = top -> data;
            q = top;
            top = top -> link;
            free(q);
            // 让当前节点之乡右孩子
            p=p -> rchild;
        }while(!(p == NULL && top == NULL));
    }
    return n;
}

//　已知非空二叉树采用二叉链表存储结构，根结点地址为T，请写出非递归算法，该算法打印数据信息为item的节点所有的祖先节点，假设数据信息为item的节点不多于一个
// 这里为了简化算法，假设每个节点的数据信息为一个十进制整数。根据定义，一个节点的祖先定义为根结点到该节点的双亲节点路径上的所有节点。因此本题利用后续遍历二叉树的非递归算法达到目的
// 在遍历的过程中，当找到满足条件的节点时，堆栈中依次保存的就是该节点的祖先节点

#define NodeNum 100   /* 定义二叉树中节点最大数目 */
void ANCESTOR(BTREE, int item)
{
    // 第一个堆栈用来存放节点，第二个堆栈用来存放标志
    BTREE STACK1[NodeNum], p = T;
    int STACK2[NodeNum],top = -1,flag;
    if(T != NULL && T -> data != item) {   /* 若二叉树不为空且根结点不满足条件 */
        do{
            while(p!=NULL){
                STACK1[++top] = p;   /*当前p所指节点的地址进栈*/
                STACK2[top] = 0;     /*标志0进栈*/
                p = p -> lchild;     /*将p移动到其左孩子节点*/
            }
            p = STACK1[top];         /*栈1的顶节点（地址）退栈送p*/
            flag = STACK2[top--];    /*栈2的顶元素（标志）退栈送flag*/
            if(flag == 0) {
                STACK1[++top] = p;      /*当前p所指节点再次进栈*/
                STACK2[top] = 1;        /*标志1进栈*/
                p = p -> rchild;        /*将p移到右孩子节点*/
            }
            else{
                if(p -> data === item) {  /*若P所指节点满足条件*/
                    while(top != -1) {  /*依次输出P所指节点的祖先*/
                        printf("%4d",STACK1[top--] -> data);
                    }
                    break;   /*退出算法*/
                }
                else
                    p = NULL;  /*置p为null*/
            }
        }while(!(p == NULL && top == -1))
    }
}

// 将字符串a复制为字符串b,然后输出字符串b
int main()
{
    char a[] = "I am a student", b[20];
    int i;
    for(i = 0; *(a + i) != '\0'; i++)
        *(b+i) = *(a+i);
    *(b+i)='\0';
}

// 将若干字符串按字母顺序由小到大的输出, 用选择排序
// 选择排序，每次选择一个最小的，然后跟当前的交换
void sort(char *name[], int n)
{
    char *temp;
    int i, j, k;
    for(i = 0;i < n-1;i++)
    {
        k = i;
        for(j = i+1; j < n; j++)
            if(strcmp(name[k], name[j] > 0)) k = j;
        if (k != i)
        {
            temp = name[i];
            name[i] = name[k];
            name[k] = temp;
        }
    }
}

// 从键盘输入一些字符，逐个把他们送到磁盘上去，直到用户输入一个"#"为止
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    char ch, filename[10];
    printf("请输入所用的文件名");
    scanf("%s",filename);
    if(fp = fopen(filename, "w") == NULL)
    {
        printf("无法打开此文件");
        exit(0);
    }
    ch = getchar();
    printf("请输入一个准备存储到磁盘的字符串，#号结束")；
    ch = getchar();
    while(ch != '#')
    {
        fputc(ch, fp);
        putchar(ch);
        ch = getchar();
    }
    fclose(fp);
    putchar(10);
    return 0;
}

// 将一个磁盘文件中的信息复制到另一个磁盘文件中，要求将上例建立的file1.dat文件中的内容复制到另一个磁盘文件file2.dat中
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *in, *out;
    char ch, infile[10], outfile[10];
    printf("输入读入文件的名字");
    scanf("%s", infile);
    printf("输入输出文件的名字");
    scanf("%s", outfile);
    if (in = fopen(infile, "r") == NULL)
    {
        printf("无法打开此文件");
        exit(0);
    }
    if (in = fopen(outfile, "w") == NULL)
    {
        printf("无法打开此文件");
        exit(0);
    }
    while(!feof(in))        //如果未遇到输入文件的结束标志
    {
        ch = fgetc(in);     //从输入文件读入一个字符，暂放在变量ch中
        fputc(ch, out);     //将ch写到out文件中
        putchar(ch);        //将ch打印到屏幕上
    }
    putchar(10);            //显示完全部字符后换行
    fclose(in);             //关闭输入文件
    fclose(out);            //关闭输出文件
    return 0;
}

// 从键盘读入若干个字符串，对他们按照字母大小的顺序排序，然后把排好序的字符串送到磁盘文件中保存
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *fp;
    char str[3][10],temp[10];   //str是用来存放字符串的二维数组，temp是临时数组
    int i, j, k, n = 3;
    printf("enter string");
    for(i = 0; i < n; i++)
        gets(str[i])            //输入字符串
    for(i = 0; i < n - 1; i++)  //用选择排序对字符串排序
    {
        k = i;
        for(j = i + 1; j < n; j++)
        {
            if(strcmp(str[k], str[i]) > 0) k = j;
        }
        if(k != i)
        {
            strcpy(temp, str[i]);
            strcpy(str[i], str[k]);
            strcpy(str[k], temp);
        }
    }
    if (fp = fopen('D:\\CC\\string.dat', "w") == NULL)
    {
        printf("cannot open");
        exit(0)
    }
    print("\nThe new sequents:");
    for(i = 0; i < n; i++)
    {
        fputs(str[i], fp);
        fputs("\n",fp);
        printf("%s\n",str[i]);
    }
    return 0;
}




