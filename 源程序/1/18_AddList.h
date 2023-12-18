#include<string.h>
status AddList(LISTS &Lists,char ListName[])
// 只需要在Lists中增加一个名称为ListName的空线性表，线性表数据又后台测试程序插入。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(Lists.length<Lists.listsize) {
        strcpy(Lists.elem[Lists.length].name, ListName);
        Lists.elem[Lists.length].L.elem=NULL;
        printf("请输入新添加的线性表中的各个值\n");
        InitList(Lists.elem[Lists.length].L);
        Lists.length++;
        return OK;
    }
    else return ERROR;
    /********** End **********/
}
