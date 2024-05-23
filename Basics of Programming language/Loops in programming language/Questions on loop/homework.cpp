#include<iostream>
using namespace std;

int main(){
    int n,sum=0;
    cout<<"Enter the value of n: ";
    cin>>n;

    int i=0;
    while(i<n){
        i=i+1;
        if(i%2==0){
            sum=sum+i;
        }

    }
    cout<<sum<<endl;

}