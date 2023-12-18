int NextAdjVex(ALGraph G,KeyType v,KeyType w)
//v对应G的一个顶点,w对应v的邻接顶点；操作结果是返回v的（相对于w）下一个邻接顶点的位序；
// 如果w是最后一个邻接顶点，或v、w对应顶点不存在，则返回-1。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int vPos = LocateVex(G, v);
    int wPos = LocateVex(G, w);
    if (vPos != -1 && wPos != -1) {
        ArcNode *p = G.vertices[vPos].firstarc;
        while (p != NULL) {
            if (p->adjvex == wPos) { // 找到顶点 w 的位置序号对应的邻接顶点
                p = p->nextarc;
                if (p != NULL) {
                    return p->adjvex; // 返回顶点 v 的下一个邻接顶点的位置序号
                }
                break;
            }
            p = p->nextarc;
        }
    }
    return -1; // 顶点 v 或 w 不存在，或者 w 是最后一个邻接顶点时返回-1
    /********** End **********/
}
