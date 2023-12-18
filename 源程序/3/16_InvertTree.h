void InvertTree(BiTree &T){
    //通过递归，到叶子节点，然后return以后再进行左右调换
    if(T==NULL) return;
    if(T->lchild) InvertTree(T->lchild);
    if(T->rchild) InvertTree(T->rchild);
    //说明已经到还没有调换的倒数第二层
    if(T->lchild && T->rchild){
        BiTree p=T->lchild;
        T->lchild = T->rchild;
        T->rchild = p;
    }
    else return;
}
/*
 *      1
 *     2    3
 *    4 _  5    6
 */
//1 a 2 b 4 c 0 n 0 n  0 n 3 f 5 g 0 n 0 n 6 g 0 n 0 n -1 n
//1 a 2 b 4 c 0 n 0 n  7 i 0 n 0 n  3 f 5 g 0 n 0 n 6 g 0 n 0 n -1 n