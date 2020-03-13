#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 100007;
int n,k;
vector <int> adl[N];

int par[N], child[N];
void dfs(int a, int p){
    
    par[a]=p;
    for (auto x : adl[a]){
        if (x!=p) dfs(x, a);
    }
    
    child[p]+=child[a];
//    child[a]++;
}

void dfs_cut(int a, int p){
    cout << "flip " << a << el;
    for (auto x : adl[a]){
        if (x!=p) dfs_cut(x, a);
    }
}

int main() {
    cin >> n >> k;
    
    if (n-k<k){
        k=n-k;
        for (int i=1;i<=n;i++){
            cout << "flip " << i << el;
        }
    }
    
    for (int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
    }
    
    for (int i=1;i<=n;i++){
        child[i]=1;
    }
    dfs(1,0);
    // for (int i=1;i<=n;i++){
    //     cout << child[i] << " ";
    // }
    
    cout << el;
    
    int node=-1;
    for (int i=1;i<=n;i++){
        if (child[i]==k){
            node=i;
            break;
        }
    }
    
    if (node==-1){
        cout << -1 << el;
        return 0;
    }
    
    dfs_cut(node, par[node]);
    cout << "cut " << node << " " << par[node] << el;
    
    return 0;
}
