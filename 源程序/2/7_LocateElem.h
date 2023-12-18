status LocateElem(LinkList L,ElemType e)
// 如果线性表L存在，查找元素e在线性表L中的位置序号；如果e不存在，返回ERROR；当线性表L不存在时，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L==NULL) return INFEASIBLE;
    LinkList p=L->next;
    if(p==NULL) return ERROR;
    int cnt=0;
    while(p->next!=NULL){
        cnt++;
        if(p->data==e) return cnt;
        p=p->next;
    }
    return ERROR;

    /********** End **********/
}
