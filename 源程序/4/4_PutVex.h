status check(ALGraph G){
    int cnt[MAX_VERTEX_NUM]={0};
    for(int i=0;i<G.vexnum;i++){
        cnt[G.vertices[i].data.key]+=1;
        if(cnt[G.vertices[i].data.key]>1) return ERROR;
    }
    return OK;
}
status PutVex(ALGraph &G,KeyType u,VertexType value)
//根据u在图G中查找顶点，查找成功将该顶点值修改成value，返回OK；
//如果查找失败或关键字不唯一，返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    for(int i=0;i<G.vexnum;i++){
        if(G.vertices[i].data.key==u){
            G.vertices[i].data = value;
            return check(G);
        }
    }
    return ERROR;
    /********** End **********/
}
