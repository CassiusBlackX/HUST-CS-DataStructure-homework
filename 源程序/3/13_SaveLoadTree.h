void writeNodeToFile(FILE* fp, BiTree T) {
    if (T != NULL) {
        fwrite(&T->data, sizeof(TElemType), 1, fp); //写入节点数据
        writeNodeToFile(fp, T->lchild); //写入左子树节点数据
        writeNodeToFile(fp, T->rchild); //写入右子树节点数据
    }
    else{
        //如果是空节点，那么就专门创造一个空节点用来填充，这样读的时候才知道这里是一个空节点
        TElemType emptyNode = {0, {'\0'}}; // 用于补空子树的空结点
        fwrite(&emptyNode, sizeof(TElemType), 1, fp);
    }
}
status SaveBiTree(BiTree T, char FileName[])
//将二叉树的结点数据写入到文件FileName中
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 1 *********/
    if(T==NULL) return INFEASIBLE;
    FILE *fp=fopen(FileName, "wb");
    if(fp==NULL) return ERROR;
    writeNodeToFile(fp,T);
    fclose(fp);
    return OK;
    /********** End 1 **********/
}
void readNodeFromFile(FILE* fp, BiTree& T) {
    TElemType nodeData;
    if (fread(&nodeData, sizeof(TElemType), 1, fp) == 1) { //读取一个节点的数据
        if(nodeData.key==0) T=NULL;//如果读到了空节点，那么就直接把该处节点置为NULL就好
        else{
            //如果不是空节点就赋值，并且递归的往下继续走
            T = (BiTree)malloc(sizeof(BiTNode)); //分配节点空间
            T->data = nodeData; //将节点数据存储到节点中
            T->lchild = NULL;//养成好习惯，每新创建一个节点都先暂时把左右孩子都变成空
            T->rchild = NULL;
            readNodeFromFile(fp, T->lchild); //递归读取左子树
            readNodeFromFile(fp, T->rchild); //递归读取右子树
        }

    }
}
status LoadBiTree(BiTree &T,  char FileName[])
//读入文件FileName的结点数据，创建二叉树
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 2 *********/
    if(T!=NULL) return INFEASIBLE;
    FILE *fp=fopen(FileName, "rb");
    if(fp==NULL) return ERROR;
    readNodeFromFile(fp,T);
    fclose(fp);
    return OK;
    /********** End 2 **********/
}

/*
 *      1
 *     2    3
 *         4   5
 */