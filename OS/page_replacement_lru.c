#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *front, *rear;

void enqueue(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    
    if (rear == NULL)
    {
        front = newnode;
        rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

int dequeue()
{
    struct node *temp;
    int x;
    if (front == NULL)
    {
        printf("Frames Empty");
    }
    else if (front == rear)
    {
        x = front->data;
        temp = front;
        front = NULL;
        rear = NULL;
        free(temp);
        return x;
    }
    else
    {
        x = front->data;
        temp = front;
        front = front->next;
        free(temp);
        return x;
    }
    
}
void deleteItem(int data) 
{
    struct node *temp,*prevnode;
    temp=front;
    while(temp!=NULL && temp->data!=data)
    {
        prevnode=temp;
        temp=temp->next;
    }
    if(temp==front)
    {
        struct node *headtemp;
        headtemp=front;
        front=front->next;
        free(headtemp);
    }
    else if(temp!=NULL)
    {
        prevnode->next=temp->next;
        free(temp);
    }
    else
    {
        printf("Element not found");
    }
}

void display()
{
    struct node *temp;
    temp = front;
    while (temp->next != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

void display_frames(int frames[], int frame_nos)
{
    for(int i = 0; i < frame_nos; i++)
    {
        printf("%d ",frames[i]);
    }
    printf("\n");
}

void main()
{
    int pages[] = {6, 0, 12, 0, 30, 4, 2, 30, 32, 1, 20, 15};
    int frame_nos = 3;

    int frames[frame_nos];
    for(int i = 0; i < frame_nos; i++)
        frames[i] = -1;
    
    int no_pages = sizeof(pages) / sizeof(pages[0]); 
    for(int i = 0; i < no_pages; i++)
    {
        int page = pages[i];
        int hit = 0, empty = 0;
        
        for (int j = 0; j < frame_nos; j++)
        {
            if(page == frames[j])
            {
                printf("Page Hit\n");
                hit = 1;
                deleteItem(frames[j]);
                enqueue(page);
                break;
            }
            if(frames[j] == -1)
            {
                empty = 1;
            }
            
        }
        
        if(hit == 0)
        {
            printf("Page miss.\n");
            enqueue(page);
            
            if(empty == 0)
            {
                int old_page = dequeue();
                printf("Page removed: %d\n", old_page);
                for (int j = 0; j < frame_nos; j++)
                {
                    if(old_page == frames[j])
                    {
                        frames[j] = page;
                        break;
                    }
                }
            }
            else
            {
                for (int j = 0; j < frame_nos; j++)
                {
                    if(frames[j] == -1)
                    {
                        frames[j] = page;
                        break;
                    }
                }
            }
            
        }
        printf("frames:");display_frames(frames, frame_nos);
        // printf("queue:");display();
    }
}
