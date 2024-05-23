# include<iostream>
using namespace std;
int main() {

int a, b, c;
cout<<"Enter first number: ";
cin>>a;
cout<<"\nEnter second number: ";
cin>>b;
cout<<"\nEnter third number: ";
cin>>c;

if(a>b) {
    if(a>c) {
        cout<<"Largest number is "<<a<<endl;
    }
    else {
        cout<<"Largest number is "<<c<<endl;
    }
}

else if(b>a) {
    if(b>c) {
        cout<<"Lagerst number is "<<b<<endl;
    }
    else {
        cout<<"Largest number is "<<c<<endl;
    }

}

else {
    cout<<"Largest number is"<<a<<endl;
}

return 0;
}