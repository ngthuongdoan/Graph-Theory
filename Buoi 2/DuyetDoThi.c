#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_ELEMENTS 100
#define MaxLength 100

typedef int ElementType;
typedef struct Queue
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

int top(Queue *Q)
{
	return Q->Elements[Q->Front];
}

typedef int ElementType;
typedef struct List
{
	ElementType data[MAX_ELEMENTS];
	int size;
} List;
/* Tao danh sach rong */
void make_null(List *L)
{
	L->size = 0;
}
/* Them mot phan tu vao cuoi danh sach */
void push_back(List *L, ElementType x)
{
	L->data[L->size] = x;
	L->size++;
}
/* Lay phan tu tai vi tri i, phan tu bat dau o vi tri 1 */
ElementType element_at(List *L, int i)
{
	return L->data[i - 1];
}
/* Tra ve so phan tu cua danh sach */
int count_list(List *L)
{
	return L->size;
}
typedef struct Graph
{
	// n la so dinh
	int n;
	// ma tran dinh cung
	int A[MAX_VERTICES][MAX_VERTICES];
} Graph;

// ham khoi tao do thi
void init_graph(Graph *G, int n)
{
	int i, j;
	G->n = n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			G->A[i][j] = 0;
}

int adjacent(Graph *G, int x, int y)
{
	return G->A[x][y] != 0;
}

// them cung vao do thi
void add_edge(Graph *G, int x, int y)
{
	G->A[x][y] = 1;
	G->A[y][x] = 1;
}

//Tinh bac cua mot dinh đơn cung
int degree(Graph *G, int x)
{
	int y, deg = 0;
	for (y = 1; y <= G->n; y++)
		if (G->A[x][y] > 0)
			deg++;
	return deg;
}

List neighbors(Graph *G, int x)
{
	List L;
	make_null(&L);
	int y;
	for (y = 1; y <= G->n; y++)
	{
		if (adjacent(G, x, y))
			push_back(&L, y);
	}
	return L;
}

void inDS(Graph *G)
{
	int i, j;
	for (i = 0; i < G->n; i++)
	{
		for (j = 0; j < G->n; j++)
		{
			printf("%d ", G->A[i][j]);
		}
		printf("\n");
	}
}

/* Duyệt đồ thị theo chiều rộng */
List breath_first_search(Graph *G)
{
	Queue L;
	List a;
	int mark[MAX_VERTICES];
	make_null(&a);
	MakeNull_Queue(&L);
	/* Khởi tạo mark, chưa đỉnh nào được xét */
	int j;
	for (j = 1; j <= G->n; j++)
		mark[j] = 0;
	/* Đưa 1 vào frontier */
	EnQueue(1, &L);
	push_back(&a,1);
	/* Duyệt 1 */
	mark[1] = 1;
	/* Vòng lặp chính dùng để duyệt */
	while (!Empty_Queue(L))
	{
		/* Lấy phần tử đầu tiên trong L ra */
		int x = Front(L);
		DeQueue(&L);
		
		printf("%d\n", x);
		/* Lấy các đỉnh kề của nó */
		List list = neighbors(G, x);
		/* Xét các đỉnh kề của nó */
		for (j = 1; j <= list.size; j++)
		{
			int y = element_at(&list, j);
			if (mark[y] == 0)
			{ // y chưa duyệt, duyệt nó
				printf("%d\n", y);
				push_back(&a,y);
				mark[y] = 1;	//Đánh dấu y đã duyệt
				EnQueue(y, &L); //Đưa vào hàng đợi để lát nữa xét
			}
		}
	}
	return a;
}

int main(int argc, char const *argv[])
{
	freopen("dt.txt", "r", stdin); //Khi nộp bài nhớ bỏ dòng này.
	Graph G;
	int n, m, u, v, w, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);

	for (e = 1; e <= m; e++)
	{
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}

	List a;
	make_null(&a);
	a=breath_first_search(&G);
	int i;
	for ( i = 0; i < a.size; i++)
	{
		printf("%d\n",a.data[i]);
	}
	
	return 0;
}
