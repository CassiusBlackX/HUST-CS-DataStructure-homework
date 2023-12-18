status InitMultiLists(LISTS &ML){
    if(ML==NULL){
        ML = (LISTS) malloc(sizeof(LISTNode));
        ML->next = NULL;
        LISTS p,q=ML;
        char name[30];
        int n;
        printf("请输入将要创建的链表的个数\n");
        scanf("%d",&n);
        int result=0;
        while(n--){
            printf("请输入线性表的名字\n");
            scanf("%s",name);
            p = (LISTS) malloc(sizeof(LISTNode));
            strcpy(p->ListName,name);
            p->L=NULL;
            result = InitList(p->L);
            if(result == INFEASIBLE) {
                printf("多线性表中的一个线性表在初始化时不为空～\n");
                return INFEASIBLE;
            }
            q->next = p;
            q=p;
        }
        q->next = NULL;
        return OK;
    }
    else return INFEASIBLE;
}
status DestroyMultiLists(LISTS& ML){
   if(ML!=NULL){
       LISTS p=ML,q;
       while(p!=NULL){
           q=p->next;
           DestroyList(p->L);
           free(p);
           p=q;
       }
       ML=NULL;
       return OK;
   }
   else return INFEASIBLE;
}
status MultiListsAdd(LISTS &ML){
    //先遍历到当前LISTS的最后一个元素
    LISTS q,p=ML;
    char name[30];
    printf("请输入想要新添加的线性表的名字，然后再输入新线性表的数字，以0结尾\n");
    scanf("%s",name);
    while(p->next!=NULL && strcmp(p->ListName,name)!=0)p=p->next;
    if (strcmp(p->ListName,name)==0) return ERROR;
    int result;
    q = (LISTS) malloc(sizeof(LISTNode));
    strcpy(q->ListName,name);
    result = InitList(q->L);
    if(result==INFEASIBLE){
        printf("增加新线性表的时候新线性表表头初始时候不为空\n");
        return INFEASIBLE;
    }
    p->next=q;
    q->next=NULL;
    return OK;
}
status MultiListsDelete(LISTS &ML,char * name){
    if(ML==NULL) return INFEASIBLE;
    LISTS q=ML,p=ML->next;
    if(p==NULL) return ERROR;
    while(p->next!=NULL && strcmp(p->ListName,name)!=0) {
        q=p;
        p=p->next;
    }
    if(p->next==NULL && strcmp(p->ListName,name)!=0) return ERROR;
    int result = DestroyList(p->L);
    if(result==OK) printf("成功删除该线性表的数据部分\n");
    else {
        printf("该名称对应的线性表不存在\n");
        return INFEASIBLE;
    }
    q->next=NULL;
    free(p);
    return OK;
}
LISTS MultiListsLocate(LISTS &ML,char name[]){
    if (ML==NULL) return NULL;
    LISTS p = ML;
    while( p!=NULL &&strcmp(p->ListName,name)!=0 ){
        p=p->next;
    }
    if (p!=ML)    return p;
    else return NULL;
}