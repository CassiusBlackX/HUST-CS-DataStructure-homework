status check(ALGraph &G,VertexType V[],KeyType VR[][2]){
    if(V[0].key==-1) return ERROR;
    for (int i = 0; V[i].key != -1; i++) {
        G.vertices[i].data = V[i]; // 将顶点序列按V中的次序依次存放在表头结点数组中
        //其实从功能性的角度来说，这一步应该是在下面的create里面做的，但是既然在这里需要统计，那么就顺便在这里面就把它加进去好了
        G.vexnum++; // 统计顶点数
        if(i > MAX_VERTEX_NUM) return ERROR;
        for(int j=0;j<G.vexnum-1;j++){
            if(V[j].key==V[i].key) return ERROR;
        }
    }
    int flag=0;
    for(int i=0;VR[i][0]!=-1;i++){
        for(int j=0;j<G.vexnum;j++){
            if(VR[i][0]==V[j].key) {
                flag=1;
                break;
            }
        }
        for(int j=0;j<G.vexnum;j++){
            if(VR[i][1]==V[j].key) {
                flag&=1;
                break;
            }
        }
        if (flag==0) return ERROR;
        flag = 0;
    }
    return OK;
}
int locateNode(VertexType V[],KeyType VR[][2],int i,int j){
    int v = VR[i][j];
    int k=0;
    while(V[k].key!=-1){
        if(V[k].key==v) return k;
        k++;
    }
}
status CreateGraph(ALGraph &G) {
    //读入数据
    VertexType V[MAX_VERTEX_NUM];
    KeyType VR[100][2];
    printf("请输入图的顶点的key和对应的others\n");
    int i=0;
    do{
        scanf("%d%s",&V[i].key,V[i].others);
    }while(V[i++].key!=-1);
    i=0;
    printf("请输入图的边\n");
    do {
        scanf("%d%d",&VR[i][0],&VR[i][1]);
    } while(VR[i++][0]!=-1);

    ArcNode *p;
    G.vexnum = 0;
    G.arcnum = 0;
    G.kind = UDG;
    for (int i = 0; i < MAX_VERTEX_NUM; i++) {
        G.vertices[i].data.key = -1;
        G.vertices[i].firstarc = NULL;
    }
    int result = check(G,V,VR);
//    for (int i = 0; i<G.vexnum; i++) {
//        G.vertices[i].data = V[i]; // 将顶点序列按V中的次序依次存放在表头结点数组中
//    }
    if(result==ERROR) return ERROR;
    for (int i = 0; VR[i][0] != -1; i++) {
        int v1 = locateNode(V,VR,i,0), v2 = locateNode(V,VR,i,1);
        // 处理VR中的关系，采用首插法，将表结点插入到对应的链表中
        p = (ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex = v2; // 将该结点的邻接点设置为v2
        p->nextarc = G.vertices[v1].firstarc; // 将该结点插入到v1的邻接表中
        G.vertices[v1].firstarc = p;
//        G.arcnum++;
        // 由于是无向图，因此需要再处理一次，不过其实就是反过来，对称的弄一遍就可以了
        p = (ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex = v1;
        p->nextarc = G.vertices[v2].firstarc;
        G.vertices[v2].firstarc = p;
        G.arcnum++;
    }
    return OK;
}
void PrintList(ALGraph G){
    for(int i=0;i<G.vexnum;i++){
        printf("%d %s ",G.vertices[i].data.key,G.vertices[i].data.others);
        ArcNode *p = G.vertices[i].firstarc;
        while(p!=NULL){
            printf("%d ",p->adjvex);
            p = p->nextarc;
        }
        printf("\n");
    }
}