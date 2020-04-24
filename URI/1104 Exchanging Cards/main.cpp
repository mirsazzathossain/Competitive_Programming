#include<bits/stdc++.h>


using namespace std;

int ans(set<int>s1, set<int>s2){
    set<int>::iterator it;
    int cnt = 0;
    for(it = s1.begin(); it != s1.end(); ++it){
        if(s2.find(*it) != s2.end()){
            s2.erase(*it);
            cnt++;
        }
    }

    return (s1.size()-cnt)<s2.size() ? s1.size()-cnt:s2.size();
}

int main(){

    int a, b, x;

    //ofstream fout("output.txt");

    while(cin>>a>>b){
        if(a == 0 && b == 0) break;

        set<int>s1;
        set<int>s2;

        for(int i=0; i<a; i++){
            cin>>x;
            s1.insert(x);
        }
        for(int i=0; i<b; i++){
            cin>>x;
            s2.insert(x);
        }

        if(s1.size()<s2.size()){
            cout<<ans(s1, s2)<<endl;
        }
        else{
            cout<<ans(s2, s1)<<endl;
        }



    }


    return 0;
}