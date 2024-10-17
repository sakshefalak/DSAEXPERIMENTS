#include <stdio.h> 
#include <stdlib.h> 
struct Node { 
int data; 
struct Node* next; 
}; 
struct Node* createNode(int data) { 
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); if (!newNode) { 
printf("Memory allocation failed\n"); 
exit(1); 
} 
newNode->data = data; 
newNode->next = NULL; 
return newNode; 
} 
void insertAtBeginning(struct Node** head, int data) { struct Node* newNode = createNode(data); 
if (*head == NULL) { 
*head = newNode; 
newNode->next = newNode; 
} else { 
struct Node* temp = *head; 
while (temp->next != *head) { 
temp = temp->next; 
} 
temp->next = newNode; 
newNode->next = *head; 
*head = newNode; 
} 
} 
void insertAtEnd(struct Node** head, int data) {
struct Node* newNode = createNode(data); if (*head == NULL) { 
*head = newNode; 
newNode->next = newNode; 
} else { 
struct Node* temp = *head; 
while (temp->next != *head) { 
temp = temp->next; 
} 
temp->next = newNode; 
newNode->next = *head; 
} 
} 
void deleteFromBeginning(struct Node** head) { if (*head == NULL) { 
printf("List is empty\n"); 
return; 
} 
struct Node* temp = *head; 
if (temp->next == *head) { 
free(temp); 
*head = NULL; 
} else { 
struct Node* last = *head; 
while (last->next != *head) { 
last = last->next; 
} 
last->next = temp->next; 
*head = temp->next; 
free(temp); 
} 
} 
void deleteFromEnd(struct Node** head) { if (*head == NULL) { 
printf("List is empty\n");
return; 
} 
struct Node* temp = *head; if (temp->next == *head) { 
free(temp); 
*head = NULL; 
return; 
} 
struct Node* secondLast = NULL; while (temp->next != *head) { secondLast = temp; 
temp = temp->next; 
} 
secondLast->next = *head; free(temp); 
} 
void display(struct Node* head) { if (head == NULL) { 
printf("List is empty\n"); 
return; 
} 
struct Node* temp = head; do { 
printf("%d -> ", temp->data); temp = temp->next; 
} while (temp != head); 
printf("(back to head)\n"); 
} 
void circularLinkedListMenu() { struct Node* head = NULL; int choice, data; 
do {
printf("\nCircular Singly Linked List Menu:\n"); printf("1. Insert at Beginning\n"); 
printf("2. Insert at End\n"); 
printf("3. Delete from Beginning\n"); 
printf("4. Delete from End\n"); 
printf("5. Display List\n"); 
printf("6. Exit\n"); 
printf("Enter your choice: "); 
scanf("%d", &choice); 
switch (choice) { 
case 1: 
printf("Enter data to insert at the beginning: "); scanf("%d", &data); 
insertAtBeginning(&head, data); 
break; 
case 2: 
printf("Enter data to insert at the end: "); 
scanf("%d", &data); 
insertAtEnd(&head, data); 
break; 
case 3: 
deleteFromBeginning(&head); 
break; 
case 4: 
deleteFromEnd(&head); 
break; 
case 5: 
display(head); 
break; 
case 6: 
printf("Exiting Circular Singly Linked List Menu...\n"); break; 
default: 
printf("Invalid choice! Please try again.\n"); 
} 
} while (choice != 6); 
}
int main() { 
circularLinkedListMenu(); 
return 0; 
} 