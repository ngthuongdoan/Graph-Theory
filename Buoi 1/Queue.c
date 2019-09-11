#include <stdio.h>
#include <stdlib.h>
#define MaxLength 100

typedef int ElementType;
typedef struct
{
    ElementType Elements[MaxLength];
    int Front, Rear;
} Queue;

void MakeNull_Queue(Queue *Q)
{
    Q->Front = -1;
    Q->Rear = -1;
}

int Empty_Queue(Queue Q)
{
    return (Q.Front == -1);
}

int Full_Queue(Queue Q)
{
    return ((Q.Rear - Q.Front + 1) == MaxLength);
}

ElementType Front(Queue Q)
{
    if (Empty_Queue(Q))
        printf("Hang rong");
    else
        return Q.Elements[Q.Front];
}

void DeQueue(Queue *Q)
{
    if (!Empty_Queue(*Q))
    {
        Q->Front = Q->Front + 1;
        if (Q->Front > Q->Rear)
            MakeNull_Queue(Q);
        //Dat lai hang rong
    }
    else
        printf("Loi: Hang rong!");
}

void EnQueue(ElementType X, Queue *Q)
{
    if (!Full_Queue(*Q))
    {
        if (Empty_Queue(*Q))
            Q->Front = 0;
        if (Q->Rear == MaxLength - 1)
        { //Di chuyen tinh tien ra truoc Front -1 vi tri
            for (int i = Q->Front; i <= Q->Rear; i++)
                Q->Elements[i - Q->Front] = Q->Elements[i];
            //Xac dinh vi tri Rear moi
            Q->Rear = MaxLength - Q->Front - 1;
            Q->Front = 0;
        }
        //Tang Rear de luu noi dung moi
        Q->Rear = Q->Rear + 1;
        Q->Elements[Q->Rear] = X;
    }
    else
        printf("Loi: Hang day!");
}

void push(Queue *Q, int x)
{
    Q->Rear++;
    Q->Elements[Q->Rear] = x;
}
int top(Queue *Q)
{
    return Q->Elements[Q->Front];
}
void pop(Queue *Q)
{
    Q->Front++;
}