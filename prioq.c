#include<stdio.h>
#include<stdlib.h>

struct queue{
    int *queue;
    int rear;
    int front;

}cq,pq;

int csize,psize;


void insertprio()
{
    int key,i;
    printf("enter key\n");
    scanf("%d",&key);

    if(pq.front==-1)
    {
        pq.front=pq.rear=0;
        pq.queue[pq.rear]=key;
    }

    else{
        if(pq.rear==psize-1)
        {
            printf("full, reaaloc\n");
            psize++;
            pq.queue=(int *)realloc( pq.queue,psize*sizeof(int));
        }

       for(i=pq.rear; i>=0 && pq.queue[i] >key ;i--)
        {
            pq.queue[i+1]=pq.queue[i];
        }
        pq.queue[i+1]=key;
    
       pq.rear++;
    }
}

void deleteprio()
{
    if(pq.front==-1)
    {
        printf("empty\n");
    }
    else if(pq.front==pq.rear)
    {
        printf("deleted %d",pq.queue[pq.front]);
        pq.rear=pq.front=-1;
    }
    else{
        printf("deleted %d",pq.queue[pq.front]);
        pq.front++;
    }
}

void displayprio()
{
    for(int i=pq.front;i<=pq.rear;i++)
    {
        printf("%d ",pq.queue[i]);
    }
    printf("\n");
}


int main()
{
    int choice;
    printf("enetr sixe of proo\n");
    scanf("%d",&psize);
    pq.queue=(int *)malloc(psize*sizeof(int));
    pq.front=-1;
    pq.rear=-1;


    printf("enetr sixe of cir q\n");
    scanf("%d",&csize);
    cq.queue=(int *)malloc(csize*sizeof(int));
    cq.front=-1;
    cq.rear=-1;

    do{
        printf("eneter choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            insertprio();
            break;

            case 2:
            deleteprio();
            break;

            case 3:
            displayprio();
            break;
        }
    }while(choice!=4);
}