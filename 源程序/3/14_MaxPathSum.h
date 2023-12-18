//int MaxPathSum(BiTree T,int cursum,int maxsum){
//    if (T==NULL) {
//        maxsum = cursum>maxsum?cursum:maxsum;
//        return maxsum;
//    }
//    MaxPathSum(T->lchild,cursum+1,maxsum);
//    MaxPathSum(T->rchild,cursum+1,maxsum);
//    return maxsum;
//}
//这个和求树的深度有什么区别？
//这个求和是用来求所有路径的总和
int max(int a, int b) {
    return a > b ? a : b;
}

int MaxPathSum(BiTree T) {
    if (T == NULL) { // 递归边界：空节点返回0
        return 0;
    }
    int leftSum = MaxPathSum(T->lchild); // 左子树的最大路径和
    int rightSum = MaxPathSum(T->rchild); // 右子树的最大路径和
    // 计算根节点到左右子树中较大的路径和
    int rootSum = T->data.key + max(0, max(leftSum, rightSum));
    //*-*- 说实话其实本来都没有想到过还有可能key是负数的情况，但是看了老师发的图片以后才想到这个可能
    return rootSum;
}
/*
 *      -10
 *      9   20
 *         15   7
 */
//-10 a 9 b 0 n 0 n 20 c 15 d 0 n 0 n 7 d 0 n 0 n -1 n

/*
 *      1
 *     2    3
 *    4 5  6    7
 1 a 2 b 4 c 0 n 0 n 5 d 0 n 0 n 3 e 6 f 0 n 0 n 7 g 0 n 0 n -1 n
 */