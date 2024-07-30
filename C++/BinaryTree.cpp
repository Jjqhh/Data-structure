// 满二叉树和完全二叉树因其特殊的性质适合用数组进行存储
// 其余二叉树因其性质则更适合用链表进行存储、

//遍历二叉树（递归）
/* #include <iostream>
using namespace std;

typedef struct BinaryNode
{
    char data;
    BinaryNode *lchild;
    BinaryNode *rchild;
} BinaryNode, *BinaryTree;

void creatNode(BinaryTree &T)
{
    char temp;
    cin >> temp;
    if (temp == '#')
    {
        T = nullptr;
        return;
    }
    else
    {
        T = new BinaryNode;
        T->data = temp;
        creatNode(T->lchild);
        creatNode(T->rchild);
    }
}

void preTraverse(BinaryTree T)
{
    if (T == nullptr)
    {
        return;
    }
    else
    {
        cout << T->data << " ";
        preTraverse(T->lchild);
        preTraverse(T->rchild);
    }
}

void inTraverse(BinaryTree T)
{
    if (T == nullptr)
        return;
    else
    {
        inTraverse(T->lchild);
        cout << T->data << " ";
        inTraverse(T->rchild);
    }
}

void postTraverse(BinaryTree T)
{
    if (T == nullptr)
        return;
    else
    {
        postTraverse(T->lchild);
        postTraverse(T->rchild);
        cout << T->data << " ";
    }
}

int main()
{
    BinaryTree T;
    cout << "Please enter the tree's data:";
    creatNode(T);
    preTraverse(T);
    cout << endl;
    inTraverse(T);
    cout << endl;
    postTraverse(T);
    cout << endl;
    return 0;
} */


//遍历二叉树（非递归）
#include <iostream>
using namespace std;

typedef struct BinaryNode
{
    char data;
    BinaryNode *lchild;
    BinaryNode *rchild;
} BinaryNode, *BinaryTree;

typedef struct Stack
{
    char data;
    Stack *next;
} *ListStack;

void push(ListStack &s, BinaryTree &p)
{
    ListStack newNode = new Stack;
    newNode->data = p->data;
    if(s == nullptr)
        s = newNode;
    else
    {
        newNode->next = s;
        s = newNode;
    }
}

char pop(ListStack &s)
{
    char data;
    ListStack current = s;
    data = current->data;
    s = s->next;
    delete current;
    return data;
}

bool emptyStack(ListStack s)
{
    if(s == nullptr)
        return true;
    else
        return false;
}

void initialStack(ListStack &s)
{
    s = nullptr;
}

void creatBinaryTree(BinaryTree &root)
{
    char temp;
    cin >> temp;
    if(temp == '#')
    {
        root = nullptr;
        return;
    }
    else
    {
        root->data = temp;
        creatBinaryTree(root->lchild);
        creatBinaryTree(root->rchild);
    }
}

void preTraverse(ListStack s,BinaryTree root)
{
    initialStack(s);
    BinaryTree p = root;
    while (p || !emptyStack(s))
    {
        if(p)
        {
            push(s, p);
            p = p->lchild;
        }
        else
        {
            pop(s);
            p = p->rchild;
        }
    }
}

int main()
{
    ListStack s;
    BinaryTree t;
    initialStack(s);
    cout << "Please enter the new tree's data:";
    creatBinaryTree(t);
    preTraverse(s, t);

    return 0;
}