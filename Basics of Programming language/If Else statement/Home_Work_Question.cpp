#include<iostream>
using namespace std;
int main(){

    char ch;
    cout<<"Enter the Value of character : ";
    cin>>ch;

    if(ch>=65 && ch<=90) {
        cout<<"Upper Case"<<endl;
    }

    else if(ch>=97 && ch<=122) {
        cout<<"Lower Case"<<endl;
    }

    else if(ch>=0 && ch<=64)
    {
         cout<<"Numeric NUmber"<<endl;
    }

    else
    {
        cout<<"Not Registered"<<endl;
    }

    return 0;
}