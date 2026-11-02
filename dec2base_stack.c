#include <stdio.h>
#define MAXSIZE 100
// 定义顺序栈
typedef struct
{
    int data[MAXSIZE];
    int top;   // 栈顶指针，-1代表空栈
}Stack;
// 初始化栈
void InitStack(Stack *s)
{
    s->top=-1;
}
// 入栈
int Push(Stack *s,int val)
{
    if(s->top==MAXSIZE-1)
    {
        printf("栈满！\n");
        return 0;
    }
    s->data[++s->top]=val;
    return 1;
}
// 出栈
int Pop(Stack *s,int *val)
{
    if(s->top==-1)
    {
        return 0;
    }
    *val=s->data[s->top--];
    return 1;
}
// 十进制转base进制函数
void DecToBase(int number,int base)
{
    Stack st;
    InitStack(&st);
    int rem;
    // 处理负数
    if(number<0)
    {
        printf("-");
        number=-number;
    }
    if(number==0)
    {
        printf("0");
        return;
    }
    // 除基取余，余数入栈
    while(number!=0)
    {
        rem=number%base;
        Push(&st,rem);
        number=number/base;
    }
    // 出栈输出
    while(st.top!=-1)
    {
        Pop(&st,&rem);
        printf("%d",rem);
    }
}
int main()
{
    int num,base;
    printf("请输入十进制整数：");
    scanf("%d",&num);
    printf("请输入目标进制base(2~9)：");
    scanf("%d",&base);
    if(base <2 || base>9)
    {
        printf("进制范围错误！base必须2~9\n");
        return 1;
    }
    printf("转换结果：");
    DecToBase(num,base);
    printf("\n");
    return 0;
}