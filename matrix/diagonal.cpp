#include <iostream>

using namespace std;

class Diagonal{
    private:
        int n;
        int *A;
    public:
        Diagonal(){
            n=2;
            A = new int[n];
        }
        Diagonal(int n){
            this->n = n;
            A= new int[n];
        }
        void takeInput(){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    int x;
                    cin>>x;

                    if(i==j)
                        A[i] = x;
                }
            }
            cout<<endl;
        }
        void set(int i,int j,int x){
            if(i==j) A[i] = x;
        }
        int get(int i,int j){
            if(i==j) return A[i];
            return 0;
        }
        void display(){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j) cout<<A[i]<<" ";
                    else cout<<"0"<<" ";
                }
                cout<<"\n";
            }
        }
        ~Diagonal(){
            delete []A;
        }
};
int main(){
    Diagonal d(3);
    d.takeInput();
    d.set(1,1,3);
    cout<<d.get(1,1)<<endl;
    cout<<d.get(0,1)<<endl;
    d.display();
    return 0;
}