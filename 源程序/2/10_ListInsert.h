status ListInsert(LinkList &L,int i,ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L==NULL) return INFEASIBLE;
    if(i==0) return ERROR;
    LinkList p;
//    if(L->next==NULL){
//        p = (LinkList) malloc(sizeof(LNode));
//        p->next=NULL;
//    }
    p=L;
    for(int j=1;j<i;j++){
        if(p==NULL)return ERROR;
        p=p->next;
    }
    if(p==NULL)return ERROR;
    LinkList q = (LinkList) malloc(sizeof(LNode));
    q->data=e;
    q->next=p->next;
    p->next=q;
    return OK;
    /********** End **********/
}
