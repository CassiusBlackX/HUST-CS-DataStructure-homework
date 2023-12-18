typedef struct Queue {
    BiTree data;
    struct Queue *next;
} Queue;

// 初始化队列
void initQueue(Queue **pHead, Queue **pTail) {
    *pHead = (Queue *)malloc(sizeof(Queue));
    (*pHead)->next = NULL;
    *pTail = *pHead;
}

// 入队
void enqueue(Queue **pTail, BiTree t) {
    Queue *pNew = (Queue *)malloc(sizeof(Queue));
    pNew->data = t;
    pNew->next = NULL;
    (*pTail)->next = pNew;
    *pTail = pNew;
}

// 出队
BiTree dequeue(Queue **pHead, Queue **pTail) {
    if (*pHead == *pTail) {  // 队列为空
        return NULL;
    }
    Queue *p = (*pHead)->next;
    BiTree res = p->data;
    (*pHead)->next = p->next;
    if (*pTail == p) {  // 如果队尾指针指向要出队的节点
        *pTail = *pHead;  // 队尾指针指向头节点
    }
    free(p);
    return res;
}

//销毁队列
void destroyQueue(Queue *phead){
    Queue *p=phead;
    while(p){
        phead=phead->next;
        free(p);
        p=phead;
    }
}