#include <iostream>
using namespace std;

void display(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void selectionSort(int *a, int n){
    for(int i=0;i<n;i++){
        int min_idx = i;
        for(int j=i;j<n;j++){
            if(a[j]<a[min_idx]){
                min_idx = j;
            }
        }
        int temp = a[min_idx];
        a[min_idx] = a[i];
        a[i] = temp;
    }
}


int main(){
    int a[] = {211,234,124,2124,4454,768,4386,3348,5};
    int n = sizeof(a)/sizeof(int);
    selectionSort(a,n);
    display(a,n);

    return 0;
}
