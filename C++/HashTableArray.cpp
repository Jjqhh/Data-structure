//****************************************************************哈希表实现（数组）（实例代码）
/* #include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <search.h>
using namespace std;

// 数据结构的构建（键值对）
typedef struct Pair
{
    int key;          // 键，用于快速检索或标识与之相关联的值。
    char element[20]; // 值，用于存储与key相关联的值（该值为字符串）
} DATA, *LPDATA;


// 哈希表的构建（采用取余法）（通过取余法所求的哈希地址，所产生的地址个数的范围： [0，p-1]）
typedef struct hashTable
{
    LPDATA *table; // 指向键值对的二级指针，便于初始化，以及判断当前hash地址是否冲突（如果用结构体数组充当哈希地址，不好判断空的情况）
    int divisor;   // 限定哈希地址的数目 & 存储哈希元素
    int curSize;   // 当前元素个数
} HASH, *LPHASH;

// 哈希结构的结构体描述--->用结构体指针表示哈希结构
// 创建一块空间，并将该空间初始化为NULL
LPHASH createHashTable(int p) //p为最大容量
{
    LPHASH hash = (LPHASH)malloc(sizeof(HASH)); // 动态申请内存
    assert(hash);                               // 为空则报错，异常处理
    // 给数据做初始化
    hash->curSize = 0;
    hash->divisor = p;
    // 容量由取余数决定
    //为二级指针分配空间，该空间为存放p个指针的一个数组（相当于）
    hash->table = (LPDATA *)malloc(sizeof(LPDATA) * hash->divisor);
    assert(hash->table);
    //对一级指针进行初始化（即对指向Pair类的指针进行初始化）
    for (int i = 0; i < hash->divisor; ++i) // 多个一级指针
    {
        hash->table[i] = NULL; ////二级指针申请内存后给每个一级指针做初始化
    }
    return hash;
}




// 哈希函数
// 可能会存在哈希冲突，需要找合适的位置去存放元素，不一定是直接取余，直接取余得到的地址不一定能用
// 传入键，通过键去找：因为是通过键去生成哈希地址
// 找完一圈后回到原来的位置(通过取余法)，说明没有合适的位置
// 如果 curPos + 1中没有元素，把元素放在当前位置即可
// 要找的表 传入键
int search(LPHASH hash, int key)
{
    //pos为position的简称，表示位置（在这里表示哈希地址）
    int pos = key % hash->divisor; // 不存在冲突的hash地址 正常情况
    int curPos = pos;  //传入关键字的当前哈希地址
    // 存在冲突 开放地址法做哈希地址的查找
    do
    {
        // key相同，采用覆盖的数据方式 不当做哈希冲突来做
        if (hash->table[curPos] == NULL || hash->table[curPos]->key == key)
            return curPos;                     // 判断当前位置能不能用 ==NUll说明可以用
        curPos = (curPos + 1) % hash->divisor; // 不为NULL往后走 如果后面为NULL就插到当前位置
    } while (curPos != pos); // 当前Pos不等于原来Pos就一直去做查找
    return curPos;
}
//!= 原来地址一直做查找
//== 原来地址:找完一圈后回到原来的位置说明它没有合适的位置 直接返回





// 插入数据
// 注意先申请内存再插入元素,用的是二级指针，刚刚只申请了一级指针的内存
// 要插入的表 要插入的数据
void insertData(LPHASH hash, DATA data)
{
    // 做插入前先求hash地址--->调用哈希函数                  //不存在哈希冲突
    int pos = search(hash, data.key); // 找到要存储数据的哈希地址
    if (hash->table[pos] == NULL)   // 当前下标没有数据 直接插入
    {
        hash->table[pos] = (LPDATA)malloc(sizeof(DATA)); // 注意先申请内存再拷贝元素
        memcpy(hash->table[pos], &data, sizeof(DATA));   // 内存拷贝
        hash->curSize++;
    }
    else // 存在哈希冲突
    {
        if (hash->table[pos]->key == data.key) // 键相同回到原来位置
        {
            strcpy(hash->table[pos]->element, data.element); // 用覆盖元素的方式
        }
        else // 键不同回到原来位置说明满了
        {
            printf("hash表满了,无法插入!\n");
            return;
        }
    }
}



// 打印哈希表--->打印数组
void printHash(LPHASH hash)
{
    for (int i = 0; i < hash->divisor; ++i) // 用最大容量长度做打印
    {
        if (hash->table[i] == NULL)
        {
            cout << "NULL" << endl;
        }
        else // 不为空打印元素
        {
            cout << hash->table[i]->key << " : " << hash->table[i]->element << endl;
        }
    }
}




// 测试代码
int main()
{
    LPHASH hash = createHashTable(10); // 创建哈希表
    DATA array[5] = {1, "雷电", 11, "春天", 23, "四月", 44, "baby", 56, "virtual"};
    for (int i = 0; i < 5; i++)
    {
        insertData(hash, array[i]); // 把数据插到哈希表中
    }
    printHash(hash); // 打印哈希表
    return 0;
}
 */

//*******************************************哈希表实现（数组）（哈希函数：取余法）(冲突：线性探测法)
/* #include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef struct DATA
{
    int key;       //这里的关键字key为ID，ID表示学号
    char value[20];   //这里的值value为名字name
} DATA, *LPDATA;

typedef struct HASH
{
    LPDATA *table;    //散列表，注意该散列表是指向DATA结构指针的指针
    int divisor;      //divisor为除数，即为tableSize表长
    int curSize;        
} HASH, *LPHASH;

int Hash(int key, int tableSize)
{
    return key % tableSize;
}

//创建散列（哈希）表
LPHASH creatHashTable(int tableSize)
{
    LPHASH hash = new HASH;      //new一块HASH空间给hash，此时hash指向的结构里面有HASH结构的三个元素
    hash->divisor = tableSize;   //将HASH结构里的divisor设置为表长，以后就不需要再单独得传递一个表长的参数了
    hash->curSize = 0;           //将散列表中目前的元素个数设置为0
    hash->table = new LPDATA[tableSize]; //为hash指针指向的结构HASH里的table分配表长大小的数组来存放数据
    for (int i = 0; i != tableSize; ++i)
    {
        hash->table[i] = nullptr;     //将table所分配的数组大小的空间全都设置为空
    }
    return hash;   //返回hash指针，该指针保存了分配的所有空间
}

//查找
int search(LPHASH hash, int key)
{
    int pos = Hash(key, hash->divisor);    //pos为位置position的缩写，在这里表示哈希地址
    int curPos = pos;           //创建一个当前变量用来后续的追踪判定
    do
    {
        //该if语句所判定的意思是，如果当前位置（即关键字key所映射的哈希地址）为空或者当前位置里的数据和新插入数据相同的时候，此时可以将该数据插入到该哈希地址上，此时返回这个可以插入的哈希地址curPos。否则即当前位置不为空，且当前位置上的数据与新插入的数据也不同，此时将当前位置向后移动一位进行循环判定，直到找到符合if条件的位置进行返回，如果没有找到，则返回-1表示找不到这样一个位置存储新的数据。
        if (hash->table[curPos] == nullptr || hash->table[curPos]->key == key)
        {
            return curPos;
        }
        else
            curPos = (curPos + 1) % hash->divisor;
    } while (curPos != pos);
    return -1;
}

//插入
void insert(LPHASH hash)
{
    cout << "请输入待插入的数据 :";
    DATA data;
    cin >> data.key >> data.value;
    int pos = search(hash, data.key); //通过search函数找到一个可以插入的位置
    //该if控制语句意思为：如果找到的这个可以插入的位置为空，则将数据插入进去，否则的话就是原来位置上的数据与待插入的数据相同，此时else区域块里代码将进行对原先数据的覆盖操作
    if (hash->table[pos] == nullptr)
    {
        hash->table[pos] = new DATA;
        memcpy(hash->table[pos], &data, sizeof(DATA));
        hash->curSize++;
    }
    else
    {
        if (hash->table[pos]->key == data.key)
            strcpy(hash->table[pos]->value, data.value);
        else
        {
            cout << "哈希表已满，插入失败！！！" << endl;
            return;
        }
    }
}

//删除数据
void  deleteData(LPHASH hash)
{
    cout << "请输入待删除学生的学号：";
    int key = 0;
    cin >> key;
    hash->table[search(hash, key)] = nullptr; // 通过search函数找到该关键字所映射的哈希地址，并将这一块指向该空间的指针置空
    delete hash->table[search(hash, key)];   // 删除空间上的数据
    
}

//打印数据
void printTable(LPHASH hash)
{
    for (int i = 0; i != hash->divisor; ++i)  //遍历哈希表
    {
        if (hash->table[i] == nullptr)   // 如果为存储元素，打印nullptr，否则打印数据
            cout << "nullptr" << endl;
        else
            cout << hash->table[i]->key << " : " << hash->table[i]->value << endl;
    }
}

int main()
{
    int tableSize = 11;
    LPHASH hash = creatHashTable(tableSize);
    for (int i = 0; i != 5; ++i)
    {
        insert(hash);
    }
    printTable(hash);
    cout << "请输入学生的学号进行查询：";
    int id = 0;
    cin >> id;
    cout << hash->table[search(hash, id)]->value << endl;
    deleteData(hash);
    printTable(hash);

    return 0;
}
 */


//*********************************************************************哈希表（拉链法）(尾插法)
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
    if (hash != nullptr)
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

//*******************************************************************哈希表（拉链法）（头插法）
#include <iostream>
#include <cstring>
using namespace std;

typedef struct Node
{
    int key;         //学生学号
    char value[20];  //学生姓名
    Node *next;     //指向下一结点的指针
} NODE, *ListNode;

typedef struct Hash
{
    ListNode *table;   //哈希表
    int divisor;        //用来存储表长
} HASH, *HashTable;

int Hash(int key, int divisor)
{
    return key % divisor;
}

HashTable creatHashTable(int num)
{
    HashTable hash = new HASH; // new一块HASH空间给hash，此时hash指向的结构里面有HASH结构的三个元素
    hash->divisor = num;       
    hash->table = new ListNode[num];   //为table分配表长大小的数组空间
    for (int i = 0; i != num; ++i)
    {
        hash->table[i] = nullptr;       //将数组里的每一个指针置空
    }
    return hash;
}

//查找（在这里的查找函数由于示例需要，我令它返回char*，即返回学生名字）
char *search(HashTable hash, int key)
{
    int pos = Hash(key, hash->divisor); //通过哈希函数确定哈希地址pos
    ListNode current = hash->table[pos];    //table数组里的每一个值都是一个指针，将current指向由pos确定的哈希地址处
    while (current != nullptr)   //遍历该链表（此链表为）
    {
        if (current->key == key)    //如果所查到的pos地址上的关键字相同，返回值，否则，遍历进行探测
        {
            return current->value;
        }
        else
            current = current->next;
    }
    cout << "No data!!!" << endl;
    return nullptr;
}

//头插法插入
void frontInsert(HashTable hash, int key, char *value)
{
    int pos = Hash(key, hash->divisor);    //获取哈希地址
    ListNode newNode = new NODE;           
    newNode->key = key;                 
    strcpy(newNode->value, value);
    if(hash->table[pos] == nullptr)        //如果插入的是第一个结点，让插入结点的next域置空
    {
        newNode->next = nullptr;
    }
    newNode->next = hash->table[pos];      //将第二次插入的结点指向上一次插入的结点，插到上一次插入结点的前面
    hash->table[pos] = newNode;           //将对应索引的table指针指向新插入结点，完成头插
}

//尾插法插入
void rearInsert(HashTable hash, int key, char *value)
{
    int pos = Hash(key, hash->divisor);
    ListNode newNode = new Node;
    newNode->key = key;
    strcpy(newNode->value, value);
    newNode->next = nullptr;  //至此，结点创建并设置完成
    ListNode *tail = &hash->table[pos];     //tail为二级指针，即指向table数组中pos索引所在位置的指针，因为table[pos]处存放的为指向链表的指针，所以应将table[pos]指针的地址赋给tail指针
    while(*tail != nullptr)   //对tail指针进行解引用，得到table[pos]指针，若该指针为空，则直接指向新结点
        tail = &(*tail)->next; //若不为空，则遍历链表，直到遇到链表中的尾结点，并在该尾结点的后面插入新结点，先对tail指针进行解引用，得到指向链表的指针，再对指向链表下一结点的指针进行取地址并赋给二级指针tail
    *tail = newNode;
}


void deleteData(HashTable hash, int key)
{
    int pos = Hash(key, hash->divisor);           //锁定哈希地址
    ListNode current = hash->table[pos];
    ListNode prev = nullptr;
    while (current != nullptr)                 //遍历哈希地址所对应的链表
    {
        if (current->key == key)                //若关键字相同，进行删除操作
        {
            if (prev == nullptr)              //若prev为空，说明待删除结点为第一个结点
            {
                hash->table[pos] = current->next;  //此时将哈希地址所对应的table指针指向该链表的第二结点
                delete current;   //并删除第一个结点
            }
            else    //若不是第一个结点，则链接待删除结点的前一结点与后一结点，架空待删除结点
            {
                prev->next = current->next;
                delete current;
            }
        }
        prev = current;         //更新prev指针
        current = current->next;    //更新current指针
    }
}

void printHashTable(HashTable hash)
{
    for (int i = 0; i != hash->divisor; ++i) //遍历数组
    {
        if (hash->table[i] == nullptr)
            cout << "nullptr!" << endl;
        else // 若不为空，遍历数组内指针所指向的链表
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
            ListNode next = current->next;   //记录待删除销毁结点的下一个结点位置
            delete current;                 //销毁当前结点
            current = next;  //更新current指针
        }
    } // 若成功进行遍历，此时所分配的链表结点空间均会被销毁
    delete[] hash->table;  //此时再销毁存放指向链表的指针数组
    delete hash;        //最后再销毁hash指针所指向的结点
    hash = nullptr;    //销毁后将hash指针置空，避免悬挂指针
}

int main()
{
    cout << "请输入待输入的数据个数： ";
    int numbers = 0;
    cin >> numbers;
    int tableSize = 2 * numbers + 1;
    HashTable hash = new HASH;
    hash = creatHashTable(tableSize);

    for (int i = 0; i != numbers; ++i)
    {
        cout << "请输入新的数据：";
        int key;
        char value[20];
        cin >> key >> value;
        rearInsert(hash, key, value);
    }
    printHashTable(hash);
    cout << "请输入待删除数据的个数: ";
    int n;
    cin >> n;
    for (int i = 0; i != n; ++i)
    {
        cout << "请输入待删除学生的学号： ";
        int ID;
        cin >> ID;
        deleteData(hash, ID);
    }
    printHashTable(hash);
    destroyHashTable(hash);
    return 0;
}
