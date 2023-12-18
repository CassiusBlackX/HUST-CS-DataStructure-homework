#include<string.h>
#include"./def.h"
#include"./1_InitList.h"
#include"./2_DestroyList.h"
#include"./3_ClearList.h"
#include"./4_ListEmpty.h"
#include"./5_ListLength.h"
#include"./6_GetElem.h"
#include"./7_LocateElem.h"
#include"./8_PriorElem.h"
#include"./9_NextElem.h"
#include"./10_ListInsert.h"
#include"./11_ListDelete.h"
#include"./12_ListTraverse.h"
#include"./13_ReverseList.h"
#include"./14_RemoveNthFromEnd.h"
#include"./15_SortList.h"
#include"./16_SaveList.h"
#include"./17_MultiLists.h"
void showMenu(){
    system("clear");
    printf("\n");
    printf("\t\tMenu for chain Table On Sequence Structure \n");
    printf("--------------------------------------------------------------------\n");
    printf("\t1. InitList\t\t\t\t\t7. LocateElem\n");
    printf("\t2. DestroyList\t\t\t\t8. PriorElem\n");
    printf("\t3. ClearList\t\t\t\t9. NextElem \n");
    printf("\t4. ListEmpty\t\t\t\t10. ListInsert\n");
    printf("\t5. ListLength\t\t\t\t11. ListDelete\n");
    printf("\t6. GetElem\t\t\t\t\t12. ListTrabverse\n");
    printf("\t13. ReverseList\t\t\t\t14. RemoveNthFromEnd\n");
    printf("\t15. SortList\t\t\t\t16. SaveList\n");
    printf("\t17. LoadList\t\t\t\t0. Exit\n");
    printf("--------------------------------------------------------------------\n");
    printf("\t请选择你的操作[0~17]:\n");
    printf("\tMenu for Multi Linear Table On Sequence Structure\n");
    printf("\t18. InitMultiLists\t\t\t19. DestroyMultiLists\n");
    printf("\t20. MultiListsAddOne\t\t21. MultiListsDeleteOne\n");
    printf("\t22. SwitchList\n");
}

int main(void){
    LinkList L;
    LISTS ML=NULL;
    LISTS p;
    char listname[30];
    int op=1;
    L = NULL;
    int result = 0;
    int i,n;
    char FileName[30]="./list.dat",TempName[30];
    ElemType e,pre,next;
    while(op){
        showMenu();
        scanf("%d",&op);
        switch(op){
            case 1:
                result = InitList(L);
                if(result==OK) printf("线性表创建成功！\n");
                else printf("线性表创建失败！\n");
                break;
            case 2:
                result = DestroyList(L);
                if(result==OK) printf("线性表销毁成功\n");
                else printf("线性表销毁失败! \n");
                break;
            case 3:
                result = ClearList(L);
                if(result==OK) printf("线性表清空成功\n");
                else printf("线性表清空失败\n");
                break;
            case 4:
                result = ListEmpty(L);
                if(result==TRUE)printf("线性表为空\n");
                else if(result==FALSE)printf("线性表不为空\n");
                else printf("线性表不存在\n");
                break;
            case 5:
                result = ListLength(L);
                if(result==INFEASIBLE)printf("线性表不存在\n");
                else printf("线性表长度为%d\n",result);
                break;
            case 6:
                printf("请输入希望查找的元素的序号（从1开始）\n");
                scanf("%d",&i);
                result = GetElem(L,i,e);
                if(result==OK) printf("查找成功，第%d号元素的值为%d",i,e);
                else if(result==INFEASIBLE) printf("线性表不存在\n");
                else printf("查找失败，可能所给i不在线性表长度内");
                break;
            case 7:
                printf("请输入希望查找的元素的值\n");
                scanf("%d",&e);
                result = LocateElem(L,e);
                if(result==INFEASIBLE)printf("线性表不存在\n");
                else if(result)printf("查找成功，值为%d的元素的序号为%d",e,result);
                else printf("查找失败，可能所给值并不在线性表中\n");
                break;
            case 8:
                printf("请输入希望查找的前驱元素的值\n");
                scanf("%d",&e);
                result = PriorElem(L,e,pre);
                if(result==OK)printf("查找成功，%d元素的前驱为%d\n",e,pre);
                else if(result==INFEASIBLE)printf("线性表不存在\n");
                else printf("查找失败，可能所给值不在线性表中\n也有可能所给值是线性表的第一个元素的值，该元素无前驱\n");
                break;
            case 9:
                printf("请输入希望查找的后继元素的值\n");
                scanf("%d",&e);
                result = NextElem(L,e,next);
                if(result==OK)printf("查找成功，%d元素的后继为%d\n",e,next);
                else if(result==INFEASIBLE)printf("线性表不存在\n");
                else printf("查找失败，可能所给值不在线性表中\n也有可能所给值是线性表的最后一个元素的值，该元素无后继\n");
                break;
            case 10:
                printf("请输入希望在其前面插入元素的序号以及希望插入的值\n");
                scanf("%d %d",&i,&e);
                result = ListInsert(L,i,e);
                if(result==OK)printf("插入成功\n");
                else if(result==INFEASIBLE) printf("线性表不存在\n");
                else printf("插入失败\n");
                break;
            case 11:
                printf("请输入希望删除的元素的序号\n");
                scanf("%d",&i);
                result = ListDelete(L,i,e);
                if(result==OK)printf("删除成功，删除元素的值为%d\n",e);
                else if(result==INFEASIBLE)printf("线性表不存在\n");
                else printf("删除失败，可能i不在线性表长度范围内\n");
                break;
            case 12:
                result = ListTraverse(L);
                if(result==OK)printf("\n线性表遍历成功\n");
                else printf("线性表不存在\n");
                break;
            case 13:
                result = ReverseList(L);
                if(result==OK) printf("线性表翻转成功\n");
                else printf("线性表为空\n");
                break;
            case 14:
                printf("输入要删除的线性表的倒数第n个元素的序号n\n");
                scanf("%d",&n);
                result = RemoveNthFromEnd(L,n,e);
                if(result==OK)printf("成功删除线性表倒数第%d个元素，删除元素的值为%d\n",n,e);
                else if(result==INFEASIBLE)printf("线性表为空\n");
                else printf("输入的n不在线性表的范围内\n");
                break;
            case 15:
                result = SortList(L);//既写了冒泡排序，也写了快速排序，不过还是老老实实，默认冒泡排序了
                if(result==OK) printf("排序成功\n");
                else if(result==INFEASIBLE)printf("线性表不存在\n");
                else printf("线性表为空，没有什么可以排序的\n");
                break;
            case 16:
                printf("请输入希望存储线性表的路径及文件名，如果回车则将以默认名字保存至默认路径\"./list.dat\"\n");
                if(scanf("%s",TempName)) strcpy(FileName,TempName);
                result = SaveList(L,FileName);
                if(result == OK)printf("线性表保存成功\n");
                else if (result==INFEASIBLE)printf("线性表不存在\n");
                else printf("线性表保存失败\n");
                break;
            case 17:
                printf("请输入希望读取线性表的路径及文件名，如果回车则将以默认名字打开默认文件\"./list.dat\"\n");
                if(scanf("%s",TempName)) strcpy(FileName,TempName);
                result = LoadList(L,FileName);
                if(result == OK)printf("线性表读取成功\n");
                else if (result==INFEASIBLE)printf("线性表已经存在，执行此造作将会覆盖原线性表，中断！\n");
                else printf("线性表读取失败\n");
                break;
            case 18:
                result = InitMultiLists(ML);
                if(result==OK) printf("多线性表创建成功！\n");
                else printf("多线性表创建失败！\n");
                break;
            case 19:
                result = DestroyMultiLists(ML);
                if(result==OK) printf("多线性表销毁成功\n");
                else printf("多线性表销毁失败! \n");
                break;
            case 20:
                result = MultiListsAdd(ML);
                if(result==OK) printf("新增线性表成功\n");
                else printf("新增线性表失败\n");
                break;
            case 21:
                printf("请输入希望删除的线性表的名字\n");
                scanf("%s",listname);
                result = MultiListsDelete(ML,listname);
                if(result==OK)printf("成功删除多线性表中的该线性表\n");
                else if (result==ERROR)printf("输入的名字不在多线性表中或多线性表为空，请检查\n");
                else printf("多线性表为空或想删除的线性表不存在\n");
                break;
            case 22:
                printf("请输入接下来将要进行操作的链表的名字\n");
                scanf("%s",listname);
                p = MultiListsLocate(ML,listname);
                if(p==NULL) printf("该表不存在！\n");
                else {
                    printf("查找成功，接下来请针对该表进行操作！(2~17)\n");
                    L = p->L;
                }
                break;
            case 0:
                break;
        }
    }
    printf("欢迎下次再使用本系统！\n");
}
