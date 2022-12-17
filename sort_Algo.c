// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

int binarysearch(int arr[], int low, int high, int x){
    if(high>=low){
        int mid = low + (high-low)/2;
        
        if(arr[mid]==x) return mid;
        else if(x > arr[mid]) return binarysearch(arr, mid+1, high, x);
        else return binarysearch(arr, low, mid-1, x);
    }
    return -1;
}

int* insertionsort(int arr[], int s){
    int cur, j;
    for(int i=1; i<s; i++){
        cur = arr[i];
        j = i-1;
        while(cur < arr[j] && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = cur;
    }
    return arr;
}

int* shellsort(int arr[], int s){
    int cur, j;
    for(int gap=s/2; gap>=1; gap/=2){
        for(int i=gap; i<s; i++){
        cur = arr[i];
        j = i-gap;
        while(cur < arr[j] && j>=0){
            arr[j+gap] = arr[j];
            j-=gap;
        }
        arr[j+gap] = cur;
    }    
    }
    return arr;
}

int* selectionsort(int arr[], int s){
    int temp;
    for(int i=0; i<s-1; i++){
        for(int j=i+1; j<s; j++){
            if(arr[j] < arr[i]){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    return arr;
}

int* bubblesort(int arr[], int n){
    int temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return arr;
}


int main() {
    int *arr;
    int s;
    printf("Enter size = ");
    scanf("%d", &s);
    arr = (int*)malloc(sizeof(int)*s);
    for(int i=0; i<s; i++){
        scanf("%d", &arr[i]);
    }
    
    

    arr = bubblesort(arr, s);
    for(int i=0; i<s; i++){
        printf(" %d", arr[i]);
    }
    
    if(binarysearch(arr, 0, s-1, 4) == -1) printf("\nNot found");
    else printf("\nfound");
    return 0;
    
}
