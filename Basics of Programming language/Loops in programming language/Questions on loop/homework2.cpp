#include<iostream>
using namespace std;

int main(){
    int n,i=0;
    cout<<"Enter the number to check: ";
    cin>>n;

    while(i<=n){
        i=i+1;
        if(i==1){
            continue;
            }
        else if(n%i==0){
            cout<<"The number is prime"<<endl;
        }
        else{
            cout<<"The number is not prime"<<endl;
        }

    }
}