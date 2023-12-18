status ListDelete(LinkList &L,int i,ElemType &e)
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L==NULL)return INFEASIBLE;
    if(L->next==NULL) return ERROR;
    if(i<=0)return ERROR;
    LinkList p=L;
    for(int j=1;j<i;j++){
        if(p==NULL) return ERROR;
        p=p->next;
    }
    if(p->next==NULL) return ERROR;
    LinkList q=p->next;
    e=q->data;
    p->next=q->next;
    free(q);
    return OK;

    /********** End **********/
}
