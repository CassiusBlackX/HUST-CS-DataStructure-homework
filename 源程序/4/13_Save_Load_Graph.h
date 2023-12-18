int GetArcNum(ALGraph G) {
    int arcNum = 0;
    for (int i = 0; i < G.vexnum; i++) {
        ArcNode *p = G.vertices[i].firstarc;
        while (p != NULL) {
            arcNum++;
            p = p->nextarc;
        }
    }
    return arcNum / 2;
}

status SaveGraph(ALGraph G, char FileName[]) {
    FILE *file = fopen(FileName, "w");
    if (file == NULL) {
        printf("Failed to open file for writing.\n");
        return ERROR;
    }

    //悄悄的把图的这些特征信息也打到文件里面，这样到时候就不需要计算了，hihi
    fprintf(file, "%d %d\n", G.vexnum, GetArcNum(G));

    for (int i = 0; i < G.vexnum; i++) {
        fprintf(file, "%d %s\n", G.vertices[i].data.key, G.vertices[i].data.others);
    }
    for (int i = 0; i < G.vexnum; i++){
        ArcNode *p = G.vertices[i].firstarc;
        while (p != NULL) {
            fprintf(file, "%d ", p->adjvex);
            p = p->nextarc;
        }
        fprintf(file, "-1\n");  // 用-1表示邻接顶点结束
    }

    fclose(file);
    return OK;
}

status LoadGraph(ALGraph &G, char FileName[]) {
    FILE *file = fopen(FileName, "r");
    if (file == NULL) {
        printf("Failed to open file for reading.\n");
        return ERROR;
    }

    int vexnum, arcnum;
    fscanf(file, "%d %d", &vexnum, &arcnum);
    G.vexnum = vexnum;
    G.arcnum = arcnum;

    for (int i = 0; i < G.vexnum; i++) {
        int key;
        char others[20];
        fscanf(file, "%d %s", &key, others);
        G.vertices[i].data.key = key;
        strcpy(G.vertices[i].data.others, others);
        G.vertices[i].firstarc = NULL;
    }

    for (int i = 0; i < G.arcnum; i++) {
        int v;
        fscanf(file, "%d ", &v);
        ArcNode *p = (ArcNode *) malloc(sizeof(ArcNode)),*q=NULL;
        G.vertices[i].firstarc = p;
        while(v != -1) {
            p->adjvex = v;
            p->nextarc = NULL;
            fscanf(file,"%d",&v);
            if(v==-1) break;
            p ->nextarc = (ArcNode *) malloc(sizeof(ArcNode));
            p = p->nextarc;
        }
    }
    fclose(file);
    return OK;
}
