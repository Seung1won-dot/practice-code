#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_end(struct Node** head, int data) {
    struct Node* new_node = create_node(data);
    
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void print_list(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void delete_node(struct Node** head, int data) {
    if (*head == NULL) {
        return;
    }
    
    if ((*head)->data == data) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    
    struct Node* current = *head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }
    
    if (current->next != NULL) {
        struct Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    
    insert_at_end(&head, 10);
    insert_at_end(&head, 20);
    insert_at_end(&head, 30);
    insert_at_end(&head, 40);
    
    printf("연결 리스트: ");
    print_list(head);
    
    delete_node(&head, 20);
    printf("20 삭제 후: ");
    print_list(head);
    
    return 0;
}

