#include<iostream>
#include<windows.h>
#include<cstdlib> // 需要用到 system("pause")
using namespace std;

//定义一个联系人结构体
struct Contact
{
    char name[100];        //姓名
    char phonenumber[12];  //电话
    struct Birthday
    {
        int year;
        int month;
        int day;
    }birthday;
    int age;
    char sex;
};

// 输入一个联系人信息
Contact InputContact()
{
    Contact contact;
    cout << "请输入姓名: ";
    cin >> contact.name;
    cout << "请输入电话: ";
    cin >> contact.phonenumber;
    cout << "请输入生日(年 月 日，用空格隔开): ";
    cin >> contact.birthday.year >> contact.birthday.month >> contact.birthday.day;
    cout << "请输入性别(M/F): ";
    cin >> contact.sex;
    
    contact.age = 2026 - contact.birthday.year;
    return contact;
}

//定义链表的结点结构体
struct Node{
    Contact data;   //数据域
    Node *next;     //指针域
};

// 初始化通讯录
Node* InitAddressBook()
{
    Node* head = new Node;
    if(head == nullptr)
    {
        cout << "内存分配失败" << endl;
        return nullptr;
    }
    head->next = nullptr;
    return head;
}

// 头插法
int CreateAddressBookHead(Node* head, Contact data)
{
    if(head == nullptr) return 0;
    
    Node* newNode = new Node;
    if(newNode == nullptr) return 0;
    
    newNode->data = data;
    newNode->next = head->next;
    head->next = newNode;
    return 1;
}

// 打印通讯录
void PrintAddressBook(Node* head)
{
    Node* p = head->next;
    if(p == nullptr) {
        cout << "通讯录为空！" << endl;
        return;
    }
    while(p != nullptr)
    {
        cout << "姓名：" << p->data.name << endl;
        cout << "电话：" << p->data.phonenumber << endl;
        cout << "生日：" << p->data.birthday.year << "-"
             << p->data.birthday.month << "-" << p->data.birthday.day << endl;
        cout << "性别：" << p->data.sex << " 年龄：" << p->data.age << endl;
        cout << "-------------------------" << endl;
        p = p->next;
    }
}

int main(){
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    Node* head = InitAddressBook();

    cout << "--- 输入第一个联系人 ---" << endl;
    Contact contact1 = InputContact();
    CreateAddressBookHead(head, contact1);

    cout << "\n--- 输入第二个联系人 ---" << endl;
    Contact contact2 = InputContact();
    CreateAddressBookHead(head, contact2);

    cout << "\n===== 通讯录列表 =====" << endl;
    PrintAddressBook(head);

    // 暂停程序，防止黑框瞬间关闭
    cout << "\n按任意键退出程序..." << endl;
    system("pause");

    return 0;
}
