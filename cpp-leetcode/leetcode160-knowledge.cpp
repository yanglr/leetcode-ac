// list.c, 参考: 正月点灯笼(黄浩杰)的实现
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

int get_list_length(Node *list)
{
    Node *p = list;
    int length = 0;
    while (p != NULL)
    {
        ++length;
        p = p->next;
    }
    return length;
}

/* 先移动gapLen的距离 */
Node* relocate_first_node(Node * list, int offset)
{
    Node *p = list;
    int i;
    for (i = 0; i < offset; i++)
    {
        p = p->next;
    }
    return p;
}

Node* find_common_node(Node *list1, Node *list2)
{
    int length1 = get_list_length(list1);
    int length2 = get_list_length(list2);
    Node *long_list = list1;
    Node *short_list = list2;
    if (length2 > length1)
    {
        long_list = list2;
        short_list = list1;
    }

    int offset = abs(length1 - length2);
    Node *p1 = relocate_first_node(long_list, offset);
    Node *p2 = short_list;
    while (p1 != NULL)
    {
        if (p1 == p2)
        {
            return p1;
        }
        
        p1 = p1->next;            
        p2 = p2->next;
    }
    
    return NULL;
}

int main()
{
    Node n1, n2, n3, n4, n5, n6, n7;
    n1.value = 1;
    n2.value = 2;
    n3.value = 3;
    n4.value = 4;
    n5.value = 5;
    n6.value = 6;
    n7.value = 7;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = NULL;
    n7.next = &n4;
    Node* list1 = &n1;
    Node* list2 = &n7;
    printf("list1 length: %d\n", get_list_length(list1));
    printf("list2 length: %d\n", get_list_length(list2));

    Node* common = find_common_node(list1, list2);
    printf("common node = %d\n", common->value);
    
    return 0;
}