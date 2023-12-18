status check(BiTree &T,int lst[]){
    static int result = 1;
//    printf("data:%d\n",T->data.key);
    lst[T->data.key]++;

    if(lst[T->data.key]>1) {
//        printf("\nexcute to error\n");
        result=ERROR;
    }

    if(T->lchild!=NULL) result = result && check(T->lchild,lst);
    if(T->rchild!=NULL) result = result && check(T->rchild,lst);

    return result;
}

status Assign(BiTree &T,KeyType e,TElemType value)
//实现结点赋值。此题允许通过增加其它函数辅助实现本关任务
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(T==NULL) return INFEASIBLE;
    BiTree p= LocateNode(T,e);
    if(p!=NULL) {
        p->data = value;
        int lst[1000]={0};
        int result = check(T,lst);
        if(result==ERROR){
            p->data.key = e;
        }
        return result;
    }
    else {
        return ERROR;
    }
    /********** End **********/
}
