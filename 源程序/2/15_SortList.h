void  my_swap(LinkList &p,LinkList &q){
    ElemType tmp=p->data;
    p->data=q->data;
    q->data= tmp;
}
status SortList(LinkList L){
    if(L==NULL) return INFEASIBLE;
    if(L->next==NULL) return ERROR;
    LinkList p=L->next;
    int length = ListLength(L);
    for(int i=0;i<length-1;i++){
        p = L->next;
        for(int j=0;j<length-i-1;j++){
            if(p->data>p->next->data){
                my_swap(p,p->next);
            }
            p=p->next;
        }
    }
    return OK;
}

status SortList(LinkList start, LinkList end){
    if(start == end || start == NULL) return OK;
   LinkList p=start,q=start->next;
   while(q!=end){
       if(q->data < start->data){
           p = p->next;
           my_swap(p,q);
       }
       q = q->next;
   }
    my_swap(p,start);
    SortList(start, p);
    SortList(p->next, end);
}