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

const int N = 1e4 + 10;

int n, k;
pii ar[N];
unordered_map<string, int> pconv, sconv;
int plen, slen;

vector<int> adj[N];
int out[N], in[N];

int assign[N];
bool vis[N];

bool taken[N];
vector<int> group[N];

bool match(int v){
    if (vis[v]) return false;
    vis[v] = 1;
    for (auto& u : adj[v]){
        if (assign[u] == 0 || match(assign[u])){
            assign[v] = u;
            assign[u] = v;
            return true;
        }
    }
    return false;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        string a = s.substr(0, k);
        string b = s.substr((int)s.size() - k, k);
        if (pconv[a] == 0){
            pconv[a] = ++plen;
            ar[i].fi = plen;
        } else ar[i].fi = pconv[a];
        if (sconv[b] == 0){
            sconv[b] = ++slen;
            ar[i].se = slen;
        } else ar[i].se = sconv[b];
    }
    for (int i=1;i<=n;i++){
        ar[i].se += plen;
        adj[ar[i].fi].pb(ar[i].se);
        out[ar[i].fi]++;
        in[ar[i].se]++;
    }
    int len = 0;
    for (int i=1;i<=plen;i++){
        fill(vis + 1, vis + plen + slen + 1, 0);
        if (match(i)) len++;
    }
    for (int i=1;i<=plen;i++){
        for (auto& x : adj[i]){
            if (assign[i]) in[x]--;
            if (assign[x]) out[i]--;
        }
    }
    for (int i=1;i<=plen;i++){
        if (assign[i]){
            if (out[i]) taken[i] = 1;
            else taken[assign[i]] = 1;
        }
    }
    for (int i=1;i<=n;i++){
        if (taken[ar[i].fi]){
            group[ar[i].fi].pb(i);
        } else{
            group[ar[i].se].pb(i);
        }
    }
    cout << len << el;
    for (int i=1;i<=plen + slen;i++){
        if (group[i].size()){
            cout << group[i].size() << ' ';
            for (auto& x : group[i]){
                cout << x << ' ';
            }
            cout << el;
        }
    }

    return 0;
}