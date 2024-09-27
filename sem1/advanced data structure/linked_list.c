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

struct inputResult {
    int isNum; // ? variable to store the status of input type (int or char)
    int number; // ? variable to hold the input if it is a number
    char command; // ? variable to hold the input if it is a character
};

struct inputResult processInput();

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
void insert() {
    int value;
    printf("Enter the value to insert: ");
    scanf("%d",&value);

    struct node *newNode = createNode(value);

    struct inputResult res = processInput();
    /*// ? if the input is integer, parse it and return as the position number;
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
    }*/

    //* beginning
    if(res.command == 'b') {
        newNode->data = value;
        newNode->next = head;
        head = newNode;

        printf("%d was added to the list beginning\n",newNode->data);
    }
    //* end
    else if(res.command == 'e') {
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
        printf("%d was added to the list end\n",newNode->data);
    }
    //* insert at specific position
    else if(res.number) {
        printf("NOT YET IMPLEMENTED!\n");
    } else {
        printf("Enter a valid option!\n");
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
            case 1: insert(); break;
            case 2: printf("deletion\n"); break;
            case 3: displayList(); break;
            case 4: printf("details\n"); break;
            case 0: printf("Qutting program...\n"); exit(1);
            default: printf("Invalid Input");
        }
    } while(choice !=0);
}

// ? this function is intended to use with insertion and deletion
struct inputResult processInput() {
    char input[10];

    struct inputResult res;

    printf("Enter your preferred position number or a specific position: 'b' - beginning, 'e' - end: ");
    scanf("%s",input);

    res.isNum = 1; // ? assume the input to be integer

    if(input[0] == 'b' || input[0] == 'e') {
        res.isNum = 0; // * Not a number
        res.command = input[0]; // * store the command
    } else {
        // ? This loops checks if every character is an integer, if any of the character or element is not a digit, then isNum is set to 0, indicating its not a number
        for(int i=0; i<strlen(input); i++){
            if(!isdigit(input[i])) {
                res.isNum = 0;
                break;
            }
        }

        // ? After the loop check, if the input is a number, cast it to int
        if(res.isNum == 1) 
            res.number = atoi(input);
    } // end of else

    return res;
}