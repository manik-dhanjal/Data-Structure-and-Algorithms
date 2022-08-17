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

int partition(int *a, int n){
    int mid = n/2;
    swap(a[mid],a[n-1]);
    int ptr = n-1;

    for(int i=n-2;i>=0;i--){
        if(a[i]>a[ptr]){
            int temp = a[i];
            a[i] = a[ptr-1];
            a[ptr-1] = a[ptr];
            a[ptr] = temp;
        }
    }
    return ptr;
}

void quickSort(int *a, int n){
    if( n < 2 ) return;

    int par = partition(a,n);
    quickSort(a,par);
    quickSort(&a[par+1], n-par-1 );
    return;
}
struct DigitArr{
    int n;
    int *arr;
};


int main(){
    int a[] = {211,234,124,2124,4454,768,4386,3348,5};
    int n = sizeof(a)/sizeof(int);
    quickSort(a,n);
    display(a,n);

    return 0;
}
