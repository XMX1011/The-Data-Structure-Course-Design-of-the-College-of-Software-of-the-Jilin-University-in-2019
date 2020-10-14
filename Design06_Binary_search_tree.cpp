#include "stdc++.h"
using namespace std;
typedef struct BiTNode
{
    int val;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
void Insert(BiTree &T, int key)
{
    if (!T)
    {
        T = new BiTNode();
        T->val = key;
        T->lchild = T->rchild = NULL;
    }
    if (key == T->val)
        return;
    if (key > T->val)
        Insert(T->rchild, key);
    if (key < T->val)
        Insert(T->lchild, key);
}
void InorderTraverse(BiTree root)
{
    if (root == NULL)
        return;
    InorderTraverse(root->lchild);
    printf("%d ", root->val);
    InorderTraverse(root->rchild);
}
bool Search(BiTree root, int val)
{
    if (root == NULL)
        return false;
    if (root->val == val)
        return true;
    if (val < root->val)
        return Search(root->lchild, val);
    if (val > root->val)
        return Search(root->rchild, val);
}
int getNodelayer(BiTree T, int level, char key)
{
    int l;
    if (T)
    {
        if (T->val == key)
        {
            return level; //找到与key值相同的结点，返回层数level
        }
        l = getNodelayer(T->lchild, level + 1, key); //在左子树中查找key结点，并得到其层数
        if (l != -1)
        {
            return l;
        }
        else
        { //在右子树中查找key结点，并得到其层数
            return getNodelayer(T->rchild, level + 1, key);
        }
    }
    return -1; //若T为NULL，返回-1
}
int main()
{
    printf("number of elements:");
    int n;
    cin >> n;
    printf("input:");
    BiTNode *root = NULL;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        Insert(root, t);
    }
    printf("\nIn_order:");
    InorderTraverse(root);
    printf("\ninput the number of search elements:");
    int num;
    cin >> num;
    while (num--)
    {
        printf("search: ");
        int op;
        cin >> op;
        if (Search(root, op))
        {
            printf("found\n");
            printf("the level is %d\n", getNodelayer(root, 1, op));
            InorderTraverse(root);
        }
        else
        {
            printf("not found\n");
            Insert(root, op);
            InorderTraverse(root);
        }
    }
    cout << endl;
    system("pause");
    return 0;
}