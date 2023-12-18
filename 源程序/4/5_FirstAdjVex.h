int FirstAdjVex(ALGraph G,KeyType u)
//根据u在图G中查找顶点，查找成功返回顶点u的第一邻接顶点位序，否则返回-1；
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int v = LocateVex(G,u);
    if(v!=-1){
        ArcNode *p = G.vertices[v].firstarc;
        if(p!=NULL){
            return p->adjvex;
        }
    }
    return -1;
    /********** End **********/
}
/*
5 线性表 8 集合 7 二叉树 6 无向图 -1 nil  5 6  5 7 6 7 7 8 -1 -1
 7
 */