int getSecondLargest(int *arr, int n) {
    // code here
    int first = 0;
    int second = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > first){
            second = first;
            first = arr[i];
        }
        else if(arr[i] > second && arr[i] < first)   second = arr[i];
    }
    return (second == 0) ? -1 : second;
}
