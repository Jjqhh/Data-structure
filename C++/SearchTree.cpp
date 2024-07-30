//************************  BinaryTree  **************************
/* #include<iostream>
using namespace std;

//树结构
struct BiNode
{
    char data;
    BiNode *lchild;
    BiNode *rchild;
};
using BiTree = BiNode *;

//创建树节点
void Creat(BiTree &T)
{
    char temp;
    cin >> temp;
    if(temp == '#')
    {
        T = nullptr;
    }
    else
    {
        T = new BiNode;
        T->data = temp;
        Creat(T->lchild);
        Creat(T->rchild);
    }
}

//先序遍历树节点
void preTraversal(BiTree root)
{
    if(root == nullptr)
    {
        return;
    }
    cout << root->data << ' ';
    preTraversal(root->lchild);
    preTraversal(root->rchild);
}

//中序遍历树节点
void inTraversal(BiTree root)
{
    if(root == nullptr)
    {
        return;
    }
    inTraversal(root->lchild);
    cout << root->data << ' ';
    inTraversal(root->rchild);
}


//后序遍历树节点
void postTraversal(BiTree root)
{
    if(root == nullptr)
    {
        return;
    }
    postTraversal(root->lchild);
    postTraversal(root->rchild);
    cout << root->data << ' ';
}

//树的深度
int getDepth(BiTree root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return max(getDepth(root->lchild), getDepth(root->rchild)) + 1;
}

//树的节点个数
int getNodeCount(BiTree root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int l = getNodeCount(root->lchild);
    int r = getNodeCount(root->rchild);
    int count = l + r + 1;
    return count;
}

//叶子的个数
int getLeafNodeCount(BiTree root)
{
    if (root == nullptr)
    {
        return 0;
    }
    if (root->lchild == nullptr && root->rchild == nullptr)
    {
        return 1;
    }
    return getLeafNodeCount(root->lchild) + getLeafNodeCount(root->rchild);
}

int main()
{
    BiTree t;
    cout << "Please enter the data to the binarytree, # stands for nullptr" << endl;
    Creat(t);
    cout << "Creat successed!" << endl;
    cout << "===========Preorder traversal=========== " << endl;
    preTraversal(t);
    cout << endl;
    cout << "===========Inorder traversal=========== " << endl;
    inTraversal(t);
    cout << endl;
    cout << "===========Postorder traversal=========== " << endl;
    postTraversal(t);
    cout << endl;
    cout << "The number of nodes in the binary tree is " << getNodeCount(t) << "." << endl;
    cout << "The depth of the binary tree is " << getDepth(t) << "." << endl;
    cout << "The number of leaf nodes in the binary tree is " << getLeafNodeCount(t) << "." << endl;
    return 0;
}    */

//*********************  SearchTree  ************************
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode;
using Position = TreeNode *;
using SearchTree = TreeNode *;

void Creat(SearchTree &T);                // 创建节点
Position Find(char X, SearchTree &T);     // 查找节点值
Position FindMin(SearchTree &T);          // 查找最小值节点
Position FindMax(SearchTree &T);          // 查找最大值节点
SearchTree Insert(char X, SearchTree &T); // 插入节点
SearchTree Delete(char X, SearchTree &T); // 删除节点
char Retrieve(Position &P);               // 返回节点值
void preTraversal(SearchTree &T);         // 先序遍历
void inTraversal(SearchTree &T);          // 中序遍历
void postTraversal(SearchTree &T);        // 后序遍历
int getDepth(SearchTree &T);              // 获取深度
int getNodeCount(SearchTree &T);          // 获取节点数量
int getLeafNodeCount(SearchTree &T);      // 获取叶子数量
void SeqTraverse(Position &T);            // 队列（层序遍历）

struct TreeNode
{
    char data;
    SearchTree left;
    SearchTree right;
};

void SeqTraverse(Position &T)
{
    queue<TreeNode *> q;
    q.push(T);
    while (!q.empty())
    {
        Position temp = q.front();
        q.pop();
        cout << T->data << ' ';
        
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
    
}

// 创建节点
void Creat(SearchTree &T)
{
    char temp;
    cin >> temp;
    if (temp == '#')
    {
        T = nullptr;
    }
    else
    {
        T = new TreeNode;
        T->data = temp;
        Creat(T->left);
        Creat(T->right);
    }
}
// 删除树
SearchTree MakeEmpty(SearchTree &T)
{
    if (T != nullptr)
    {
        MakeEmpty(T->left);
        MakeEmpty(T->right);
        delete T;
    }
    return nullptr;
}

// 查找节点值
Position Find(char X, SearchTree &T)
{
    if (T == nullptr)
    {
        return nullptr;
    }
    if (X < T->data)
    {
        Find(X, T->left);
    }
    else if (X > T->data)
    {
        Find(X, T->right);
    }
    return T;
}

// 查找最小值
Position FindMin(SearchTree &T)
{
    if (T == nullptr)
    {
        return nullptr;
    }
    else if (T->left == nullptr)
    {
        return T;
    }
    else
        return FindMin(T->left);
}

// 查找最大值
Position FindMax(SearchTree &T)
{
    if (T == nullptr)
    {
        return nullptr;
    }
    else if (T->right == nullptr)
    {
        return T;
    }
    else
    {
        return FindMax(T->right);
    }
}

// 插入节点
SearchTree Insert(char X, SearchTree &T)
{
    if (T == nullptr)
    {
        T = new TreeNode;
        if (T == nullptr)
        {
            cout << "New Fair!" << endl;
        }
        else
        {
            T->data = X;
            T->left = T->right = nullptr;
        }
    }
    else if (X < T->data)
    {
        T->left = Insert(X, T->left);
    }
    else if (X > T->data)
    {
        T->right = Insert(X, T->right);
    }
    return T;
}

// 删除节点值
SearchTree Delete(char X, SearchTree &T)
{
    Position TmpCell;
    if (T == nullptr)
    {
        cout << "Data not found!" << endl;
    }
    else if (X < T->data)
    {
        T->left = Delete(X, T->left);
    }
    else if (X > T->data)
    {
        T->right = Delete(X, T->right);
    }
    // 检查 T 节点的两个子节点是否都存在（即都不是 nullptr 或其他表示空节点的值）。A
    else if (T->left && T->right)
    {
        TmpCell = FindMin(T->right);
        T->data = TmpCell->data;
        T->right = Delete(T->data, T->right);
    }
    else
    {
        TmpCell = T;
        if (T->left == nullptr)
        {
            T = T->right;
        }
        else if (T->right == nullptr)
        {
            T = T->left;
        }
        delete TmpCell;
    }
    return T;
}

// 获取节点值
char Retrieve(Position &P)
{
    if (P == nullptr)
    {
        return '#';
    }
    return P->data;
}

// 先序遍历
void preTraversal(SearchTree &T)
{
    if (T == nullptr)
    {
        return;
    }
    else
    {
        cout << T->data << ' ';
        preTraversal(T->left);
        preTraversal(T->right);
    }
}

// 中序遍历
void inTraversal(SearchTree &T)
{
    if (T == nullptr)
    {
        return;
    }
    else
    {
        inTraversal(T->left);
        cout << T->data << ' ';
        inTraversal(T->right);
    }
}

// 后序遍历
void postTraversal(SearchTree &T)
{
    if (T == nullptr)
    {
        return;
    }
    else
    {
        postTraversal(T->left);
        postTraversal(T->right);
        cout << T->data << ' ';
    }
}

// 获取树深度（从根节点开始数，包括叶子结点，但不包括空节点）
// 在递归回来的时候进行计算
int getDepth(SearchTree &T)
{
    if (T == nullptr)
    {
        return 0;
    }
    else
    {
        return max(getDepth(T->left), getDepth(T->right)) + 1;
    }
}

// 获取树节点数量（不包括空节点）
int getNodeCount(SearchTree &T)
{
    if (T == nullptr)
    {
        return 0;
    }
    int l = getNodeCount(T->left);
    int r = getNodeCount(T->right);
    int count = l + r + 1;
    return count;
}

// 获取叶子节点数量（（没有孩子的节点）
int getLeafNodeCount(SearchTree &T)
{
    if (T == nullptr)
    {
        return 0;
    }
    if (T->left == nullptr && T->right == nullptr)
    {
        return 1;
    }
    return getLeafNodeCount(T->left) + getLeafNodeCount(T->right);
}

int main()
{
    SearchTree t;
    cout << "Please enter the data to the binarytree, '#' stands for nullptr" << endl;
    Creat(t);
    cout << "Creat successed!" << endl;
    cout << "===========Preorder traversal=========== " << endl;
    preTraversal(t);
    cout << endl;
    cout << "===========Inorder traversal=========== " << endl;
    inTraversal(t);
    cout << endl;
    cout << "===========Postorder traversal=========== " << endl;
    postTraversal(t);
    cout << endl;
    cout << endl;
    cout << "The number of nodes in the binary tree is " << getNodeCount(t) << "." << endl;
    cout << "The depth of the binary tree is " << getDepth(t) << "." << endl;
    cout << "The number of leaf nodes in the binary tree is " << getLeafNodeCount(t) << "." << endl;

    cout << endl
         << endl
         << "Delete A" << endl;

    // Delete
    Delete('A', t);
    cout << "===========Preorder traversal=========== " << endl;
    preTraversal(t);
    cout << endl;
    cout << "===========Inorder traversal=========== " << endl;
    inTraversal(t);
    cout << endl;
    cout << "===========Postorder traversal=========== " << endl;
    postTraversal(t);
    cout << endl
         << endl
         << "Insert J" << endl;

    // Insert
    Insert('J', t);
    cout << "===========Preorder traversal=========== " << endl;
    preTraversal(t);
    cout << endl;
    cout << "===========Inorder traversal=========== " << endl;
    inTraversal(t);
    cout << endl;
    cout << "===========Postorder traversal=========== " << endl;
    postTraversal(t);
    cout << endl;
    cout << "The number of nodes in the binary tree is " << getNodeCount(t) << "." << endl;
    cout << "The depth of the binary tree is " << getDepth(t) << "." << endl;
    cout << "The number of leaf nodes in the binary tree is " << getLeafNodeCount(t) << "." << endl;

    return 0;
}

