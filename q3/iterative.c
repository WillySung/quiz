/* FIXME: Implement! */
#include <stdio.h>
#include <stdlib.h>

// Maximum stack size
#define MAX_SIZE 100


/* A binary tree TreeNode has data, pointer to left child
   and a pointer to right child */
struct TreeNode
{
     int data;
     struct TreeNode* left;
     struct TreeNode* right;
};
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct TreeNode *newNode(int data)
{
     struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
     node->data = data;
     node->left = NULL;
     node->right = NULL;
 
     return(node);
}

// An iterative process to print preorder traversal of Binary tree
void flatten(struct TreeNode *root)
{
    
     struct TreeNode *stack[MAX_SIZE];
     int top = -1;
     struct TreeNode *ptr = root;

     // Base Case
     if (ptr == NULL)
        return;

     do
     {
        printf("%d ", ptr->data); // print the node
        if (ptr->right)
            stack[++top] = ptr->right; 
        if (ptr->left)
            stack[++top] = ptr->left; 

        /* Pop a pointer */
        if (top == -1)
               break; // we are done
 
        ptr = stack[top--];
     } while((ptr != NULL) || (top > -1));
}

/* Driver program to test above functions*/
int main()
{
    /*
              1
             / \
            2   5
           / \   \
          3   4   6
    */      
    
     struct TreeNode *root  = newNode(1);
     root->left             = newNode(2);
     root->right           = newNode(5);
     root->left->left     = newNode(3);
     root->left->right   = newNode(4);
     root->right->right  = newNode(6); 
 
     printf("\nflattened binary tree is \n");
     flatten(root);
     printf("\n");
 
     return 0;
}
