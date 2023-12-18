status DeleteArc(ALGraph &G,KeyType v,KeyType w)
//在图G中删除弧<v,w>，成功返回OK,否则返回ERROR
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

    // 查找弧<v, w>并删除
    ArcNode *p = G.vertices[i].firstarc;
    ArcNode *q = NULL;

    while (p != NULL) {
        if (p->adjvex == j) {
            // 删除弧<v, w>
            if (q == NULL) {
                G.vertices[i].firstarc = p->nextarc;
            } else {
                q->nextarc = p->nextarc;
            }
            free(p);
//            G.arcnum--;
            break;
        }
        q = p;
        p = p->nextarc;
    }

    // 查找弧<w, v>并删除
    p = G.vertices[j].firstarc;
    q = NULL;

    while (p != NULL) {
        if (p->adjvex == i) {
            // 删除弧<w, v>
            if (q == NULL) {
                G.vertices[j].firstarc = p->nextarc;
            } else {
                q->nextarc = p->nextarc;
            }
            free(p);
            G.arcnum--;
            break;
        }
        q = p;
        p = p->nextarc;
    }

    return OK;

    /********** End **********/
}