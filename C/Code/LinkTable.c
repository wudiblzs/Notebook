// 代码源自苏小红老师的C语言程序设计12.8
#include <stdio.h>
#include <stdlib.h>
struct link *AppendNode(struct link *head);
struct link *DeleteNode(struct link *head, int nodeData);
struct link *InsertNode(struct link *head, int nodeData);
void DisplyNode(struct link head);
void DeleteMemory(struct link head);
struct link
{
    // 数据域
    int data;
    // 指针域
    struct link *next;
};
int main(void)
{
    int i = 0;
    char c;
    struct link *head = NULL;   // 链表头指针
    printf("Do you want to append a new  node(Y/N)?");
    scanf(" %c", &c);           // %c前有一个空格
    while (c == 'y' || c == 'Y')
    {
        head = AppendNode(head);
        DisplyNode(head);
        printf("Do you want to append a new  node(Y/N)?");
        scanf(" %c", &c);  
        i++;
    }
    printf("%d new nodes have been appended!\n", i);
    DeleteMemory(head);
    return 0;
}

struct link *AppendNode(struct link *head)
{
   
    struct link *p = NULL, *pr = head;
    int data;
    p = (struct link *)malloc(sizeof(struct link));
    if (p == NULL)
    {
        printf("No enough memory to allocate!\n");
        exit(0);
    }
    if (head == NULL)
    {
        head = p;
    }
    else
    {
        while (pr->next != NULL)        // 若未到表尾，则移动pr直到pr指向表尾
        {   
            pr = pr->next;
        }
        pr->next = p;
    }
    printf("Input node data:");
    scanf("%d", &data);
    p->data = data;
    p->next = NULL;
    return head;
}

void DisplyNode(struct link head)
{
    struct link *p = head;
    int j = i;
    while (p != NULL)
    {
        printf("%5d%10d\n", j, p->data);
        p = p->next;
        j++;
    }
    
}

void DeleteMemory(struct link head)
{
    struct link *p = head, *pr = NULL;
    while (p != NULL)   
    {
        pr = p;
        p = p->next;
        free(pr);
    }
    
}

struct link *DeleteNode(struct link *head, int nodeData)
{
    // 函数功能：从head指向的链表中删除一个节点，返回删除节点后的链表的头指针
    struct link *p = head, *pr = head;
    if (p = NULL)
    {
        printf("Linkeed Table is empty!\n");
        return head;
    }
    while (nodeData != p->data && p->next != NULL)
    {                                   // 未找到且未到表尾
        pr = p;                         // pr中保存当前节点的指针
        p = p->next;                    // p指向当前节点的下一节点
    }
    if (nodeData == p->data)
    {
        if (p == head)
        {
            head = p->next;             // 让头指针指向待删除节点p的下一节点
        }
        else
        {
            pr->next = p->next;         // 让前一节点的指针域指向待删除节点的下一节点
        }
        free(p);
    }
    else                                // 找到表尾仍未发现节点值为nodeData的节点
    {
        printf("This Node has not been found!\n");
    }
    return head;
}

struct link *InsertNode(struct link *head, int nodeData)
{
    struct link *pr = head, *p = head, *temp = NULL;
    p = (struct link *)malloc(sizeof(struct link));     
    if (p == NULL)
    {
        printf("No memory!\n");
        exit(0);
    }
    p->next = NULL;
    p->data = nodeData;
    if (head = NULL)
    {
        head = p;                       // 待插入节点作为头节点
    }
    else                                // 若原列表非空
    {                                   // 若未找到待插入节点的位置且未到表尾，则继续找
        while (pr->data < nodeData && pr->next != NULL)
        {
            temp = pr;                  // 在temp中保存当前节点的指针 
            pr = pr->next;              // pr指向当前节点下一节点
        }
        if (pr->data >= nodeData)
        {
            if (pr == head)             // 若在表头添加新节点
            {
                p->next = head;         // 将新节点的指针域指向原链表的头节点
                head = p;               // 让head指向新节点
            }
            else                        // 若在链表中间插入新节点
            {
                pr = temp;
                p->next = pr->next;     // 将新节点的指针域指向下一个节点
                pr->next = p;           // 让前一节点的指针域指向新节点
            }
        }
        else                            // 若在表尾添加节点
        {
            pr->next = p;               // 让节点的指针域指向新节点
        }
        
        
    }
    return head;                        // 返回插入新节点后的链表头指针head的值
}
