#include<iostream>
using namespace std;
int main(){

    int n1,n2;
    cout<<"Enter two numbers: ";
    cin>>n1>>n2;

    char op;
    cout<<"Enter Operation to do: ";
    cin>>op;

    switch(op)
    {
    case '+':
    cout<<n1+n2<<endl;
    break;

    case '-':
    cout<<n1-n2<<endl;
    break;

    case '*':
    cout<<n1*n2<<endl;
    break;

    case '/':
    cout<<n1/n2<<endl;
    break;

    default:
    cout<<"Enter valid operator"<<endl;
    break;

    }

}