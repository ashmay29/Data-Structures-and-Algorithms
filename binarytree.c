//Binary Tree
#include <stdio.h>
#include <malloc.h>
struct node
{
int data;
struct node *left;
struct node *right;
};
struct node *tree;
void create_tree(struct node *);
struct node *insertElement(struct node *, int);
void preorderTraversal(struct node *);
void inorderTraversal(struct node *);
void postorderTraversal(struct node *);
struct node *findSmallestElement(struct node *);
struct node *findLargestElement(struct node *);
int totalNodes(struct node *);
int Height(struct node *);
int main()
{
int option, val;
struct node *ptr;
create_tree(tree);
do
{
printf("\nAANSHUVISHAH_60009220168\n");
printf("\nSelect any one of the options:\n");
printf("\n 1. Insert Element");
printf("\n 2. Preorder Traversal");
printf("\n 3. Inorder Traversal");
printf("\n 4. Postorder Traversal");
printf("\n 5. Find the smallest element");
printf("\n 6. Find the largest element");
printf("\n 7. Count the total number of nodes");
printf("\n 8. Determine the height of the tree");
printf("\n 9. Exit");
printf("\n\n Enter your option : ");
scanf("%d", &option);
switch(option)
{
case 1:
printf("\n Enter the value of the new node : ");
scanf("%d", &val);
tree = insertElement(tree, val);
break;
case 2:
printf("\n The elements of the tree are : \n");
preorderTraversal(tree);
break;
case 3:
printf("\n The elements of the tree are : \n");
inorderTraversal(tree);
break;
case 4:
printf("\n The elements of the tree are : \n");
postorderTraversal(tree);
break;
case 5:
ptr = findSmallestElement(tree);
printf("\n Smallest element is :%d",ptr->data);
break;
case 6:
ptr = findLargestElement(tree);
printf("\n Largest element is : %d", ptr->data);
break;
case 7:
printf("\n Total no. of nodes = %d", totalNodes(tree));
break;
case 8:
printf("\n The height of the tree = %d",Height(tree));
break;
}
while(option!=9);
return 0;
}
}
void create_tree(struct node *tree)
{
tree = NULL;
}
struct node *insertElement(struct node *tree, int val)
{
struct node *ptr, *nodeptr, *parentptr;
ptr = (struct node*)malloc(sizeof(struct node));
ptr->data = val;
ptr->left = NULL;
ptr->right = NULL;
if(tree==NULL)
{
tree=ptr;
tree->left=NULL;
tree->right=NULL;
}
else
{
parentptr=NULL;
nodeptr=tree;
while(nodeptr!=NULL)
{
parentptr=nodeptr;
if(val<nodeptr->data)
nodeptr=nodeptr->left;
else
nodeptr = nodeptr->right;
}
if(val<parentptr->data)
parentptr->left = ptr;
else
parentptr->right = ptr;
}
return tree;
}
void preorderTraversal(struct node *tree)
{
if(tree != NULL)
{
printf("%d\t", tree->data);
preorderTraversal(tree->left);
preorderTraversal(tree->right);
}
}
void inorderTraversal(struct node *tree)
{
if(tree != NULL)
{
inorderTraversal(tree->left);
printf("%d\t", tree->data);
inorderTraversal(tree->right);
}
}
void postorderTraversal(struct node *tree)
{
if(tree != NULL)
{
postorderTraversal(tree->left);
postorderTraversal(tree->right);
printf("%d\t", tree->data);
}
}
struct node *findSmallestElement(struct node *tree)
{
if( (tree == NULL) || (tree->left == NULL))
return tree;
else
return findSmallestElement(tree ->left);
}
struct node *findLargestElement(struct node *tree)
{
if( (tree == NULL) || (tree->right == NULL))
return tree;
else
return findLargestElement(tree->right);
}
int totalNodes(struct node *tree)
{
if(tree==NULL)
return 0;
else
return(totalNodes(tree->left) + totalNodes(tree->right) + 1);
}
int Height(struct node *tree)
{
int leftheight, rightheight;
if(tree==NULL)
eturn 0;
else
{
leftheight = Height(tree->left);
rightheight = Height(tree->right);
}
if(leftheight > rightheight)
return (leftheight + 1);
else
return (rightheight + 1);
}
