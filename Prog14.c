#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int value)
{
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if (!newnode)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    newnode->data = value;
    newnode->next = head;
    head = newnode;
}

void search(int element)
{
    int pos = 1 , check=0;
    struct Node* finder = head;
    while (finder!=NULL)
    {
        if (finder->data == element)
        {
            printf("%d found at postion %d.\n" , element , pos);
            check = 1;
            break;
        }
        finder = finder->next;
        pos++;
    }
    if (check == 0)
    {
        printf("Element not present.\n");
    }
}

void no_of_nodes()
{
    int count=0;
    struct Node* counter = head;
    while (counter!=NULL)
    {
        count = count+1;
        counter = counter->next;
    }
    printf("Number of Nodes: %d\n" , count);
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("List Elements: ");
    while (temp!=NULL)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void main()
{
    int ch , check=0;
    while (check == 0)
    {
        printf("---MENU---\n");
        printf("1.Insert\n");
        printf("2.Check for an element\n");
        printf("3.Count number of nodes\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d" , &ch);

        switch(ch)
        {
            case 1:
                int value;
                printf("Enter the number to be inserted: ");
                scanf("%d" , &value);
                insert(value);
                break;

            case 2:
                int ele;
                printf("Enter the number to be searched: ");
                scanf("%d" , &ele);
                search(ele);
                break;

            case 3:
                no_of_nodes();
                break;

            case 4:
                display();
                break;

            case 5:
                check = 1;
                break;

            default:
                printf("Invalid choice.\n");
        }
    }
}
