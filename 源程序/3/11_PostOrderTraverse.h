status PostOrderTraverse(BiTree T,void (*visit)(BiTree))
//后序遍历二叉树T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(T==NULL) return INFEASIBLE;
    Stack * S1 = createStack();
    Stack * S2 = createStack();
    push(S1,T);

    while(!isEmpty(S1)){
        BiTree node = pop(S1);
        push(S2,node);
        if(node->lchild!=NULL){
            push(S1,node->lchild);
        }
        if(node->rchild!=NULL){
            push(S1,node->rchild);
        }
    }

    while(!isEmpty(S2)){
        visit(pop(S2));
    }
    destroyStack(S1);
    destroyStack(S2);
    return OK;
    /********** End **********/
}
