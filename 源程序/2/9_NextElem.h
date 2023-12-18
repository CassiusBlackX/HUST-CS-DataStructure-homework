status NextElem(LinkList L,ElemType e,ElemType &next)
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L==NULL) return INFEASIBLE;
    LinkList q = L->next;
    if(q==NULL) return ERROR;
    LinkList p=q->next;
    if(p==NULL) return ERROR;
    while(p!=NULL){
        if(q->data==e){
            next = p->data;
            return OK;
        }
        p=p->next;
        q=q->next;
    }
    return ERROR;

    /********** End **********/
}
