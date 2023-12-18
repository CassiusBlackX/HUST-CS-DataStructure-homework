status PriorElem(LinkList L,ElemType e,ElemType &pre)
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L==NULL) return INFEASIBLE;
    LinkList q=L->next;
    if(q==NULL) return ERROR;
    LinkList p=L->next->next;
    if(p==NULL) return ERROR;
    while(p!=NULL){
        if(p->data==e){
            pre=q->data;
            return OK;
        }
        q=p;
        p=p->next;
    }
    return ERROR;

    /********** End **********/
}