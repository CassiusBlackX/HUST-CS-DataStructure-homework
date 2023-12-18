status RemoveNthFromEnd(LinkList &L,int n,ElemType &e){
    if(L==NULL)return INFEASIBLE;
    int length = ListLength(L);
    if(n>length || n<=0)return ERROR;
    int index=length+1-n;
    return ListDelete(L,index,e);
}