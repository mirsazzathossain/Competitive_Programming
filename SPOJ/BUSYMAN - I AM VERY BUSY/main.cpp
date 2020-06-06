#include<bits/stdc++.h>

using namespace std;

struct scedule{
    int start_time;
    int end_time;
};

bool operator<(const scedule& s1, const scedule& s2) {
    if(s1.end_time != s2.end_time) return s1.end_time<s2.end_time;
    return false;
}


int main(){

    int t, n;
    cin>>t;

    while(t--){
        cin>>n;
        scedule arr[n];
        
        int st, en;
        for (int i = 0; i < n; i++){
            cin>>st>>en;
            scedule temp;
            temp.start_time = st;
            temp.end_time = en;
            arr[i] = temp;
        }

        sort(arr, arr+n);

        int cnt = 1, fao = arr[0].end_time;
        for (int i = 1; i < n; i++){
            if(arr[i].start_time >= fao){
                cnt++;
                fao = arr[i].end_time;
            }
        }
        
        cout<<cnt<<endl;
    }

    return 0;
}

