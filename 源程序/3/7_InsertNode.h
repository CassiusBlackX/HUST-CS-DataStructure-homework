status InsertNode(BiTree &T,KeyType e,int LR,TElemType c)
//插入结点。此题允许通过增加其它函数辅助实现本关任务
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(T==NULL) return INFEASIBLE;
    BiTree p= LocateNode(T,e);
    if(p==NULL)return ERROR;
    BiTree q=(BiTree) malloc(sizeof(BiTNode));
    q->data=c;
    q->lchild=q->rchild=NULL;
    if (LR==0){//0左1右
        //作为左子节点
        if(p->lchild==NULL){
            //如果该节点本来就没有左子节点，那么直接赋值就好
            p->lchild=q;
        }
        else{
            //如果本来左子节点就有东西，那么把左子节点变为右子节点,然后再把c赋值上去
            if(p->rchild==NULL){
                p->rchild=p->lchild;
                p->lchild=q;
            }
            else{
                //如果原来节点有左右子节点，把p的原来的左子树作为q的右子树
                q->rchild=p->lchild;
                p->lchild=q;
            }
        }
    }
    else if(LR==1){
        //做右子节点
        if(p->rchild==NULL){
            //如果该节点本来就没有右子节点，那么直接赋值就好
            p->rchild=q;
        }
        else{
            if(p->lchild==NULL){
                p->lchild=p->rchild;
                p->rchild=q;
            }
            else return ERROR;
        }
    }
    else{
        //LR==-1,作为根节点插入,原根节点作为q的右子树
        BiTree tmp = T;
        q->rchild = tmp;
        T=q;
    }
    int lst[1000]={0};
    if(check(T,lst))return OK;
    else return ERROR;
    return OK;
    /********** End **********/
}

//1 1 a  2 2 b  3 3 c     6  4 d   7  5 e   0  0 null 3 -1 6 f
/*
 *      1
 *     2   3
 *        4  5
 */
/*
 *      6
 *          1
 */


/*
 *      1
 *    2     _
 *  3   4
 * _ _ 5  _
 */
//实际产生的二叉链表
/*
 *      1
 *    2     3
 *   _  _  4  5
 *
 */