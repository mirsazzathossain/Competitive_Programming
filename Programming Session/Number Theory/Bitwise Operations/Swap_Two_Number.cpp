#include<bits/stdc++.h>

using namespace std;

void swap(int &a, int &b){
    //     a = 00000000 00000000 00000000 00000111
    //     b = 00000000 00000000 00000000 00010010
    a = a^b; //00000000 00000000 00000000 00010101
    b = a^b; //00000000 00000000 00000000 00000111
    a = a^b; //00000000 00000000 00000000 00010010
}

int main(){

    //Swap two number without using third variable
    int a=7, b=18;
    swap(a, b);
    cout<<a<<" "<<b<<endl; 
    
    return 0;
}