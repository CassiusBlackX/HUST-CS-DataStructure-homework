/*
 * 功能说明：e是和T中结点关键字类型相同的给定值。删除T中关键字为e的结点；同时，根据该被删结点的度进行讨论：
如关键字为e的结点度为0，删除即可；
如关键字为e的结点度为1，用关键字为e的结点孩子代替被删除的e位置；
如关键字为e的结点度为2，用e的左子树（简称为LC）代替被删除的e位置，将e的右子树（简称为RC）作为LC中最右节点的右子树。
成功删除结点后返回OK，否则返回ERROR。
 */

BiTree FindParent(BiTree T, KeyType e) {
    if (T == NULL) {  // 空树
        return NULL;
    }
    if ((T->lchild != NULL && T->lchild->data.key == e) || (T->rchild != NULL && T->rchild->data.key == e)) {  // 当前节点的左子节点或右子节点为目标节点
        return T;
    }
    BiTree parent = FindParent(T->lchild, e);  // 在左子树中查找
    if (parent != NULL) {  // 在左子树中找到了
        return parent;
    }
    parent = FindParent(T->rchild, e);  // 在右子树中查找
    if (parent != NULL) {  // 在右子树中找到了
        return parent;
    }
    return NULL;  // 没有找到目标节点
}
BiTree FindRightestLeaf(BiTree root) {
    // 如果根节点为空，则返回空指针
    if (root == NULL) {
        return NULL;
    }
    // 如果根节点是叶子节点，则返回该节点
    if (root->lchild == NULL && root->rchild == NULL) {
        return root;
    }
    // 否则先向右子树递归查找
    BiTree right = FindRightestLeaf(root->rchild);
    // 如果右子树有叶子节点，则返回该节点
    if (right != NULL) {
        return right;
    }
    // 如果右子树没有叶子节点，则继续向左子树递归查找
    return FindRightestLeaf(root->lchild);
}
status DeleteNode(BiTree &T,KeyType e)
//删除结点。此题允许通过增加其它函数辅助实现本关任务
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(T==NULL) return INFEASIBLE;
    BiTree q;
    //要先判断，如果根节点就是要删除的点的话要单独走
    if(T->data.key==e){
        if(T->lchild==NULL && T->rchild==NULL) T=NULL;//如果T下面什么都没有，T也NULL就可以了
        else if(T->rchild!=NULL && T->lchild!=NULL){
            //如果度为二，取左孩子作为二叉树根节点，左孩子树的最右节点的右孩子接上T的右孩子
            BiTree rightest= FindRightestLeaf(T->lchild);
            rightest->rchild=T->rchild;
            q = T;
            T = T->lchild;
            free(q);
            q=NULL;
        }
        else{
            //度为1
            q = T;
            if(T->lchild!=NULL){
                T = T->lchild;
            }
            else{
                T = T->rchild;
            }
            free(q);
            q=NULL;
        }
        return OK;
    }
    BiTree parent = FindParent(T,e);
    if(parent==NULL) return ERROR;
    int side=0;
    if(parent->lchild->data.key==e){
        side = 0;//目标节点q是parent的左孩子
        q=parent->lchild;
    }
    else if(parent->rchild->data.key==e) {
        side = 1;//目标节点q是parent的右孩子
        q=parent->rchild;
    }
    if(q->lchild==NULL && q->rchild==NULL){
        //度为0，可以直接删除
        if(side==0) parent->lchild=NULL;
        else parent->rchild=NULL;
    }
    else if(q->lchild!=NULL && q->rchild!=NULL){
        //度为2，用q的左子树代替被删除的q的位置，将q的右子树作为q的左子树中最右节点的右子树
        if(side==0) parent->lchild=q->lchild;
        else parent->rchild=q->lchild;
        BiTree rightest = FindRightestLeaf(q->lchild);
        rightest->rchild=q->rchild;
    }
    else{
        //度为1，用q的子节点代替q
        int qside=0;
        if(q->lchild!=NULL) qside=0;
        else qside=1;
        if(side==0){
            if(qside==0) parent->lchild=q->lchild;
            else parent->lchild=q->rchild;
        }
        else{
            if(qside==0) parent->rchild=q->lchild;
            else parent->rchild=q->rchild;
        }
    }
    free(q);
    return OK;
    /********** End **********/
}
/*
 * 测试输入：1 1 a    2 2 b     3 3 c    6 4 d    7 5 e    0 0 null   1
预期输出：
 2,b 3,c 4,d 5,e
 2,b 4,d 3,c 5,e

测试输入：1 1 a    2 2 b     3 3 c    6 4 d    7 5 e    0 0 null   10
 预期输出：  删除操作失败
 */
/*
 *      1
 *     2    3
 *         4    5
 */
/*
 *      1
 *     2    3
 *      6  4   5
 */

//1 1 a  2 2 b 5 6 f  3 3 c     6  4 d   7  5 e   0  0 null  10
/*
 *      1
 *     2    3
 *      6  4  5
 */

/*
 *      1
 *     2    3
 *    4 5  6    7
 *
 *      1
 *     4    3
 *      5  6    7
 */