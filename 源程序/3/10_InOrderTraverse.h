status InOrderTraverse(BiTree T,void (*visit)(BiTree))
//中序遍历二叉树T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(T==NULL) return INFEASIBLE;
    Stack * stack = createStack();
    BiTree node=T;
    while(node!=NULL || !isEmpty(stack)){
        while(node){
            push(stack,node);
            node=node->lchild;
        }
        node = pop(stack);
        visit(node);
        node = node->rchild;
    }
    destroyStack(stack);
    return OK;
    /********** End **********/
}
