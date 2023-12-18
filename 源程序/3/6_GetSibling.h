//BiTNode* GetSibling(BiTree T,KeyType e)
////实现获得兄弟结点
//{
//    // 请在这里补充代码，完成本关任务
//    /********** Begin *********/
//    static int find=0;
//    static BiTree result=NULL;
//    printf("data:%d\n",T->data.key);
//
//    if(T=NULL){
//        return NULL;
//    }
//    else if(T->data.key==e){
//        //找到了要找兄弟的节点
//        find = 1;
//        return result;
//    }
//    else{
//        GetSibling(T->lchild,e);
//        //每次退出循环就看一下是因为找到了还是因为到叶子了
//        //因为是左子树优先，所以兄弟如果有一定是在右边
//        if(find){
//            //找到要找兄弟的节点了了，当前T就是两兄弟的parent节点
//            if(T->rchild!=NULL){
//                result=T->rchild;
//                return result;
//            }
//            else{
//                //parent的右节点为空，说明没有双亲
//                return result;
//            }
//        }
//         GetSibling(T->rchild,e);
//        //每次退出循环就看一下是因为找到了还是因为到叶子了
//        //因为是左子树优先，所以兄弟如果有一定是在右边
//        if(find){
//            //找到要找兄弟的节点了了，当前T就是两兄弟的parent节点
//            if(T->rchild!=NULL){
//                return T->rchild;
//            }
//            else{
//                //parent的右节点为空，说明没有双亲
//                return NULL;
//            }
//        }
//    }
//    /********** End **********/
//}


// 查找指定结点的兄弟结点
BiTNode* GetSibling(BiTree T, KeyType key) {
    if (T == NULL) {
        return NULL;    // 空树返回NULL
    } else if (T->lchild && T->lchild->data.key == key) {
        return T->rchild;    // 找到了目标结点，返回其兄弟结点的指针
    } else if (T->rchild && T->rchild->data.key == key) {
        return T->lchild;    // 找到了目标结点，返回其兄弟结点的指针
    } else {
        BiTNode *left = GetSibling(T->lchild, key);   // 在左子树中查找
        BiTNode *right = GetSibling(T->rchild, key);  // 在右子树中查找
        if (left != NULL) {
            return left;    // 左子树中找到了目标结点，返回其兄弟结点的指针
        } else {
            return right;   // 右子树中找到了目标结点，返回其兄弟结点的指针，若没找到也返回NULL
        }
    }
}
