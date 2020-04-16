#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin, s);

        string l="", r="";

        for(int i=0; i<s.length(); i++){
            if(i<(int)(s.length()/2)) l.push_back(s[i]);
            else r.push_back(s[i]);
        }
        reverse(l.begin(), l.end());
        reverse(r.begin(), r.end());

        cout<<l<<r<<endl;
    }

    return 0;
}