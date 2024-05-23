#include<iostream>
using namespace std;

int main(){

int n;
cin>>n;

//For Loop

int sum=0;
for(int i=1; i<=n; i++){
    sum=sum+i;
}

cout<<sum<<endl;


//While Loop

while(n>0){
    cout<<n<<endl;
    cin>>n;
}

//Do_while Loop

do{
    cout<<n<<endl;
    cin>>n;
}while(n>0);


}
