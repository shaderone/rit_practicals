/* Features : 
1) insertion at beginning | specific position | end
2) deletion from beginning | specific position | end 
3) clear view of linked list as whole, first one | last one | specific one
4) check if a data exists
5) additional details about head and other pointers
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct node {
    int data;
    struct node *next;
};

// ? Head pointer
struct node *head = NULL;

// ? function to create a newNode and return its address
struct node * createNode(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    if(newNode == NULL) {
        printf("Memory allocation Failed! Quitting");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

//? function to insert a node with position number as the parameter
void insert(int position) {
    int value;
    printf("Enter the value to insert: ");
    scanf("%d",&value);

    struct node *newNode = createNode(value);

    //* beginning
    if(position == 0) {
        newNode->data = value;
        newNode->next = head;
        head = newNode;

        printf("%d was added to the list\n",newNode->data);
    }
    //* end
    else if(position == 1) {
        newNode->data = value;
        newNode->next = NULL;
        //? if the list is empty
        if(head == NULL) {
            head = newNode;
        } 
        //? traverse to the end node
        else {
            struct node *current = head;

            while(current->next != NULL) {
                current = current->next;
            }

            current->next = newNode;
            newNode->next = NULL;   
        }
    }
    //* insert at specific position
    else {
        printf("NOT YET IMPLEMENTED!\n");
    }
}

void displayList() {
    int count = 0;
    struct node *ptr = head;

    if(ptr == NULL) 
        printf("List is empty!");
    else {
        while(ptr != NULL) {
            count++;
            printf("Node %d : data = %d\n",count,ptr->data);
            ptr = ptr->next;
        }
    }
}

int main() {
    int choice;
    int pref;
    do {
        printf("\033[31mOperations available \033[0m: 1) Insert 2)Delete 3)display 4)details 0) EXIT: ");
        scanf("%d",&choice);      
        
        switch(choice){
            case 1: printf("Enter preference : "); scanf("%d",&pref); insert(pref); break;
            case 2: printf("deletion\n"); break;
            case 3: displayList(); break;
            case 4: printf("details\n"); break;
            case 0: printf("Qutting program...\n"); exit(1);
            default: printf("Invalid Input");
        }
    } while(choice !=0);
}

// ! ---------------------------------Unused Code below---------------------------------

// ? this function is intended to use with insertion and deletion
/*void processInput() {
    char input[10];
    printf("Enter your preferred position number or a specific position: 'b' - beginning, 'e' - end");
    scanf("%s",input);

    isNum = 1; // ? assume the input to be integer

    // ? This loops checks if every character is an integer, if any of the character or element is not a digit, then isNum is set to 0, indicating its not a number
    for(int i=0; i<strlen(input); i++){
        if(!isdigit(input[i])) {
            isNum = 0;
            break;
        }
    }

    // ? if the input is integer, parse it and return as the position number;
    if(isNum) {
        int num;
        sscanf(input,"%d",&num);
        printf("the input [ %d ] is a number",num);
    }
    // ? if the input is character, return either ;
    else if(strlen(input) == 1){
        char ch = input[0];
        printf("the input [ %c ] is a character",ch);
    }
    // ? if the input is integer, parse it and return as the position number;
    else {
        printf("the input [ %s ] is a string",input);
    }
}*/