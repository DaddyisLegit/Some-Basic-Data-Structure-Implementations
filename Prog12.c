#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertion_after_element(int element , int value)
{
    struct Node* temp = head;
    while(temp!=NULL && temp->data!=element)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("Element not present.\n");
        return;
    }
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if (!newnode)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    newnode->data = value;
    newnode->next = temp->next;
    temp->next = newnode;

    printf("%d inserted after element %d.\n", value, element);
}

void del_from_beginning()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    head = temp->next;
    printf("%d deleted.\n" , temp->data);
    free(temp);
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("List elements: ");
    while (temp != NULL)
    {
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
        printf("1. Insert After Element\n");
        printf("2. Delete From Beginning\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element after which to insert: ");
                scanf("%d", &element);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertion_after_element(element, value);
                break;
            case 2:
                del_from_beginning();
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
