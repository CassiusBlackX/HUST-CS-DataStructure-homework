status InsertArc(ALGraph &G,KeyType v,KeyType w)
//在图G中增加弧<v,w>，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i, j;

    // 查找顶点v在顶点数组中的位置
    for (i = 0; i < G.vexnum; i++) {
        if (G.vertices[i].data.key == v)
            break;
    }

    // 未找到顶点v，返回错误
    if (i == G.vexnum)
        return ERROR;

    // 查找顶点w在顶点数组中的位置
    for (j = 0; j < G.vexnum; j++) {
        if (G.vertices[j].data.key == w)
            break;
    }

    // 未找到顶点w，返回错误
    if (j == G.vexnum)
        return ERROR;

    // 检查弧<v, w>是否已经存在
    ArcNode *p = G.vertices[i].firstarc;
    while (p != NULL) {
        if (p->adjvex == j)
            return ERROR;  // 弧<v, w>已经存在，返回错误
        p = p->nextarc;
    }

    // 创建弧<v, w>
    ArcNode *arc_vw = (ArcNode*)malloc(sizeof(ArcNode));
    arc_vw->adjvex = j;
    arc_vw->nextarc = G.vertices[i].firstarc;
    G.vertices[i].firstarc = arc_vw;

    // 创建弧<w, v>
    ArcNode *arc_wv = (ArcNode*)malloc(sizeof(ArcNode));
    arc_wv->adjvex = i;
    arc_wv->nextarc = G.vertices[j].firstarc;
    G.vertices[j].firstarc = arc_wv;
    G.arcnum++;//最后只加一条边

    return OK;
    /********** End **********/
}