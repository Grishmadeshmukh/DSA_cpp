#include <iostream>
using namespace std;

void selectionSort(int arr[], int n){ //n=size=10
    int i, j, min_idx;
    for(i=0;i<n;i++){
        min_idx = i; //minimum element in unsorted part
        for(j=i+1;j<n;j++){
            if (arr[j] < arr[min_idx])  //> for descending
            min_idx = j; 
           // Swap the found minimum element with the first element
            int temp = arr[min_idx]; 
            arr[min_idx] = arr[i]; 
            arr[i] = temp;
        }
    }
}

void insertionSort(int arr[], int n) {  //n=size=10
    int i, key, j;  
    for (i = 1; i<n; i++) {  
        key = arr[i];  
        j=i-1;  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j>= 0 && arr[j]>key) {  //(j>= 0 && arr[j]<key) for descending
            arr[j+1]=arr[j];  
            j=j-1;  
        }  
        arr[j+1] = key;  
    }  
}  

void bubbleSort(int arr[], int n)  {  //n=size=10
    int i, j;  
    for (i=0; i<n-1; i++)      
      // Last i elements are already in place  
    for (j=0; j<n-1-i; j++){ 
        if (arr[j] > arr[j+1]) { // < for descending
            int temp = arr[j]; 
            arr[j] = arr[j+1]; 
            arr[j+1] = temp;
        }
    }  
}


int partition (int arr[], int low, int high) { 
    int pivot = arr[high];    
    int i = low-1;  // Index of smaller element 
    for (int j=low; j<=high-1; j++) { 
        
        if (arr[j] <= pivot) { // >= for descending
            i++;
            int t = arr[i]; 
            arr[i] = arr[j]; 
            arr[j] = t;
        } 
    } 
    int t = arr[i+1]; 
    arr[i+1] = arr[high]; 
    arr[high] = t;
    return (i + 1); 
}

void quickSort(int arr[], int low, int high) { 
    if (low < high) { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

int partition1(int arr[],int p,int q){
    int pivot =arr[q];
    int i=p-1; 
    for(int j=p;j<=q-1;j++){
        if(arr[j]<=pivot){ //> for descending
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int t=arr[i+1];
    arr[i+1]=arr[q];
    arr[q]=t;
    return (i+1);
}

void quicksort1(int arr[],int p, int q){
    if(p<q){ 
       int mid =partition1(arr,p,q);
       quicksort1(arr, p, mid-1);
       quicksort1(arr, mid+1, q); 
    }
}

void merge(int arr[], int l, int m, int r){
    int n1=m-l+1;
    int n2=r-m;
    int L[n1], R[n2];//temp arrays
 
    // Copy data to temp arrays L[] and R[]
    for (int i=0;i<n1;i++)
        L[i] = arr[l+i];
    for (int j=0;j<n2;j++)
        R[j] = arr[m+1+j];
 
    // Merge the temp arrays back into arr[l..r]
 
    
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = l;// Initial index of merged subarray
    while (i<n1 && j<n2){
        if (L[i]<=R[j]){  //>= for descending
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of
    // L[], if there are any
    while (i<n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    while (j<n2) {
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int l,int h){ // l=low=0 h=high=9 =r
    if(l>=h){
        return;//returns recursively
    }
    int m = (l+h)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,h);
    merge(arr,l,m,h);
}



void radixsort1 (int arr[], int n){
    int i, m=0, e=1, b[10];
    for (i=0; i<n; i++){
        if (arr[i]>m)
            m=arr[i];
    }
    while (m/e>0)
    {
        int bucket[10]={0};
        for (i=0; i<n; i++)
            bucket[arr[i]/e%10]++;  
           // bucket[9-arr[i]/e%10]++;  //for descending
        for (i=1; i<10; i++)
            bucket[i]+=bucket[i-1];
        for (i=n-1; i>=0; i--)
           b[--bucket[arr[i]/e%10]]=arr[i];  
            //b[--bucket[9-arr[i]/e%10]]=arr[i];  //for descending
        for (i=0; i<n;i++){
            arr[i]=b[i];      
        }
        e*=10;
    }
}


int main(){
    int arr[10]={2,38,16,23,12,56,10,91,8,5};
    //selectionSort(arr, 10); 
   // insertionSort(arr,10);
   // bubbleSort(arr,10);
   // quickSort(arr,0,9);
   quicksort1(arr,0,9);
 // mergeSort(arr, 0, 9);
  //radixsort (arr,9);
  //radixsort1(arr,10);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}



