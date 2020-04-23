#include<bits/stdc++.h>

using namespace std;


int num(map<int, int>mp ,int width, int length){
    int a, b, cnt = 0;
    map<int, int>::reverse_iterator it = mp.rbegin();

    while (width != 0 && it != mp.rend()){
        a = it->first;
        if(a > length) it++;
        else{
            b = length - a;
            if(a == b){
                if(mp[a]<2) it++;
                else {
                    cnt+=2;
                    width--;
                    mp[a]--;mp[b]--;
                }
            }
            else{
                if(mp[a] == 0 || mp[b] == 0) it++;
                else if(a == length || b == length){
                    cnt+=1;
                    width--;
                    mp[a]--;mp[b]--;
                }
                else {  
                    cnt+=2;
                    width--;
                    mp[a]--;mp[b]--;
                }
            }
        }
    }

    if(cnt == 0 || width != 0) return -1;

    return cnt;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // fstream fin("input.txt");
    // ofstream fout("output.txt");

    int n, m, l, k, x, rslt1, rslt2;
    map<int, int>mp;

    while (true){
        cin>>n>>m;
        if(n == 0 && m == 0) break;


        cin>>l;
        cin>>k;

        for(int i=0; i<k; i++){
            cin>>x;
            mp[x]++;
            mp[0]++;
        }


        rslt1 = -1;
        rslt2 = -1;

        if((n*100)%l == 0){
            rslt1 = num(mp, (n*100)/l, m);
        }
        if((m*100)%l == 0){
            rslt2 = num(mp, (m*100)/l, n);
        }

        if(rslt1 == -1 && rslt2 == -1) cout<<"impossivel"<<endl;
        else if(min(rslt1, rslt2) == -1) cout<<max(rslt1, rslt2)<<endl;
        else cout<<min(rslt1, rslt2)<<endl;

        mp.clear();
    }
    

    return 0;
}