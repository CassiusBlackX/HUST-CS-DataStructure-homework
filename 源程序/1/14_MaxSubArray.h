int dfs(SqList L,int index,int sum){
    static int maxsum = -9999;
    if(index==L.length){
        maxsum=maxsum>sum?maxsum:sum;
        return maxsum;
    }
    //选择当前元素或者不选择当前元素
    dfs(L,index+1,maxsum>sum?maxsum:sum);
    dfs(L,index+1,sum);
    return maxsum;
}
int dp(SqList L){
    int maxsum=L.elem[0];
    int cursum=L.elem[0];
    for(int i=1;i<L.length;i++){
        cursum=cursum>0?cursum+L.elem[i]:L.elem[i];
        //只要当前求和没有加成负，那么就继续加，
        //反正等会儿是和maxsum取最大，影响不大
        //1 -8 9 这种情况，不能看到负数就停，要继续向后看
        maxsum=cursum>maxsum?cursum:maxsum;
    }
    return maxsum;
}
status MaxSubArray(SqList &L,ElemType &e){
    e=-9999;
    if(L.elem==NULL) return INFEASIBLE;
    if (L.length==0) return ERROR;
    //使用dfs算法来实现连续子数组的最大值的求解
//    e = dfs(L,0,0);
    e = dp(L);
    return OK;
}