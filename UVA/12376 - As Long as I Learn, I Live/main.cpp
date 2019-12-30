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
typedef vector<vector<int>> vvi;
#define white 0
#define black 1

int weight[100];
int color[100];
vvi adj;
int learnUnit;
int node;

void bfs(){
    learnUnit = 0;
    node = 0;
    color[0] = black;

    queue<int>q;
    q.push(0);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        int i, mxNode = -1;
        loop0(i, adj[u].size()){
            int v = adj[u][i];

            if(mxNode == -1 && color[v] == white){
                mxNode = v;
            }else if(weight[v] > weight[mxNode] && color[v] == white){
                mxNode = v;
            }
        }
        if(mxNode == -1) break;
        q.push(mxNode);
        color[mxNode] = black;
        node = mxNode;
        learnUnit += weight[node];
    }
}



int main(){
    //fastio;
    //fstream fin("input.txt");
    //ofstream fout("output.txt");
    
    int t, i, n, m;
    sfi(t);

    loop1(i, t){
        sfi(n); sfi(m);
        adj.resize(n);

        int j;
        loop0(j, n){
            sfi(weight[j]);
            color[j] = white;
        }

        int u, v;
        while(m--){
            sfi(u); sfi(v);
            adj[u].pb(v);
        }

        bfs();

        pcase(i); pfi(learnUnit); printf(" "); pfi(node); endl;
        adj.clear();

    }
    
    
    return 0;
}