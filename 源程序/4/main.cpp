#include <string.h>
#include "./def.h"
#include "queue.h"
#include "1_CreateGraph.h"
#include "2_DestroyGraph.h"
#include "3_LocateVex.h"
#include "4_PutVex.h"
#include "5_FirstAdjVex.h"
#include "6_NextAdjVex.h"
#include "7_InsertVex.h"
#include "8_DeleteVex.h"
#include "9_InsertArc.h"
#include "10_DeleteArc.h"
#include "11_DFSTraverse.h"
#include "12_BFSTraverse.h"
#include "13_Save_Load_Graph.h"
#include "14_VerticesSetLessThanK.h"
#include "15_ShortestPathLength.h"
#include "16_ConnectedComponentsNums.h"
#include "./17_MultiGraph.h"

void showMenu(){
    system("clear");
    printf("\n");
    printf("\t\t\t\tMenu for UDG \n");
    printf("-------------------------------------------------\n");
    printf("\t1. CreateGraph\t\t\t\t7. InsertVex\n");
    printf("\t2. DestroyGraph\t\t\t\t8. DeleteVex\n");
    printf("\t3. LocateVex\t\t\t\t9. InsertArc\n");
    printf("\t4. PutVex \t\t\t\t\t10. DeleteArc\n");
    printf("\t5. FirstAdjVex\t\t\t\t11. DFSTraverse\n");
    printf("\t6. NextAdjVex\t\t\t\t12. BFSTraverse\n");
    printf("\t13. SaveGraph\t\t\t\t14. LoadGraph\n");
    printf("\t15. VerticesSetLessThanK\t16. ShortestPathLength\n");
    printf("\t17. ConnectedComponentsNums\t18. InitMultiGraph\n");
    printf("\t19. GraphAdd\t\t\t\t20. GraphDelete\n");
    printf("\t21. GraphSwitch\t\t\t\t22. MultiGraphShow\n");
    printf("\t0. Exit\n");
    printf("-------------------------------------------------\n");
    printf("\t请选择你的操作[0~17]:\n");

}

int main(){
    int op=1,result=0,u,w,*arr;
    ALGraph G;//感觉可能有点危险，因为唯一判断图空不空的方法居然是只能看顶点数
    GraphManager graphManager;
    graphManager.listsize = MAX_GRAPH_NUM;
    graphManager.length = 0;
    VertexType v;
    char FileName[30];
    while(op){
        showMenu();
        scanf("%d",&op);
        switch (op){
            case 1:
                result = CreateGraph(G);
                if(result==ERROR) printf("创建图失败\n");
                else {
                    printf("创建图成功\n");
                    PrintList(G);
                }
                break;
            case 2:
                if(G.vexnum==0) printf("是空图！\n");
                else {
                    result = DestroyGraph(G);
                    printf("销毁图成功\n");
                }
                break;
            case 3:
                if(G.vexnum==0) printf("是空图！\n");
                else {
                    printf("请输入想要查找的顶点的key\n");
                    scanf("%d", &u);
                    result = LocateVex(G, u);
                    if (result == -1) printf("查找顶点失败，顶点不在图中\n");
                    else printf("查找顶点成功，该顶点的序号为%d\n", result);
                }
                break;
            case 4:
                if(G.vexnum==0) printf("是空图！\n");
                else {
                    printf("请输入想要赋值的顶点的原来的key\n");
                    scanf("%d", &u);
                    printf("请输入想要赋的key和others\n");
                    scanf("%d%s", &v.key, v.others);
                    result = PutVex(G, u, v);
                    if (result == ERROR) printf("给顶点赋值失败，可能原本的顶点不存在或赋值不合法\n");
                    else printf("给顶点赋值成功\n");
                }
                break;
            case 5:
                if(G.vexnum==0) printf("是空图！\n");
                else {
                    printf("请输入想要查找第一邻接顶点位序的顶点的key\n");
                    scanf("%d", &u);
                    result = FirstAdjVex(G, u);
                    if (result == -1) printf("查找失败\n");
                    else printf("查找成功，顶点%d的第一邻接顶点位序为%d\n", u, result);
                }
                break;
            case 6:
                if(G.vexnum==0) printf("是空图！\n");
                else {
                    printf("请输入想要查找的两个顶点的位序\n");
                    scanf("%d%d", &u, &w);
                    result = NextAdjVex(G, u, w);
                    if (result == -1) printf("查找失败\n");
                    else printf("查找成功，%d相对于%d的下一个邻接顶点的位序为%d\n", u, w, result);
                }
                break;
            case 7:
                if(G.vexnum==0) printf("是空图！\n");
                else {
                    printf("请输入想要插入的顶点的key和others\n");
                    scanf("%d%s", &v.key, v.others);
                    result = InsertVex(G, v);
                    if (result == ERROR) printf("插入顶点失败\n");
                    else printf("插入顶点成功\n");
                }
                break;
            case 8:
                if(G.vexnum==0) printf("是空图！\n");
                else {
                    printf("请输入想要删除的顶点的key\n");
                    scanf("%d", &u);
                    result = DeleteVex(G, u);
                    if (result == ERROR) printf("删除顶点失败\n");
                    else printf("删除顶点成功\n");
                }
                break;
            case 9:
                if(G.vexnum==0) printf("是空图！\n");
                else {
                    printf("请输入想要添加的边的两个顶点的key\n");
                    scanf("%d%d", &u, &w);
                    result = InsertArc(G, u, w);
                    if (result == ERROR) printf("插入边失败\n");
                    else printf("插入边成功\n");
                }
                break;
            case 10:
                if(G.vexnum==0) printf("是空图！\n");
                else {
                    printf("请输入想要删除的弧的两个顶点的key\n");
                    scanf("%d%d", &u, &w);
                    result = DeleteArc(G, u, w);
                    if (result == ERROR) printf("删除弧失败\n");
                    else printf("删除弧成功\n");
                }
                break;
            case 11:
                if(G.vexnum==0) printf("是空图！\n");
                else {
                    DFSTraverse(G, visit);
                    printf("\nDFS遍历图成功\n");
                }
                break;
            case 12:
                if(G.vexnum==0) printf("是空图！\n");
                else {
                    BFSTraverse(G, visit);
                    printf("\nBFS遍历图成功\n");
                }
                break;
            case 13:
                if(G.vexnum==0) printf("是空图！\n");
                else {
                    printf("当前图的样式\n");
                    PrintList(G);
                    printf("请输入想要保存图到的文件的名称\n");
                    scanf("%s", FileName);
                    result = SaveGraph(G, FileName);
                    if (result == ERROR) printf("保存图失败\n");
                    else printf("保存图成功\n");
                }
                break;
            case 14:
                printf("请输入将要传入图的文件的名称\n");
                scanf("%s", FileName);
                result = LoadGraph(G, FileName);
                if (result == ERROR) printf("加载图失败\n");
                else printf("加载图成功\n");
                break;
            case 15:
                if(G.vexnum==0) printf("是空图！\n");
                else {
                    printf("请输入想要找的顶点v的key以及距离k\n");
                    scanf("%d%d", &u, &w);
                    arr = VerticesSetLessThanK(G, u, w);
                    printf("查找成功，接下来将打印结果\n");
                    for (int i = 0; arr[i] != -1; i++) printf("%d ", arr[i]);
                    printf("\n");
                }
                break;
            case 16:
                if(G.vexnum==0) printf("是空图！\n");
                else {
                    printf("请输入想要查找的最短路径的顶点的key\n");
                    scanf("%d%d", &u, &w);
                    result = ShortestPathLength(G, u, w);
                    if (result == -1) printf("查找最短路径失败，可能两个顶点并不连通\n");
                    printf("最短路径为%d\n", result);
                }
                break;
            case 17:
                result = ConnectedComponentsNums(G);
                printf("图的联通分量的个数为%d\n",result);
                break;
            case 18:
                result = InitMultiGraph(graphManager);
                if (result==ERROR) printf("创建多图管理者失败\n");
                else printf("创建多图管理者成功\n");
                break;
            case 19:
                result = GrapthAdd(graphManager);
                if(result==OK) printf("在多图管理者中添加图成功\n");
                break;
            case 20:
                result = GraphDelete(graphManager);
                if(result==OK) printf("在多图管理者中删除图成功\n");
                break;
            case 21:
                result = GraphSwitch(graphManager,G);
                break;
            case 22:
                MultiGraphShow(graphManager);
                break;
            case 99:
                PrintList(G);
                break;
            case 0:
                break;
        }
    }
    printf("欢迎下次再使用本系统！\n");
    return 0;
}

/*
0 n 1 a 2 b 3 c 4 d 5 e 6 f 7 g 8 h 9 i 10 j 11 k 12 l -1 n 0 1 0 2 0 6 0 5 3 5 3 4 5 4 9 11 9 10 9 12 11 12 7 8 4 6 -1 -1
12 a 11 a 10 a 9 a 8 a 7 a 6 a 5 a 4 a 3 a 2 a 1a 0 a -1 n 0 1 0 2 0 6 0 5 3 5 3 4 5 4 9 11 9 10 9 12 11 12 7 8 4 6 -1 -1
 */
/*
5 线性表 8 集合 7 二叉树 6 无向图 -1 nil 5 6 5 7 6 7 7 8  -1 -1
    5--6
    |  /
    | /
    7------8
*/