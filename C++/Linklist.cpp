//**************************************************************************带头结点的单向链表
/* #include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    Node *next;
} *ListNode;

// 创建新结点
ListNode creatNewNode()
{
    ListNode newNode = new Node;
    if (newNode == nullptr) // 判断内存分配是否成功
    {
        cout << "New Failed!!!" << endl;
        return nullptr;
    }
    cout << "请输入新结点中的数据： ";
    cin >> newNode->data;
    newNode->next = nullptr;
    return newNode;
}

// 创建链表
ListNode creatLinkList(int n)
{
    ListNode head = nullptr; // 将头指针与尾指针置为空，便于检查后续循环中新创建节点是否为第一个结点的情况，也方便检查链表是否为空的操作
    ListNode tail = nullptr;
    for (int i = 0; i != n; ++i)
    {
        ListNode newNode = creatNewNode();
        if (newNode == nullptr)
        {
            cout << "New Failed!!!" << endl;
            return nullptr;
        }
        if (head == nullptr) // 如果头指针head为空，说明是链表的第一个结点，将头指针head与尾指针指向该节点
        {
            head = newNode;
            tail = newNode;
        }
        else // 如果头指针不为空，即不是第一个结点，此时只需要将尾指针进行跟进就好
        {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return head; // 头指针在指向链表中创建的第一个结点后，便没有发生改变，正常返回即可
}

// 判断链表是否为空
bool emptyList(ListNode head)
{ // 此处我添加了打印的操作，便于检查该操作的正确性！
    if (head->next == nullptr)
    {
        cout << "该链表为空！！！" << endl;
        return true;
    }
    else
    {
        cout << "该链表不为空！！！" << endl;
        return false;
    }
}

// 查找结点（返回上一结点）
ListNode findPreNode(ListNode head, int data)
{
    ListNode current = head->next;
    ListNode prev = head;
    while (current != nullptr)
    {
        if (current->data == data)
            return prev;
        prev = current;
        current = current->next;
    }
    cout << "未找到数据！！！" << endl;
    return nullptr;
}

// 删除结点
void deleteNode(ListNode head)
{
    int data = 0;
    cout << "请输入待删除的节点数据： ";
    cin >> data;
    ListNode position = findPreNode(head, data); // 如果找到该数据，返回该数据的前一个结点
    ListNode temp = position->next->next;        // 将temp表示为待删除结点的后一个结点
    delete position->next;                       // 删除节点时要释放空间，结点是手动进行的内存分配，删除时应及时销毁
    position->next = temp;                       // 将所删除结点的前后指针相连
}

// 插入结点
void insertNode(ListNode head)
{
    int data = 0;
    cout << "请输入待被插入的节点数据： ";
    cin >> data;
    ListNode position = findPreNode(head, data);
    ListNode newNode = creatNewNode(); // 创建一个待插入的新结点
    ListNode temp = position->next;    // temp记录待被插入节点的后一节点的位置
    position->next = newNode;          // 将前一结点指向新结点
    newNode->next = temp;              // 再将新结点指向之前保存的后一结点temp
    // 注意插入顺序，先保存后一结点位置，在更改前一结点的指针域，否则后一结点的地址将会丢失
}

// 销毁链表
void distroyList(ListNode head)
{
    ListNode current = head; // 将current指向头结点，头结点也要在循环内进行删除
    while (head)
    {
        current = head->next; // 保存后一结点位置
        delete head;          // 删除当前结点
        head = current;       // 更新结点
    }
}

// 打印链表
void printList(ListNode head)
{
    ListNode current = head->next; // 跳过头结点，从首元节点开始打印
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }
}

int main()
{
    ListNode head = new Node;
    cout << "请输入链表中元素的个数： ";
    int num = 0;
    cin >> num;
    head->next = creatLinkList(num);
    printList(head); // 注意下面操作传入的是头结点head本身
    cout << endl;
    emptyList(head);

    deleteNode(head);
    printList(head);

    insertNode(head);
    printList(head);

    distroyList(head);
    return 0;
}
 */
//************************************************************************不带头结点的单向链表
/* 
#include <iostream>
#include <string>
using namespace std;

typedef struct LinkNode
{
    int data;
    LinkNode *next;
} Node, *ListNode;

// 创建新节点
ListNode CreatNode()
{
    ListNode newNode = new Node;
    if (newNode == nullptr)
    {
        cout << "New failed!!!" << endl;
        return nullptr;
    }
    cout << "请输入新节点的值：";
    cin >> newNode->data;
    newNode->next = nullptr; // 最后一个设置为空
    return newNode;
}

// 创建链表
ListNode CreatList(int listSize)
{
    ListNode head = nullptr;
    ListNode tail = nullptr;
    for (int i = 0; i != listSize; ++i)
    {
        ListNode newNode = CreatNode();
        if (newNode == nullptr)
            cout << "New Failed!!!" << endl;
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// 打印链表
void printList(ListNode &head)
{
    ListNode current = head;
    while (current)
    {
        cout << "链表中的值为：";
        cout << current->data << endl;
        current = current->next;
    }
}

// 销毁链表
void destroyList(ListNode &head)
{
    ListNode current = head;
    while (current)
    {
        ListNode temp = current->next;
        delete current;
        current = temp;
    }
}

// 查找节点(返回前一节点)
ListNode findPreNode(ListNode &head, int data)
{
    ListNode current = head;
    while (current->next->data != data)
    {
        current = current->next;
    }
    return current;
}

// 删除节点
void deleteNode(ListNode &head)
{
    cout << "请输入待删除的值：";
    int data = 0;
    cin >> data;
    // 检查所删除结点是否为第一个结点，如果为第一个结点则需要传递头指针的引用，对外部头指针的连接进行修改，将其指向所删除结点的下一个结点，若不进行引用进行参数传递，则该函数中只是对副本链表的副本进行操作，无法作用于外部头指针head，即无法正确的删除链表中的结点
    if (head->data == data)
    {
        ListNode temp = head;
        head = head->next;
        delete temp;
    }
    else //若不为首元节点，则进行正常删除
    {
        ListNode position = findPreNode(head, data);
        ListNode temp = position->next->next;
        delete position->next;
        position->next = temp;
    }
}

// 插入节点
void insertNode(ListNode &head)
{
    int data = 0;
    cout << "请输入待插入位置后的值：";
    cin >> data;
    //与删除操作一致，需要检查是否为首元节点。
    if (head->data == data)
    {
        ListNode newNode = CreatNode();
        newNode->next = head;
        head = newNode;
    }
    else
    {
        ListNode position = findPreNode(head, data);
        // cout << "请输入待插入的值：";
        ListNode newNode = CreatNode();
        ListNode temp = position->next;
        position->next = newNode;
        newNode->next = temp;
    }
}

// 判断链表是否为空
bool emptyList(ListNode head)
{
    //因为传递的是头指针，并不是头结点，所以只需对头指针head进行检查即可
    return head == nullptr;
}
int main()
{
    ListNode head = CreatList(3);
    if (!emptyList(head))
        cout << "该链表不为空！" << endl;
    printList(head);

    deleteNode(head);
    printList(head);

    insertNode(head);
    printList(head);

    destroyList(head);
    head = nullptr;   //在链表销毁操作中,虽然传递的是头指针的引用，但是并没有实际改变head的指向，且没有返回值，为了防止head成为悬挂指针，此时将head置空是一个良好的编程习惯

    return 0;
} */
 
//****************************************************************************带头结点双向链表
/* #include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    Node *prior;     //指向前驱节点的指针
    Node *next;      //指向后继结点的指针
} *ListNode;

// 创建节点
ListNode creatNode()
{
    ListNode newNode = new Node;
    int data = 0;
    cout << "请输入新节点数据： ";
    cin >> data;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prior = nullptr;
    return newNode;
}

// 创建链表
void creatLinkList(ListNode head, int n)
{
    head->next = nullptr;         //将指向前驱结点和指向后继结点的指针均置为空
    head->prior = nullptr;
    ListNode tail = nullptr;
    for (int i = 0; i != n; ++i)
    {
        ListNode newNode = creatNode();
        if (head->next == nullptr)     //判断是否为第一个结点，如果是，将新结点与头结点相互建立联系
        {
            head->next = newNode;    //头指针的next域指向新结点
            newNode->prior = head;   //新结点的prior域指向头结点
            tail = newNode;          //尾指针tail进行跟进
        }
        else   //如果不是第一个结点，利用跟进的尾指针tail与新结点建立指针域的互相联系即可
        {
            newNode->prior = tail;
            tail->next = newNode;
            tail = tail->next;  //更新尾结点
        }
    }
}

// 查找节点（返回当前节点） //由于结点带有prior指针，所以可以轻松获取前驱结点的地址，所以返回所查找节点即可。
ListNode findNode(ListNode head, int data)
{
    ListNode current = head->next;        // 跳过头结点
    while (current)
    {
        if (current->data == data)
            return current;
        else
            current = current->next;
    }
    return nullptr;
}

// 删除节点
void deleteNode(ListNode &head)
{
    cout << "请输入待删除的节点数据： ";
    int data = 0;
    cin >> data;
    ListNode current = findNode(head, data);
    ListNode prev = current->prior;        //prev为待删除结点的前驱结点
    ListNode next = current->next;         //next为待删除结点的后继结点
    if (next == nullptr)                   //如果后继结点为空，则待删除结点为尾结点
    {
        prev->next = next;      //让前驱结点指向后继结点（此时next为nullptr）；
        delete current;         //删除当前节点即可
    }
    else         //若不为空，则为正常情况，由于设置了头结点，所以直接删除即可
    {
        prev->next = next;          //让前驱结点的next域指向后继结点
        next->prior = prev;         //让后继结点的prior域指向前驱结点
        delete current;             //删除被架空的当前结点
    }
}

// 插入节点
void insertNode(ListNode &head)
{
    cout << "请输入待插入的位置（前） : ";
    int data = 0;
    cin >> data;
    ListNode current = findNode(head, data);
    ListNode newNode = creatNode();
    newNode->prior = current->prior; //让新结点的prior指向当前结点的前驱结点，开始逐步建立联系
    newNode->next = current;         //将新结点的next指向所查找到的结点前
    current->prior->next = newNode;  //让当前结点的前驱结点的next指向新结点
    current->prior = newNode;        // 让当前结点的prior指向新结点
}


// 销毁链表
void destroyList(ListNode head)
{
    ListNode current = head;
    while (head != nullptr)
    {
        current = head->next;
        delete head;  //从头结点进行销毁，直到道尾节点为空，到最后head被置为空
        head = current;
    }
}

// 遍历链表
void printList(ListNode head)
{
    ListNode current = head->next; //跳过头结点
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
}

int main()
{
    ListNode head = new Node;   //头结点
    creatLinkList(head, 3);
    printList(head);

    insertNode(head);
    printList(head);

    deleteNode(head);
    printList(head);

    destroyList(head);
    head = nullptr;   //由于原始指针依旧指向的为被销毁后的头结点，为避免悬挂指针，将head置空
    return 0;
}

 */
//*******************************************************************************单项循环链表
/* #include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    Node *next;
} *ListNode;

// 创建节点
ListNode creatNode()
{
    ListNode newNode = new Node;
    cout << "请输入数据 : ";
    int data = 0;
    cin >> data;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// 创建链表
void creatLinkList(ListNode head, int n)
{
    head->next = head;       // 初始化头结点的next域指向自身
    ListNode tail = nullptr; // 将尾结点初始化为空，准备进行跟进
    for (int i = 0; i != n; ++i)
    {
        ListNode newNode = creatNode();
        if (head->next == head) // 如果指向自身，说明为newNode为第一个结点
        {
            head->next = newNode; // 将头结点与新结点相连
            newNode->next = head; // 尾结点的next域始终指向头结点，所以每当创建新结点是要进行更新
            tail = newNode;
        }
        else // 不是第一个结点，利用尾结点的跟进依次在后面进行链接
        {
            tail->next = newNode;
            newNode->next = head;
            tail = tail->next;
        }
    }
}

// 查找
ListNode findPreNode(ListNode head, int data)
{
    ListNode current = head->next; // 跳过头结点
    ListNode prev = head;          // 因为是单向循环链表，虽为循环，但还是单项，即要增设一个指针记录前驱结点的地址
    while (current != head)        // 若current指向头结点，即说明已经把链表遍历了一遍
    {
        if (current->data == data)
            return prev;
        current = current->next; // prev指针始终比current指针满一步，即current找到时，返回prev就行
        prev = prev->next;
    }
    cout << "未找到数据！！！" << endl;
    return nullptr; // 遍历一遍后，若没有找到数据，即返回nullptr；
}

// 删除节点
void deleteNode(ListNode head)
{
    cout << "请输入待被删除的数据: ";
    int data = 0;
    cin >> data;
    ListNode prev = findPreNode(head, data); // 查找操作返回的是前驱结点，用prev保存
    ListNode toDelete = prev->next;          // 确定待删除结点位置
    ListNode next = toDelete->next;          // 用next记录待删除节点的后继结点
    prev->next = next;                       // 架空待删除结点
    delete toDelete;
}

// 插入节点   与单链表的插入类似，不做赘述
void insertNode(ListNode head)
{
    cout << "请输入插入在哪个数据前面： ";
    int data = 0;
    cin >> data;
    ListNode prev = findPreNode(head, data);
    ListNode newNode = creatNode();
    ListNode next = prev->next; // 这里next为待插入结点的后继结点
    prev->next = newNode;
    newNode->next = next;
}

// 销毁链表
void destroyList(ListNode &head)
{
    // 如果链表为空，直接返回
    if (head == nullptr)
        return;
    // 若链表只有一个头结点，删除后将head置空就行
    if (head->next == head)
    {
        delete head;
        head = nullptr;
        return;
    }
    ListNode current = head;     // 利用current对链表进行遍历
    ListNode nextNode = nullptr; // 初始化下一结点nextNode为空
    while (current->next != head)
    {
        nextNode = current->next; // 更新newNode，始终在删除当前节点前获取下一结点位置，这样才能找到
        delete current;
        current = nextNode; // 更新current
    }
}

// 判断链表是否为空
bool emptyList(ListNode head)
{
    if (head->next == head)
    {
        cout << "该链表为空！！！" << endl;
        return true;
    }
    else
    {
        cout << "该链表不为空!!!" << endl;
        return false;
    }
}

// 打印链表
void printList(ListNode head)
{
    ListNode current = head->next; // 跳过头结点
    while (current != head)        // 遍历一圈
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    ListNode Head = new Node;
    creatLinkList(Head, 3);
    printList(Head);

    deleteNode(Head);
    printList(Head);

    insertNode(Head);
    printList(Head);

    emptyList(Head);
    deleteNode(Head);
    deleteNode(Head);
    deleteNode(Head);
    emptyList(Head);
    destroyList(Head);
    // Head = nullptr;   //由于传递的是引用，所以在destroyList()函数中对头节点删除后进行了置空操作，此时外部的Head也会受到同样的改变，即为空，不需要在次置空
    return 0;
}
 */
//*******************************************************************************双向循环链表
/* #include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    Node *prior;
    Node *next;
} *ListNode;

// 创建节点
ListNode creatNode()
{
    cout << "请输入新节点数据： ";
    int data = 0;
    cin >> data;
    ListNode newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prior = nullptr;
    return newNode;
}

// 创建链表
void creatLinkList(ListNode head, int n)
{
    head->next = head;     // 老样子，初始化链表的头结点的next域指向自己
    head->prior = nullptr; // 将头结点的prior置为空，等待新结点加入进行更新
    ListNode tail = nullptr;
    for (int i = 0; i != n; ++i)
    {
        ListNode newNode = creatNode();
        if (head->next == head) // 判断链表是否为空，如果为空，即为创建的第一个结点
        {
            head->next = newNode;  // 头结点的next指针指向新结点
            head->prior = newNode; // 头结点的prior指针指向新结点
            newNode->prior = head; // 新结点的prior指针指向头结点
            newNode->next = head;  // 新结点的next指针指向头结点
            // 此时该两个结点既是双向的，也是循环的
            tail = newNode;
        }
        else
        {
            // 利用尾指针进行两个结点相互的链接
            tail->next = newNode;
            newNode->prior = tail;
            newNode->next = head; // 将尾结点的next域指向头结点
            tail = tail->next;
            head->prior = newNode; // 不要忘了最后要把头结点的prior域指向新结点
        }
    }
}
// 查找节点
ListNode findNode(ListNode head, int data)
{
    // 由于是双向，可以不用刻意返回前驱节点
    ListNode current = head->next; // 跳过头结点
    while (current != head)
    {
        if (current->data == data)
            return current;
        else
            current = current->next;
    }
    return nullptr; // 没找到则返回空
}

// 删除节点
void deleteNode(ListNode head)
{
    cout << "请输入待删除的节点数据：";
    int data = 0;
    cin >> data;
    ListNode current = findNode(head, data);
    ListNode prev = current->prior; // 待删除结点的前驱结点
    ListNode next = current->next;  // 待删除结点的后继结点
    prev->next = next;
    next->prior = prev;
    // 架空当前结点（即待被删除结点）
    delete current;
}

// 插入节点
void insertNode(ListNode head)
{
    cout << "请输入在哪个数据之前插入：";
    int data = 0;
    cin >> data;
    ListNode current = findNode(head, data);
    ListNode newNode = creatNode();
    ListNode prev = current->prior; 
    newNode->next = current;
    current->prior = newNode;
    newNode->prior = prev;
    prev->next = newNode;
}
// 销毁链表
void destroyList(ListNode head)
{
    // 如果链表为空，直接返回
    if (head == nullptr)
        return;
    // 若链表只有一个头结点，删除后将head置空
    if (head->next == head)
    {
        delete head;
        head = nullptr;
        return;
    }
    ListNode current = head;     // 利用current对链表进行遍历
    ListNode nextNode = nullptr; // 初始化下一结点nextNode为空
    while (current->next != head)
    {
        nextNode = current->next; // 更新newNode，始终在删除当前节点前获取下一结点位置，这样才能找到
        delete current;
        current = nextNode; // 更新current
    }
}
    // 打印节点数据
    void printNode(ListNode head)
    {
        ListNode current = head->next; // 跳过头结点
        do
        {
            // 也是一种写法，先打印一遍，在更新结点进行循环判断
            cout << current->data << " ";
            current = current->next;
        } while (current != head);

        cout << endl;
    }

    // 判断链表是否为空
    bool emptyList(ListNode head)
    {
        if (head->next == head)
        {
            cout << "该链表为空！！！" << endl;
            return true;
        }
        else
        {
            cout << "该链表不为空！！！" << endl;
            return false;
        }
    }

    int main()
    {
        ListNode Head = new Node;
        cout << "请输入链表数据个数： ";
        int n = 0;
        cin >> n;
        creatLinkList(Head, n);
        printNode(Head);

        deleteNode(Head);
        printNode(Head);

        insertNode(Head);
        printNode(Head);

        deleteNode(Head);
        deleteNode(Head);
        deleteNode(Head);
        emptyList(Head);
        destroyList(Head);
        Head = nullptr;
        return 0;
    } */