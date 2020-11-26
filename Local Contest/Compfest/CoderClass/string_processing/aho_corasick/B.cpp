#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int C = 26;
const int N = 210;
const int S = 110;
const int INF = 1e9;

struct Vertex{
    int p;
    int link;
    char pch;
    int go[C];

    int val = 0;

    Vertex(int p = -1, char ch = '$') : p(p), pch(ch), link(-1) {
        fill(begin(go), end(go), -1);
    }
};
vector<Vertex> t(1);

int add_string(const string& s, int val){
    int v = 0;
    for (auto ch : s){
        int c = ch - 'a';
        if (t[v].go[c] <= v){
            t[v].go[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].go[c];
    }
    t[v].val = val;

    return v;
}

int go(int v, char ch);
int get_link(int v){
    if (t[v].link == -1){
        if (v == 0 || t[v].p == 0) t[v].link = 0;
        else t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}
int go(int v, char ch){
    int c = ch - 'a';
    if (t[v].go[c] == -1){
        t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
}

int n, m, power;
int ar[C + 10];
vector<int> adj[N * S];
int len;
int value[N * S];
int dp[N][N * S]; // sisa power, node -> total value

void dfs(int node){
    for (auto x : adj[node]){
        value[x] += value[node];
        dfs(x);
    }
}

void init(){
    len = t.size();
    len--;
    for (int i=1;i<=len;i++){
        int lnk = get_link(i);
        adj[lnk].pb(i);
    }
    dfs(0);
}
pii par[N][N * S];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> power;
    for (int i=1;i<=n;i++){
        string s;
        int val;
        cin >> s >> val;
        int v = add_string(s, val);
        value[v] = val;
    }
    init();
    for (int i=1;i<=m;i++){
        char c;
        int a, b;
        cin >> c >> b;
        a = c - 'a';
        ar[a] = b;
    }

    for (int i=0;i<N;i++){
        for (int j=0;j<N * S;j++){
            dp[i][j] = -INF;
        }
    }
    dp[0][0] = 0;
    for (int i=0;i<=power;i++){
        for (int j=0;j<=len;j++){
            if (dp[i][j] == -INF) continue;
            for (int k=0;k<C;k++){
                if (ar[k] == 0) continue;
                int ni = i + ar[k];
                if (ni > power) continue;
                int nj = go(j, char(k + 'a'));
                int nval = dp[i][j] + value[nj];
                if (dp[ni][nj] < nval){
                    dp[ni][nj] = nval;
                    par[ni][nj] = mp(i, j);
                }
            }
        }
    }
    int ans = 0;
    pii last;
    for (int i=0;i<=power;i++){
        for (int j=0;j<=len;j++){
            if (ans < dp[i][j]){
                ans = dp[i][j];
                last = mp(i, j);
            }
        }
    }
    if (ans == 0){
        cout << ans << el;
        return 0;
    }
    string sans;
    while (last != mp(0, 0)){
        sans.pb(t[last.se].pch);
        last = par[last.fi][last.se];
    }
    reverse(sans.begin(), sans.end());
    cout << ans << el;
    cout << sans << el;

    return 0;
}