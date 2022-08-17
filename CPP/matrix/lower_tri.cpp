#include <iostream>

using namespace std;

class LowerTri{
    private:
        int n;
        int *A;
    
    public:
        LowerTri(){
            n=2;
            A = new int[(n*(n+1))/2];
        }
        LowerTri(int n){
            this->n = n;
            A = new int[(n*(n+1))/2];
        }

        void set(int i, int j, int x);
        int get(int i, int j);
        void display();
        void takeInput();
        void displayArr();
        ~LowerTri(){
            delete []A;
        }
};

void LowerTri::set(int i, int j, int x){
    if(j<=i){
        // row major
        // A[((i*(i+1))/2)+j] = x;

        // col major
        A[n*j - ((j-1)*j)/2 + i-j ] = x;
    }
}

int LowerTri::get(int i,int j){
    if(j<=i){
        // row major
        // return A[((i*(i+1))/2)+j];

        // col major
        return A[n*j - ((j-1)*j)/2 + i-j ];
    }
    return 0;
}

void LowerTri::display(){
    for(int i=0; i<n ; i++){
        for(int j=0;j<n;j++){
            cout<<this->get(i,j)<<" ";
        }
        cout<<endl;
    }
}

void LowerTri::takeInput(){
    for( int i=0; i<n; i++){
        for( int j=0; j<n; j++){
            int x;
            cin>>x;
            this->set(i,j,x);
        }
    }
}

void LowerTri::displayArr(){
    for(int i=0; i< ((n*(n+1))/2);i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main(){
    LowerTri lm(3);
    lm.takeInput();
    lm.set(1,2,4);
    lm.set(2,0,10);
    lm.display();
}