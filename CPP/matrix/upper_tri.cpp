#include <iostream>

using namespace std;

class UpperTri{
    private:
        int n;
        int *A;
    public:
        UpperTri(){
            n=2;
            A = new int[(2*(2+1))/2];
        }
        UpperTri(int n){
            this->n = n;
            A = new int[n*(n+1)/2];
        }
        void set(int i, int j, int x);
        int get(int i, int j);
        void takeInput();
        void display();
        ~UpperTri(){
            delete []A;
        }
};

void UpperTri::set(int i, int j, int x){
    if(j>=i){
        // row major
        A[(n*i)-((i-1)*i)/2+(j-i)] = x;

        // col major
        // A[(j*(j+1)/2)+i+1] = x;
    }
}

int UpperTri::get(int i, int j){
    if(j>=i){
          // row major
        return A[(n*i)-((i-1)*(i)/2)+(j-i)];

        // col major
        // return A[(j*(j+1)/2)+i+1];
    }
    return 0;
}

void UpperTri::display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           cout<<this->get(i,j)<<" ";
        }
        cout<<"\n";
    }
}

void UpperTri::takeInput(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            this->set(i,j,x);
        }
    }
}
int main(){
    UpperTri um(3);
    um.takeInput();
    cout<<endl;
    um.set(1,2,40);
    um.get(1,1);
    um.display();
    return 0;
}