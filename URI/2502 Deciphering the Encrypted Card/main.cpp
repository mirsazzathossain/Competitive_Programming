#include<bits/stdc++.h>

using namespace std;


int main(){

    int c, n;



    while(cin>>c>>n){
        string a, b;
        cin.ignore();
        getline(cin, a);getline(cin, b);

        map<char, char>m;
        for(int i=0; i<c; i++){
            m.insert({a[i], b[i]});
            m.insert({b[i], a[i]});
        }
       
        string s;
        for(int i=0; i<n; i++){
            getline(cin, s);

            string rslt = "";

            for(int j=0; j<s.length(); j++){
                char ch = toupper(s[j]);

                if(m.find(ch) == m.end()) rslt.push_back(s[j]);
                else
                    rslt.push_back(isupper(s[j])?m[ch]:(char)tolower(m[ch]));
            }

            cout<<rslt<<endl;
        }

        cout<<endl;

    }

    return 0;
}