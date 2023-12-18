status ReverseList(LinkList &L){
    if(L==NULL)return INFEASIBLE;
    if(L->next==NULL){
        printf("线性表为空\n");
        return OK;
    }
    int length = ListLength(L);
    LinkList prev=L->next,cur=prev->next,nxt=(LinkList) malloc(sizeof(LNode));
    prev->next=NULL;
    for(int i=1;i<length;i++){
        nxt=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nxt;
        //就是不断地把每个节点的"next"指向它的前一个节点，就变成了形式意义上的反转
    }
    L->next=prev;//最后再把头节点接到反转后的链表的第一个节点前就完成了反转
    return OK;
}
//H 1 2 3
//  p q tmp
//H 2 3 1
//  p q