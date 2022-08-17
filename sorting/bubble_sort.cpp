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

void bubbleSort(int *a, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]) 
                swap(a[j],a[j+1]);
        }
    }
}

int main(){
    int a[] = {211,234,124,2124,4454,768,4386,3348,5};
    int n = sizeof(a)/sizeof(int);
    bubbleSort(a,n);
    display(a,n);

    return 0;
}