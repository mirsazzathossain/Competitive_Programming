#include<bits/stdc++.h>

using namespace std;

struct Time{
    string period;
    int hr;
    int min;
    int sec;
};

bool operator<(Time t1, Time t2){
    if(t1.period != t2.period){
        return (t1.period == "AM")? true:false;
    }
    else if(t1.hr != t2.hr){
        return t1.hr < t2.hr;
    }
    else if (t1.min != t2.min){
        return t1.min < t2.min;
    }
    else if (t1.sec != t2.sec){
        return t1.sec < t2.sec;
    }
    else{
        return false;
    } 
}


int main(){

    int n;
    cin>>n;

    Time arr[n];
    int h, m, s;
    string p;

    for(int i=0; i<n; i++){
        cin>>h>>m>>s>>p;
        Time temp;
        temp.period = p;
        temp.hr = h;
        temp.min = m;
        temp.sec = s;

        arr[i] = temp;
    }

    sort(arr, arr+n);

    for (int i = 0; i < n; i++){
        cout<<arr[i].hr<<":"<<arr[i].min<<":"<<arr[i].sec<<" "<<arr[i].period<<endl;
    }
    

    return 0;
}