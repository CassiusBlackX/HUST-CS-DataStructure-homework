status InitList(LinkList &L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L==NULL){
        printf("请输入数字，以0结尾\n");
        L = (LinkList ) malloc(sizeof(LNode));
        L->next = NULL;
        ElemType i;
        LNode *s,*r=L;
        scanf("%d",&i);
        while(i){
            s=(LinkList) malloc(sizeof(LNode));
            s->data = i;
            r->next = s;
            r = s;
            scanf("%d",&i);
        }
        r->next=NULL;
        return OK;
    }
    else return  INFEASIBLE;
    /********** End **********/
}