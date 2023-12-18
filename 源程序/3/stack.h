typedef struct StackNode {
    BiTNode* data; // 栈中存储二叉树节点的指针
    struct StackNode* next; // 指向下一个节点的指针
} StackNode;

typedef struct {
    StackNode* top; // 栈顶指针
} Stack;

// 创建一个空栈
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

// 销毁栈
void destroyStack(Stack* stack) {
    if (stack == NULL) {
        return;
    }
    StackNode* current = stack->top;
    while (current != NULL) {
        StackNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(stack);
}

// 判断栈是否为空
bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// 将一个节点压入栈中
void push(Stack* stack, BiTNode* data) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
}

// 弹出栈顶元素
BiTNode* pop(Stack* stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    BiTNode* data = stack->top->data;
    StackNode* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}