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
// 前序遍历  堆栈采用链式存储
// 已知二叉树采用二叉链表存储结构，根结点的地址为T，请写出一非递归算法，统计出该二叉树中度为1的节点数目，要求用到堆栈采用链式存储结构
// 利用二叉树的遍历操作，前序遍历，在遍历的过程中每访问一个节点就判断该节点是否只存在一颗子树，同时记录（前序遍历）
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
                // p为遍历当前二叉树的节点，q为链式堆栈的当前节点
                // 度为1的时候记录数据
                if(p->lchild !=NULL && p->rchild == NULL || p->lchild == NULL && p->rchild != NULL)
                    n++;
                // 让其左孩子进栈
                q = (BLinkList)malloc(sizeof(BLNode));
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

// 后序遍历 二叉链表存储结构
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
// 用选择排序对字符串排序
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

// 约瑟夫圆桌问题，已知n个人围坐在圆桌周围，从编号为k的人开始报数，数到m的那个人出列，他的下一个人又开始报数，直到全部的人出列
// 建立一个具有n个链节点且无头节点的循环链表
// 确定第1个报数点的位置
// 不断地从链表中删除一个链结点，直到链表中只剩下一个链接点
void JOSEPHUS(int n, int m, int k)
{
    LinkList p, r, list = NULL;
    int i;
    // 建立一个单项循环链表
    for(i = 1; i <= n; i++)
    {
        //申请一个链接点
        p = (LinkList)malloc(sizeof(LNode));
        // 存放第i个结点的编号
        p -> data = i;
        if(list == NULL)
            list = p;
        else
            r-link = p;
        r = p
    }
    p -> link = list;   //至此建立了一个循环链表
    p = list;
    for(i = 1; i < k; i++)
    {
        r = p;
        p = p -> link;
    }       // 此时p指向的是第一个出发节点
    while(p -> link != p)
    {
        for(i = 1; i < m; i++){
            r = p;
            p = p -> link;
        }       // p指向第m个节点，r指向第m-1个节点
        r -> link = p -> link;    //删除m个节点
        printf("%4d", p -> data);  //输出一个节点编号
        free(p)         // 释放被删除节点的空间
        p = r -> link;      // p指向显得出发节点
    }
    printf("\n最后被删除的节点是%4d\n", p -> data)
}

// 打印文本文件的最后n行，命令行的格式为 tail [-n] filename
// 1、检查命令行参数的正确性分析
// 2、建立一个具有n个链接点的且不带头接待你的单向循环链表
// 3、当文件读入结束后，循环链表中保留的正好是需要打印的n行
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <alloc.h>

#define DEFLINES 10   /* n的缺省值是10 */
#define MAXLEN 81    /* 这里，假设一行长度为80个字符 */

struct Tail {
    char data[MAXLEN];
    struct Tail *link;
};    // 定义循环链表中的一个链接点构造

main(int argc,char *argv[])
{
    char curline[MAXLEN], *fil ename;
    int n = DEFLINES, i;
    struct Tail *list, *ptr, *qtr;
    FILE *fp;
    // 进行命令行的参数正确性检查
    if(argc == 3 && argv[1][0] == '-'){
        // 将字符类型的n转换为整数类型的n
        n = atoi(argv[1] + 1);
        filename = argv[2];
    }
    else if(argc == 2)
        filename =argv[1];
    else{
        printf(stderr, "Usage:tail [-n] filename\n");
        exit(1);
    }
    // 以只读的方式打开文本文件
    if((fp = fopen(filename, "r")) == NULL){
      fprint(stderr, "cannot open file");
      exit(-1);
    }
    list = qtr = (struct Tail *)malloc(sizeof(struct Tail));
    qtr -> data = '\0';
    for(i = 1; i < n; i++){
        ptr = (struct Tail *)malloc(sizeof(struct Tail));
        ptr -> data[0] = '/0';
        qtr -> link = ptr;
        qtr = ptr;
    }
    // 建立一个不带头节点的单向循环链表
    ptr -> link = list;
    ptr = list;
    // 从文本文件中读一行放入curline中
    while(fgets(curline, MAXLEN, fp) != NULL){
        // 将读到的一行送入链接点的数据域
        strcpy(ptr -> data, curline);
        // ptr指向下一个链接点
        ptr = ptr -> link;
    }
    for(i = 0; i < n; i++){
        if(ptr -> data[0] == '\0')
            // 打印文本文件的第一行
            printf("%s", ptr -> data);
        ptr = ptr -> link;
    }   //打印文本文件的最后n行
    fclose(fp);
    return 0;
}

// 对于给定的任意无符号十进制整数num，如何依次输出与其等值的八进制数
// 将num除以8，取余数
// 判断商是否为0，若是0，转换结束，若不是0，将商送到num转第一步
void CONVERSION(int num)
{
    int STACK[M], top = -1;
    do{
        // 本次求得的余数进栈
        STACK[++top] = num % 8;
        num = num / 8;
    }while(num != 0);
    while(top >= 0)
        printf("%d", STACK[top--])
}
// 若堆栈采用链式存储结构
void CONVERSION(int num)
{
    STLink p, top = NULL;
    do{
        p = (STLink)malloc(STNode);
        p -> data = num % 8;
        p -> link = top;
        top = p;
        num = num/8;
    }while(num != 0)
    while(top != NULL){
        p = top;
        printf("%d", p -> data);
        top = top -> link;
        free(p)
    }
}

// 设中缀表达式E存放于字符数组中，并以@作为结束标志符，请写出判断一个中缀表达式E中左右圆括号是否匹配的算法
// 需要从左到右依次进行扫描，扫描 遇到左边括号进栈，遇到右边括号退栈，最后，若栈空，则匹配
#define MAXLEN 100;
int isMatch(char E[])
{
    char stack[MAXLEN];
    int top = -1, i = 0;
    while(E[i] != '@')
    {
        if(E[i] == '(')
            stack[++top] = '(';
        else(E[i] == ')')
        {
            if(top == -1)
            {
                return 0；
            }
            top--
        }
        i++
    }
    return top == -1
}


// 循环队列的插入
void fun() {
    // 判断循环队列满
    if((rear + 1) % m == front)
        return 0;
    else {
        QUEEU[++rear % m] = item;
        return 1
    }
}

// 循环队列的删除
int Delete()
{
    //判断是否为空栈
    if(rear == front)
    {
        return 0;
    }
    else {
        front = (front + 1) % m;
        item = QUEEU[front]
        return;
    }
}

// 二叉树的前序遍历
#define MAX;
int pre(datatype BT[], int M)
{
    int STACK[MaxN], i, top = -1;
    do{
        while(i < M && BT[i] != 0)
        {
            VISIT(BT[i]);
            STACK[++top] = i;
            i = i * 2 + 1
        }
        i = STACK[top--];
        i = i * 2 + 2
    }while(i != M && BT[i] == 0 && top < 0)
}

// 已知某具n个节点的二叉树的前序序列和中序序列分别为PREOD[0, n-1],INOD[0, n-1],并且各节点的数据都不相同，
// 请写一非递归算法，生成二叉树的二叉链表结构
// 根据前序序列的每一个节点在中序序列中的位置，利用逐点插入法将前序序列中的节点插入一颗二叉排序树中

// 确定节点在后续序列中的位置
int SEC(datatype INOD[], int n, datatype item)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(item = INOD[i])
            return i + 1
    }
}
void INS(BTREE &T, datatype item)
{
    BTREE p, q;
    int ord;
    p = (BTNode)malloc(sizeof(BTREE));
    p -> data = item;

    p -> lchild = p -> rchild = NULL;
    if(T == NULL)
        T = p;
    else
    {
        // que定item在中序序列中的位置
        ord = SEC(INOD, n, item);
        q = T;
        while(1)
            if(q -> lchild !=NULL)
                q = q -> lchild
    }
}




