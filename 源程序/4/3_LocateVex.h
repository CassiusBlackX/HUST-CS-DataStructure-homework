int LocateVex(ALGraph G,KeyType u)
//根据u在图G中查找顶点，查找成功返回位序，否则返回-1；
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    for (int i = 0; i < G.vexnum; i++) {
        if (G.vertices[i].data.key == u) {
            return i; // 找到关键字为u的顶点，返回其位置序号
        }
    }
    return -1;
    /********** End **********/
}
