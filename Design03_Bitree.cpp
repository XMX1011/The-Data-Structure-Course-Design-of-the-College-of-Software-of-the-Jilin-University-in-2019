#include "stdc++.h"
using namespace std;
template <class T>
struct BiNode
{
    T data;
    BiNode<T> *lchild, *rchild;
};
template <class T>
class BiTree
{
public:
    BiTree();
    ~BiTree();
    BiNode<T> *GetRoot();
    void PreOrder(BiNode<T> *node);
    void InOrder(BiNode<T> *node);
    void PostOrder(BiNode<T> *node);
    int NodesNum(BiNode<T> *node);
    int TreeDepth(BiNode<T> *node);
    int LeafNum(BiNode<T> *node);
    void TrackandDepth(BiNode<T> *node);

private:
    BiNode<T> *m_root;
    BiNode<T> *Create();
};
template <class T>
BiTree<T>::BiTree()
{
    m_root = new BiNode<T>;
    m_root = Create();
}
template <class T>
BiTree<T>::~BiTree() {}
template <class T>
BiNode<T> *BiTree<T>::Create()
{
    char ch;
    cin >> ch;
    BiNode<T> *pnode = NULL;
    if (ch == '#')
    {
        pnode = NULL;
    }
    else
    {
        pnode = new BiNode<T>;
        pnode->lchild = Create();
        pnode->data = ch;
        pnode->rchild = Create();
    }
    return pnode;
}
template <class T>
BiNode<T> *BiTree<T>::GetRoot()
{
    return m_root;
}
template <class T>
void BiTree<T>::PreOrder(BiNode<T> *node)
{
    if (!node)
        return;
    else
    {
        cout << node->data;
        PreOrder(node->lchild);
        PreOrder(node->rchild);
    }
}
template <class T>
void BiTree<T>::InOrder(BiNode<T> *node)
{
    if (!node)
        return;
    else
    {
        InOrder(node->lchild);
        cout << node->data;
        InOrder(node->rchild);
    }
}
template <class T>
void BiTree<T>::PostOrder(BiNode<T> *node)
{
    if (!node)
        return;
    else
        PostOrder(node->lchild);
    PostOrder(node->rchild);
    cout << node->data;
}
template <class T>
int BiTree<T>::LeafNum(BiNode<T> *node)
{
    if (!node)
        return 0;
    if (!node->lchild && !node->rchild)
        return 1;
    return LeafNum(node->lchild) + LeafNum(node->rchild);
}
template <class T>
int BiTree<T>::TreeDepth(BiNode<T> *node)
{
    int LChildDep = 1, RChildDep = 1;
    if (!node)
        return 0;
    LChildDep += TreeDepth(node->lchild);
    RChildDep += TreeDepth(node->rchild);
    return (LChildDep > RChildDep) ? (LChildDep) : (RChildDep);
}
template <class T>
int BiTree<T>::NodesNum(BiNode<T> *node)
{
    if (!node)
        return 0;
    return NodesNum(node->lchild) + NodesNum(node->rchild) + 1;
}
char path[20];
int dep = 0;
template <class T>
void BiTree<T>::TrackandDepth(BiNode<T> *node)
{
    if (node)
    {
        if (node->lchild == NULL && node->rchild == NULL)
        {
            path[dep++] = node->data;
            for (int i = 0; i < dep - 1; i++)
            {
                cout << path[i] << "->";
            }
            cout << path[dep - 1];
            cout << '\t' << dep << endl;
            dep--;
            return;
        }
        else
        {
            path[dep++] = node->data;
            for (int i = 0; i < dep - 1; i++)
            {
                cout << path[i] << "->";
            }
            cout << path[dep - 1];
            cout << '\t' << dep << endl;
            TrackandDepth(node->lchild);
            TrackandDepth(node->rchild);
            dep--;
        }
    }
}
int main()
{
    BiTree<char> bitree;
    cout << "PreOrder\t";
    bitree.PreOrder(bitree.GetRoot());
    cout << endl;
    cout << "InOrder\t";
    bitree.InOrder(bitree.GetRoot());
    cout << endl;
    cout << "PostOrder\t";
    bitree.PostOrder(bitree.GetRoot());
    cout << endl;
    //bitree.TrackandDepth(bitree.GetRoot());
    system("pause");
}