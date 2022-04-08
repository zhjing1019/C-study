/*
 * 一个关于三叉树的题目，小于100的值代表树叶，大于100的值为分支点，建树的过程是水平方向建树，
 * 输入格式：
 * 先输入n，代表有n组数据，接下来n行，
 * 输入4个数，第一个数代表根节点，接下来分别代表三个子节点，-1代表子节点不存在，
 * 输入的顺序按照层次遍历的次序。接下来，要求寻找叶子节点的最短路径，最短路径是指不经过重复的边。
 * 输入方式，首先输入一个值m，代表m行，接下来m行输入m个叶子节点和对应的优先级，
 * 要求按优先级输出从上次到达的位置到该节点的最短路径，每条路径的最后一个节点要求输出目标叶子节点，最后要求回到根节点。
 *
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int id;
    struct Node* left;
    struct Node* mid;
    struct Node* right;
    struct Node* father;
};

struct Leaf{
    int id;
    int pri;
};

typedef struct Node* node;
typedef struct Leaf leaf;

leaf arr[105];
int arr_len = 0;

int path1[500],path2[500];
int path1_len = 0,path2_len = 0;

node find_node (node root,int id)
{
    if (root == NULL || root->id == id) {
        return root;
    }
    node temp;
    temp = find_node(root->left,id);
    if (temp == NULL) {
        temp = find_node(root->mid,id);
        if (temp == NULL) {
            temp = find_node(root->right,id);
        }
    }
    return temp;
}

void sort()
{
    int i,j;
    leaf temp;

    for(i = 0;i < arr_len - 1;i++) {
        for(j = 0;j < arr_len - 1 - i;j++) {
            if (arr[j].pri > arr[j + 1].pri) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

}

node find_common(node root,node res,node dst)
{
    if (root == NULL || root == res || root == dst) {
        return root;
    }
    node left,mid,right;
    left = find_common(root->left,res,dst);
    mid = find_common(root->mid,res,dst);
    right = find_common(root->right,res,dst);

    if (((left != NULL) && (mid != NULL)) || ((left != NULL) && (right != NULL)) || ((mid != NULL) && (right != NULL))) {
        return root;
    }
    else if (left != NULL) {
        return left;
    }
    else if (mid != NULL) {
        return mid;
    }
    else if (right != NULL) {
        return right;
    }
}

int find_path(node root,node res,node dst)
{
    path1_len = 0;
    path2_len = 0;
    node common,temp;
    common = find_common(root,res,dst);
    //printf("common %d\n",common->id);
    temp = res;
    while (temp != common) {
        path1[path1_len] = temp->id;
        temp = temp->father;
        path1_len++;
    }
    path1[path1_len] = temp->id;
    path1_len++;

    temp = dst;
    while (temp != common) {
        path2[path2_len] = temp->id;
        temp = temp->father;
        path2_len++;
    }
    path2[path2_len] = temp->id;
    path2_len++;
    //printf("len2 %d\n",path2_len);

    int i;
    for (i = 0;i < path1_len;i++) {
        printf("%d ",path1[i]);
    }
    for (i = path2_len - 2;i > 0;i--) {
        printf("%d ",path2[i]);
    }
    if (path2_len > 1) {
        printf("%d\n",path2[0]);
    }
    return path2[1];

}

void prin(node root)
{
    if (root != NULL) {
        printf("%d ",root->id);
        prin(root->left);
        prin(root->mid);
        prin(root->right);
    }
}

int main()
{
    int i,j,n,id,id0[4];
    node root,temp,temp1;
    root = NULL;

    scanf("%d",&n);
    for(i = 0;i < n;i++) {
        scanf("%d",&id);
        if (root == NULL) {
            root = (struct Node *)malloc(sizeof(struct Node));
            root->id = id;
            root->father = NULL;
            root->left = NULL;
            root->right = NULL;
            root->mid = NULL;
            temp = root;
        }
        else {
            temp = find_node(root,id);
        }
        for(j = 1;j < 4;j++) {
            scanf("%d",&id);
            if (id == -1) {
                temp1 = NULL;
            }
            else {
                temp1 = (struct Node*)malloc(sizeof(struct Node));
                temp1->id = id;
                temp1->father = temp;
                temp1->left = NULL;
                temp1->mid = NULL;
                temp1->right = NULL;
            }

            if (j == 1) {
                temp->left = malloc((sizeof(struct Node)));
                temp->left = temp1;
            }
            else if (j == 2) {
                temp->mid = malloc((sizeof(struct Node)));
                temp->mid = temp1;
            }
            else if(j == 3) {
                temp->right = malloc((sizeof(struct Node)));
                temp->right = temp1;
            }
        }
        //prin(root);
    }
    int m,pri;
    scanf("%d",&m);
    for(i = 0;i < m;i++) {
        scanf("%d %d",&id,&pri);
        arr[i].id = id;
        arr[i].pri = pri;
        arr_len++;
    }
    sort();

    node res,dst;
    res = root;

    for (i = 0;i < arr_len;i++) {
        dst = find_node(root,arr[i].id);
        int aa;
        aa = find_path(root,res,dst);
        res = find_node(root,aa);
    }
    find_path(root,res,root);


    return 0;
}