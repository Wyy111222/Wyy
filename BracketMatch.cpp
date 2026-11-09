#include <iostream>
#include <string>
using namespace std;
typedef char DataType;
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
    return top==nullptr;
}
bool Push(LinkStack* &top,DataType val)
{
    LinkStack* newNode=new LinkStack;
    if(newNode==nullptr)
    {
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
        return false;
    }
    LinkStack* p=top;
    val=p->data;
    top=top->next;
    delete p;
    return true;
}
bool GetTop(LinkStack* top, DataType &val)
{
    if(IsEmpty(top))
    {
        return false;
    }
    val=top->data;
    return true;
}
bool IsValid(string s)
{
    LinkStack* stack=InitStack();
    bool flag=true;
    int i=0;
    char ch;
    char topCh;
    while(i<s.size() && flag==true)
    {
        ch=s[i];
        if(ch=='('||ch=='['||ch=='{')
        {
            Push(stack,ch);
        }
        else if(ch==')')
        {
            if(!IsEmpty(stack) && GetTop(stack,topCh) && topCh=='(')
            {
                Pop(stack,topCh);
            }
            else
            {
                flag=false;
            }
        }
        else if(ch==']')
        {
            if(!IsEmpty(stack) && GetTop(stack,topCh) && topCh=='[')
            {
                Pop(stack,topCh);
            }
            else
            {
                flag=false;
            }
        }
        else if(ch=='}')
        {
            if(!IsEmpty(stack) && GetTop(stack,topCh) && topCh=='{')
            {
                Pop(stack,topCh);
            }
            else
            {
                flag=false;
            }
        }
        i++;
    }
    if(IsEmpty(stack) && flag==true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    string str;
    cin >> str;
    if(IsValid(str))
    {
        cout << "该字符串是有效括号！" << endl;
    }
    else
    {
        cout << "该字符串不是有效括号！" << endl;
    }
    return 0;
}
