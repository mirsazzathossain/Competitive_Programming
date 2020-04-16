#include<bits/stdc++.h>

using namespace std;

map<string, int>m;



int main(){

    m.insert({"suco de laranja", 120});
    m.insert({"morango fresco", 85});
    m.insert({"mamao", 85});
    m.insert({"goiaba vermelha", 70});
    m.insert({"manga", 56});
    m.insert({"laranja", 50});
    m.insert({"brocolis", 34});


    int t, n;

    string s;

    while(true){
        cin>>t;
        if(t==0) break;

        int total = 0;
        for(int i=0; i<t; i++){
            cin>>n;
            cin.ignore();
            getline(cin, s);

            total += n * m[s];
        }

        if(total > 130) cout<<"Menos "<<total-130<<" mg"<<endl;
        else if(total >= 110) cout<<total<<" mg"<<endl;
        else cout<<"Mais "<<110-total<<" mg"<<endl;
    }

    return 0;
}