status PreOrderTraverse(BiTree T,void (*visit)(BiTree))
//先序遍历二叉树T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(T==NULL) return INFEASIBLE;
    Stack * stack = createStack();//创建一个栈
    push(stack,T);//根节点入栈
    while(!isEmpty(stack)){
        BiTree node = pop(stack);//弹出栈顶元素
        visit(node);
        if(node->rchild){
            //右子节点入栈
            push(stack,node->rchild);
        }
        if(node->lchild){
            //左节点入栈
            push(stack,node->lchild);
        }
    }
    destroyStack(stack);//销毁栈
    return OK;
    /********** End **********/
}

