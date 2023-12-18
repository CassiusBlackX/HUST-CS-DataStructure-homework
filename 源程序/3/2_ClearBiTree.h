status DestroyBiTree(BiTree &T)
//将二叉树设置成空，并删除所有结点，释放结点空间
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(T==NULL) return INFEASIBLE;
    if(T->lchild!=NULL) DestroyBiTree(T->lchild);
    if(T->rchild!=NULL) DestroyBiTree(T->rchild);
    BiTree p = T;
    free(p);
    T=NULL;
    return OK;
}
status ClearBiTree(BiTree &T){
    if (T==NULL) return INFEASIBLE;
    if(T->lchild!=NULL) ClearBiTree(T->lchild);
    if(T->rchild!=NULL) ClearBiTree(T->rchild);
    T->data.key=0;
    //TODO:这里只是把每一个节点的key给改成0了，并没有东others。理论上似乎应该需要动的才对的。
//    free(T->data.others);
    return OK;
}

/*
 *      1
 *    2   3
 *  4   5
 */