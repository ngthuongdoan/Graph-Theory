/*=== Cai dat Stack bang mang ===*/
/*=== Khai bao ===*/

#include <stdio.h>
#define MaxLength 100
typedef char ElementType;
//typedef float ElementType;
typedef struct
{
    ElementType Elements[MaxLength];
    int Top_idx;
} Stack;
/*=== Tao rong ===*/
void MakeNull_Stack(Stack *S)
{
    S->Top_idx = MaxLength;
}
/*=== Kiem tra rong ===*/
int Empty_Stack(Stack S)
{
    return (S.Top_idx == MaxLength);
}
/*=== Kiem tra day ===*/
int Full_Stack(Stack S)
{
    return (S.Top_idx == 0);
}
/*=== Lay 1 phan tu ra khoi ngan xep ===*/
ElementType Top(Stack S)
{
    if (!Empty_Stack(S))
        return S.Elements[S.Top_idx];
    else
    {
        printf("\nLoi ! Stack rong");
        return NULL;
    }
}
/*=== Them phan tu vao stack ===*/
void Push(ElementType X, Stack *S)
{
    if (Full_Stack(*S))
        printf("\nLoi ! Stack dda^`y kho^ng the^? the^m");
    else
    {
        S->Top_idx = (S->Top_idx - 1); /* Giam Top 1 don vi
					* (Cho Top chi dden phan tu ke)*/
        S->Elements[S->Top_idx] = X;   /* Bo phan tu moi voi dau ngan xep*/
    }
}
/*=== Xoa phan tu khoi ngan xep ===*/
void Pop(Stack *S)
{
    if (Empty_Stack(*S))
        printf("\nLoi ! Stack rong");
    else
    {
        S->Top_idx = (S->Top_idx + 1); /* Tang Top 1 don vi
					* (Cho Top chi lu`i xuong phan tu sau)*/
    }
}
