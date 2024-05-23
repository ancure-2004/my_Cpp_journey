#include<iostream>
using namespace std;
int main(){
    char value;
    int sum=0;
    cout<<"Enter the value: ";
    cin>>value;

    switch(value){
        case 'a':
        sum=value/100;
        cout<<"100 value notes required are "<<sum;

        case 'b':
        value=value-sum;
        sum=value/50;
        if(sum=0){
            break;
        }
        else
        cout<<"50 value notes required are "<<sum;

        case 'c':
        value=value-sum;
        sum=value/50;
        if(sum=0){
            break;
        }
        else
        cout<<"20 value notes required are "<<sum;

        case 'd':
        value=value-sum;
        sum=value/50;
        if(sum=0){
            break;
        }
        else
        cout<<"1 value notes required are "<<sum;


        default:
        cout<<"Enter the valid value";


        
    }




}