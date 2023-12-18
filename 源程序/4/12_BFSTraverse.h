void BFSTraverse(ALGraph &G, void (*visit)(VertexType)) {
    int i;
    Queue Q;  // 定义队列Q用于广度优先搜索
    InitQueue(Q);

    // 初始化访问标记数组
    for (i = 0; i < G.vexnum; i++) {
        visited[i] = FALSE;
    }

    // 对每个未访问过的顶点进行广度优先搜索
    for (i = 0; i < G.vexnum; i++) {
        if (visited[i] == FALSE) {
            visited[i] = TRUE;
            visit(G.vertices[i].data);  // 访问顶点i

            Enqueue(Q, i);  // 将顶点i入队

            while (!IsEmpty(Q)) {
                int v;
                Dequeue(Q, v);  // 出队顶点v

                // 遍历顶点v的邻接顶点
                ArcNode *p = G.vertices[v].firstarc;
                while (p != NULL) {
                    int adjvex = p->adjvex;
                    if (visited[adjvex] == FALSE) {
                        visited[adjvex] = TRUE;
                        visit(G.vertices[adjvex].data);  // 访问顶点adjvex
                        Enqueue(Q, adjvex);  // 将顶点adjvex入队
                    }
                    p = p->nextarc;
                }
            }
        }
    }
}
