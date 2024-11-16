//TO-DO LIST 

// Basic idea:
//     1. Insert tasks. 
//     2. delete tasks.
//     3. Update tasks.
//     4. View tasks.
//     5. Add and remove subtasks.

//change subtask add multiple subtasks

//structure of the node for list
//as we use scanf for string, it will only accept a single word as task

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char data[100];
    struct node*next;
    struct node*subtask;
    struct node*prev;
};


struct node*head=NULL;
struct node*newnode,*temp;

//display function to display the list created.
void display(struct node*ptr)
{
    struct node*subT;
    int order=1;
    if(ptr==NULL)
    {
        printf("\nOops! The list may be empty or unfound");
        return;
    }
    while(ptr!=NULL)
    {
        printf("\n%d. %s",order,ptr->data);
        if(ptr->subtask!=NULL)
        {
            subT=ptr->subtask;
            printf("\n\tSubtask : %s",subT);
        }
        order++;
        ptr=ptr->next;
    }
    printf("\n%d tasks to complete today!",order-1);
    
}

//main menu
void main()
{
    int stop=0;
    printf("\nWelcome to 2dolist!\nPlan, Organize and Achieve your daily tasks\n");
    while(stop!=1)
    {
        printf("\n\n1. Create a new List");
        printf("\n2. Add tasks to existing list");
        printf("\n3. Add subtask");
        printf("\n4. Delete subtask");
        printf("\n5. Change task");
        printf("\n6. Delete task");
        printf("\n7. Display my list");
        printf("\n8. Exit the application");
        int choice;
        printf("\n\nEnter choice to perform:");
        scanf("%d",&choice);
        if(choice==1)
        {
            char ListName[40];
            printf("\nEnter name of List : ");
            scanf("%s",ListName);
            int start=0;
            char addTask[2];
            printf("\nAdd Task?(Y/N) : ");
            scanf("%s",addTask);
            if(strcmp(addTask,"Y")==0)
            {
                start=1;
            }
            while(start!=0){
                newnode=(struct node*)malloc(sizeof(struct node));
                newnode->subtask=NULL;
                printf("\nEnter task: ");
                scanf("%s",newnode->data);
                if(head==NULL)
                {

                    head=temp=newnode;
                }
                else{
                    temp->next=newnode;
                    newnode->prev=temp;
                    temp=newnode;
                }
                temp->next=NULL;
                printf("\nAdd Task?(Y/N) : ");
                scanf("%s",addTask);
                if(strcmp(addTask,"N")==0)
                {
                    start=0;
                }
            }
            printf("\nList created successfully with given tasks");
        }
        else if(choice == 7)
        {
            display(head);
        } 
        else if(choice==2)
        {
            temp=head;
            if(temp==NULL)
            {
                printf("\nOops! There is no existing list, creae a new list and then add tasks to it.");
                return;
            }
            else{
                printf("\nEnter number of tasks to add into the existing list:");
                int number,num1;
                scanf("%d",&number);
                num1=number;
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                while(number!=0)
                {
                    newnode=(struct node*)malloc(sizeof(struct node));
                    printf("\nEnter task:");
                    scanf("%s",newnode->data);
                    newnode->subtask=NULL;
                    temp->next=newnode;
                    newnode->prev=temp;
                    temp=temp->next;
                    number--;
                }
                temp->next=NULL;
                printf("\n%d tasks succesfully added to your 2dolist!",num1);
            }
        }
        else if(choice==6)
        {
            printf("\nEnter task number to delete : ");
            int deletetask;
            scanf("%d",&deletetask);
            int index=1;
            int flag=0;
            temp=head;
            while(temp!=NULL)
            {
                if(index==deletetask && index==1)//deleting the first task
                {
                    head=head->next;
                    free(temp);
                    flag=1;
                    break;
                }
                else if(temp->next==NULL && index==deletetask) // delete last task
                {
                    temp->prev->next=NULL;
                    free(temp);
                    flag=1;
                    break;
                }
                else if(index==deletetask)
                {
                    temp->prev->next=temp->next;
                    temp->next->prev=temp->prev;
                    free(temp);
                    flag=1;
                    break;
                }
                temp=temp->next;
                index++;
            }
            if(flag==0)
            {
                printf("\nSorry, task not found!");
            }
            else{
                printf("\nTask succesfully deleted");
            }
            
        }
        else if(choice==5) // modify choice
        {
            printf("\nEnter task to modify : ");
            int modify;
            int flag=0;
            int index=1;
            scanf("%d",&modify);
            temp=head;
            while(temp!=NULL)
            {
                if(modify==index)
                {
                    printf("\nEnter modified task: ");
                    flag=1;
                    scanf("%s",temp->data);
                }
                temp=temp->next;
                index++;
            }
            if(flag==1)
            {
                printf("\nTask succesfully modified");
            }
            else{
                printf("\nSorry, task not found");
            }
        }
        else if(choice==8)
        {
            printf("\nThank You for using 2dolist!");
            stop=1;
            
        }
        else if(choice==3)
        {
            printf("\nEnter task number to add subtask:");
            int index=1;
            int subtask;
            int flag=0;
            scanf("%d",&subtask);
            temp=head;
            while(temp!=NULL)
            {
                if(index==subtask)
                {
                    flag=1;
                    newnode=(struct node*)malloc(sizeof(struct node));
                    printf("Enter subtask: ");
                    scanf("%s",newnode->data);
                    temp->subtask=newnode;
                }
                index++;
                temp=temp->next;
            }
            if(flag==1)
            {
                printf("\nSubtask inserted successfully");
            }
            else{
                printf("\nSorry, task not found");
            }
        }
        else if(choice==4)//delete subtask
        {
            printf("\nEnter task number to delete subtask: ");
            int tasknum;
            int index=1;
            scanf("%d",&tasknum);
            temp=head;
            while(temp!=NULL)
            {
                if(index==tasknum)
                {
                    if(temp->subtask!=NULL)
                    {
                        temp->subtask=NULL;
                        printf("\nSubtask deleted successfully");
                        break;
                    }
                    else{
                        printf("\nOops! Subtask doesnt exist");
                    }
                }
                index++;
                temp=temp->next;
            }
        }
    }
}
