#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define COUNT 2

typedef struct BinaryTreeRoot
{
    int32_t data;
    struct BinaryTreeRoot *leftNode;
    struct BinaryTreeRoot *rightNode;
}BinaryTreeRoot;

void Binary_Preorder_Traversal(BinaryTreeRoot *rootNode);
void PrintTree_In2D(BinaryTreeRoot *rootNode, char space);
void Binary_Tree_Insert();

int main(void)
{
    BinaryTreeRoot *rootNode = (BinaryTreeRoot*)malloc(sizeof(BinaryTreeRoot));
    rootNode->data = 10;
    rootNode->leftNode = (BinaryTreeRoot*)malloc(sizeof(BinaryTreeRoot));
    rootNode->leftNode->data = 20;
    rootNode->leftNode->leftNode= (BinaryTreeRoot*)malloc(sizeof(BinaryTreeRoot));
    rootNode->leftNode->leftNode->data = 30;
    rootNode->leftNode->leftNode->leftNode = NULL;
    rootNode->leftNode->leftNode->rightNode = NULL;

    rootNode->rightNode = (BinaryTreeRoot*)malloc(sizeof(BinaryTreeRoot));
    rootNode->rightNode->data = 40;
    rootNode->rightNode->rightNode= (BinaryTreeRoot*)malloc(sizeof(BinaryTreeRoot));
    rootNode->rightNode->rightNode->data = 50;
    rootNode->rightNode->rightNode->leftNode = NULL;
    rootNode->rightNode->rightNode->rightNode = NULL;
    
    Binary_Preorder_Traversal(rootNode);
    PrintTree_In2D(rootNode, 1);
    return 0;
}
void Binary_Preorder_Traversal(BinaryTreeRoot *rootNode)
{
    if(rootNode == NULL)
        return;
    printf("Data = %d\n", rootNode->data);
    Binary_Preorder_Traversal(rootNode->leftNode);
    Binary_Preorder_Traversal(rootNode->rightNode);
    
}
void PrintTree_In2D(BinaryTreeRoot *rootNode, char space)
{
   if (rootNode == NULL)
      return;
   space += COUNT;
   PrintTree_In2D(rootNode->rightNode, space);
   for (int i = COUNT; i < space; i++)
      printf("\t");
   printf("%d\n",rootNode->data);
   PrintTree_In2D(rootNode->leftNode, space);
}