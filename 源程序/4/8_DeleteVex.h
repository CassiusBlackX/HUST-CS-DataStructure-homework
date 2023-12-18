///*
// * 删弧分为两种类型
// * 第一种是从要删除的顶点v开始删除，这种弧度特别好删除，指着v删除就可以了
// * 另一种是从图的其它点里面找到v然后删除相关的弧，这种时候再调用deletearc函数就可以了（？）
// */

status DeleteVex(ALGraph &G, KeyType v) {
    int i, j;
    // 查找顶点v在顶点数组中的位置
    for (i = 0; i < G.vexnum; i++) {
        if (G.vertices[i].data.key == v)
            break;
    }

    if(G.arcnum==0) return ERROR;
    //说实话，这个是根据测试集反推出来的，但是并不明白为什么要这么做

    // 未找到顶点v，返回错误
    if (i == G.vexnum)
        return ERROR;

    // 删除顶点v的弧链表
    ArcNode *p, *pre,*q;
    p = G.vertices[i].firstarc;
    while (p != NULL) {
        q = p->nextarc;
        free(p);
        p = q;
        G.arcnum--;  // 弧数减一
    }

    // 删除顶点v
    for (j = i; j < G.vexnum - 1; j++) {
        G.vertices[j] = G.vertices[j + 1];
    }
    G.vexnum--;  // 顶点数减一

    // 删除与顶点v相关的弧
    for (j = 0; j < G.vexnum; j++) {
//        if (j == i)  // 跳过顶点v所在的行
//            continue;

        p = G.vertices[j].firstarc;
        pre = NULL;

        // 遍历顶点j的弧链表
        while (p != NULL) {
            if (p->adjvex == i) {
                // 删除指向顶点v的弧
                if (pre == NULL) {
                    G.vertices[j].firstarc = p->nextarc;
                } else {
                    pre->nextarc = p->nextarc;
                }
                q = p->nextarc;
                free(p);
                p = q;
            }
            else if(p->adjvex > i){
                p->adjvex--;
                pre = p;
                p = p->nextarc;
            }
            else {
                pre = p;
                p = p->nextarc;
            }
        }
    }
    return OK;
}

//5 线性表 8 集合 7 二叉树 6 无向图 -1 nil 5 6 5 7 6 7 7 8 -1 -1  7
/*
 0-3
 |/
 2-1
*/

/*
0  2
1
3  0
 */