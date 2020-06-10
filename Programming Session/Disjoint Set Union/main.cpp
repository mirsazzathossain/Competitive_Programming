#include<bits/stdc++.h>

using namespace std;

int arr[10000];
int parr[10000];

int Find(int x){
    if(parr[x] == x) return x;
    return Find(parr[x]);
}

void Union(int a, int b){
    parr[Find(b)] = Find(a);
}

int mx = 0;
void HCLPQ(int a, int n){
    if((a == 0 && arr[a+1] == 0)||
       (a == n-1 && arr[a-1] == 0)||
       (arr[a+1] == 0 && arr[a-1] == 0)){
        arr[a]++;
    }
    else if(arr[a+1] != 0 && arr[a-1] != 0){
        arr[a] = arr[Find(a+1)]+arr[Find(a-1)]+1;
        Union(a, a-1);
        Union(a+1, a);
        arr[Find(a)] = arr[a];
    }
    else if(arr[a+1] != 0 || arr[a-1] != 0){
        arr[a] = (arr[a+1] != 0) ? (arr[Find(a+1)]+1):(arr[Find(a-1)]+1);
        (arr[a+1] != 0) ? Union(a+1, a):Union(a, a-1);
        arr[Find(a)] = arr[a];
    }

    if(mx<arr[Find(a)]) mx = arr[Find(a)];
    
}


int main(){
    int n, a;
    cin>>n;

    for(int i=0; i<n; i++){
        arr[i] = 0;
        parr[i] = i;
    }

    for(int i=0; i<n; i++){
        cin>>a;
        HCLPQ(a, n);
        cout<<mx<<endl;
    }

    return 0;
}