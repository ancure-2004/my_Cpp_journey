#include<iostream>
using namespace std;
int main(){
    int n, j=0;
    cout<<"Enter the number: ";
    cin>>n;
    for(int i=2;i<n;i++){
        if(n%i==0){
            j=j+1;
        }
    }
    if(j==0){
        cout<<"The given number is prime"<<endl;
    }
    else{
        cout<<"The given number is not prime"<<endl;
    }
}