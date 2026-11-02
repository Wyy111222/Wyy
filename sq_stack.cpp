#include<iostream>
using namespace std;
typedef int DataType;
struct Stack
{
    int top;
    int maxsize;
    DataType* elements;
};
//初始化一个空的顺序栈
bool InitStack(Stack &s,int size)
{
    if(size<=0)
        return false;
    s.maxsize=size;
    s.elements=new DataType[size];
    s.top=-1;  //-1代表空栈
    return true;
}
//判断顺序栈是否为空
bool IsEmpty(Stack &s)
{
    return s.top==-1;
}
//判断顺序栈是否满
bool IsFull(Stack &s)
{
    return s.top==s.maxsize-1;
}
//入栈
bool Push(Stack &s,DataType x)
{
    if(IsFull(s))
    {
        cout << "栈满，入栈失败!" <<endl;
        return false;
    }
    s.top++;
    s.elements[s.top]=x;
    return true;
}
//出栈，出栈元素用引用参数x带回
bool Pop(Stack &s,DataType &x)
{
    if(IsEmpty(s))
    {
        cout << "栈空，出栈失败！" << endl;
        return false;
    }
    x=s.elements[s.top];
    s.top--;
    return true;
}
//获取栈顶元素值(不删除栈顶)
bool GetTop(Stack &s,DataType &x)
{
    if(IsEmpty(s))
    {
        cout << "栈空，无栈顶元素!" << endl;
        return false;
    }
    x=s.elements[s.top];
    return true;
}
//销毁栈
void DestroyStack(Stack &s)
{
    if (s.elements != nullptr)
    {
        delete[]s.elements;
        s.elements=nullptr;
    }
    s.top=-1;
    s.maxsize=0;
}
//测试主函数
int main()
{
    Stack st;
    InitStack(st,5);
    Push(st,10);
    Push(st,20);
    Push(st,30);
    int val;
    if(GetTop(st,val))
        cout << "栈顶元素:" << val << endl;
    if(Pop(st,val))
        cout << "出栈元素:" << val << endl;
    if(GetTop(st,val))
        cout << "新栈顶元素:" << val << endl;
    if(IsEmpty(st))
        cout << "栈为空" << endl;
    else
        cout << "栈不为空" << endl;
    DestroyStack(st);
    return 0;
}
