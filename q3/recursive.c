/* FIXME: Implement! */
#include <stdio.h>
#include <stdlib.h>
 
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
struct TreeNode* newNode(int data)
{
     struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
     node->data = data;
     node->left = NULL;
     node->right = NULL;
 
     return(node);
}
 
 
/* Given a binary tree, print its nodes in preorder*/
void flatten(struct TreeNode* root)
{
     if (root == NULL)
          return;
 
     /* first print data of node */
     printf("%d ", root->data);  
 
     /* then recur on left sutree */
     flatten(root->left);  
 
     /* now recur on right subtree */
     flatten(root->right);
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