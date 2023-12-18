status LevelOrderTraverse(BiTree T,void (*visit)(BiTree))
//按层遍历二叉树T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(T==NULL) return INFEASIBLE;
    Queue *phead,*ptail;
    initQueue(&phead,&ptail);
    enqueue(&ptail,T);
    while(phead!=ptail){
        BiTree node = dequeue(&phead,&ptail);
        visit(node);
        if(node->lchild!=NULL){
            enqueue(&ptail,node->lchild);
        }
        if(node->rchild!=NULL){
            enqueue(&ptail,node->rchild);
        }
    }
    destroyQueue(phead);
    return OK;
    /********** End **********/
}