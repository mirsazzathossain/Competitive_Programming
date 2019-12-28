#include<bits/stdc++.h>

using namespace std;

//Inputs
#define sfi(x) scanf("%d", &x)
#define sfl(x) scanf("%ld", &x)
#define sfd(x) scanf("%lf", &x)
#define sfc(x) scanf("%c", &x)
#define sfs(x) getline(cin, x);
#define in(x) cin>>x;
//Outputs
#define pfi(x) printf("%d", x)
#define pfl(x) printf("%ld", x)
#define pfd(x) printf("%lf", x)
#define pfc(x) printf("%c", x)
#define out(x) cout<<x
#define endl printf("\n")
#define pcase(i) printf("Case %d: ", i)
//Loops
#define loop0(i, n) for(i=0; i<n; i++)
#define loop1(i, n) for(i=1; i<=n; i++)
#define loopab(i, a, b) for(i=a; i<=b; i++)
#define loopr0(i, n) for(i=n-1; i>=0; i--)
#define loopr1(i, n) for(i=n; i>=1; i--)
#define looprab(i, a, b) for(i=b; i>=a; i--)
#define iterate(it, x) for(it=x.begin(); it!=x.end(); it++)
//Fast Input Output
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
//Data Types
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef vector<double> vd;
typedef set<int> si;
typedef set<long long> sll;
typedef set<double> sd;
typedef set<string> ss;
typedef pair<int, int> pii;
typedef map<int, int> mpii;
typedef map<string, int> mpsi;
//Keywords
#define pb push_back
#define ins insert
//Useful Functions
#define sort(x) sort(x.begin(), x.end());
#define sortr(x, a, b) sort(x.begin()+a, x.end()+b+1);
#define sortd(x) sort(x.begin(), x.end(), greater<int>());
#define rev(x) reverse(x.begin(), x.end());
#define revr(x, a, b) reverse(x.begin()+a, x.end()+b+1);
//Constants
const int MOD = 1000000007;
const int MAX = 1000005;
const double PI = acos(-1.0);

//Custom
typedef vector<vector<pair<int, int> > > vvpii;
#define white 0
#define gray 1
#define black 2
int color[30000];
mpii leafNodes;
ll mx = 0;
int node = -1;
ll final = 0;
vvpii adj;

void dfs(int u, ll total){
    color[u] = gray;

    int i;
    loop0(i, adj[u].size()){
        int v = adj[u][i].first;
        if(color[v]==white){
            dfs(v, total + adj[u][i].second);
        }
    }

    if(adj[u].size() == 1 && color[adj[u][0].first] != white){
        if(total>mx){
            mx = total;
            node = u;
        }
    }
    color[u] = black;
}


int main(){
    //fastio;
    //fstream fin("input.txt");
    //ofstream fout("output.txt");

    int t, i;
    sfi(t);

    loop1(i, t){
        node = -1;
        mx = 0;
        int k;
        loop0(k, 30000){
            color[k]=white;
        }


        int n;
        sfi(n);
        adj.resize(n);

        int u, v, w, j;

        loop0(j, n-1){
            sfi(u); sfi(v); sfi(w);
            adj[u].pb(pii(v, w));
            adj[v].pb(pii(u, w));
        }

        dfs(0, 0);

        loop0(k, 30000){
            color[k]=white;
        }

        int newNode = node;
        node = -1;
        mx = 0;
        loop0(k, 30000){
            color[k]=white;
        }

        dfs(newNode, 0);
        pcase(i);pfl(mx);endl;
        adj.clear();
    }
    
    return 0;
}