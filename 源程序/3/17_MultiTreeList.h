status InitMultiTreeList(MultiTreeList &MT){
    printf("请输入将要初始化的二叉树的个数\n");
    int n;
    TElemType definition[100]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("请输入二叉树的名字(每个二叉树的名字不能重复！)\n");
        scanf("%s",MT.elem[i].name);
        printf("请输入二叉链表的值，以key=-1结尾\n");
        int j=0;
        do{
            scanf("%d %s",&definition[j].key,definition[j].others);
        }while(definition[j++].key!=-1);
        int result = CreateBiTree(MT.elem[i].T,definition);
        if(result==INFEASIBLE) {
            printf("当前索引下的二叉链表已经存在，不能再次创建！\n");
            return ERROR;
        }
        else if(result==ERROR) {
            printf("key不唯一\n");
            return ERROR;
        }
        else {
            printf("二叉链表创建成功\n");
            MT.length++;
        }
    }
    return OK;
}

status SwitchTree(MultiTreeList MT,char treename[],BiTree &L){
    for(int i=0;i<MT.length;i++){
        if (strcmp(treename,MT.elem[i].name)==0){
            printf("成功找到名字为%s的二叉树\n",treename);
            if(L!=NULL) printf("当前二叉树存在，将覆盖原来二叉树\n");
            L = MT.elem[i].T;
            printf("接下来的操作都将针对%s的二叉树进行\n",treename);
            return OK;
        }
    }
    printf("找不到名为%s的二叉树\n",treename);
    return ERROR;
}

status ShowAllTree(MultiTreeList MT){
    if(MT.elem==NULL) return INFEASIBLE;
    if(MT.length==0) printf("线性表为空\n");
    else {
        for (int i = 0; i < MT.length; i++) {
            printf("第%d个树名为%s，先序遍历序列为：\n", i, MT.elem[i].name);
            PreOrderTraverse(MT.elem[i].T, visit);
            printf("\n");
        }
    }
    return OK;
}

status AddTree(MultiTreeList &MT){
    printf("请输入新树的名字\n");
    char treename[30];
    scanf("%s",treename);
    for(int i=0;i<MT.length;i++){
        if(strcmp(treename,MT.elem[i].name)==0){
            printf("树名不能重复\n");
            return ERROR;
        }
    }
    strcpy(MT.elem[MT.length].name,treename);
    TElemType definition[100]={0};
    printf("请输入二叉链表的值，以key=-1结尾\n");
    int j=0;
    do{
        scanf("%d %s",&definition[j].key,definition[j].others);
    }while(definition[j++].key!=-1);
    int result = CreateBiTree(MT.elem[MT.length].T,definition);
    if(result==INFEASIBLE) {
        printf("当前索引下的二叉链表已经存在，不能再次创建！\n");
        return ERROR;
    }
    else if(result==ERROR) {
        printf("key不唯一\n");
        return ERROR;
    }
    else {
        printf("二叉链表创建成功\n");
        MT.length++;
    }
    return OK;
}

status DeleteTree(MultiTreeList &MT){
    printf("请输入你想要删除的树的名字\n");
    char treename[30];
    scanf("%s",treename);
    for(int i=0;i<MT.length;i++){
        if(strcmp(MT.elem[i].name,treename)==0){
            printf("查找成功\n");
            BiTree p=MT.elem[i].T;
            free(p);
            MT.elem[i].T=NULL;
            for(int j=i;j<MT.length-1;j++){
                MT.elem[j]=MT.elem[j+1];
            }
            MT.length--;
//            free(p);
//            p=NULL;
            printf("已释放该二叉树所占的空间\n");
            return OK;
        }
    }
    printf("查找失败\n");
    return ERROR;
}