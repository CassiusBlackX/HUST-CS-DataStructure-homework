status  SaveList(SqList L,char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem==NULL) return INFEASIBLE;
    FILE * fp;
    fp = fopen(FileName,"wb");
    for(int i=0;i<L.length;i++){
        fprintf(fp,"%d ",L.elem[i]);
    }
    fclose(fp);
    return OK;
    /********** End **********/
}
status  LoadList(SqList &L,char FileName[])
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem!=NULL) return INFEASIBLE;
    L.elem=(ElemType *) malloc(sizeof(ElemType)*LIST_INIT_SIZE);
    L.listsize=LIST_INIT_SIZE;
    L.length=0;
    FILE * fp;
    fp = fopen(FileName,"rb");
    if(fp==NULL) printf("open fail");
    ElemType read;
    fscanf(fp,"%d",&read);
    L.elem[0]=read;
    L.length++;
    while(fscanf(fp,"%d",&read)!=EOF){
        if(L.length+1>=L.listsize){
            L.elem = (ElemType *) realloc(L.elem, sizeof(ElemType) * (LIST_INIT_SIZE + LISTINCREMENT));
            L.listsize+=LISTINCREMENT;
        }
        L.elem[L.length++]=read;
    }
    fclose(fp);
    return OK;
    /********** End **********/
}