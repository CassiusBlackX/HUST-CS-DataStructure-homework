status InitMultiGraph(GraphManager &graphManager){
    int n,result;
    printf("请输入将要创建的图的个数\n");
    scanf("%d",&n);
    char name[30];
    for(int i=0;i<n;i++){
        printf("请输入图的名字\n");
        scanf("%s",name);
        strcpy(graphManager.elem[i].name,name);
        result = CreateGraph(graphManager.elem[i].G);
        if(result==ERROR){
            printf("创建图失败！\n");
            return ERROR;
        }
        graphManager.length++;
    }
    return OK;
}
status GrapthAdd(GraphManager &graphManager){
    if(graphManager.length>= graphManager.listsize) return ERROR;
    printf("请输入将要添加的图的名称\n");
    char name[30];
    scanf("%s",name);
    strcpy(graphManager.elem[graphManager.length].name,name);
    int result = CreateGraph(graphManager.elem[graphManager.length].G);
    if(result==ERROR) {
        printf("添加图失败\n");
        return ERROR;
    }
    graphManager.length++;
    return OK;
}
status GraphDelete(GraphManager &graphManager){
    char name[30];
    printf("请输入将要删除的图的名字\n");
    scanf("%s",name);
    for(int i=0;i<graphManager.length;i++){
        if(strcmp(name,graphManager.elem[i].name)==0){
            int result = DestroyGraph(graphManager.elem[i].G);
            if(result==ERROR) {
                printf("删除图失败\n");
                return ERROR;
            }
            for(int j=i;j<graphManager.length-1;j++){
                graphManager.elem[j] = graphManager.elem[j+1];
            }
            graphManager.length--;
            return OK;
        }
    }
    printf("查找不到名为%s的图\n",name);
    return ERROR;
}
status GraphSwitch(GraphManager graphManager,ALGraph &G){
    char name[30];
    printf("请输入将要切换的图的名字\n");
    scanf("%s",name);
    for(int i=0;i<graphManager.length;i++){
        if(strcmp(name,graphManager.elem[i].name)==0){
            printf("成功找到名为%s的图，接下来的操作都将在该图上\n",name);
            G = graphManager.elem[i].G;
            return OK;
        }
    }
    printf("查找失败\n");
    return ERROR;
}
status MultiGraphShow(GraphManager graphManager){
    for(int i=0;i<graphManager.length;i++){
        printf("%s\n",graphManager.elem[i].name);
        PrintList(graphManager.elem[i].G);
    }
    return OK;
}