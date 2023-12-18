BiTNode* LocateNode(BiTree T,KeyType e)
//查找结点
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (T == NULL) {
        return NULL;    // 空树返回NULL
    } else if (T->data.key == e) {
        return T;    // 找到了目标结点，返回结点指针
    } else {
        BiTree left = LocateNode(T->lchild, e);   // 在左子树中查找
        BiTree right = LocateNode(T->rchild, e);  // 在右子树中查找

        if (left != NULL) {
            return left;    // 左子树中找到了目标结点，返回结点指针
        } else {
            return right;   // 右子树中找到了目标结点，返回结点指针，若没找到也返回NULL
        }
    }
}
status BiTreeEmpty(BiTree T){
    if(T==NULL) return INFEASIBLE;
    if(T->lchild==NULL && T->rchild==NULL) return TRUE;
    else if(T->lchild->data.key==0 || T->rchild->data.key==0) return TRUE;
    else return FALSE;
}