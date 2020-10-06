#include<bits/stdc++.h>
using namespace std;

void merge2(int *arr, int start, int end) {
    int mid = (start+end)/2;
    int i = start, j = mid+1, k = start;
    int temp[10000];

    while(i <= mid and j <= end) {
        if(arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while(i <= mid) {
        temp[k++] = arr[i++];
    }
    while(j <= end) {
        temp[k++] = arr[j++];
    }
    for(int i = start; i <= end; i++) {
        arr[i] = temp[i];
    }

}

// function for merge sort 
void mergeSort(int *arr, int start, int end) {

    if(start >= end) {
        return;
    }

    int mid = (start+end)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, end);
}


void merge(int arr[] , int a[], int b[],int n , int n1, int n2){
    int l=0;
    int r=0;

    for(int i=0;i<n;i++){

        if((a[l]<b[r] && l<n1) || r==n2){
            arr[i] = a[l];
            l++;
        }
        else{
            arr[i] = b[r];
            r++;
        }
    }
}

int* divider(int start , int end , int arr[]){
    int* a = new int[end-start];

    for(int i=start;i<end;i++){
        a[i-start] = arr[i];
    }

    return a;
}

void merge_sort(int arr[],int n){
    if(n>1){
        int mid = (0+n)/2;
        int* a = divider(0,mid,arr);
        int* b = divider(mid , n , arr);
        merge_sort(a,mid);
        merge_sort(b,n-mid);

        merge(arr,a,b,n,mid,n-mid);

    }
}



int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    merge_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }





}