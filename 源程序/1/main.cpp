#include "def.h"
#include "1_InitList.h"
#include "2_DestroyList.h"
#include "3_ClearList.h"
#include "4_ListEmpty.h"
#include "5_ListLength.h"
#include "6_GetElem.h"
#include "7_LocateElem.h"
#include "8_PriorElem.h"
#include "9_NextElem.h"
#include "10_ListInsert.h"
#include "11_ListDelete.h"
#include "12_ListTraverse.h"
#include "13_Save_LoadList.h"
#include "14_MaxSubArray.h"
#include "15_SubArrayNum.h"
#include "16_SortList.h"
#include "17_InitMultiLists.h"
#include "18_AddList.h"
#include "19_RemoveList.h"
#include "22_LocateList.h"

void showMenu(){
    system("clear");
    printf("\n");
    printf("\t\tMenu for Linear Table On Sequence Structure \n");
    printf("-------------------------------------------------\n");
    printf("\t\t\t1. InitList\t\t\t\t\t7. LocateElem\n");
    printf("\t\t\t2. DestroyList\t\t\t\t8. PriorElem\n");
    printf("\t\t\t3. ClearList\t\t\t\t9. NextElem \n");
    printf("\t\t\t4. ListEmpty\t\t\t\t10. ListInsert\n");
    printf("\t\t\t5. ListLength\t\t\t\t11. ListDelete\n");
    printf("\t\t\t6. GetElem\t\t\t\t\t12. ListTrabverse\n");
    printf("\t\t\t13. SaveList\t\t\t\t14. LoadList\n");
    printf("\t\t\t15. MaxSubArray\t\t\t\t16. SubArrayNum\n");
    printf("\t\t\t17. SortList\t\t\t\t0. Exit\n");
    printf("-------------------------------------------------\n");
    printf("\t请选择你的操作[18~21]:\n");
    printf("\t\tMenu for Multi Linear Table On Sequence Structure\n");
    printf("\t\t\t18. InitMultiLists\t\t19. AddList\n");
    printf("\t\t\t20. RemoveList\t\t\t21. LocateList\n");
    printf("\t\t\t22. ElemDelete\t\t\t23. ElemAdd\n");
    printf("\t\t\t24. SingleListSort\t\t25. SingleListPrior\n");
    printf("\t\t\t26. SingleListNext\t\t27. ElemGet\n");
    printf("\t\t\t28. SwitchList\n");
}

int main(void){
    SqList L;
    LISTS ML;
    ML.listsize=LIST_INIT_SIZE;
    ML.length=0;
    for(int i=0;i<10;i++){
        ML.elem[i].L.elem=NULL;
    }
    char listname[30];
    int op=1;
    L.elem = NULL;
    int result = 0,flag = 0;
    int i,n;
    char FileName[30]="./list.dat",TempName[30];
    ElemType e,pre,next,k;
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
                printf("请输入希望删除的元素的序号（从1开始）\n");
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
                printf("请输入希望存储线性表的路径及文件名，eg:\"list.dat\"\n");
                if(scanf("%s",TempName)) strcpy(FileName,TempName);
                result = SaveList(L,FileName);
                if(result == OK)printf("线性表保存成功\n");
                else if (result==INFEASIBLE)printf("线性表不存在\n");
                else printf("线性表保存失败\n");
                break;
            case 14:
                printf("请输入希望读取线性表的路径及文件名，eg\"list.dat\"\n");
                if(scanf("%s",TempName)) strcpy(FileName,TempName);
                result = LoadList(L,FileName);
                if(result == OK)printf("线性表读取成功\n");
                else if (result==INFEASIBLE)printf("线性表已经存在，执行此造作将会覆盖原线性表，中断！\n");
                else printf("线性表读取失败\n");
                break;
            case 15:
                result = MaxSubArray(L,e);//既写了冒泡排序，也写了快速排序，不过还是老老实实，默认冒泡排序了
                if(result==OK) printf("找到最大子数组，值为%d\n",e);
                else if(result==INFEASIBLE)printf("线性表不存在\n");
                else printf("线性表为空，没有什么可以排序的\n");
                e=0;//没有什么影响，其实这里
                break;
            case 16:
                printf("请打印希望查找的和为k的子数组的k值\n");
                scanf("%d",&k);
                result = SubArrayNum(L,k);
                if(result==INFEASIBLE)printf("线性表不存在\n");
                else if(result==0) printf("不存在子数组其和为%d\n",k);
                else printf("和为k的子数组的个数为%d\n",result);
                break;
            case 17:
                result = SortList(L);
                if(result== INFEASIBLE) printf("线性表不存在\n");
                else if (result==0)printf("线性表长度为0，没有什么好排序的\n");
                else printf("排序成功\n");
                break;
            case 18:
                result = InitMultiLists(ML);
                if(result==INFEASIBLE) printf("多线性表不存在\n");
                else if (result==ERROR)printf("多线性表初始化失败\n");
                else printf("多线性表创建成功\n");
                break;
            case 19:
                printf("请输入要新添加的线性表的名字\n");
                scanf("%s",listname);
                result = AddList(ML,listname);
                if(result==OK) printf("在多线性表中添加新的线性表成功\n");
                else if (result==ERROR) printf("多线性表中添加新的线性表失败 \n");
                else printf("多线性表不存在\n");
                break;
            case 20:
                printf("请输入要删除的线性表的名字\n");
                scanf("%s",listname);
                result = RemoveList(ML,listname);
                if(result==OK) printf("从多线性表中删除线性表成功\n");
                else printf("从多线性表中删除线性表失败\n");
                break;
            case 21:
                printf("请输入希望查找的线性表的名字\n");
                scanf("%s",listname);
                printf("%s",listname);
                result = LocateList(ML,listname);
                if(result==0) printf("没有在多线性表中找到%s的线性表\n");
                else if(result==INFEASIBLE) printf("多线性表不存在\n");
                else {
                    printf("成功找到名为%s的线性表，序号为%d\n",listname,result);
                    flag = ListTraverse(ML.elem[result-1].L);
                    if (flag==OK)printf("\n%s的表元素值分别为上\n",listname);
                    else if (flag==INFEASIBLE) printf("%s表元素不存在\n",listname);
                }
                break;
            case 22:
                printf("请输入希望进行操作的线性表的名字\n");
                scanf("%s",listname);
                result = LocateList(ML,listname);
                if(result==0) printf("没有在多线性表中找到%s的线性表\n");
                else if(result==INFEASIBLE) printf("多线性表不存在\n");
                else {
                    printf("成功找到名为%s的线性表，序号为%d\n",listname,result);
                    printf("请输入希望删除的元素的序号（从1开始）\n");
                    scanf("%d",&i);
                    flag = ListDelete(ML.elem[result-1].L,i,e);
                    if (flag==OK)printf("成共删除%s线性表中的第%d个元素，值为%d\n",listname,i,e);
                    else if (flag==INFEASIBLE) printf("%s线性表不存在\n",listname);
                    else printf("%d值可能超出表范围，失败\n",i);
                }
                break;
            case 23:
                printf("请输入希望进行操作的线性表的名字\n");
                scanf("%s",listname);
                result = LocateList(ML,listname);
                if(result==0) printf("没有在多线性表中找到%s的线性表\n");
                else if(result==INFEASIBLE) printf("多线性表不存在\n");
                else {
                    printf("成功找到名为%s的线性表，序号为%d\n",listname,result);
                    printf("请输入希望在其前面插入元素的序号以及希望插入的值\n");
                    scanf("%d%d",&i,&e);
                    flag = ListInsert(ML.elem[result-1].L,i,e);
                    if(flag==OK)printf("添加成功\n");
                    else if(flag==INFEASIBLE)printf("线性表不存在\n");
                    else printf("添加失败\n");
                }
                break;
            case 24:
                printf("请输入希望进行操作的线性表的名字\n");
                scanf("%s",listname);
                result = LocateList(ML,listname);
                if(result==0) printf("没有在多线性表中找到%s的线性表\n");
                else if(result==INFEASIBLE) printf("多线性表不存在\n");
                else {
                    printf("成功找到名为%s的线性表，序号为%d\n",listname,result);
                    flag = SortList(ML.elem[result-1].L);
                    if(flag== INFEASIBLE) printf("线性表不存在\n");
                    else if (flag==0)printf("线性表长度为0，没有什么好排序的\n");
                    else printf("排序成功\n");
                }
                break;
            case 25:
                printf("请输入希望进行操作的线性表的名字\n");
                scanf("%s",listname);
                result = LocateList(ML,listname);
                if(result==0) printf("没有在多线性表中找到%s的线性表\n");
                else if(result==INFEASIBLE) printf("多线性表不存在\n");
                else {
                    printf("成功找到名为%s的线性表，序号为%d\n",listname,result);
                    printf("请输入希望在该表中查找其前驱的元素的值\n");
                    scanf("%d",&e);
                    flag = PriorElem(ML.elem[result-1].L,e,pre);
                    if(flag==OK)printf("查找成功，%d元素的前驱为%d\n",e,pre);
                    else if(flag==INFEASIBLE)printf("线性表不存在\n");
                    else printf("查找失败，可能所给值不在线性表中\n也有可能所给值是线性表的第一个元素的值，该元素无前驱\n");
                }
                break;
            case 26:
                printf("请输入希望进行操作的线性表的名字\n");
                scanf("%s",listname);
                result = LocateList(ML,listname);
                if(result==0) printf("没有在多线性表中找到%s的线性表\n");
                else if(result==INFEASIBLE) printf("多线性表不存在\n");
                else {
                    printf("成功找到名为%s的线性表，序号为%d\n",listname,result);
                    printf("请输入希望在该表中查找其后继的元素的值\n");
                    scanf("%d",&e);
                    result = NextElem(ML.elem[result-1].L,e,next);
                    if(result==OK)printf("查找成功，%d元素的后继为%d\n",e,next);
                    else if(result==INFEASIBLE)printf("线性表不存在\n");
                    else printf("查找失败，可能所给值不在线性表中\n也有可能所给值是线性表的最后一个元素的值，该元素无后继\n");
                }
                break;
            case 27:
                printf("请输入希望进行操作的线性表的名字\n");
                scanf("%s",listname);
                result = LocateList(ML,listname);
                if(result==0) printf("没有在多线性表中找到%s的线性表\n");
                else if(result==INFEASIBLE) printf("多线性表不存在\n");
                else {
                    printf("成功找到名为%s的线性表，序号为%d\n",listname,result);
                    printf("请输入希望获得值的元素的序号（从1开始）\n");
                    scanf("%d",&i);
                    flag = GetElem(L,i,e);
                    if(flag==OK) printf("查找成功，第%d号元素的值为%d",i,e);
                    else if(flag==INFEASIBLE) printf("线性表不存在\n");
                    else printf("查找失败，可能所给i不在线性表长度内");
                }
                break;
            case 28:
                printf("请输入希望进行操作的线性表的名字\n");
                scanf("%s",listname);
                result = LocateList(ML,listname);
                if(result==0) printf("没有在多线性表中找到%s的线性表\n");
                else if(result==INFEASIBLE) printf("多线性表不存在\n");
                else {
                    printf("成功找到名为%s的线性表，序号为%d\n", listname, result);
                    L=ML.elem[result-1].L;
                    printf("接下来请选择2～17的操作来对该线性表进行操作！\n");
                }
            case 0:
                break;
        }
    }
    printf("欢迎下次再使用本系统！\n");
}
