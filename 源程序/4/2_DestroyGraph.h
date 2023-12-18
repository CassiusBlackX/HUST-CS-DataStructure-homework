status DestroyGraph(ALGraph &G)
/*销毁无向图G,删除G的全部顶点和边*/
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i;
    ArcNode *p, *q;
    for (i = 0; i < G.vexnum; i++) {
        p = G.vertices[i].firstarc;
        while (p != NULL) {
            q = p->nextarc;
            free(p);
            p = q;
        }
    }
    G.vexnum = 0;
    G.arcnum = 0;
    return OK;
    /********** End **********/
}
