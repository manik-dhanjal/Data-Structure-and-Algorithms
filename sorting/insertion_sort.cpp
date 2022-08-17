#include <iostream>

using namespace std;

void display(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void insertionSort(int *a,int n){
    for(int i=1 ; i<n ; i++){
        int temp = a[i];
        int j=i;
        while(j>0 && a[j-1]>temp){
            a[j] = a[j-1];
            j--;
        }
        a[j] = temp;
    }
}


int main(){
    int a[] = {211,234,124,2124,4454,768,4386,3348,5};
    int n = sizeof(a)/sizeof(int);
    
    insertionSort(a,n);
    display(a,n);

    return 0;
}
