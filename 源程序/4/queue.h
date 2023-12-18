
typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front;  // 队头指针
    int rear;   // 队尾指针
} Queue;

// 初始化队列
void InitQueue(Queue &Q) {
    Q.front = 0;
    Q.rear = 0;
}

// 判断队列是否为空
int IsEmpty(Queue Q) {
    return Q.front == Q.rear;
}

// 判断队列是否已满
int IsFull(Queue Q) {
    return (Q.rear + 1) % MAX_QUEUE_SIZE == Q.front;
}

// 入队
status Enqueue(Queue &Q, int value) {
    if (IsFull(Q)) {
        return ERROR;
    }
    Q.data[Q.rear] = value;
    Q.rear = (Q.rear + 1) % MAX_QUEUE_SIZE;
    return OK;
}

// 出队
status Dequeue(Queue &Q, int &value) {
    if (IsEmpty(Q)) {
        return ERROR;
    }
    value = Q.data[Q.front];
    Q.front = (Q.front + 1) % MAX_QUEUE_SIZE;
    return OK;
}


//------------------------------------------
typedef struct {
    int adjvex;
    int distance;
} QueueElem;

typedef struct {
    QueueElem data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queueue;

// 初始化队列
void InitQueue(Queueue *queue) {
    queue->front = queue->rear = 0;
}

// 判断队列是否为空
bool IsEmpty(Queueue *queue) {
    return queue->front == queue->rear;
}

// 入队
void Enqueue(Queueue *queue, QueueElem elem) {
    if ((queue->rear + 1) % MAX_QUEUE_SIZE == queue->front) {
        printf("Queueue is full.\n");
        return;
    }
    queue->data[queue->rear] = elem;
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
}

// 出队
QueueElem Dequeue(Queueue *queue) {
    if (IsEmpty(queue)) {
        printf("Queueue is empty.\n");
        QueueElem emptyElem = { -1, -1 };
        return emptyElem;
    }
    QueueElem elem = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    return elem;
}
