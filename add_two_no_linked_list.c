#include <stdio.h>
#include <stdlib.h>

typedef struct Node_s
{
    int data;
    struct Node_s *next;
}Node_t;

void print_list(Node_t *root);
void insert_element_end(Node_t **root, int value);
Node_t *add_two_linked_list(Node_t *linked_list1, Node_t *linked_list2);
void insert_element_start(Node_t **root, int value);
void reverse_link_list(Node_t **root);
int8_t find_loops_in_link_list(Node_t *root);
int main(void)
{
    Node_t *linked_list1 = NULL, *linked_list2 = NULL;
    int8_t ret_val = 0;
    insert_element_start(&linked_list1, 1);
    insert_element_end(&linked_list1, 2);
    insert_element_end(&linked_list1, 3);
    insert_element_end(&linked_list1, 4);
    insert_element_end(&linked_list1, 5);
    insert_element_end(&linked_list1, 6);
    
    linked_list1->next->next->next->next->next->next = linked_list1->next->next->next;
    print_list(linked_list1);
    
    ret_val = find_loops_in_link_list(linked_list1);
    if(ret_val){
        printf("No Loop Found\n");
    }
    else {
        printf("Loop Found\n");
    }
#if 0
    insert_element_start(&linked_list2, 4);
    insert_element_end(&linked_list2, 3);
    insert_element_end(&linked_list2, 2);
    linked_list1->next->next = linked_list1->next->next;
    add_two_linked_list(linked_list1, linked_list2);
    
#endif
}
Node_t *add_two_linked_list(Node_t *linked_list1, Node_t *linked_list2)
{
    Node_t *sum = NULL;
    Node_t *list1 = linked_list1, *list2 = linked_list2;
    int carry_flow = 0;
    int temp_sum = 0;

    while( (list1 != NULL) && (list2 != NULL) )
    {
        temp_sum = linked_list1->data + linked_list2->data;
        if(temp_sum > 9) {
            carry_flow = temp_sum - 10; //  18 - 9 -> 9 
        }
        else {
            carry_flow = temp_sum;
        }
        insert_element_start(&sum, carry_flow);
        list1 = list1->next;
        list2 = list2->next;
    }
    print_list(sum);
    return sum;
}
void print_list(Node_t *root)
{
    while (root != NULL)
    {
        printf("Data = %d\tAddr = %p, \nNext Addr = %p\n", root->data, root, root->next);
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
void reverse_link_list(Node_t **root)
{
    Node_t *curr = *root;

    
}

int8_t find_loops_in_link_list(Node_t *root)
{
    Node_t *first_ptr = root, *second_ptr = root;
    while(first_ptr != NULL 
            && second_ptr != NULL 
            && second_ptr->next->next != NULL) {

        first_ptr = first_ptr->next;
        second_ptr = second_ptr->next->next;

        if(first_ptr->data == second_ptr->data)
        {
            return 0;
        }
    }
    return 1;
}



