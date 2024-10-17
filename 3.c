#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void insert(void);
int deleteElement(void);
void display(void);

int main() 
{
    int option, value; 

    do 
    {
        printf("\n MAIN MENU ");
        printf("\n 1. Insert an element");
        
        printf("\n 2. Delete an element ");
        
        printf("\n 3. Display The Queue ");
        
        printf("\n 4. EXIT ");
        
        printf("\nEnter your operation: ");
        
        scanf("%d", &option);

        switch(option) 
        {
            case 1:
                insert();
                break;
            case 2:
                value = deleteElement();
                if (value != -1) {
                    printf("\nThe number deleted is = %d", value);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...");
                break;
            default:
                printf("Invalid option! Please enter a valid option.");
                break;
        }
    } 
    while (option != 4);
    
    return 0;
}

void insert()
{
    int num;
    printf("Enter the element to be inserted into the queue: ");
    scanf("%d", &num);
    
    if (rear == MAX - 1)
    {
        printf("The queue is full!\n");
    }
    else
    {
        if (rear == -1 && front == -1) 
        {
            front = rear = 0;
        }
        else 
        {
            rear++;
        }
        queue[rear] = num;
    }
}

int deleteElement() 
{
    int val;
    if (front == -1 || front > rear) 
    {
        printf("UNDERFLOW\n");
        return -1;
    } 
    else 
    {
        val = queue[front];
        front++;
        if (front > rear) 
        {
            front = rear = -1;
        }
        return val;
    }
}


void display() {
    int i;
    if (front == -1 || front > rear) 
    {
        printf("The queue is empty\n");
    } 
    else 
    {
        printf("Queue elements are: ");
        for (i = front; i <= rear; i++) 
        {
            printf("%d ", queue[i]);
        }
    }
}