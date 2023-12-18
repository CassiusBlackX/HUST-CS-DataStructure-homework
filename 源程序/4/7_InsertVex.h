status InsertVex(ALGraph &G,VertexType v)
//在图G中插入顶点v，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (G.vexnum >= MAX_VERTEX_NUM) {
        return ERROR; // 顶点个数已满，无法插入新顶点
    }

    int i = LocateVex(G, v.key); // 检查关键字是否已存在于图中
    if (i != -1) {
        return ERROR; // 关键字重复，无法插入新顶点
    }

    G.vertices[G.vexnum].data = v; // 在顶点数组的最后位置插入新顶点
    G.vertices[G.vexnum].firstarc = NULL; // 初始化新顶点的邻接表
    G.vexnum++; // 顶点数加一

    return OK; // 插入新顶点成功
    /********** End **********/
}
