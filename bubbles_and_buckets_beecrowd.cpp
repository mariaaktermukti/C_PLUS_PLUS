#include <stdio.h>
#include <stdlib.h>

long long mergeCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    long long invCount = 0;
    
    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);
        }
    }
    
    while(i <= mid)
        temp[k++] = arr[i++];
    
    while(j <= right)
        temp[k++] = arr[j++];
    
    for(i = left; i <= right; i++)
        arr[i] = temp[i];
    
    return invCount;
}

long long mergeSortCount(int arr[], int temp[], int left, int right) {
    long long invCount = 0;
    if(left < right) {
        int mid = (left + right) / 2;
        invCount += mergeSortCount(arr, temp, left, mid);
        invCount += mergeSortCount(arr, temp, mid+1, right);
        invCount += mergeCount(arr, temp, left, mid, right);
    }
    return invCount;
}

int main(){
    while(1) {
        int N;
        if(scanf("%d", &N) != 1) break;
        if(N == 0) break;
        
        int *arr = (int*) malloc(N * sizeof(int));
        int *temp = (int*) malloc(N * sizeof(int));
        for (int i = 0; i < N; i++){
            scanf("%d", &arr[i]);
        }
        
        long long inversions = mergeSortCount(arr, temp, 0, N - 1);
        if(inversions % 2 == 1)
            printf("Marcelo\n");
        else
            printf("Carlos\n");
        
        free(arr);
        free(temp);
    }
    
    return 0;
}
