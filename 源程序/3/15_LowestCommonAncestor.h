//BiTree LowestCommonAncestor(BiTree T, BiTree e1, BiTree e2){
//    if (T==NULL) return NULL;
//    if(T->data.key==e1->data.key || T->data.key==e2->data.key) return T;
//
//    BiTree leftCommonAncestor = LowestCommonAncestor(T->lchild,e1,e2);
//    BiTree rightCommonAncestor = LowestCommonAncestor(T->rchild,e1,e2);
//
//    if(leftCommonAncestor && rightCommonAncestor) return T;
//    return (leftCommonAncestor!=NULL)? leftCommonAncestor:rightCommonAncestor;
//}

BiTree LowestCommonAncestor(BiTree T, BiTree e1, BiTree e2) {
    if (T == NULL) {
        return NULL;
    }

    if (T == e1 || T == e2) {
        return T;
    }

    BiTree leftCommonAncestor = LowestCommonAncestor(T->lchild, e1, e2);
    BiTree rightCommonAncestor = LowestCommonAncestor(T->rchild, e1, e2);

    if (leftCommonAncestor && rightCommonAncestor) {
        return T;
    }

    if (leftCommonAncestor != NULL) {
        return leftCommonAncestor;
    }

    if (rightCommonAncestor != NULL) {
        return rightCommonAncestor;
    }

    return NULL;
}

