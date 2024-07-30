//************************************************************************队列的实现（顺序表）
/* #include<iostream>
#define MAXSIZE 50
using namespace std;

typedef struct Queue
{
    int *base;  //动态数组
    int front;
    int rear;
} sqQueue;

//判断队列是否为空
bool emptyQueue(sqQueue &q)
{
    if(q.front == q.rear)
        return true;
    else
        return false;
}

//初始化队列
void initialQueue(sqQueue &q)
{
    q.base = new int[MAXSIZE];
    q.front = q.rear = 0;
}

//入队
void push(sqQueue &q)
{
    cout << "Please enter the new data: ";
    int data = 0;
    cin >> data;
    q.base[q.rear] = data;
    q.rear++;
}

//出队并返回元素数据
int pop(sqQueue &q)
{
    int data = 0;
    data = q.base[q.front];
    q.front++;
    return data;
}

int main()
{
    sqQueue q;
    initialQueue(q);
    if(emptyQueue(q))
        cout << "队列为空！！！" << endl;
    else
        cout << "队列不为空！！！" << endl;

    for (int i = 0; i != 5; ++i)
    {
        push(q);
    }

    if (emptyQueue(q))
        cout << "队列为空！！！" << endl;
    else
        cout << "队列不为空！！！" << endl;

    for (int i = 0; i != 5; ++i)
    {
        cout << pop(q) << " ";
    }
    cout << endl;

    if (emptyQueue(q))
        cout << "队列为空！！！" << endl;
    else
        cout << "队列不为空！！！" << endl;

    return 0;
}  */

//***********************************************************************循环队列实现（顺序表）

#include <iostream>
#define MAXSIZE 5
using namespace std;

typedef struct Queue
{
    int *base;
    int rear;
    int front;
} SqQueue;

// 判断队列是否满队
bool fullQueue(SqQueue &q)
{
    if ((q.rear + 1) % MAXSIZE == q.front)
    {
        cout << "队列已满！！！" << endl;
        return true;
    }
    else
    {
        cout << "队列未满 ！！！" << endl;
        return false;
    }
}
// 判断队列是否为空
bool emptyQueue(SqQueue &q)
{
    if (q.front == q.rear)
    {
        cout << "队列为空！！！" << endl;
        return true;
    }
    else
    {
        cout << "队列不为空！！！" << endl;
        return false;
    }
}

// 初始化队列
void initialQueue(SqQueue &q)
{
    q.base = new int[MAXSIZE];
    q.front = q.rear = 0;
}

// 入栈
void push(SqQueue &q)
{
    cout << "Please enter the new data: ";
    int data = 0;
    cin >> data;
    q.base[q.rear] = data;
    q.rear = (q.rear + 1) % MAXSIZE;
}

// 出栈并获取栈顶元素
int pop(SqQueue &q)
{
    int data = 0;
    data = q.base[q.front];
    q.front = (q.front + 1) % MAXSIZE;
    return data;
}

// 销毁栈
void destroyQueue(SqQueue &q)
{
    q.front = q.rear = 0;
}

// 获取队列长度
int queueLength(SqQueue &q)
{
    return (q.rear - q.front + MAXSIZE) % MAXSIZE;
}
int main()
{
    SqQueue q;
    initialQueue(q);
    emptyQueue(q);
    cout << queueLength(q) << endl;
    for (int i = 0; i != MAXSIZE - 1; ++i)
    {
        push(q);
    }
    emptyQueue(q);
    fullQueue(q);
    cout << queueLength(q) << endl;
    for (int i = 0; i != 3; ++i)
    {
        cout << pop(q) << " ";
    }
    cout << endl;
    cout << queueLength(q) << endl;
    emptyQueue(q);
    for (int i = 0; i != 2; ++i)
    {
        push(q);
    }
    cout << endl;
    cout << queueLength(q) << endl;
    for (int i = 0; i != 3; ++i)
    {
        cout << pop(q) << " ";
    }
    emptyQueue(q);
    fullQueue(q);
    cout << queueLength(q) << endl;
    return 0;
}


//**************************************************************************队列的实现（链表）
/* #include <iostream>
using namespace std;

typedef struct QueueNode
{
    int data;
    QueueNode *next;
} QueueNode, *QueuePtr;

typedef struct LinkQueue
{
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

// 初始化队列
void initialQueue(LinkQueue &q)
{
    q.front = q.rear = new QueueNode;
    q.rear->next = nullptr;
}

//  判断队列是否为空
bool emptyQueue(LinkQueue &q)
{
    if (q.front == q.rear)
    {
        cout << "队列为空！！！" << endl;
        return true;
    }
    else
    {
        cout << "队列不为空！！！" << endl;
        return false;
    }
}

// 销毁队列
void deleteQueue(LinkQueue &q)
{
    while (q.front)
    {
        QueuePtr temp = q.front->next;
        delete q.front;
        q.front = temp;
    }
}

//  判断队列是否已满

//  入队
void push(LinkQueue &q)
{

    cout << "Please enter the new data : ";
    int data = 0;
    cin >> data;
    // q.rear->next = new QueueNode;
    // q.rear = q.rear->next;
    // q.rear->data = data;
    // q.rear->next = nullptr;
    QueuePtr p = new QueueNode;
    p->data = data;
    p->next = nullptr;
    q.rear->next = p;
    q.rear = p;
}

//  出队列并或获取元素
void pop(LinkQueue &q)
{
    QueuePtr temp = q.front->next;
    cout << temp->data << " ";
    q.front->next = temp->next;
    if (temp == q.rear)
        q.rear = q.front; // 重要，凭借该操作可以为后续判断队列是否为空提供条件
    delete temp;
}

int main()
{
    LinkQueue q;
    initialQueue(q);
    emptyQueue(q);

    push(q);
    push(q);
    push(q);
    push(q);
    push(q);
    emptyQueue(q);
    pop(q);
    pop(q);
    pop(q);
    pop(q);
    pop(q);
    cout << endl;
    emptyQueue(q);
    deleteQueue(q);
    return 0;
} */