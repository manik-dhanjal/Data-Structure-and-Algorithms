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

void heapify(int *a, int n){
    for(int i=n-1;i>=0;i--){
       int itr_p = i;
       int itr_c = (( itr_p+1 ) * 2 ) -1;
       while(itr_c<n){
        if(itr_c+1<n && a[itr_c]<a[itr_c+1]) itr_c++;

        if(a[itr_c] > a[itr_p]){
            swap(a[itr_c], a[itr_p]);
            itr_p = itr_c;
            itr_c = (( itr_p+1) * 2) -1;
        }
        else break;
       }
    }
}

void popAll(int *a, int n){
    for(int i=n-2;i>=0;i--){
        swap(a[0], a[i+1]);
        int itr_p = 0;
        int itr_c = ((itr_p+1) * 2) -1;
        while(itr_c <= i){
            if(itr_c+1 <= i && a[itr_c] < a[itr_c+1]) itr_c++;
            
            if(a[itr_c] > a[itr_p]){
                swap( a[itr_c], a[itr_p]);
                itr_p = itr_c;
                itr_c = ((itr_p+1) * 2) -1;
            }
            else break;
        }
    }
}
void heapSort(int *a, int n){
    heapify(a,n);
    popAll(a,n);
}

int main(){
    int a[] = {211,234,124,2124,4454,768,4386,3348,5};
    int n = sizeof(a)/sizeof(int);
    heapSort(a,n);
    display(a,n);

    return 0;
}