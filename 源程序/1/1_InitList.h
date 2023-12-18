status InitList(SqList& L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem==NULL)
    {
        printf("请输入数字，以0结尾\n");
        L.elem=(ElemType *) malloc(sizeof(ElemType)*LIST_INIT_SIZE);
        L.listsize=LIST_INIT_SIZE;
        L.length=0;
        ElemType x;
        scanf("%d",&x);
        while(x){
            if(L.length+1>=L.listsize) {
                L.elem = (ElemType *) realloc(L.elem, sizeof(ElemType) * (LIST_INIT_SIZE + LISTINCREMENT));
                L.listsize+=LISTINCREMENT;
            }
            L.elem[L.length++]=x;
            scanf("%d",&x);
        }
        return OK;
    }
    else return INFEASIBLE;
    /********** End **********/
}
