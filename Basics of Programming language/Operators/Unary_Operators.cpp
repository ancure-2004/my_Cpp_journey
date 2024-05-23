#include<iostream>
using namespace std;
int main() {

//Example 1
int i=1;
int j=2;
int k;
k= i + j + i++ + j++ + ++i + ++j;
cout<<i<<" "<<j<<" "<<k<<endl;

//Example 2
int i=0;
i = i++ - --i + ++i - i--;
cout<<i<<endl;

//Example 3
int i=10, j=20, k;
k= i-- - i++ + --j - ++j + --i - j-- + ++i - j++;
cout<<i<<endl;
cout<<j<<endl;
cout<<k<<endl;

return 0;

}