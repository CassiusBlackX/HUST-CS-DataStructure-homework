#include <string.h>
#include "./def.h"
#include "stack.h"
#include "queue.h"
#include "1_CreateBiTree.h"
#include "2_ClearBiTree.h"
#include "3_BiTreeDepth.h"
#include "4_LocateNode.h"
#include "5_Assign.h"
#include "6_GetSibling.h"
#include "7_InsertNode.h"
#include "8_DeleteNode.h"
#include "9_PreOrderTraverse.h"
#include "10_InOrderTraverse.h"
#include "11_PostOrderTraverse.h"
#include "12_LevelOrderTraverse.h"
#include "13_SaveLoadTree.h"
#include "14_MaxPathSum.h"
#include "15_LowestCommonAncestor.h"
#include "16_InvertTree.h"
#include "17_MultiTreeList.h"
void showMenu(){
    system("clear");
    printf("\n");
    printf("\t\tMenu for BiTree On Sequence Structure \n");
    printf("-------------------------------------------------\n");
    printf("\t1. CreateBiTree\t\t\t\t7. Assign\n");
    printf("\t2. DestroyBiTree\t\t\t8. GetSibling\n");
    printf("\t3. ClearBiTree\t\t\t\t9. InsertNode\n");
    printf("\t4. BiTreeEmpty\t\t\t\t10. DeleteNode\n");
    printf("\t5. BiTreeDepth\t\t\t\t11. PreOrderTraverse\n");
    printf("\t6. LocateNode\t\t\t\t12. InOrderTraverse\n");
    printf("\t13. PostOrderTraverse\t\t14. LevelOrderTraverse\n");
    printf("\t15. SaveTree\t\t\t\t16. LoadTree \n");
    printf("\t17. MaxPathSum\t\t\t\t18. LowestCommonAncestor\n");
    printf("\t19. InvertTree\t\t\t\t20. MultiTreeListInit\n");
    printf("\t21. SwitchTree\t\t\t\t22. ShowAllTree\n");
    printf("\t23. AddTree\t\t\t\t\t24. DeleteTree\n");
    printf("\t0. Exit\n");
    printf("-------------------------------------------------\n");
    printf("\t请选择你的操作[0~24]:\n");

}

int main(){
    int op=1,result=0,LR=0,i=0;
    KeyType e;
    TElemType value,definition[100]={0};
    char FileName[30]="tree.dat",treename[30];
    BiTree T=NULL;
    MultiTreeList MT;
    MT.listsize = LIST_INIT_SIZE;
    MT.length=0;
    for(int i=0;i<10;i++){
        MT.elem[i].T=NULL;
    }

    BiTree node,e1,e2;
    while(op){
        showMenu();
        scanf("%d",&op);
        switch (op) {
            case 1:
                printf("请输入二叉链表的值，以key=-1结尾\n");
                do{
                    scanf("%d %s",&definition[i].key,definition[i].others);
                }while(definition[i++].key!=-1);
                result = CreateBiTree(T,definition);
                if(result==INFEASIBLE) printf("二叉链表已经存在，不能再次创建！\n");
                else if(result==ERROR) printf("key不唯一\n");
                else printf("二叉链表创建成功\n");
                i=0;
                break;
            case 2:
                result = DestroyBiTree(T);
                if(result==INFEASIBLE)printf("二叉树不存在，无法销毁\n");
                else printf("二叉链表销毁成功\n");
                break;
            case 3:
                result = ClearBiTree(T);
                if(result==INFEASIBLE)printf("二叉树不存在，无法清空\n");
                else printf("二叉链表清空成功\n");
                break;
            case 4:
                result = BiTreeEmpty(T);
                if (result==INFEASIBLE) printf("二叉链表不存在\n");
                else if(result==TRUE) printf("二叉链表为空\n");
                else printf("二叉链表不为空\n");
                break;
            case 5:
                result = BiTreeDepth(T);
                printf("二叉树的深度为%d\n",result);
                break;
            case 6:
                printf("请输入想要查找的节点的key\n");
                scanf("%d",&e);
                node = LocateNode(T,e);
                if(node==NULL) printf("查找失败\n");
                else printf("找到了key为%d的节点，其对应others为%s",node->data.key,node->data.others);
                break;
            case 7:
                printf("请输入将要赋值的节点的key\n");
                scanf("%d",&e);
                printf("请输入将要赋的key和others\n");
                scanf("%d%s",&value.key,value.others);
                result = Assign(T,e,value);
                if(result==INFEASIBLE) printf("二叉链表不存在\n");
                else if(result==ERROR) printf("赋值失败，可能新值的key与表中其它节点的key矛盾\n");
                else printf("赋值成功\n");
                break;
            case 8:
                printf("请输入想要查找兄弟节点的节点的key\n");
                scanf("%d",&e);
                node = GetSibling(T,e);
                if(node==NULL) printf("查找失败\n");
                else printf("查找成功，其兄弟节点为%d,%s\n",node->data.key,node->data.others);
                break;
            case 9:
                printf("请输入将要插入的节点的双亲节点的key\n");
                scanf("%d",&e);
                printf("请输入左右的选择，左0右1\n");
                scanf("%d",&LR);
                printf("请输入将要插入的节点的值\n");
                scanf("%d%s",&value.key,value.others);
                result = InsertNode(T,e,LR,value);
                if(result==INFEASIBLE) printf("二叉链表不存在\n");
                else if (result==ERROR) printf("插入节点失败\n");
                else printf("插入成功\n");
                break;
            case 10:
                printf("请输入将要删除的节点的key\n");
                scanf("%d",&e);
                result = DeleteNode(T,e);
                if(result==INFEASIBLE) printf("二叉链表不存在\n");
                else if(result==ERROR) printf("删除节点失败，可能输入的key并不存在于当前二叉链表中\n");
                else printf("删除成功\n");
                break;
            case 11:
                result = PreOrderTraverse(T,visit);
                if(result==INFEASIBLE) printf("二叉链表不存在\n");
                else printf("\n先序遍历成功\n");
                break;
            case 12:
                result = InOrderTraverse(T, visit);
                if(result==INFEASIBLE) printf("二叉链表不存在\n");
                else printf("\n中序遍历成功\n");
                break;
            case 13:
                result = PostOrderTraverse(T,visit);
                if(result==INFEASIBLE) printf("二叉链表不存在\n");
                else printf("\n后序遍历成功\n");
                break;
            case 14:
                result = LevelOrderTraverse(T,visit);
                if(result==INFEASIBLE) printf("二叉链表不存在\n");
                else printf("\n层序遍历成功\n");
                break;
            case 15:
                printf("请输入希望保存二叉树到的文件名\n");
                scanf("%s",FileName);
                result = SaveBiTree(T,FileName);
                if(result==INFEASIBLE)printf("二叉链表不存在\n");
                else printf("二叉链表保存成功\n");
                break;
            case 16:
                printf("请输入要打开的文件名\n");
                scanf("%s",FileName);
                result = LoadBiTree(T,FileName);
                if(result==INFEASIBLE)printf("当前T不为空，不可以\n");
                else printf("从文件生成二叉链表成功\n");
                break;
            case 17:
                //不理解这个最大路径和深度的区别是什么
                //这个求的是路径的总数
                result = MaxPathSum(T);
                printf("二叉树的最大路径为%d\n",result);
                break;
            case 18:
                printf("请输入想要查找公共祖先的第一个节点的key\n");
                scanf("%d",&e);
                e1 = LocateNode(T,e);
                printf("请输入想要查找公共祖先的第二个节点的key\n");
                scanf("%d",&e);
                e2 = LocateNode(T,e);
                node = LowestCommonAncestor(T,e1,e2);
                if (node == NULL) printf("查找失败\n");
                else printf("查找成功，找到的公共祖先的key为%d，others为%s\n",node->data.key,node->data.others);
                break;
            case 19:
                if(T==NULL) {
                    printf("二叉链表不存在，终止\n");
                    break;
                }
                InvertTree(T);
                printf("翻转成功\n");
                break;
            case 20:
                result = InitMultiTreeList(MT);
                if (result=OK) printf("多二叉树管理线性表初始化成功\n");
                else printf("多二叉树管理线性表初始化失败\n");
                break;
            case 21:
                printf("请输入接下来将要进行操作的二叉树的名字\n");
                scanf("%s",treename);
                SwitchTree(MT,treename,T);
                break;
            case 22:
                result = ShowAllTree(MT);
                if(result==INFEASIBLE) printf("线性表不存在\n");
                else printf("以上即为多线性表中的所有树\n");
                break;
            case 23:
                result = AddTree(MT);
                if(result==OK) printf("新树创建成功\n");
                else printf("新树创建失败\n");
                break;
            case 24:
                result = DeleteTree(MT);
                if(result==OK) printf("树删除成功\n");
                else printf("树删除失败\n");
                break;
            case 0:
                break;
        }
    }
    printf("欢迎下次再使用本系统！\n");
    return 0;
}

/*
    1
   2    3
  4 5  6
1 a 2 b 4 c 0 n 0 n 5 d 0 n 0 n 3 e 6 f 0 n 0 n 0 n 0 n -1 n
*/