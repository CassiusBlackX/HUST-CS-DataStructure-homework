#include "def.h"
#include "1_CreateBiTree.h"
#include "15_LowestCommonAncestor.h"
#include "4_LocateNode.h"

int main(){
    BiTree T=NULL;
    TElemType definition[100];
    int i=0;
    do{
        scanf("%d%s",&definition[i].key,definition[i].others);
    } while (definition[i++].key!=-1);
    int result = CreateBiTree(T,definition);
    BiTree e1 = LocateNode(T,8);
    printf("%d\n",e1->data.key);
    BiTree e2 = LocateNode(T,9);
    printf("%d\n",e2->data.key);
    BiTree ancestor = LowestCommonAncestor(T,e1,e2);
    printf("%d",ancestor->data.key);
    return 0;
}

/*
 *      1
 *     2    3
 *         4    5
 *        7 8  9  10
 */
// 1 a 2 b 0 n 0 n 3 c 4 d 7 f 0 n 0 n 8 g 0 n 0 n 5 s 9 f 0 n 0 n 10 w 0 n 0 n -1 n