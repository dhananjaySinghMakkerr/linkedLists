#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Node{
int data;
struct Node* next;
}Node;

void insert(Node** head,int data)
{
Node* temp;
  temp=(struct Node*)malloc(sizeof(Node));
  temp->data=data;
  temp->next=NULL;

  if(*head==NULL)
   {
     *head=temp;
   }
   else{
    Node* p=*head;
   while(p->next!=NULL)
   {
       p=p->next;
   }
   p->next=temp;
   }

}

//(1)-----LOOP BASED COUNT NODES


int countNodes(Node* p){
  int count=1;
  while(p->next!=NULL)
  {
    count++;
    p=p->next;
  }
  return count;
}

// (2)---RECURSIVE FUNCTION TO FIND COUNT OF NODES


int countnode(int count,Node* p)
{
    if(p->next==NULL)
    {
        return count;
    }
    else{
            count++;
        return countnode(count,p->next);
    }
}


//(3)-----FIND SUM OF ALL ELEMENTS OF LINKED LIST



int sumRecursive(Node* p,int sum)
{
    if(p==0)
    {
        return sum;
    }
    else
    {
        sum=sum+p->data;
        return sumRecursive(p->next,sum);
    }
}


//(4)-----DISPLAYING ELEMENTS OF LINKED LIST(LOOP)



void disp(Node** head)
{
   Node* temp;
    temp=*head;
    while(temp!=NULL)
    {
        printf("--->%d",temp->data);
        temp=temp->next;

    }
}

//(5)------GET MIDDLE ELEMENT OF A LINKED LIST


void getMiddle(Node* p)
{
   int count=0;
int length=countNodes(p);
if((length%2)!=0)
{
    for(;count<(length/2);count++)
    {
        p=p->next;
     }
}
else
{
    for(;count<(length/2);count++)
    {
        p=p->next;
    }
}
printf("%d",p->data);
}

//(6)----SEARCH FOR AN ELEMENT IN LINKED LIST(LINEAR SEARCH WITH MOVE TO HEAD)


Node* search(Node* p,int key)
{
    Node* q=NULL;
    Node* headp=p;
    while(p!=NULL)
    {
        if(p->data==key)
        {
            q->next=p->next;
            p->next=headp;
            return p;
        }
        q=p;
        p=p->next;
    }
}

//(7)----INSERT AT GIVEN POSITION

void insertPos(Node** p,int pos,int val)
{
    Node* q=*p;
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=val;
    temp->next=NULL;
    if(pos==0)
    {
        temp->next=(*p);
        (*p)=temp;
    }
    int i;
    for(i=1;i<pos;i++)
    {
         q=q->next;
    }
    temp->next=(q)->next;
    q->next=temp;
}


//(8)----INSERT ELEMENT IN A SORTED LIST

void insertSort(Node** p,int val)
{
    Node* k=(*p);
    Node* q=NULL;
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=val;
    temp->next=NULL;
    if(*p==NULL)
    {
        temp->next=NULL;
        *p=temp;
    }
    if(((*p)->data)>(temp->data))
    {
       temp->next=(*p);
       (*p)=temp;
    }
    while(k!=NULL)
    {
        if((k->data)<(temp->data))
        {
            q=k;
            k=k->next;
        }
        else{
            temp->next=q->next;
            q->next=temp;
            break;
        }
    }
}

//(9)----DELETE A NODE
int deleteNodeByPos(Node** p,int pos)
{
    int x;
    Node* q=NULL;
    Node* temp;
    int i;
    if(pos==1)
    {
         x=(*p)->data;
         temp=*p;
        (*p)=(*p)->next;
        free(temp);
    }
    else
    {
        temp=*p;
        for(i=1;i<pos;i++)
        {
            q=temp;
            temp=temp->next;
        }
        q->next=temp->next;
        x=temp->data;
        free(temp);
        return x;
    }
}

//(10)------REVERSAL OF LINKED LIST BY REVERSING ELEMENTS

void reversalOfElements(Node* p){
    Node* temp=p;
    int count=countNodes(p);
    int j,i,arr[count];
    i=0;
    for(j=1;j<=count;j++)
    {
        arr[i]=p->data;
        p=p->next;
        i++;
    }
    i--;
    for(j=1;j<=count;j++)
    {
        temp->data=arr[i];
        temp=temp->next;
        i--;
    }
}

//(11)----REVERSE LINKED LIST BY CHANGING LINKS

Node* reverseByChangingLinks(Node* p){

Node* temp=NULL;
Node* q=NULL;
while(p!=NULL){
    temp=p->next;
    p->next=q;
    q=p;
    p=temp;
}
return q;


}


int j=0;
Node* headp[20];

//FUNCTION TO CONCATENATE THE REVERSED SUB LINKED LISTS

Node* concatLL(){
    j=0;
    Node* p=headp[j];

while(headp[j])
{
   while(p->next!=NULL)
   {
      p=p->next;
   }
   j++;
   p->next=headp[j];

}
 return headp[0];
}


//(12)-----FUNCTION TO REVERSE 'k' ELEMENTS AT ONCE LINKED LIST

Node* revK(Node* p,int k)
{
    int i;
    Node* temp=NULL;
    Node* q=NULL;
    if(p!=NULL)
    {
    for(i=1;i<=k;i++)
    {
        if(p!=NULL)
        {
        temp=p->next;
        p->next=q;
        q=p;
        p=temp;
        }
    }
    headp[j]=q;
    j++;
    revK(p,k);
    }
    else{
        concatLL();
    }

}

//----FORMING A NUMBER WHILE DIGITS ARE REPRESENTED AS NODES

void formNumber(Node* p,int* x,int* count)
{

    if(p->next==NULL){
            (*count)--;
        (*x)=(*x)+((p->data)*pow(10,*count));

       }
       else{
          formNumber(p->next,x,count);
          (*count)--;
          (*x)=(*x)+((p->data)*pow(10,(*count)));

       }
}

//(13)----MERGE TWO LISTS

Node* mergeLists(Node* p,Node** q)
{
    Node* swap;
    if((*q)->data<p->data)
    {
        swap=p;
        p=*q;
        *q=swap;
   }
   swap=p;
  Node* temp=NULL;
  Node* head2;
    while((*q)!=NULL&&p!=NULL)
    {
        head2=*q;
         while(p!=NULL)
         {
             if(p->data<(head2->data))
             {
                 temp=p;
                 p=p->next;
             }
             else
                {
                   temp->next=head2;
                    *q=(*q)->next;
                   head2->next=p;
                temp=head2;
                   break;
                }
         }


    }
if(*q!=NULL)
{
    temp->next=(*q);
}
return swap;
}



//(14)----CHECKING FOR LOOP

int  hasLoop(Node* p)
{
    Node* q=p;
    while(q!=NULL)
    {
        q=q->next->next;
        p=p->next;
        if(p==q)
        {

            return 1;
        }
    }
     return 0;
}

void createLoop(Node* p)
{
    Node* q=NULL;
int i;
for(i=1;i<countNodes(p);i++)
{
    p=p->next;
    if(i=3)
    {
        q=p;
    }
}
p->next=q;
}

int main()
{
int y;
Node* head=0;
Node* head2=0;
insert(&head,1);
insert(&head,3);
insert(&head,4);
insert(&head,6);
insert(&head,7);
insert(&head,8);
insert(&head,9);
insert(&head2,2);
insert(&head2,5);
insert(&head2,11);
createLoop(head);
/*insert(&head,13);
insert(&head,15);
insert(&head,17);
insert(&head,19);
insert(&head,21);*/
//disp(&head);
//printf("\n\n");
disp(&head2);
printf("\n\n");
/*insertSort(&head,14);
printf("\n\n");
disp(&head);
y=deleteNodeByPos(&head,4);
printf("\n\n");
disp(&head);
printf("\n %d",y);*/
/*int no=0;
int no2=0;
int length=countNodes(head);printf("\n\n");
formNumber(head,&no,&length);
printf("%d \n",++no);
length=countNodes(head2);
formNumber(head2,&no2,&length);
printf("%d",++no2);
int sum=no+no2;
printf("%d",sum);*/
//Node* headp=mergeLists(head,&head2);
//disp(&headp);

int t=hasLoop(head);
printf("%d",t);
    return 0;
}
