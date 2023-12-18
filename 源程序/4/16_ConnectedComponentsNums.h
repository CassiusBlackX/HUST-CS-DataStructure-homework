//使用DFS，用一个顶点数组，每经过一个顶点就变1，然后从没有经过过的顶点开始，直到所有顶点都经过过了
void DFS(ALGraph G,int v){
    visited[v] = TRUE;
    ArcNode *p = G.vertices[v].firstarc;
    while(p!=NULL){
        int adjvex = p->adjvex;
        if(visited[adjvex] == FALSE){
            DFS(G,adjvex);
        }
        p = p->nextarc;
    }
}
int ConnectedComponentsNums(ALGraph G){
    for(int i=0;i<G.vexnum;i++){
        visited[i]=FALSE;
    }
    int circles = 0;
    for(int i=0;i<G.vexnum;i++){
        if(visited[i]==TRUE) continue;
        DFS(G,i);
        circles++;
    }
    return circles;
}