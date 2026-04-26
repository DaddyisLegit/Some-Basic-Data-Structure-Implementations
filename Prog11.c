#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;

// Insert at end
void insert(int value) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if (!newnode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL) {   // empty list
        head = tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
    printf("%d inserted at the end.\n", value);
}

// Delete after a given element
void del_after_element(int element) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL && temp->data != element) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element %d not found.\n", element);
        return;
    }
    if (temp->next == NULL) {
        printf("No node exists after element %d.\n", element);
        return;
    }
    struct Node* del_node = temp->next;
    temp->next = del_node->next;
    if (del_node == tail) {  // update tail if last node deleted
        tail = temp;
    }
    printf("Node with value %d deleted after element %d.\n", del_node->data, element);
    free(del_node);
}

// Display list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("List elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, element;
    int check = 0;

    while (check == 0) {
        printf("\n--- MENU ---\n");
        printf("1. Insert at End\n");
        printf("2. Delete After Element\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                printf("Enter element after which to delete: ");
                scanf("%d", &element);
                del_after_element(element);
                break;
            case 3:
                display();
                break;
            case 4:
                check = 1;
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
