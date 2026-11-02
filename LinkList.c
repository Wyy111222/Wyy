#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
typedef struct Node{
    DataType data;
    struct Node *next;
}Node ,*LinkList;
LinkList Init_LinkList(){
    LinkList head=(Node*)malloc(sizeof(Node));
    if(head==NULL) {
        printf("内存分配失败！\n");
        exit(1);
    }
    head->next=NULL;
    return head;
}
void CreateListHead(LinkList Head,int arr[],int n){
    for(int i=0;i<n;i++){
        Node*newNode=(Node*)malloc(sizeof(Node));
        newNode->data=arr[i];
        newNode->next=Head->next;
        Head->next=newNode;
    }
}
void CreateListTail(LinkList head,int arr[],int n){
    Node*tail=head;
    for(int i=0;i<n;i++){
        Node*newNode=(Node*)malloc(sizeof(Node));
        newNode->data=arr[i];
        newNode->next=NULL;
        tail->next=newNode;
        tail=newNode;
    }
}
int IsEmpty(LinkList head){
    if(head==NULL||head->next==NULL){
        return 1;
    }
    return 0;
}
int GetLength(LinkList head){
    int len=0;
    Node*p=head->next;
    while(p!=NULL){
        len++;
        p=p->next;
    }
    return len;
}
void PrintList(LinkList head){
    if(IsEmpty(head)){
        printf("链表为空\n");
        return;
    }
    Node*p=head->next;
    while(p!=NULL){
    printf("%d ",p->data);
    p=p->next;
    }
    printf("\n");
}
void DestroyList(LinkList head){
    Node*p=head;
    while(p!=NULL){
        Node*temp=p;
        p=p->next;
        free(temp);
    }
}
int main(){
    system("chcp 65001");
    int arr[]={10,20,30,40,50};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("---1.测试初始化---\n");
    LinkList L1=Init_LinkList();
    printf("初始化完成，链表是否为空?(1是/0否):%d\n",IsEmpty(L1));
    printf("当前链表长度:%d\n\n",GetLength(L1));
    printf("---2.测试头插法---\n");
    CreateListHead(L1,arr,n);
    printf("头插法结果(逆序):");
    PrintList(L1);
    printf("当前链表长度:%d\n\n",GetLength(L1));
    printf("---3.测试尾插法---\n");
    LinkList L2=Init_LinkList();
    CreateListTail(L2,arr,n);
    printf("尾插法结果(正序):");
    PrintList(L2);
    printf("当前链表长度:%d\n\n",GetLength(L2));
    printf("---4.测试是否为空---\n");
    printf("L2链表是否为空?(1是/0否):%d\n\n",IsEmpty(L2));
    DestroyList(L1);
    DestroyList(L2);
    system("pause");
    return 0;
}