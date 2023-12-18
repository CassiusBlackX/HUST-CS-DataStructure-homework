status create(BiTree &T, TElemType definition[],int &index){
    if (definition[index].key == 0) {
        T = NULL;
        index++;
        return 0;
    }

    T = (BiTNode*)malloc(sizeof(BiTNode));
    if (!T) {
        return -1;
    }

    T->data = definition[index];
    index++;

    create(T->lchild, definition, index);
    create(T->rchild, definition, index);

    return 0;
}

status check(TElemType definition[]){
    int i=0;
    int lst[1000]={0};
    while(definition[i].key!=-1){
        if(definition[i].key!=0){
            lst[definition[i].key]+=1;
            if (lst[definition[i].key]>1) return ERROR;
        }
        i++;
    }
    return OK;
}
status CreateBiTree(BiTree &T,TElemType definition[])
/*根据带空枝的二叉树先根遍历序列definition构造一棵二叉树，将根节点指针赋值给T并返回OK，
如果有相同的关键字，返回ERROR。此题允许通过增加其它函数辅助实现本关任务*/
{
    //请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(T!=NULL) return INFEASIBLE;
    int result = check(definition);
    if(result==ERROR) return result;
    int index=0;
    result = create(T,definition,index);
    return result==0?OK:OVERFLOW;
    /********** End **********/
}

//12003400500
/*
 *      1
 *    2   3
 *       4  5
 */



//1,a 2,b 3,c 4,d 5,e
// 2,b 1,a 4,d 3,c 5,e