//因为没有明确说明，顶点v本身到v到的距离也小于k，所以也算在里面了
int* VerticesSetLessThanK(ALGraph G, int v, int k) {
    // 初始化visited数组，表示所有顶点都未访问过
    for (int i = 0; i < G.vexnum; i++) {
        visited[i] = FALSE;
    }

    // 初始化队列，将起点v入队，并标记为已访问
    v = LocateVex(G,v);
    Queue Q;
    InitQueue(Q);
    Enqueue(Q, v);
    visited[v] = TRUE;

    // 记录距离起点v的距离
    int distance[MAX_VERTEX_NUM];
    for (int i = 0; i < G.vexnum; i++) {
        distance[i] = -1;
    }
    distance[v] = 0;

    // 遍历队列，找到距离起点v小于k的所有顶点
    while (!IsEmpty(Q)) {
        int u;
        Dequeue(Q, u);
        ArcNode* p = G.vertices[u].firstarc;
        while (p) {
            int w = p->adjvex;
            if (!visited[w]) {
                visited[w] = TRUE;
                distance[w] = distance[u] + 1;
                if (distance[w] < k) {
                    Enqueue(Q, w);
                }
            }
            p = p->nextarc;
        }
    }

    // 构建结果集合
    int* result = (int*)malloc(sizeof(int) * G.vexnum);
    int count = 0;
    for (int i = 0; i < G.vexnum; i++) {
        if (distance[i] != -1 && distance[i] < k) {
            result[count++] = G.vertices[i].data.key;
        }
    }
    result[count] = -1; // 用-1表示集合结束
    return result;
}
