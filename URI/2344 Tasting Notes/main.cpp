#include <iostream>
 
using namespace std;
 
 
int main() {
    int n;

    cin>>n;

    if(n>=86) cout<<"A"<<endl;
    else if(n>=61) cout<<"B"<<endl;
    else if(n>=36) cout<<"C"<<endl;
    else if(n>=1) cout<<"D"<<endl;
    else cout<<"E"<<endl;


    return 0;
}