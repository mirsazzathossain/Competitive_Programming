#include<bits/stdc++.h>

using namespace std;

int mod(string s, int mod){
    int rslt = 0;

    for(int i=0; i<s.length(); i++){
        rslt = ((rslt * 10) + (s[i] - '0'))%mod;
    }

    return rslt%mod;
}

int main(){

    string year;

    bool first = false;
    while(cin>>year){

        if(first) cout<<endl;

        bool festival = false;
        bool leap = false;
        first = true;

        if (((mod(year, 4) == 0) && (mod(year, 100) != 0)) || (mod(year, 400) == 0)){
            cout<<"This is leap year."<<endl;
            festival = true;
            leap = true;
        }

        if (mod(year, 15) == 0){
            cout<<"This is huluculu festival year."<<endl;
            festival = true;
        }

        if (mod(year, 55) == 0 &&  leap == true){
            cout<<"This is bulukulu festival year."<<endl;
        }

        if (festival == false){
            cout<<"This is an ordinary year."<<endl;
        }


    }

    return 0;
}