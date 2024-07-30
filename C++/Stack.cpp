//************************************************************************* 栈的实现（顺序表）

/* #include <iostream>
#define MAXSIZE 10
using namespace std;

typedef struct Stack
{
    int *top;
    int *base;
    int stackSize; // 用来标记栈的最大元素数量
} Stack;

// 初始化栈（建立一个空栈）
void initialStack(Stack &s)
{
    s.base = new int[MAXSIZE];
    s.top = s.base;
    s.stackSize = MAXSIZE;
}

// 判断栈是否为空栈
bool emptyStack(Stack &s)
{
    if (s.top - s.base)
        return false;
    else
        return true;
}

// 判断栈是否为满栈
bool fullStack(Stack &s)
{
    if (s.top - s.base == s.stackSize)
        return true;
    else
        return false;
}

// 得到栈的长度
int stackLength(Stack &s)
{
    return s.top - s.base;
}

// 入栈
void push(Stack &s)
{
    if (s.top - s.base == s.stackSize)
        cout << "Push failed!!!" << endl;
    cout << "Please enter the data: ";
    int data = 0;
    cin >> data;
    *s.top++ = data;
}

// 出栈并弹出栈顶元素
int pop(Stack &s)
{
    if (s.top == s.base)
        cout << "Pop failed!!!";
    int data = 0;
    data = *--s.top;
    return data;
}

// 清空栈
void clearStack(Stack &s)
{
    s.top = s.base;
}

// 销毁栈
void destroyStack(Stack &s)
{
    delete s.base;
    s.stackSize = 0;
    s.base = s.top = nullptr;
}

int main()
{
    Stack s;
    initialStack(s);
    if (emptyStack(s))
        cout << "s是空栈!!!" << endl;
    else
        cout << "s不是空栈!!!" << endl;
    for (int i = 0; i != 5; ++i)
    {
        push(s);
    }
    while (s.top != s.base)
        cout << pop(s) << " ";
    cout << endl;

    if (emptyStack(s))
        cout << "s是空栈!!!" << endl;
    else
        cout << "s不是空栈!!!" << endl;

    cout << stackLength(s) << endl;

    return 0;
} */

//****************************************************************************栈的实现（链表）
#include <iostream>
using namespace std;

typedef struct stackNode
{
    int data;            //数据域
    stackNode *next;     //指针域
} *LinkStack;

// 初始化链栈
void initialStack(LinkStack &s)
{
    s = nullptr;         //初始化链栈指针s为空
}

// 判断链栈是否为空
bool emptyStack(LinkStack &s)
{
    if (s == nullptr)
    {
        cout << "该链栈为空！！！" << endl;
        return true;
    }
    else
    {
        cout << "该链栈不为空！！！" << endl;
        return false;
    }
}

// 入栈
void push(LinkStack &s)
{
    LinkStack newNode = new stackNode;
    cout << "请输入待入栈数据:";
    int data = 0;
    cin >> data;
    newNode->data = data;
    if (s == nullptr)
        s = newNode;
    else
    {
        newNode->next = s;
        s = newNode;
    }
}

// 出栈
void pop(LinkStack &s)
{
    LinkStack temp = s->next;   //用临时指针将栈的下一个地址进行记录
    delete s;                   //由于上一步操作，在删除栈顶指针s前，下一空间地址也已保存，不会造成地址丢失
    s = temp;     //更新指针
}

// 获取栈顶元素
int getTopData(LinkStack &s)
{
    return s->data;      //获取栈顶指针所指向数据
}

// 销毁链栈
void destroyStack(LinkStack &s)
{
    LinkStack temp = s->next;   
    while (s)
    {
        delete s;
        s = temp;
        temp = temp->next;
    }
}

int main()
{
    LinkStack s;
    initialStack(s);
    emptyStack(s);

    for (int i = 0; i != 5; ++i)
    {
        push(s);
    }
    emptyStack(s);
    for (int i = 0; i != 5; ++i)
    {
        cout << getTopData(s) << " ";
        pop(s);
    }

    cout << endl;
    emptyStack(s);

    return 0;
}
