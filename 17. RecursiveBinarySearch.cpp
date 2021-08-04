int binarySearch(int arr[], int low, int high, int n){
while(high >= low) { 
        int mid = (low + high) / 2; 
        if (arr[mid] == n) 
            return mid; 
        if (arr[mid] > n) 
            return binarySearch(arr, low, mid - 1, n); 
        else 
            return binarySearch(arr, mid + 1, high, n); 
        
    } 
    return -1;
}

int main(){
    int n;
    cout<<"enter number to be searched";
    cin>>n;
    int arr[10]={2,5,8,12,16,23,38,56,72,91};
    int low=0,high=9,mid;
    int result = binarySearch(arr, 0, high, n); 
    (result == -1) ? cout << "Element is not present in array": cout << "Element is present at index " << result; 
    
}




