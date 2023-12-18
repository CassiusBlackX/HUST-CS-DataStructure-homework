//void dfs(SqList L,int index,int sum,int k,int &g){
//    if(index==L.length)
//        return ;
//    sum += L.elem[index];
//    if(sum==k) g++;
//    if(sum>=k) dfs(L,index+1,sum-L.elem[index],k,g);
//    dfs(L,index+1,sum,k,g);
//    return ;
//}
//
//int SubArrayNum(SqList L,ElemType k){
//    if(L.elem==NULL) return INFEASIBLE;
//    if(L.length==0) return ERROR;
//    int g = 0;
//    dfs(L,0,0,k,g);
//    return g;
//}

#include <stdio.h>
#include <stdlib.h>

int SubArrayNum(SqList L, int k) {
    int numsSize = L.length;
    int count = 0;
    int sum = 0;
    int* dp = (int*) malloc(sizeof(int) * numsSize);
    //dp用来记录以第i个元素为结尾的连续子数组中和为k的个数
    //1。当前元素值等于k，那么只有一个，dp[i]=1
    //2。不等于，那么有两种可能
    //2。1 以前中某个位置j结尾的子数组加上[i]可以得到k，子数组的个数由dp[j]给出
    //2。2 单独一个元素[i]偶成一个子数组，和为[i]，如果[i]恰好等于k-[j]，那么[i]可以和之前某个位置j结尾的子数组的元素相加得到和为k的子数组
    for (int i = 0; i < numsSize; i++) {
        dp[i] = 0;
    }
    for (int i = 0; i < numsSize; i++) {
        sum += L.elem[i];
        if (sum == k) {
            count++;
        }
        if (dp[sum - k] > 0) {
            count += dp[sum - k];
        }
        dp[sum]++;
    }
    free(dp);
    return count;
}


