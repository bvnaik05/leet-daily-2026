bool searchInSorted(int* arr, int n, int k) {
    int l = 0;
    int r = n - 1;
    
    while(l <= r){
        int mid = (l + r) / 2;
        if(arr[mid] == k) return true;
        else if(arr[mid] > k) r = mid - 1;
        else l = mid + 1;
    }
    return false;
}
