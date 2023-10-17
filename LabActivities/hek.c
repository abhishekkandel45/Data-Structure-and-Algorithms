// Write a program to implemeb=nt all kinds of linked lists

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertAtBeginning(int data){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
        return;
    }
    struct node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(int data, int position){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if(position == 1){
        newNode->next = head;
        head = newNode;
        return;
    }
    struct node *temp = head;
    for(int i = 1; i < position - 1; i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtBeginning(){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
}

void deleteAtEnd(){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(int position){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    if(position == 1){
        struct node *temp = head;
        head = head->next;
        free(temp);
        return;
    }
    struct node *temp = head;
    for(int i = 1; i < position - 1; i++){
        temp = temp->next;
    }
    struct node *temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
}

void display(){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(){
    int choice, data, position;
    while(1){
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter the data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter the data: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                insertAtPosition(data, position);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

