#pragma gcc optimize ("O3")
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

void dismiss(){
    cout << -1 << el;
    exit(0);
}

const int N = 2e3 + 10, M = 4 * N;

// operation indexing:
// row = [0..n - 1]
// col = [n..2n - 1]
int n;
int mat[N][N];
int ar[N];

int assign[M];

// graph indexing:
// 2 * x for node x, 2 * x + 1 for node ~x
vector<int> adj[M], radj[M]; // implication graph
bool vis[M];
int comp[M];
vector<int> order;
void dfs1(int node){
    vis[node] = 1;
    for (auto x : adj[node]){
        if (!vis[x]){
            dfs1(x);
        }
    }
    order.pb(node);
}
void dfs2(int node, int num){
    comp[node] = num;
    for (auto x : radj[node]){
        if (comp[x] == -1){
            dfs2(x, num);
        }
    }
}
void solve2sat(){
    fill(vis, vis + M, 0);
    for (int i=0;i<n * 4;i++){
        if (!vis[i]){
            dfs1(i);
        }
    }
    fill(comp, comp + M, -1);
    int curNum = 0;
    int len = order.size();
    for (int i=0;i<len;i++){
        int v = order[len - i - 1];
        if (comp[v] == -1){
            dfs2(v, curNum++);
        }
    }
    for (int i=0;i<n * 4;i+=2){
        if (comp[i] == comp[i + 1]) dismiss();
        assign[i / 2] = (comp[i] > comp[i + 1]);
    }
}
vector<pii> ans;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill(assign, assign + M, -1);
    cin >> n;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            char ch;
            cin >> ch;
            mat[i][j] = (int)(ch - '0');
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            char ch;
            cin >> ch;
            mat[i][j] ^= (int)(ch - '0');
        }
    }
    for (int i=0;i<n;i++){
        char ch;
        cin >> ch;
        ar[i] = (int)(ch - '0');
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            int rowi = ar[j];
            int colj = ar[i];

            int a = i * 2;
            int ra = a + 1;
            int b = (n + j) * 2;
            int rb = b + 1;
            if (rowi && colj){
                if (mat[i][j] == 0){ // a ^ b = 0
                    adj[a].pb(b);
                    adj[b].pb(a);
                    adj[ra].pb(rb);
                    adj[rb].pb(ra);
                } else{ // a ^ b = 1
                    adj[a].pb(rb);
                    adj[b].pb(ra);
                    adj[rb].pb(a);
                    adj[ra].pb(b);
                }
            } else if (rowi){ // a only
                if (mat[i][j]) adj[ra].pb(a);
                else adj[a].pb(ra);
            } else if (colj){ // b only
                if (mat[i][j]) adj[rb].pb(b);
                else adj[b].pb(rb);
            } else if (mat[i][j]){
                dismiss();
            }
        }
    }
    for (int i=0;i<4 * n;i++){
        for (auto j : adj[i]){
            radj[j].pb(i);
        }
    }
    solve2sat();
    for (int i=0;i<n;i++){
        if (assign[i]) ans.pb(mp(0, i));
    }
    for (int i=n;i<2 * n;i++){
        if (assign[i]) ans.pb(mp(1, i - n));
    }
    cout << ans.size() << el;
    for (auto x : ans){
        if (x.fi == 0){
            cout << "row " << x.se << el;
        } else{
            cout << "col " << x.se << el;
        }
    }

    return 0;
}