#include<bits/stdc++.h>

using namespace std;

bool is_power_of_two(int number){
    if(number & number-1) return false;
    return true;
}

int main(){

    //Is a number power of 2
    cout<<is_power_of_two(7)<<endl;

    return 0;
}