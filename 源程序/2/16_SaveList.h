status SaveList(LinkList L,char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 1 *********/
    if(L==NULL)return INFEASIBLE;
    FILE *fp;
    fp=fopen(FileName,"wb");
    if(fp==NULL) {
        printf("文件打开失败\n");
        return ERROR;
    }
    LinkList p=L->next;
    while(p!=NULL){
        fprintf(fp,"%d ",p->data);
        p=p->next;
    }
    fclose(fp);
    return OK;

    /********** End 1 **********/
}

status LoadList(LinkList &L,char FileName[])
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 2 *********/
    if(L!=NULL)return INFEASIBLE;
    FILE *fp;
    fp = fopen(FileName,"rb");
    if(fp==NULL) return ERROR;
    L=(LinkList) malloc(sizeof(LNode));
    LinkList p=(LinkList) malloc(sizeof(LNode));
    L->next=p;
    int read;
    fscanf(fp,"%d",&read);
    p->data=read;
//    fread(&read, sizeof(int),100,fp);
    while(fscanf(fp,"%d",&read)!=EOF){
        LinkList q=(LinkList) malloc(sizeof(LNode));
        q->data=read;
        p->next=q;
        p=q;
    }
    p->next=NULL;
    return OK;

    /********** End 2 **********/
}
