#include <iostream>
using namespace std;

struct DigitArr{
    int n;
    int *arr;
};

void display(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void radixSort(int *a, int n){

    // finding maximum number in array
    int max_num = INT32_MIN;
    for(int i=0;i<n;i++) 
        max_num = max( max_num, a[i] );

    // finding number of digits of largest element
    int max_dig = 0;
    while(max_num>0){
        max_num /= 10;
        max_dig++;
    }

    // initializing the memo table of digits
    DigitArr memo[10];
    for(int i=0;i<10;i++){
        memo[i].n=0;
        memo[i].arr = new int[n];
    }

    // radix sort core algorithm
    int sig = 1;
    for(int i=0; i<max_dig; i++){

        // populating memo according to current significant digit
        for(int j=0; j<n; j++){
            int temp = a[j] % (sig*10);
            int digit = temp / sig;

            int eleInDigitArray = memo[digit].n;
            memo[digit].arr[ eleInDigitArray ] = a[j];
            memo[digit].n++;
        }

        sig *= 10;

        // copying back elements in array a from memo in sorted order and reseting memo;
        int c=0;
        for(int j=0; j<10; j++){
            for(int k=0; k< memo[j].n; k++){
                a[c++] = memo[j].arr[k];
            }
            memo[j].n = 0;
        }
    }

    // deallocating memory from memo;
    for(int i=0;i<10;i++){
        delete [] memo[i].arr;
    }
}

int main(){
    int a[] = {211,234,124,2124,4454,768,4386,3348,5};
    int n = sizeof(a)/sizeof(int);
    radixSort(a,n);
    display(a,n);

    return 0;
}