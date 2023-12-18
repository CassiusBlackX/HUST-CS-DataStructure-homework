status ListDelete(SqList &L,int i,ElemType &e)
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem==NULL) return INFEASIBLE;
    if(i<=0||i>=L.length) return ERROR;
    e=L.elem[i-1];
    for(int j=i-1;j<L.length-1;j++){
        L.elem[j]=L.elem[j+1];
    }
    L.length--;
    return OK;
    /********** End **********/
}
