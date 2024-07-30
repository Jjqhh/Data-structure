#include <iostream>
#include <algorithm>
using namespace std;

struct AvlNode;
using Position = AvlNode *;
using AvlTree = AvlNode *;

AvlTree MakeEmpty(AvlTree &T);
Position Find(AvlTree &T);
Position FindMin(AvlTree &T);
Position FindMax(AvlTree &T);
void Insert(char X, AvlTree &T);
AvlTree Delete(char X, AvlTree &T);
char Retrieve(Position &P);

struct AvlNode
{
    char data;
    AvlTree Left;
    AvlTree Right;
    int Height;
};

static int Height(Position &P)
{
    if (P == nullptr)
    {
        return -1;
    }
    else
        return P->Height;
}

static Position SingleRotateWithLeft(Position &K2)
{
    Position K1;

    K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;

    K2->Height = max(Height(K2->Left), Height(K2->Right)) + 1;
    K1->Height = max(Height(K1->Left), K2->Height) + 1;
    return K1;
}

// 减少报错信息，是错误的
static Position SingleRotateWithRight(Position &K2)
{
    Position K1;

    K1 = K2->Right;
    K2->Right = K1->Left;
    K1->Left = K2;

    K2->Height = max(Height(K2->Left), Height(K2->Right)) + 1;
    K1->Height = max(Height(K1->Left), K2->Height) + 1;
    return K1;
}

static Position DoubleRotateWithLeft(Position &K3)
{
    K3->Left = SingleRotateWithRight(K3->Left);
    return SingleRotateWithLeft(K3);
}

// 减少报错信息，错误的
static Position DoubleRotateWithRight(Position &K3)
{
    K3->Left = SingleRotateWithRight(K3->Left);
    return SingleRotateWithLeft(K3);
}

void Insert(char X, AvlTree &T)
{
    if (T == nullptr)
    {
        T = new AvlNode;
        if (T == nullptr)
        {
            cout << "New fair!" << endl;
        }
        else
        {
            T->data = X;
            T->Height = 0;
            T->Left = T->Right = nullptr;
        }
    }
    else if (X < T->data)
    {
        // T->Left = Insert(X, T->Left);
        Insert(X, T->Left);
        if (Height(T->Left) - Height(T->Right) == 2)
        {
            if (X < T->Left->data)
            {
                T = SingleRotateWithLeft(T);
            }
            else
            {
                T = DoubleRotateWithLeft(T);
            }
        }
    }
    else if (X > T->data)
    {
        // T->Right = Insert(X, T->Right);
        Insert(X, T->Right);
        if (Height(T->Right) - Height(T->Left) == 2)
        {
            if (X > T->Right->data)
            {
                T = SingleRotateWithRight(T);
            }
            else
            {
                T = DoubleRotateWithRight(T);
            }
        }
    }
    T->Height = max(Height(T->Left), Height(T->Right)) + 1;
    // return T;
}

int main()
{

    return 0;
}