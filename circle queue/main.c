#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front;
	int rear;
}QueueType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//초기화
void init_queue(QueueType *qptr)
{
	qptr->front = 0;
	qptr->rear = 0;
}

int is_empty(QueueType* qptr)
{
	return (qptr->front == qptr->rear);
}

int is_full(QueueType* qptr)
{
	return ((qptr->rear + 1) % MAX_QUEUE_SIZE == qptr->front);
}

void enqueue(QueueType* qptr, element item)
{
	
	if (is_full(qptr)) {
		printf("큐가 포화상태입니다.\n");
		return;
	}

	qptr->rear = (qptr->rear + 1) % MAX_QUEUE_SIZE;
	qptr->data[qptr->rear] = item;
}

element dequeue(QueueType* qptr)
{
	
	if (is_empty(qptr)) {
		printf("큐가 공백상태입니다.\n");
	}
	
	qptr->front = (qptr->front + 1) % MAX_QUEUE_SIZE;
	return qptr->data[qptr->front];
}

void queue_print(QueueType* qptr)
{
	printf("QUEUE(front=%d rear=%d) = ",qptr->front, qptr->rear);
	if (!is_empty(qptr)) {
		int i = qptr->front;
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d | ", qptr->data[i]);
			if (i == qptr->rear) break;
		} while (i != qptr->front);
	}
	printf("\n");
}

int main()
{
		QueueType q;
		int element;
		int num; // 메뉴 선택 변수
		int out; // 데이터 출력 변수

		init_queue(&q); // 큐 초기화

	do {
		printf("=========   MENU   ===========\n");
		printf("1. Input data and Enqueue\n");
		printf("2. Dequeue and Print data\n");
		printf("3. Print Queue\n");
		printf("4. Exit\n");

		// 메뉴 선택
		printf("Select number : ");
		scanf_s("%d", &num);
		printf("\n");

		// 데이터 입력
		if (num == 1)
		{
			if (!is_full(&q)) {
				printf("Input the data : ");
				scanf_s("%d", &element);

				enqueue(&q, element);
				printf("Enqueue : %d\n", element);
			}
			else printf("Queue is full!\n");
		}

		// 큐에 저장된 값 빼기
		else if (num == 2)
		{
			out = dequeue(&q);
			printf("Dequeue : %d\n", out);

		}

		// 큐 프린트
		else if (num == 3)
		{
			printf("Print Queue : \n");
			queue_print(&q);
		}

		// 종료
		else if (num == 4)
		{
			break;
		}
	} while (1);

	printf("Exit the program.\n");
	return 0;
}