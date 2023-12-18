void quicksort(int arr[],int start, int end){
    if(start<end){
        int i,j,pivot,temp;
        pivot=start;
        i=start;
        j=end;
        while(i<j){
            while(arr[i]<=arr[pivot] && i<end) i++;
            while(arr[j]>arr[pivot]) j--;
            if(i<j){
                temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
        quicksort(arr,start,j-1);
        quicksort(arr,j+1,end);
    }
}
status SortList(SqList &L){
    if(L.elem==NULL) return INFEASIBLE;
    if(L.length==0) return ERROR;
    quicksort(L.elem,0,L.length-1);
    return OK;
}