#include <stdio.h>
void main() {
    printf("Enter the size of array:");
    int n;
    scanf("%d" , &n);
    printf("Enter max number of elements:");
    int maximum;
    scanf("%d" , &maximum);
    printf("Enter the elements:");
    int arr[n];
    for (int i=0 ; i<n ; i++){
        scanf("%d" , &arr[i]);
    }
    int check = 0;
    while (check == 0) {
        printf("---MENU---\n");
        printf("1.Insertion\n");
        printf("2.Deletion\n");
        printf("3.Exit\n");
        int ch;
        printf("Enter your choice:");
        scanf("%d", &ch);

        if (ch == 1){
            n = n+1;
            printf("Enter the element to be inserted:");
            int value;
            scanf("%d" , &value);
            printf("Enter the postion:");
            int pos;
            scanf("%d" , &pos);
            if (n > maximum){
                printf("Array is full.\n");
            }
            else {
                for(int j=n-1 ; j>=pos ; j--){
                    arr[j] = arr[j-1];
                }
                arr[pos-1] = value;
                for (int i=0 ; i<n ; i++){
                    printf("%d " , arr[i]);
                }
                printf("\n");
            }
        }

        else if (ch == 2){
            if (n == 0){
                printf("Array is already empty.");
            }
            else {
                printf("Enter the position to be deleted:");
                int pos;
                scanf("%d" , &pos);
                for(int j=pos-1 ; j<n ; j++){
                    arr[j] = arr[j+1];
                }
                n = n-1;
                for (int i=0 ; i<n ; i++){
                    printf("%d " , arr[i]);
                }
                printf("\n");
            }
        }
        else if (ch == 3){
            printf("EXITING...\n");
            ch = 1;
        }
    }
}
