/* #include <iostream>
#include <cstring>
#include "String.h"
//  class String
// {
// public:
//     String(const char *data = nullptr);
//     String(const String &data);
//     String &oper./ator=(const String &data);
//     char *get_m_data() const { return m_data; }
//     ~String() { delete[] m_data; }

// private:
//     char *m_data;
// };
// std::ostream &operator<<(std::ostream &os, const String &data);

using namespace std;
String::String(const char *data) : m_data(nullptr)
{
    if (data)
    {
        m_data = new char[strlen(data) + 1];
        strcpy(m_data, data);
    }
    else
    {
        m_data = new char[1];
        *m_data = '\0';
    }
}

String::String(const String &data) : m_data(nullptr)
{
    // delete[] m_data;
    m_data = new char[strlen(data.get_m_data()) + 1];
    strcpy(m_data, data.m_data);
}

String &String::operator=(const String &data)
{
    if (this == &data)
    {
        return *this;
    }
    else
    {
        delete[] m_data;
        m_data = new char[strlen(data.get_m_data()) + 1];
        strcpy(m_data, data.m_data);
        return *this;
    }
}

ostream &operator<<(ostream &os, const String &data)
{
    return os << data.get_m_data();
}

int main()
{
    String s1;
    String s2("Hello!");
    String s3(s2);

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    return 0;
} */

/*
#include<iostream>
#include"String.h"
#include<cstring>

using namespace std;

String::String(const char* cstr)
{
    if(cstr)
    {
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data, cstr);
    }
}

String::String(const String& str)
{
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}

String& String::operator=(const String& str)
{
    if(this == &str)
    {
        return *this;
    }
    delete[] m_data;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
    return *this;
}

String::~String()
{
    delete[] m_data;
}

int main()
{
    String s1("Hello World!");
    String s2(s1);
    String s3 = s2;
    cout << s1.get_c_str() << endl
         << s2.get_c_str() << endl
         << s3.get_c_str() << endl;
    return 0;
}  */

/*
#include<iostream>
using namespace std;

class Account
{
    public:
        static double m_rate;
        // 静态成员函数的一个主要特点是它们不与类的任何特定实例（对象）相关联。意味着静态函数没有this指针。所以不能直接访问类的非静态对象或调用非静态函数。
        // 静态函数可以访问类的非静态成员变量和成员函数，但前提是需要通过类的某个对象作为中介。
        // 静态成员变量是与类本身相关联的，而不是与类的任何特定实例相关联。因此，静态成员函数可以直接访问和修改静态成员变量，因为它们不需要通过this指针来引用。
        static void set_rate(const double &x) { m_rate = x; }
};

//静态对象必须在类外进行初始化，在类内进行类型声明来告知编译器静态对象的存在，在类外进行定义来为其分配具体的静态空间

//静态对象必须进行初始化，如果没有在类内进行内联初始化（这需要静态对象具有const或constexpr属性），就必须在类外进行初始化，因为静态对象不属于任何类的实例，它只属于类，并且在所有对象创建之前就已经存在，所以在类外的某个地方必须进行初始化。
double Account::m_rate = 8.0;


int main()
{
    Account::set_rate(5.0); //通过类名调用

    Account a;
    a.set_rate(7.0);  // 通过对象进行调用

    return 0;
} */

//    Derived类的析构函数体中的代码（如果有的话）。
//    Component类对象的析构函数（成员对象的析构函数）。
//    Base类（基类）的析构函数。

// 成员对象的析构函数会在基类的析构函数之前被调用，这是因为成员对象在基类部分之前被构造，所以它们也需要在基类部分之前被销毁。而派生类的析构函数体中的代码则在所有成员对象和基类析构函数之前执行（如果有的话）。

// #include<iostream>

//     class Base
// {
// public:
//     Base() { std::cout << "Base's structure first!" << std::endl; }
//     ~Base() { std::cout << "Base's destroy first!" << std::endl; }
// private:
//     int integer = 1;
// };

// class Component
// {
// public:
//     Component() { std::cout << "Component's structure first!" << std::endl; }
//     ~Component() { std::cout << "Component's destroy first!" << std::endl; }
// private:
//     int C_interger = 3;
// };

// class Derived : public Base
// {
// public:
//     Derived() { std::cout << "Derived's structure first!" << std::endl; }
//     ~Derived() { std::cout << "Derived's destroy first!" << std::endl; }
// private:
//     Component C;
// };

// int main()
// {
//     Derived A;
//     return 0;
// }

/*
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    if(argc == 2)
    {
        cout << "The argument supplied is " << argv[1];
    }
    else if (argc > 2)
    {
        cout << "Too many arguments supplied." << endl;
    }
    else
    {
        cout << "One argument expected." << endl;
    }
} */
/*
应当指出的是，argv[0] 存储程序的名称，argv[1] 是一个指向第一个命令行参数的指针，*argv[n] 是最后一个参数。如果没有提供任何参数，argc 将为 1，否则，如果传递了一个参数，argc 将被设置为 2。

多个命令行参数之间用空格分隔，但是如果参数本身带有空格，那么传递参数的时候应把参数放置在双引号 "" 或单引号 '' 内部。让我们重新编写上面的实例，有一个空间，那么你可以通过这样的观点，把它们放在双引号或单引号""""。让我们重新编写上面的实例，向程序传递一个放置在双引号内部的命令行参数：
*/

/* #include <iostream>
using namespace std;

int main()
{
    int a = 2;
    int *pa = &a;
    int &paa = *pa;
    cout << paa << endl;

    return 0;
} */
/*
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> ivec(7, -1);
    cout << ivec.size() << endl;
    return 0;
} */

/* #include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Pair
{
    int key;
    char element[20];
};
using DATA = Pair;
using LPDATA = Pair *;

struct hashTable
{
    LPDATA *table;
    int divisor;
    int curSize;
};

using HASH = hashTable;
using LPHASH = hashTable *;




LPHASH creatHashTable(int p)
{
    LPHASH hash = new (HASH);
    if (hash == NULL)
    {
        cout << "New Failed!" << endl;
    }
    hash->divisor = p;
    hash->curSize = 0;
    hash->table = new LPDATA[hash->divisor];
    if (hash->table == NULL)
    {
        cout << "New Failed!" << endl;
    }
    for (int i = 0; i < hash->divisor; ++i)
    {
        hash->table[i] = NULL;
    }
    return hash;
}

int search(LPHASH hash, int key)
{
    int pos = key % hash->divisor;
    int curPos = pos;
    do
    {
        if (hash->table[curPos] == NULL || hash->table[curPos]->key == key)
        {
            return curPos;
        }
        curPos = (curPos + 1) % hash->divisor;
    } while (curPos != pos);
    return curPos;
}

void insertData(LPHASH hash, DATA data)
{
    int pos = search(hash, data.key);
    if (hash->table[pos] == NULL)
    {
        hash->table[pos] = new DATA;
        memcpy(hash->table[pos], &data, sizeof(DATA));
        hash->curSize++;
    }
    else
    {
        if (hash->table[pos]->key == data.key)
        {
            strcpy(hash->table[pos]->element, data.element);
        }
        else
        {
            cout << "HastTable FULLFILLED!" << endl;
            return;
        }
    }
}

void printHash(LPHASH hash)
{
    for (int i = 0; i < hash->divisor; ++i)
    {
        if (hash->table[i] == NULL)
        {
            cout << "NULL" << endl;
        }
        else
        {
            cout << hash->table[i]->key << " : " << hash->table[i]->element << endl;
        }
    }
}

int main()
{
    LPHASH hash = creatHashTable(10);
    DATA array[5] = {
        11, "Chen Jiawang",
        34, "Chen Xiangrong",
        21, "Deng Xinyuan",
        7, "Wei Endian",
        13, "Li Yuanhang"};
    for (int i = 0; i < 5; ++i)
    {
        insertData(hash, array[i]);
    }
    printHash(hash);
    return 0;
} */

//************************************************PAT 1002 写出这个数
/* #include <iostream>
#include <string>
#include <sstream>
using namespace std;

std::string digitToPinyin(int digit)
{
    switch (digit)
    {
    case 0:
        return "ling";
    case 1:
        return "yi";
    case 2:
        return "er";
    case 3:
        return "san";
    case 4:
        return "si";
    case 5:
        return "wu";
    case 6:
        return "liu";
    case 7:
        return "qi";
    case 8:
        return "ba";
    case 9:
        return "jiu";
    default:
        return "";
    }
}

int main()
{
    std::string n;
    std::cin >> n;

    int sum = 0;
    for (char c : n)
    {
        sum += c - '0';
    }

    std::stringstream ss;
    ss << sum;
    std::string sumStr;
    ss >> sumStr;

    bool isFirst = true;
    for (size_t i = 0; i < sumStr.length(); ++i)
    {
        int digit = sumStr[i] - '0';
        if (!isFirst)
        {
            std::cout << " ";
        }
        std::cout << digitToPinyin(digit);
        isFirst = false;
    }
    std::cout << std::endl;

    return 0;
} */

//**************************************************PAT 1003 我要通过

//                     第一种方法迭代器（18/20）
/* #include <bits/stdc++.h>
using namespace std;

bool isRight(string &s)
{
    if (s.size() < 3) // 字符个数不能小于3个
    {
        return false;
    }

    if (s.find('P') >= s.find('T'))
    {
        return false;
    }

    for (char c : s) // 个数不小于3后，判断是否仅有PAT三种字符
    {
        if (c != 'P' && c != 'A' && c != 'T')
        {
            return false;
        }
    }

    int a = 0, b = 0, c = 0;            // P前A个数为a，P后T前A个数为b，T后A个数为c
    size_t Ppos = s.find('P');          // 返回指向字符P的索引
    size_t Tpos = s.find('T');          // 返回指向字符T的索引
    auto iterator_P = s.begin() + Ppos; // 字符P的索引
    auto iterator_T = s.begin() + Tpos; // 字符T的索引

    for (auto it = s.begin(); it != iterator_P; ++it)
    {
        if (*it == 'A')
            a++;
    }
    for (auto it = iterator_P; it != iterator_T; ++it)
    {
        if (*it == 'A')
            b++;
    }
    for (auto it = iterator_T; it != s.end(); ++it)
    {
        if (*it == 'A')
            c++;
    }
    if (b == 0)
    {
        return false;
    }
    if (a * b != c)
    {
        return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i)
    {
        string s;
        getline(cin, s);
        if (isRight(s))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}


//                    第二种方法数组（20/20）


int main()
{
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i != n; ++i)
    {
        string s;
        getline(cin, s);
        if (isRight(s))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

bool isRight(const string &s)
{
    int len = s.size();
    int a = 0, b = 0;
    for (int i = 0; i != len; ++i)
    {
        if (s[i] == 'P' || s[i] == 'A' || s[i] == 'T')
        {
            if (s[i] == 'P')
            {
                ++a;
            }
            if (s[i] == 'T' && a != 0)
            {
                ++b;
            }
            if (s[i] == 'T' && a == 0)
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    if (a == 1 && b == 1)
    {
        int c = 0, d = 0, e = 0;
        for (int i = 0; i != len; ++i)
        {
            if (s[i] == 'P')
            {
                ++a;
            }
            if (s[i] == 'T')
            {
                ++b;
            }
            if (s[i] == 'A' && a == 1)
            {
                ++c;
            }
            if (s[i] == 'A' && a == 2 && b == 1)
            {
                ++d;
            }
            if (s[i] == 'A' && a == 2 && b == 2)
            {
                ++e;
            }
            if ((c == 0 && e == 0 && d != 0) || (c * d == e && d != 0))
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i != n; ++i)
    {
        string s;
        getline(cin, s);
        if (isRight(s))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
} */

//**************************************************PAT 1004 成绩排名
//                          我的版本（错误）
/*
#include <bits/stdc++.h>
using namespace std;

typedef struct Student
{
    string name;
    string id;
    int score;
} Message;

void Max_Min(Message *message, int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - 1 - i; ++j)
        {
            if (message[j].score > message[j + 1].score)
            {
                int temp = message[j].score;
                message[j].score = message[j + 1].score;
                message[j + 1].score = temp;
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cout << message[i].name << " "
             << message[i].id << " "
             << message[i].score << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    cin.ignore();
    Message message[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> message[i].name >> message[i].id >> message[i].score;

        if (message[i].score > 100 || message[i].score < 0 || message[i].name.size() > 10)
        {
            return 0;
        }
    }

    Max_Min(message, n);

    return 0;
}
 */

//                           正确版本（C++）
/*
#include <bits/stdc++.h>
using namespace std;
class Student
{
public:
    void set_st_message(string n, string i, int s);
    void print();
    int get_st_score();

private:
    string name;
    string id;
    int score;
};

void Student::set_st_message(string n, string i, int s)
{
    name = n;
    id = i;
    score = s;
}
void Student::print()
{
    cout << name << " " << id << endl;
}

int Student::get_st_score()
{
    return score;
}

int main()
{
    int n;
    int st_score;
    string st_name, st_id;
    cin >> n;
    Student *p = new Student[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> st_name >> st_id >> st_score;
        p[i].set_st_message(st_name, st_id, st_score);
    }
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - 1 - i; ++j)
        {
            if (p[j].get_st_score() > p[j + 1].get_st_score())
            {
                Student temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    p[n - 1].print();
    p[0].print();
    return 0;
} */

//********************************************PAT 1005 继续(3n+1)猜想
/*
#include <bits/stdc++.h>
using namespace std;
// 6和7没有被所给数字的儿子集所覆盖，要拎出来
int sign[11000];
int enter[110];
int result[110];

int main()
{
    int n;
    int m;

    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i)
    {
        cin >> m;
        enter[i] = m;
        while (m != 1)
        {
            if (m % 2 == 0)
            {
                m = m / 2;
                sign[m]++;
            }
            else if (m % 2 != 0)
            {
                m = 3 * m + 1;
                m = m / 2;
                sign[m]++;
            }
        }
    }

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - 1 -i; ++j)
        {
            if(enter[j] < enter[j +  1])
            {
                int temp = enter[j];
                enter[j] = enter[j + 1];
                enter[j + 1] = temp;
            }
        }
    }
    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        if (sign[enter[i]] == 0)
        {
            result[j++] = enter[i];
        }
        }

        for (int i = 0; i < j; ++i)
        {
            cout << result[i] << " ";
        }
    return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;

int preme[10000];

bool isPreme(int n)
{
    for (int i = 2; i <= n / i; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    memset(preme, 0, sizeof(preme[0]));
    int n;
    int i, j;
    int count = 0;
    cin >> n;
    for (i = 0, j = 0; i < n; ++i) // 对于所输入的数范围内每一个数进行遍历
    {
        if (i % 2 == 0 && i != 2) // 如果是偶数，则直接跳过，只检查奇数
            continue;
        if (isPreme(i)) // 判断是否为素数
        {
            preme[j++] = i; // 如果为素数，装入素数数组中

        }
    }
    for (int k = 0; k < j; ++k)
    {
        if (preme[k + 1] - preme[k] == 2)
            count++;
    }
    cout << count;
    return 0;
} */
/*
#include <iostream>
using namespace std;

// find target
int index(int arr[], int tar)
{
    for (int i = 0; i != 10; ++i)
    {
        if (arr[i] == tar)
            return i;
    }
    return -1;
}

void insert(int arr[], int data)
{
    for (int i = 0; i != 10; ++i)
    {
        if (data > arr[])
        {
            arr[]
        }
        if (data < arr[i])
        {
            for (int j = 8; j >= i; j--)
            {
                arr[j + 1] = arr[j];
            }
            arr[i] = data;
            break;
        }
    }
}
int main()
{
    int arr[10] = {1, 2, 3, 4, 6, 7, 8, 9, 10};
    // int n = sizeof(arr) / sizeof(arr[0]);
    insert(arr, 5);
    for (int i = 0; i != 10; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int ret = index(arr, 7);
    cout << "index = " << ret << endl;

    return 0;
} */

/*
#include <iostream>
#include <string>
using namespace std;

typedef struct LinkNode
{
    int age;
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
    cin >> newNode->age;
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
        cout << current->age << endl;
        current = current->next;
    }
}

// 删除链表
void deleteList(ListNode &head)
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
ListNode findPreNode(ListNode &head, int age)
{
    ListNode current = head;
    while (current->next->age != age)
    {
        current = current->next;
    }
    return current;
}

// 删除节点
void deleteNode(ListNode &head)
{
    cout << "请输入待删除的值：";
    int age = 0;
    cin >> age;
    if (head->age == age)
    {
        ListNode temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        ListNode position = findPreNode(head, age);
        ListNode temp = position->next->next;
        delete position->next;
        position->next = temp;
    }
}

// 插入节点
void insertNode(ListNode &head)
{
    int age = 0;
    cout << "请输入待插入位置后的值：";
    cin >> age;
    if (head->age == age)
    {
        ListNode newNode = CreatNode();
        newNode->next = head;
        head = newNode;
    }
    else
    {
        ListNode position = findPreNode(head, age);
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

    deleteList(head);
    head = nullptr;
    if (emptyList(head))
    {
        cout << "该链表为空！" << endl;
    }

    return 0;
} */
/*
#include<iostream>
using namespace std;

typedef struct Node
{
    int num;
    Node *next;
} *ListNode;

//创建新节点
ListNode creatNewNode()
{
    ListNode newNode = new Node;
    if (newNode == nullptr)
    {
        cout << "New Failed!!!" << endl;
        return nullptr;
    }
    cout << "请输入新节点中的数据：";
    cin >> newNode->num;
    newNode->next = nullptr;
    return newNode;
}

//创建链表
ListNode creatLinkList(int num)
{
    ListNode head = nullptr;
    ListNode tail = nullptr;
    for (int i = 0; i != num; ++i)
    {
        ListNode newNode = creatNewNode();
        if (newNode == nullptr)
        {
            cout << "New Failed!!!" << endl;
            return nullptr;
        }
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return head;
}

//判断链表是否为空
bool emptyList(ListNode head)
{
    return head == nullptr;
}

//查找节点（返回上一节点）
ListNode findPreNode(ListNode head, int num)
{
    ListNode current = head;
    while (current->next->num != num)
    {
        current = current->next;
    }
    if(current == nullptr)
    {
        cout << "未找到数据！" << endl;
        return 0;
    }
    return current;
}

//删除节点
void deleteNode(ListNode head)
{
    int num = 0;
    cout << "请输入待删除的节点数据： ";
    cin >> num;
    ListNode position = findPreNode(head, num);
    ListNode temp = position->next->next;
    delete position->next;
    position->next = temp;
}

//插入节点
void insertNode(ListNode head)
{
    int num = 0;
    cout << "请输入待被插入的节点数据： ";
    cin >> num;
    ListNode position = findPreNode(head, num);
    ListNode newNode = creatNewNode();
    ListNode temp = position->next;
    position->next = newNode;
    newNode->next = temp;
}

//销毁链表
void distroyList(ListNode head)
{
    ListNode current = head;
    while(head)
    {
        current = head->next;
        delete head;
        head = current;
    }
}

//打印链表
void printList(ListNode head)
{
    ListNode current = head->next;
    while (current)
    {
        cout << current->num << " ";
        current = current->next;
    }
}

int main()
{
    ListNode head = new Node;
    head->next = creatLinkList(3);
    printList(head);

    deleteNode(head);
    printList(head);

    insertNode(head);
    printList(head);

    distroyList(head);
    head = nullptr;

    //if(emptyList(head))
    //    cout << "该链表为空链表！" << endl;

    return 0;
} */

//************************************************双向链表
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
    ListNode newNode = new Node;
    // ListNode tail = nullptr;
    int num = 0;
    cout << "请输入新节点数据： ";
    cin >> num;
    newNode->data = num;
    newNode->next = nullptr;
    newNode->prior = nullptr;
    return newNode;
}

// 创建链表
void creatLinkList(ListNode head, int n)
{
    head->next = nullptr;
    head->prior = nullptr;
    ListNode tail = nullptr;
    for (int i = 0; i != n; ++i)
    {
        ListNode newNode = creatNode();
        if (head->next == nullptr)
        {
            head->next = newNode;
            newNode->prior = head;
            tail = newNode;
        }
        else
        {
            newNode->prior = tail;
            tail->next = newNode;
            tail = tail->next;
        }
    }
}

// 查找节点（返回前一个节点）
ListNode findNode(ListNode head, int data)
{
    ListNode current = head->next; // 跳过头结点
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
    ListNode prev = current->prior;
    ListNode next = current->next;
    if (next == nullptr)
    {
        prev->next = next;
        delete current;
    }
    else
    {
        prev->next = next;
        next->prior = prev;
        delete current;
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
    newNode->prior = current->prior;
    newNode->next = current;
    current->prior->next = newNode;
    current->prior = newNode;
    if (head->next == current)
        head->next = newNode;
}

// 销毁链表
void destroyList(ListNode head)
{
    ListNode current = head;
    while (head != nullptr)
    {
        current = head->next;
        delete head;
        head = current;
    }
}

// 遍历链表
void printList(ListNode head)
{
    ListNode current = head->next;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
}

int main()
{
    ListNode head = new Node;
    creatLinkList(head, 3);
    printList(head);

    insertNode(head);
    printList(head);

    deleteNode(head);
    printList(head);

    return 0;
}
 */

//*********************************************单项循环链表
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
    cout << "Please enter data : ";
    int data = 0;
    cin >> data;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// 创建链表
void creatLinkList(ListNode head, int n)
{
    head->next = head;
    ListNode tail = nullptr;
    for (int i = 0; i != n; ++i)
    {
        ListNode newNode = creatNode();
        if (head->next == head)
        {
            head->next = newNode;
            newNode->next = head;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->next = head;
            tail = tail->next;
        }
    }
    // return head;
}

// 查找
ListNode findPreNode(ListNode head, int data)
{
    ListNode current = head->next;
    ListNode prev = head;
    while (current != head)
    {
        if (current->data == data)
            return prev;
        current = current->next;
        prev = prev->next;
    }
    return nullptr;
}

// 删除节点
void deleteNode(ListNode head)
{
    cout << "Please enter data that will be deleted: ";
    int data = 0;
    cin >> data;
    ListNode prev = findPreNode(head, data);
    ListNode toDelete = prev->next;
    ListNode next = toDelete->next;
    prev->next = next;
    delete toDelete;
}

// 插入节点
void insertNode(ListNode head)
{
    cout << "Please enter data will be fond: ";
    int data = 0;
    cin >> data;
    ListNode prev = findPreNode(head, data);
    ListNode newNode = creatNode();
    ListNode next = prev->next;
    prev->next = newNode;
    newNode->next = next;
}

// 销毁链表
void destroyList(ListNode head)
{
    if (head == nullptr || head->next == head)
    {
        delete head;
        head = nullptr;
        return;
    }
        ListNode current = head;
        ListNode nextNode = nullptr;
        while (current->next != head)
        {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
}

// 判断链表是否为空
bool emptyList(ListNode head)
{    if (head->next == head || head == nullptr)
    {
        cout << "**********************" << endl;
        return true;
    }
    else
    {
        cout << "nullptr" << endl;
        return false;
    }

}

// 打印链表
void printList(ListNode head)
{
    ListNode current = head->next;
    while (current != head)
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
    destroyList(Head);
    Head = nullptr;


    return 0;
}
 */

//****************************************双向循环链表
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
    head->next = head;
    head->prior = nullptr;
    ListNode tail = nullptr;
    for (int i = 0; i != n; ++i)
    {
        ListNode newNode = creatNode();
        if (head->next == head)
        {
            head->next = newNode;
            head->prior = newNode;
            newNode->prior = head;
            newNode->next = head;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prior = tail;
            newNode->next = head;
            tail = tail->next;
            head->prior = newNode;
        }
    }
}
// 查找节点
ListNode findNode(ListNode head, int data)
{
    ListNode current = head->next;
    while (current != head)
    {
        if (current->data == data)
            return current;
        else
            current = current->next;
    }
    return nullptr;
}

// 删除节点
void deleteNode(ListNode head)
{
    cout << "请输入待删除的节点数据：";
    int data = 0;
    cin >> data;
    ListNode current = findNode(head, data);
    ListNode prev = current->prior;
    ListNode next = current->next;
    prev->next = next;
    next->prior = prev;
    delete current;
}

// 插入节点
void insertNode(ListNode head)
{
    cout << "请输入在那个数据之前插入：";
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
//销毁链表
void destroyList(ListNode head)
{
    ListNode current = head->next;
    ListNode temp = current->next;
    do
    {
        delete current;
        current = temp;
        temp = current->next;
    } while (current != head);
    head = nullptr;
}

// 打印节点数据
void printNode(ListNode head)
{
    ListNode current = head->next;
    // ListNode prev = nullptr;
    do
    {
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
    return 0;
} */

/*
#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    Node *next;
} *Stack;

typedef struct LinkStack
{
    Stack top;
    int count = 0;
} LinkStack;

void push(LinkStack top)
{
    Stack newNode = new Node;
    if (newNode == nullptr)
        return;
    cout << "Please enter the new data: ";
    int data = 0;
    cin >> data;
    newNode->data = data;

} */

/*

#include<iostream>
#define MAXSIZE 10
using namespace std;

typedef struct Stack
{
    int *top;
    int *base;
    int stackSize; // 用来标记栈的可使用的最大容量
} Stack;

//初始化栈（建立一个空栈）
void initialStack(Stack &s)
{
    s.base = new int[MAXSIZE];
    s.top = s.base;
    s.stackSize = MAXSIZE;
}

//判断栈是否为空栈
bool emptyStack(Stack &s)
{
    if(s.top - s.base)
        return false;
    else
        return true;
}

//判断栈是否为满栈
bool fullStack(Stack &s)
{
    if(s.top - s.base == s.stackSize)
        return true;
    else
        return false;
}

//得到栈的长度
int stackLength(Stack &s)
{
    return s.top - s.base;
}

//入栈
void push(Stack &s)
{
    if(s.top - s.base == s.stackSize)
        cout << "Push failed!!!" << endl;
    cout << "Please enter the data: ";
    int data = 0;
    cin >> data;
    *s.top++ = data;
}

//出栈并弹出栈顶元素
int pop(Stack &s)
{
    if(s.top == s.base)
        cout << "Pop failed!!!";
    int data = 0;
    data = *--s.top;
    return data;
}

//清空栈
void clearStack(Stack &s)
{
    s.top = s.base;
}

//销毁栈
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
    if(emptyStack(s))
        cout << "s是空栈!!!" << endl;
    else
        cout << "s不是空栈!!!" << endl;
    for (int i = 0; i != 5; ++i)
    {
        push(s);
    }
    while(s.top != s.base)
        cout << pop(s) << " ";
    cout << endl;

    if (emptyStack(s))
        cout << "s是空栈!!!" << endl;
    else
        cout << "s不是空栈!!!" << endl;

    cout << stackLength(s) << endl;

    return 0;
} */

//*************************************栈的实现（链表）
/* #include <iostream>
using namespace std;

typedef struct stackNode
{
    int data;
    stackNode *next;
} *LinkStack;

// 初始化链栈
void initialStack(LinkStack &s)
{
    s = nullptr;
}

// 判断链栈是否为空
bool emptyStack(LinkStack &s)
{
    if (s != nullptr)
        return false;
    else
        return true;
}

// 入栈
void push(LinkStack &s)
{
    LinkStack newNode = new stackNode;
    cout << "Please enter the new data: ";
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
    LinkStack temp = s->next;
    delete s;
    s = temp;
}

// 获取栈顶元素
int getTopData(LinkStack &s)
{
    return s->data;
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
    if (emptyStack(s))
        cout << "链栈为空！！！" << endl;
    else
        cout << "链栈不为空！！！" << endl;
    for (int i = 0; i != 5; ++i)
    {
        push(s);
    }

    if (emptyStack(s))
        cout << "链栈为空！！！" << endl;
    else
        cout << "链栈不为空！！！" << endl;

    for (int i = 0; i != 5; ++i)
    {
        cout << getTopData(s) << " ";
        pop(s);
    }

    cout << endl;

    if (emptyStack(s))
        cout << "链栈为空！！！" << endl;
    else
        cout << "链栈不为空！！！" << endl;

    return 0;
}
 */

/*
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <search.h>
#include <iostream>
using namespace std;

typedef struct Pair
{
    int key;
    char value[20];
} DATA, *LPDATA;

typedef struct HashTable
{
    LPDATA *table; // 可以理解为table为一个数组，里面存放的每个元素都是一个指向LpData的指针
    int divisor;
    int curSize;
} HASH, *LPHASH;

int Hash(int key, int tableSize)
{
    return key % tableSize;
}

LPHASH creatHashTable(int tableSize)
{
    LPHASH hash = new HASH;
    hash->curSize = 0;
    hash->divisor = tableSize;
    hash->table = new LPDATA[tableSize];
    for (int i = 0; i != tableSize; ++i)
    {
        hash->table[i] = nullptr;
    }
    return hash;
}

int search(LPHASH hash, int key)
{
    int pos = Hash(key, hash->divisor);
    int curPos = pos;
    do
    {
        if (hash->table[curPos] == nullptr || hash->table[curPos]->key == key)
            return curPos;
        else
            curPos = (curPos + 1) % hash->divisor;
    } while (curPos != pos);
    return curPos;
}


void insert(LPHASH hash)
{
    DATA data;
    cout << "Please enter the new data: ";
    cin >> data.key >> data.value;
    int pos = search(hash, data.key);
    if (hash->table[pos] == nullptr)
    {
        hash->table[pos] = new DATA;
        memcpy(hash->table[pos], &data, sizeof(DATA));
        hash->curSize++;
    }
    else
    {
        if (hash->table[pos]->key == data.key)
        {
            strcpy(hash->table[pos]->value, data.value);
        }
        else
        {
            cout << "Table full!!!" << endl;
            return;
        }
    }
}

void printHash(LPHASH hash)
{

    for (int i = 0; i != hash->divisor; ++i)
    {
        if (hash->table[i] == nullptr)
            cout << "nullptr!" << endl;
        else
            cout << hash->table[i]->key << ": " << hash->table[i]->value << endl;
    }
}

int main()
{
    cout << "Please enter the data numbers: ";
    int numbers = 0;
    cin >> numbers;
    int tableSize = 2 * numbers + 1;
    LPHASH hash = creatHashTable(tableSize);
    for (int i = 0; i != numbers; ++i)
    {
        insert(hash);
    }
    cout << "The table's data numbers : " << hash->curSize << endl;
    printHash(hash);
    int key = 0;
    cout << "Please enter the key to search value: ";
    cin >> key;
    cout << hash->table[search(hash,key)]->value;
    return 0;
}
 */

/* #include <iostream>
#include <cstring>

using namespace std;

typedef struct NODE
{
    int key;
    char value[20];
    NODE *next;
} NODE, *ListNode;

typedef struct Hash
{
    ListNode *table;
    int divisor;

} HASH, *HashTable;

int Hash(int key, int tableSize)
{
    return key % tableSize;
}

HashTable creatHashTable(int num)
{
    HashTable hash = new HASH;
    hash->divisor = num;
    hash->table = new ListNode[num];
    for (int i = 0; i != num; ++i)
    {
        hash->table[i] = nullptr;
    }
    return hash;
}

void insertData(HashTable hash, int key, char *value)
{
    int pos = Hash(key, hash->divisor);
    ListNode newNode = new NODE;
    newNode->key = key;
    strcpy(newNode->value, value);
    newNode->next = nullptr;
    ListNode *tail = &hash->table[pos];
    while (*tail != nullptr)
        tail = &(*tail)->next;
    *tail = newNode;
}

char *search(HashTable hash, int key)
{
    int pos = Hash(key, hash->divisor);
    ListNode current = hash->table[pos];
    while (current != nullptr)
    {
        if (current->key == key)
        {
            return current->value;
        }
        else
        {
            cout << "No data!!!" << endl;
            return nullptr;
        }
    }
    return 0;
}

void deleteData(HashTable hash, int key)
{
    int pos = Hash(key, hash->divisor);
    ListNode current = hash->table[pos];
    ListNode prev = nullptr;
    while (current != nullptr)
    {
        if (current->key == key)
        {
            if (prev == nullptr)
            {
                hash->table[pos] = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

void printTable(HashTable hash)
{
    for (int pos = 0; pos != hash->divisor; ++pos)
    {
        if (hash->table[pos] == nullptr)
            cout << "nullptr!" << endl;
        else
        {
            ListNode current = hash->table[pos];
            do
            {
                cout << current->key << " : " << current->value << endl;
                current = current->next;
            } while (current != nullptr);
        }
    }
}

void destroyTable(HashTable hash)
{
    if(hash!=nullptr)
    {
        for (int i = 0; i != hash->divisor; ++i)
        {
            ListNode current = hash->table[i];
            while (current != nullptr)
            {
                ListNode next = current->next;
                delete current;
                current = next;
            }
        }
        delete[] hash->table;
        delete (hash);
    }
}

int main()
{
    cout << "Please enter the data numbers: ";
    int numbers = 0;
    cin >> numbers;
    int tableSize = 2 * numbers + 1;
    HashTable hash = creatHashTable(tableSize);
    for (int i = 0; i != numbers; ++i)
    {
        cout << "Please enter the new data: ";
        int key = 0;
        char value[20];
        cin >> key;
        cin >> value;
        insertData(hash, key, value);
    }
    printTable(hash);
    cout << "Please enter the data to delete: ";
    int key = 0;
    cin >> key;
    deleteData(hash, key);
    printTable(hash);
    destroyTable(hash);
    return 0;
}
 */

/* #include <iostream>
#include <cstring>
using namespace std;

typedef struct Node
{
    int key;
    char value[20];
    Node *next;
} NODE, *ListNode;

typedef struct Hash
{
    ListNode *table;
    int divisor;
} HASH, *HashTable;

int Hash(int key, int divisor)
{
    return key % divisor;
}

HashTable creatHashTable(int num)
{
    HashTable hash = new HASH;
    hash->divisor = num;
    hash->table = new ListNode[num];
    for (int i = 0; i != num; ++i)
    {
        hash->table[i] = nullptr;
    }
    return hash;
}

char *search(HashTable hash, int key)
{
    int pos = Hash(key, hash->divisor);
    ListNode current = hash->table[pos];
    while (current != nullptr)
    {
        if (current->key == key)
        {
            return current->value;
        }
        else
            current = current->next;
    }
    cout << "No data!!!" << endl;
    return nullptr;
}

void insert(HashTable hash, int key, char *value)
{
    int pos = Hash(key, hash->divisor);
    ListNode newNode = new NODE;
    newNode->key = key;
    strcpy(newNode->value, value);
    newNode->next = nullptr;
    newNode->next = hash->table[pos];
    hash->table[pos] = newNode;
}

void deleteData(HashTable hash, int key)
{
    int pos = Hash(key, hash->divisor);
    ListNode current = hash->table[pos];
    ListNode prev = nullptr;
    while (current != nullptr)
    {
        if (current->key == key)
        {
            if (prev == nullptr)
            {
                hash->table[pos] = current->next;
                delete current;
            }
            else
            {
                prev->next = current->next;
                delete current;
            }
        }
        prev = current;
        current = current->next;
    }
}

void printHashTable(HashTable hash)
{
    for (int i = 0; i != hash->divisor; ++i)
    {
        if (hash->table[i] == nullptr)
            cout << "nullptr!" << endl;
        else
        {
            ListNode current = hash->table[i];
            while (current != nullptr)
            {
                cout << current->key << " : " << current->value << endl;
                current = current->next;
            }
        }
    }
}

void destroyHashTable(HashTable hash)
{
    for (int i = 0; i != hash->divisor; ++i)
    {
        ListNode current = hash->table[i];
        while (current != nullptr)
        {
            ListNode next = current->next;
            delete current;
            current = next;
        }
    }
    delete[] hash->table;
    delete hash;
}

int main()
{
    cout << "Please enter the data's numbers: ";
    int numbers = 0;
    cin >> numbers;
    int tableSize = 2 * numbers + 1;
    HashTable hash = new HASH;
    hash = creatHashTable(tableSize);

    for (int i = 0; i != numbers; ++i)
    {
        cout << "Please enter the new data: ";
        int key;
        char value[20];
        cin >> key >> value;
        insert(hash, key, value);
    }
    printHashTable(hash);
    cout << "Please enter delete numbers :";
    int n;
    cin >> n;
    for (int i = 0; i != n; ++i)
    {
        cout << "Please enter the ID to delete: ";
        int ID;
        cin >> ID;
        deleteData(hash, ID);
    }
    printHashTable(hash);
    destroyHashTable(hash);
    return 0;
} */

/*
#include <iostream>
#define MAXSIZE 100
using namespace std;

typedef struct Stack
{
    int *top;
    int *base;
    int maxStackSize;
} Stack;

// 栈的初始化
void initialStack(Stack &s)
{
    s.base = new int[MAXSIZE];
    s.top = s.base;
    s.maxStackSize = MAXSIZE;
}

// 判断栈是否为空栈
bool emptyStack(Stack s)
{
    if (s.top == s.base)
    {
        cout << "栈为空！！！" << endl;
        return true;
    }
    else
    {
        cout << "栈不为空！！！" << endl;
        return false;
    }
}

// 判断栈是否为满栈
bool fullStack(Stack s)
{
    return s.top - s.base == s.maxStackSize;
}

// 得到栈的长度（栈内元素个数）
int getStackLength(Stack s)
{
    return s.top - s.base;
}

// 入栈
void push(Stack &s)
{
    if (s.top - s.base == s.maxStackSize)
    {
        cout << "栈已经满了，入栈失败！！！" << endl;
        return;
    }
    int data = 0;
    cout << "请输入准备入栈的数据：";
    cin >> data;
    *s.top++ = data;
}

// 出栈并返回出栈元素
int pop(Stack &s)
{
    if (s.top == s.base)
    {
        cout << "栈为空，出栈失败！！！";
        return -1;
    }
    int data = 0;
    data = *--s.top;
    return data;
}

// 清空栈（并不销毁，只是让栈内无元素）
void clearStack(Stack &s)
{
    s.top = s.base;
}

// 销毁栈
void destroyStack(Stack &s)
{
    delete s.base;
    s.maxStackSize = 0;
    s.base = s.top = nullptr;
}

int main()
{
    Stack s;
    initialStack(s);
    emptyStack(s);
    cout << "请输入待入栈元素个数：";
    int numbers = 0;
    cin >> numbers;
    for (int i = 0; i != numbers; ++i)
    {
        push(s);
    }
    emptyStack(s);
    cout << "当前栈内元素个数为：" << getStackLength(s) << endl;

    cout << "请输入待弹出元素个数：";
    int n = 0;
    cin >> n;
    for (int i = 0; i != n; ++i)
    {
        cout << pop(s) << " ";
    }
    cout << endl;
    emptyStack(s);

    return 0;
}
*/
/* 
#include <iostream>
#define MAXSIZE 5    //队列可容纳的最大元素个数
using namespace std;

typedef struct Queue
{
    int *base;     //动态数组，用于给队列分配空间
    int front;     //利用索引来模拟头指针
    int rear;      //利用索引来模拟尾指针
    int count;     //用来判断队列内当前元素个数
} Queue;

// 判断队列是否为空
bool emptyQueue(Queue q)
{
    if (q.front == q.rear)      //若头指针与尾指针相同，则队列为空
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
void initialQueue(Queue &q)
{
    q.base = new int[MAXSIZE];  // 为队列分配空间
    q.front = q.rear = 0;       //初始化头指针、尾指针的索引为0
    q.count = 0; 
}

// 入队
void push(Queue &q)
{
    cout << "请输入待入队的数据：";
    int data = 0;
    cin >> data;
    q.base[q.rear++] = data;   //q.rear为索引，如果是第一个元素，将data放到数组索引为0的位置，并让rear向后移一位
    q.count++; //队列内元素数量+1
}

// 出队并返回队头元素
int pop(Queue &q)
{
    int data = 0;
    data = q.base[q.front++]; //q.front为索引，依次从索引0处开始出队，并让front递增
    q.count--;      //出队后元素数量-1；
    return data;
}

// 销毁队列
void destroyQueue(Queue &q)
{
    delete[] q.base;     //由于初始化时分配的为数组大小的空间，这里要删除数组大小的空间
    q.front = q.rear = 0;
    q.count = 0;
}

// 判断对列是否已满
bool fullQueue(Queue q)
{
    if (q.count == MAXSIZE)  //判断队列内当前元素数量是否与队列最大可容纳数量相同
    {
        cout << "队列已满，无法添加元素！！！" << endl;
        return true;
    }
    else
    {
        cout << "队列未满，还可添加 " << MAXSIZE - q.count << "个元素！！！" << endl;
        return false;
    }
}

int main()
{
    Queue q;
    initialQueue(q);
    emptyQueue(q);
    cout << "请输入待入队的元素个数：";
    int numbers = 0;
    cin >> numbers;
    for (int i = 0; i != numbers; ++i)
    {
        push(q);
    }
    emptyQueue(q);
    cout << "请选择出队元素个数：";
    int n = 0;
    cin >> n;
    for (int i = 0; i != n; ++i)
    {
        cout << pop(q) << " ";
    }
    cout << endl;
    fullQueue(q);
    destroyQueue(q);
    return 0;
} */
/* 

#include<iostream>
using namespace std;

//与单链表的定义一样
typedef struct QueueNode
{
    int data;    
    QueueNode *next;
} QueueNode, *QueuePtr;

typedef struct ListQueue
{
    QueuePtr front;     //指向QueueNode类型的头指针
    QueuePtr rear;      //指向QueueNode类型的尾指针
} ListQueue;

//初始化队列
void initialQueue(ListQueue &q)
{
    q.front = q.rear = new QueueNode;   //此时为头指针与尾指针分配了一块空间，相当于链表中的头结点，用来简化入队与出队的操作
    q.rear->next = nullptr;  //将尾指针的next域置空
}

//判断队列是否为空
bool emptyQueue(ListQueue q)
{
    if(q.front == q.rear)       //如果头尾指针指向同一块位置，则队列为空
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

//入队
void push(ListQueue &q)
{
    cout << "请输入待入队数据：";
    int data = 0;
    cin >> data;
    QueuePtr p = new QueueNode;     //new一块空间用来添加元素
    p->data = data;
    p->next = nullptr;
    q.rear->next = p;      //入队时只需要对尾指针进行操作
    q.rear = p;            //更新尾指针
}

//获取队头元素
int getQueueData(ListQueue q)
{
    return q.front->data;     //获取队头元素时需要跳过头结点，头结点内不存储数据
}

//出队并获取队头元素
int pop(ListQueue &q)
{
    int data = 0;
    QueuePtr temp = q.front->next;    //保存待出队节点的下一节点地址
    data = temp->data;                //获取带出队节点的数据
    q.front->next = temp->next;       //架空待出队结点，因为在出队后，结点要被删除
    if(temp == q.rear)       //重要操作，此操作可用来判断队列在执行相同次数的入队与出队后队列是否为空
        q.front = q.rear;
    delete temp;
    return data;
}

//销毁链队
void destroyQueue(ListQueue &q)
{
    while(q.front)        //当队列为空时，表示队列已经从队头销毁到了队尾
    { 
        QueuePtr temp = q.front->next;   //记录下一节点位置
        delete q.front; //删除当前节点
        q.front = temp; //更新节点
    }
}

int main()
{
    ListQueue q;
    initialQueue(q);
    emptyQueue(q);
    cout << "请输入待入队的元素个数：";
    int numbers = 0;
    cin >> numbers;
    for (int i = 0; i != numbers; ++i)
    {
        push(q);
    }
    emptyQueue(q);
    cout << "请输入待出队的元素个数:";
    int n = 0;
    cin >> n;
    for (int i = 0; i != n; ++i)
    {
        cout << pop(q) << " ";
    }
    cout << endl;
    emptyQueue(q);
    //destroyQueue(q);  //此操作在队列所有元素出队完以后不可在调用
    return 0;
} */


#include<iostream>
#define MAXSIZE 5
using namespace std;

typedef struct Queue
{
    int *base;
    int front;
    int rear;
} Queue;

//判断队列是否为空
bool emptyQueue(Queue &q)
{
    if (q.front == q.rear)    //若尾指针与头指针指向位置相同，链队则为空
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

// 判断队列是否满队
bool fullQueue(Queue &q)
{
    if ((q.rear + 1) % MAXSIZE == q.front)    //如果尾指针的下一位置是头指针，则链队为满
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

// 初始化队列
void initialQueue(Queue &q)
{
    q.base = new int[MAXSIZE];
    q.front = q.rear = 0;
}

// 入栈
void push(Queue &q)
{
    cout << "请输入带入队元素个数: ";
    int data = 0;
    cin >> data;
    q.base[q.rear] = data;
    q.rear = (q.rear + 1) % MAXSIZE;    //在入队后，尾指针再向后移位的时候会自动跳过最后一个队列空间，因为要实现循环队列，队列最后一个空间不存储数据
}

// 出栈并获取栈顶元素
int pop(Queue &q)
{
    int data = 0;
    data = q.base[q.front];
    q.front = (q.front + 1) % MAXSIZE;   //出队时，跳过不存储数据的空间
    return data;
}

// 销毁栈
void destroyQueue(Queue &q)
{
    delete[] q.base;      //销毁已开辟的数组空间
    q.front = q.rear = 0;
}

// 获取队列长度
int queueLength(Queue &q)
{
    return (q.rear - q.front + MAXSIZE) % MAXSIZE;  //这一操作避免了队尾指针在队头指针前而出现的负数的情况
}


int main()
{
    Queue q;
    initialQueue(q);
    emptyQueue(q);
    cout << "请输入待入队的元素个数：";
    int numbers = 0;
    cin >> numbers;
    for (int i = 0; i != numbers; ++i)
    {
        push(q);
    }
    emptyQueue(q);
    cout << "请选择出队元素个数：";
    int n = 0;
    cin >> n;
    for (int i = 0; i != n; ++i)
    {
        cout << pop(q) << " ";
    }
    cout << endl;
    emptyQueue(q);
    fullQueue(q);
    destroyQueue(q);
    return 0;

}
