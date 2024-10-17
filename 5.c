#include <stdio.h>  
#include <stdlib.h>  
struct node {  
    int data;  
    struct node *next;  
};      

struct node *head = NULL, *tail = NULL;  

void addNode(int data) {  
    // Create a new node  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
    newNode->next = NULL;  
      
    if(head == NULL) {  
        head = newNode;  
        tail = newNode;  
    }  
    else {  
        tail->next = newNode;  
        tail = newNode;  
    }  
}  

void display() {  
    struct node *current = head;  
     
    if(head == NULL) {  
        printf("List is empty\n");  
        return;  
    }  

    printf("Nodes of the singly linked list: \n");  
    while(current != NULL) {  
        printf("%d ", current->data);  
        current = current->next;  
    }  
    printf("\n");  
}  
void deleteNode(int value) {  
    struct node *current = head, *previous = NULL;  

    if(head == NULL) {  
        printf("List is empty\n");  
        return;  
    }  

    while(current != NULL) {  
        if(current->data == value) {  
            if(current == head) {  
                head = head->next;  
            } else {  
                previous->next = current->next;  
            }  

            if(current == tail) {  
                tail = previous;  
            }  

            free(current);  
            printf("Node with value %d deleted successfully.\n", value);  
            return;  
        }  
        previous = current;  
        current = current->next;  
    }  

    printf("Node with value %d not found in the list.\n", value);  
}  
     
int main() {  
    int choice, data;  

    while(1) {  
        // Display menu options  
        printf("\nMenu:\n");  
        printf("1. Add node\n");  
        printf("2. Display list\n");  
        printf("3. Delete node\n");  
        printf("4. Exit\n");  
        printf("Enter your choice: ");  
        scanf("%d", &choice);  

        switch(choice) {  
            case 1:  
                printf("Enter data to insert: ");  
                scanf("%d", &data);  
                addNode(data);  
                break;  
            case 2:  
                display();  
                break;  
            case 3:  
                printf("Enter value to delete: ");  
                scanf("%d", &data);  
                deleteNode(data);  
                break;  
            case 4:  
                exit(0);  
            default:  
                printf("Invalid choice. Please try again.\n");  
        }  
    }  

    return 0;  
}