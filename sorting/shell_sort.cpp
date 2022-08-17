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

void shellSort(int *a, int n){
    int gap = n/2;
    while(gap>0){
        for(int i=0; i<n-gap; i++){
            if(a[i]>a[i+gap])
                swap(a[i], a[i+gap]);
        }
        gap /= 2;
    }

    // now apply insertion on partially sorted array
    for(int i=1; i<n; i++){
        int temp = a[i];
        int j=i;
        while( j>0 && a[j-1]>temp){
            a[j] = a[j-1];
            j--;
        }
        a[j] = temp;
    }
}


int main(){
    int a[] = {211,234,124,2124,4454,768,4386,3348,5};
    int n = sizeof(a)/sizeof(int);
    shellSort(a,n);
    display(a,n);

    return 0;
}