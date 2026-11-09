#include <iostream>
using namespace std;
typedef int DataType;
struct LinkStack
{
    DataType data;
    LinkStack* next;
};
LinkStack* InitStack()
{
    return nullptr;
}
bool IsEmpty(LinkStack* top)
{
    if(top==nullptr)
        return true;
    else
        return false;
}
bool Push(LinkStack* &top,DataType val)
{
    LinkStack* newNode=new LinkStack;
    if(newNode==nullptr)
    {
        cout << "内存不足，入栈失败" << endl;
        return false;
    }
    newNode->data=val;
    newNode->next=top;
    top=newNode;
    return true;
}
bool Pop(LinkStack* &top,DataType &val)
{
    if(IsEmpty(top))
    {
        cout << "栈空，无法出栈！" << endl;
        return false;
    }
    LinkStack* p=top;
    val=p->data;
    top=top->next;
    delete p;
    return true;
}
bool GetTop(LinkStack* top,DataType &val)
{
    if(IsEmpty(top))
    {
        cout << "栈空，无栈顶元素！" << endl;
        return false;
    }
    val=top->data;
    return true;
}
int main()
{
    LinkStack* top=InitStack();
    DataType x;
    Push(top,10);
    Push(top,20);
    Push(top,30);
    GetTop(top,x);
    cout << "当前栈顶：" << x << endl;
    Pop(top,x);
    cout <<"出栈元素：" << x << endl;
    GetTop(top,x);
    cout << "出栈后栈顶：" << x << endl;
    if(IsEmpty(top))
        cout << "栈是空的" << endl;
    else
        cout << "栈不为空" << endl;
        return 0;
}