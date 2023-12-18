void DFS(ALGraph G, int v, void (*visit)(VertexType)) {
    visited[v] = TRUE;  // 标记顶点v为已访问
    visit(G.vertices[v].data);  // 访问顶点v

    // 遍历顶点v的邻接顶点
    ArcNode *p = G.vertices[v].firstarc;
    while (p != NULL) {
        int adjvex = p->adjvex;
        if (visited[adjvex] == FALSE) {
            DFS(G, adjvex, visit);
        }
        p = p->nextarc;
    }
}

status DFSTraverse(ALGraph &G, void (*visit)(VertexType)) {
    // 初始化访问标记数组
    for (int i = 0; i < G.vexnum; i++) {
        visited[i] = FALSE;
    }
    // 因为图未必是完全连通的
    // 对每个未访问过的顶点进行深度优先搜索
    for (int i = 0; i < G.vexnum; i++) {
        if (visited[i] == FALSE) {
            DFS(G, i, visit);
        }
    }

    return OK;
}
