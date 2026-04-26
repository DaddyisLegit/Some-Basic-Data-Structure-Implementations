#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;

// Insert at a specific position (1-based index)
void insertAtPosition(int pos, int value) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if (!newnode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newnode->data = value;
    newnode->next = NULL;

    // Insert at beginning
    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        if (tail == NULL) tail = newnode;
        printf("%d inserted at position %d.\n", value, pos);
        return;
    }

    // Traverse to node before position
    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;

    if (newnode->next == NULL) tail = newnode;
    printf("%d inserted at position %d.\n", value, pos);
}

// Delete from the end
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head == tail) {
        printf("Node with value %d deleted from end.\n", head->data);
        free(head);
        head = tail = NULL;
        return;
    }

    struct Node* temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }

    printf("Node with value %d deleted from end.\n", tail->data);
    free(tail);
    tail = temp;
    tail->next = NULL;
}

// Display the list
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
    int choice, pos, value;
    int check = 0;

    while (check == 0) {
        printf("\n--- MENU ---\n");
        printf("1. Insert at Position\n");
        printf("2. Delete from End\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtPosition(pos, value);
                break;
            case 2:
                deleteFromEnd();
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
