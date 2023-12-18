status InitMultiLists(LISTS &ML){
//    if(ML.elem!=NULL) return INFEASIBLE;
    //但是不知道如何给这个多级别线性表分配空间！
    //只能指望编译器能够自己分配空间了
    printf("请输入将要输入的线性表的个数\n");
    int n;
    char name[30];
    scanf("%d",&n);
    printf("请输入线性表的名字\n");
    while(n--){
        scanf("%s",name);
        if(ML.length<ML.listsize){
            strcpy(ML.elem[ML.length].name,name);
            ML.elem[ML.length].L.elem=NULL;
            InitList(ML.elem[ML.length].L);
            ML.length++;
        }
        else {
            printf("线性表个数超出多线性表的容量了！\n");
            return ERROR;
        }
        printf("请输入线性表的名字\n");
    }
    return OK;
}