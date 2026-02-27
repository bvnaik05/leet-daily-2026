// User function template for C
int largest(int arr[], int n) {
    // Code Here
    int maxi = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > maxi) maxi = arr[i];
    }
    return maxi;
}
