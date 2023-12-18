int BiTreeDepth(BiTree T)
//求二叉树T的深度
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (T == NULL || T->data.key==0) {
        return 0;
    } else {
        int left_depth =  BiTreeDepth(T->lchild);
        int right_depth = BiTreeDepth(T->rchild);
        return (left_depth > right_depth ? left_depth : right_depth) + 1;
    }

    /********** End **********/
}
