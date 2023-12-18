status GetElem(LinkList L,int i,ElemType &e)
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L==NULL) return INFEASIBLE;
    if(i<1)return ERROR;
    LinkList p = L->next;
    if(p==NULL) return ERROR;
    int count = 1;
    while(p->next!=NULL)
    {
        if(count==i) {
            e = p->data;
            return OK;
        }
        p=p->next;
        count++;
    }
    return ERROR;

    /********** End **********/
}
