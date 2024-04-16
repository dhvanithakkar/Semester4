#include <stdio.h>

int queue[100];
int front=-1,rear=-1;
int n = 4;

void enque(int data)
{
    if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=data;
    }
    else if((rear+1) % n==front)
    {
        printf("Frames are full");
    }
    else{
        rear=(rear+1)%n;
        queue[rear]=data;
    }
}

void display()
{
    int i=front;
    if(front==-1 && rear==-1)
    {
        printf("Frames are empty");
    }
    else{
        while(i!=rear)
        {
            printf("%d ",queue[i]);
            i=(i+1)%n;
        }
        printf("%d ",queue[rear]);
    }
    printf("\n");
}

int deque()
{
    if(front==-1 && rear==-1)
    {
        printf("Frames are empty");
    }
    else if(front==rear)
    {
        int elem = queue[front];
        front=rear=-1;
        return elem;
    }
    else{
        int elem = queue[front];
        front=(front+1)%n;
        return elem;
    }
}

void display_frames(int frames[], int frame_nos)
{
    for(int i = 0; i < frame_nos; i++)
    {
        printf("%d ",frames[i]);
    }
    printf("\n");
}

void main() // fifo(int pages[], int frame_nos)
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
            enque(page);
            
            if(empty == 0)
            {
                int old_page = deque();
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
        display_frames(frames, frame_nos);
    }
}

// int main()
// {
//     int pages[] = {6, 0, 12, 0, 30, 4, 2, 30, 32, 1, 20, 15};
//     int frame_nos = 3;
    
//     fifo(pages, frame_nos);
    
//     return 0;
// }
