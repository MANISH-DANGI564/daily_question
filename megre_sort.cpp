#include<bits/stdc++.h>
using namespace std;
void merge(int start,int mid,int end,int *arr){
    int n1=mid-start+1;
    int n2=end-mid;
    int *arr1=new int[n1];
    int *arr2=new int[n2];
    for(int i=0;i<n1;i++){
        arr1[i]=arr[start+i];
    }
    for(int i=0;i<n2;i++){
        arr2[i]=arr[mid+1+i];
    }
    int beg=start,i=0,j=0;
    while(i<n1&&j<n2){
        if(arr1[i]<arr2[j]){
            arr[beg++]=arr1[i++];
        }
        else{
            arr[beg++]=arr2[j++];
        }
    }
    while(i<n1){
        arr[beg++]=arr1[i++];
    }
    while(j<n2){
        arr[beg++]=arr2[j++];
    }
    return;
}
void mergesort(int start,int end,int *arr){
    if(start>=end){
        return;
    }
    int mid=(start+end)/2;
    mergesort(start,mid,arr);
    mergesort(mid+1,end,arr);
    merge(start,mid,end,arr);
}
int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergesort(0,n-1,arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}