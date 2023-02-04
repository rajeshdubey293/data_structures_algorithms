#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node_s
{
    int data;
    struct Node_s *next;
} Node_t;

void print_list(Node_t *root);
void insert_element_end(Node_t **root, int value);
void insert_element_start(Node_t **root, int value);
void insert_element_given_place(Node_t **root, int value, uint32_t place);

int32_t main(void)
{

    Node_t *root_node = NULL;
    insert_element_start(&root_node, 100);
    insert_element_end(&root_node, 20);
    insert_element_end(&root_node, 30);
    insert_element_start(&root_node, 50);
    insert_element_start(&root_node, 60);
    insert_element_start(&root_node, 70);
    insert_element_start(&root_node, 80);
    insert_element_end(&root_node, 90);
    insert_element_given_place(&root_node, 110, 1);
    print_list(root_node);
    return 0;
}
void print_list(Node_t *root)
{
    while (root != NULL)
    {
        printf("Data = %d\tAddr = %p\n", root->data, root);
        root = root->next;
    }
}
void insert_element_end(Node_t **root, int value)
{
    Node_t *curr = *root;
    Node_t *new_node = (Node_t *)malloc(sizeof(Node_t));
    if (new_node == NULL)
    {
        return;
    }
    new_node->data = value;
    new_node->next = NULL;

    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_node;
}
void insert_element_start(Node_t **root, int value)
{
    Node_t *new_node = (Node_t *)malloc(sizeof(Node_t));
    if (new_node == NULL)
    {
        return;
    }
    new_node->data = value;
    new_node->next = *root;
    *root = new_node;
}
void insert_element_given_place(Node_t **root, int value, uint32_t pos)
{
    Node_t *new_node = (Node_t *)malloc(sizeof(Node_t));
    if(new_node == NULL) {
        return;
    }
    new_node->data = value;
    new_node->next = NULL;
    while(pos--) {
        if(pos == 0) {
            new_node->next = *root;
            *root = new_node;
        }
        else {
            root = &(*root)->next;
        }
    }
    
}

char show_main_menu()
{
    int choice = 0;
    printf("1. Insert element at starting position\n");
    printf("2. Insert element at last position\n");
    printf("3. Insert element at th location\n");
    printf("4. Show all element in the list\n");
    scanf("%d", &choice);
    return choice;
}