 #include<stdio.h>
 #include<stdlib.h>
 struct dll{
    int ssn;
    char name[20],dept[20],dest[20],phno[10];
    float salary;
    struct dll *prev,*next;
 };
 typedef struct dll node;
 node *start=NULL;
 int count=0;
node *createnode()
{
    node *newnode = (node *)malloc(sizeof(node));
    printf("\n enter the ssn,name,department,designation,salary,phono\n");
    scanf("%d", &(newnode->ssn));
    scanf("%s", newnode->name);
    scanf("%s", newnode->dept);
    scanf("%s", newnode->dest);
    scanf("%s", newnode->phno);
    scanf("%f", &(newnode->salary));
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

 void insertbegin(){
    node *newnode=createnode();
    if(start==NULL){
        start=newnode;
        return ;
    }
    newnode->next=start;
    start->prev=newnode;
    start=newnode;
}
void insertend(){
    node *temp=start;
    node *newnode=createnode();
    if(start==NULL){
        start=newnode;
        return ;
    }
    while(temp->next!=NULL){
        temp=temp->next;
        temp->next=newnode;
        newnode->prev=temp;
    }
}
void deletebegin(){
    node *temp=start;
    if(start==NULL){
        printf("list is empty");
        return ;
    }
    if(start->next==NULL){
        printf("deleted node is %d",temp->ssn);
        free(temp);
        start=NULL;
        return;
    }
    start=temp->next;
    printf("deleted node is %d",temp->ssn);
    free(temp);
}
void deleteend(){
    node *temp=start;
    if(start==NULL){
        printf("list is empty");
        return ;
    }
    if(start->next==NULL){
        printf("deleted node is %d",temp->ssn);
        free(temp);
        start=NULL;
        return;
    }
    while(temp->next->next!=NULL){
        temp=temp->next;
        (temp->prev)->next=NULL;
        printf("deleted node is %d",temp->ssn);
        free(temp);
    }
}
void display(){
    node *temp=start;
    if(start==NULL){
        printf("list is empty");
        return ;
    }
    while(temp!=NULL){
        printf("%d\t%s\t%s\t%s\t%s\t%f\n",temp->ssn,temp->name,temp->dept,temp->dest,temp->phno,temp->salary);
        temp=temp->next;
        count++;
    }
    printf("\n total number of nodes are %d",count);
}
int main(){
    int choice,n,i;
    while(1){
        printf("Enter your choice :\n");
        printf("1. Insert at the Beginning\n");
        printf("2. Insert at the End\n");
        printf("3. Delete from the Beginning\n");
        printf("4. Delete from the End\n");
        printf("5. Display the List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the no.of employees :\n");
            scanf("%d",&n);
            for(i=0;i<n;i++)
                insertbegin();
                break;
            case 2:
                insertend();
                break;
            case 3:
                deletebegin();
                break;
            case 4:
                deleteend();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("invalid choice");
        }
    }
}
