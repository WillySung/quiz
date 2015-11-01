#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
} ListNode;

ListNode *doReverse( ListNode *head );
ListNode *reverseBetween( ListNode *head, int m, int n );

ListNode *Reverse( ListNode *head )
{
    // No element there.
    if ( head == NULL ) return NULL;
    // Only one element.
    if ( head->next == NULL ) return head;

    ListNode *right = head->next, *newHead;

    head->next = NULL;

    newHead = Reverse( right );

    right->next = head;

    return newHead;
}

ListNode *reverseBetween( ListNode *head, int m, int n )
{
    if ( m == n ) return head;

    // Extract the sub linked list which would be reversed.
    ListNode *connect, *subHead, *tail, *tmp;
    int i;

    connect = head;

    // Find the first element in the reverse interval and
    // the last element before the reverse interval
    for ( i = 1; i < m-1; ++i, connect = connect->next )
        ;

    // Find the last element in the reverse interval
    tmp = connect;
    for ( ; i < n; ++i, tmp = tmp->next )
        ;
    // Store the next element behind the reverse interval
    tail = tmp->next;
    // Cut!
    tmp->next = NULL;

    if ( m != 1 ) {
        subHead = connect->next;
        connect->next = Reverse( subHead );
    } else {
        subHead = head;
        head = Reverse( subHead );
    }

    subHead->next = tail;

    return head;
}


void print_list(ListNode *root)
{
    while (root) {
        printf("%c ", root->data);
        root = root->next;
    }
    printf("\n");
}

int main()
{
    ListNode f = { '6', 0 };
    ListNode e = { '5', &f };
    ListNode d = { '4', &e };
    ListNode c = { '3', &d };
    ListNode b = { '2', &c };
    ListNode a = { '1', &b };

    ListNode *root = &a;
    print_list(root);
    root = reverseBetween(root,2,5);
    print_list(root);

    return 0;
}