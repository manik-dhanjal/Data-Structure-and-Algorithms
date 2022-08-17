#include <iostream>
using namespace std;

void display(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void merge(int *a, int mid, int n){
    int i=0, j=mid, c=0;
    int *temp = new int[n];
    
    while(i<mid && j<n ){
        if(a[i] < a[j]) temp[c++] = a[i++];
        else temp[c++] = a[j++];
    }

    for(; i<mid; i++) temp[c++] = a[i++];
    for(; j<n; j++) temp[c++] = a[j++];

    for(int x=0;x<n;x++){
        a[x] = temp[x];
    }
    delete []temp;
}

void mergeSort(int *a, int n){
    if(n==1) return;
    int mid = n/2;
    mergeSort(a,mid);
    mergeSort(&a[mid],n-mid);
    merge(a,mid,n);
    return;
}


int main(){
    int a[] = {211,234,124,2124,4454,768,4386,3348,5};
    int n = sizeof(a)/sizeof(int);
    mergeSort(a,n);
    display(a,n);

    return 0;
}