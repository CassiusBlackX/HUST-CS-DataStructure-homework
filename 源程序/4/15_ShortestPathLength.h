//使用BFS 失败！
//int ShortestPathLength(ALGraph G, int v, int w) {
//    v = LocateVex(G,v);
//    if (v >= G.vexnum || v < 0 || w >= G.vexnum || w < 0) {
//        printf("Invalid vertex index.\n");
//        return -1;
//    }
//
//    Queueue queue;
//    InitQueue(&queue);
//
//    bool visited[MAX_VERTEX_NUM] = { 0 };
//    visited[v] = 1;
//
//    QueueElem startElem = { v, 0 };
//    Enqueue(&queue, startElem);
//
//    while (!IsEmpty(&queue)) {
//        QueueElem elem = Dequeue(&queue);
//        int currentVertex = elem.adjvex;
//        int currentDistance = elem.distance;
//
//        if (currentVertex == w) {
//            return currentDistance;
//        }
//
//        ArcNode *p = G.vertices[currentVertex].firstarc;
//        while (p != NULL) {
//            int adjVertex = p->adjvex;
//            if (!visited[adjVertex]) {
//                visited[adjVertex] = 1;
//                QueueElem nextElem = { adjVertex, currentDistance + 1 };
//                Enqueue(&queue, nextElem);
//            }
//            p = p->nextarc;
//        }
//    }
//
//    return -1;  // 无法找到路径
//}

/*使用dji算法*/
int ShortestPathLength(ALGraph G, KeyType v, KeyType w) {
    // 根据顶点v的key值获取其对应的位序
    int vIndex = LocateVex(G, v);
    if (vIndex == -1) {
        return -1; // 顶点v不存在
    }

    // 根据顶点w的key值获取其对应的位序
    int wIndex = LocateVex(G, w);
    if (wIndex == -1) {
        return -1; // 顶点w不存在
    }

    // 初始化visited数组，表示所有顶点都未访问过
    for (int i = 0; i < G.vexnum; i++) {
        visited[i] = FALSE;
    }

    // 初始化距离数组，表示从顶点v到各顶点的最短路径长度
    int distance[MAX_VERTEX_NUM];
    for (int i = 0; i < G.vexnum; i++) {
        distance[i] = INFINITY; // 初始时将所有顶点的距离设为无穷大
    }
    distance[vIndex] = 0; // 顶点v到自身的距离为0

    // 循环遍历顶点，更新最短路径
    for (int i = 0; i < G.vexnum; i++) {
        // 找到当前未访问的距离顶点v最近的顶点u
        int u = -1;
        int minDistance = INFINITY;
        for (int j = 0; j < G.vexnum; j++) {
            if (!visited[j] && distance[j] < minDistance) {
                u = j;
                minDistance = distance[j];
            }
        }

        if (u == -1) {
            break; // 无法继续找到可达的顶点，退出循环
        }

        visited[u] = TRUE; // 标记顶点u为已访问

        // 更新从顶点v到顶点u邻接顶点的最短路径长度
        ArcNode* p = G.vertices[u].firstarc;
        while (p != NULL) {
            int adjvex = p->adjvex;
            int weight = 1; // 假设边的权重都为1
            if (!visited[adjvex] && distance[u] + weight < distance[adjvex]) {
                distance[adjvex] = distance[u] + weight;
            }
            p = p->nextarc;
        }
    }

    return distance[wIndex]; // 返回顶点v到顶点w的最短路径长度
}
/*使用BFS*/
//int ShortestPathLength(ALGraph G, KeyType v, KeyType w)
//{
//    int i, u, len = 0;
//    Queue Q;
//    ArcNode *p;
//
//    // 初始化访问标记数组
//    for (i = 0; i < G.vexnum; i++) {
//        visited[i] = FALSE;
//    }
//
//    // 获取顶点v的位序
//    u = LocateVex(G, v);
//
//    // 初始化队列
//    InitQueue(Q);
//
//    // 先将起始顶点入队并标记已访问
//    visited[u] = TRUE;
//    Enqueue(Q, u);
//
//    while (!IsEmpty(Q)) {
//        len++;  // 每次循环，路径长度加一
//        int size = Q.rear - Q.front;
//        for (i = 0; i < size; i++) {
//            // 取出队首元素
//            Dequeue(Q, u);
//            // 遍历所有与u相邻的顶点
//            for (p = G.vertices[u].firstarc; p != NULL; p = p->nextarc) {
//                int j = p->adjvex;
//                // 如果找到目标顶点，则返回路径长度
//                if (G.vertices[j].data.key == w) {
//                    return len;
//                }
//                // 如果该顶点未被访问，则将其入队并标记已访问
//                if (!visited[j]) {
//                    visited[j] = TRUE;
//                    Enqueue(Q, j);
//                }
//            }
//        }
//    }
//
//    // 如果没有找到目标顶点，则返回0表示不存在路径
//    return 0;
//}
