#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
} ListNode;

ListNode *reverseBetween( ListNode *head, int m, int n )
{
	if ( m == n ) return head;

	ListNode *connect = head, *prev, *cur, *next;
	int i;

	// Find the one which is in front of the reverse interval.
	for ( i = 1; i < m - 1; ++i, connect = connect->next )
		;

	// Find the one which is behind of the reverse interval.
	prev = connect;
	for ( ; i < n + 1; ++i, prev = prev->next )
		;

	// Reverse interval
	if ( m == 1 )
		cur = head;
	else
		cur = connect->next;
	next = cur->next;
	for ( i = n - m + 1; i != 0; --i ) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	// Connect
	if ( m != 1 )
		connect->next = prev;
	else
		head = prev;

	return head;
}
void print_list(ListNode *root) {
    while (root) {
        printf("%c ", root->data);
        root = root->next;
    }
    printf("\n");
}
 

int main() {
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