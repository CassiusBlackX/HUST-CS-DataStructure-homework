status ClearList(SqList& L)
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem==NULL) return INFEASIBLE;
    for(int i=0;i<L.length;i++)
    {
        L.elem[i]=0;
    }
    L.length=0;
    return OK;
    /********** End **********/
}
