#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 5e2 + 10;
const int INF = 1e9 + 10;

int n;
int mat[N][N];

vector<int> adj[N];
int col[N];

void init(){
    for (int i=1;i<=n;i++){
        adj[i].clear();
    }
    fill(col, col + n + 1, -1);
}

bool ok;
void dfs(int node){
    for (auto x : adj[node]){
        if (col[x] != -1){
            if (col[x] == col[node]){
                ok = 0;
                return;
            }
            continue;
        }
        col[x] = !col[node];
        dfs(x);
    }
}

bool bisa(int tar){
    init();
    for (int i=1;i<=n;i++){
        for (int j=i + 1;j<=n;j++){
            if (mat[i][j] < tar){
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }
    ok = 1;
    for (int i=1;i<=n&&ok;i++){
        if (col[i] == -1){
            col[i] = 0;
            dfs(i);
        }
    }
    return ok;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> mat[i][j];
        }
    }
    int l = 0, r = INF;
    while (l < r){
        int m = (l + r + 1) / 2;
        if (bisa(m)){
            l = m;
        } else{
            r = m - 1;
        }
    }
    cout << l << el;

    return 0;
}