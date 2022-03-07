#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n;
vector<vector<int>> inputs;
vector<vector<int>> adj;
vector<pii> bridges;

vector<bool> visited;
vector<int> tin, low;
int timer;

unordered_map<int, int> conv;
vector<int> rconv;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]){
                pii temp;
                if (v > to) temp = mp(to, v);
                else temp = mp(v, to);
                bridges.pb(temp);
            }
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n + 1, false);
    tin.assign(n + 1, -1);
    low.assign(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

vector<int> inp_from(string& s){
    vector<int> ret;
    int len = s.size();
    string cur = "";
    for (int i=0;i<len;i++){
        if ('0' <= s[i] && s[i] <= '9') cur.pb(s[i]);
        else if (cur.size()){
            ret.pb(stoi(cur));
            cur = "";
        }
    }
    if (cur.size()) ret.pb(stoi(cur));
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    adj.resize(n + 1, vector<int>());
    rconv.resize(n + 1);
    cin.ignore();
    for (int i=1;i<=n;i++){
        string s;
        getline(cin, s);
        // stringstream ss(s);
        // string temp;

        vector<int> inp;
        // while (ss >> temp){
        //     inp.pb(stoi(temp));
        // }
        inp = inp_from(s);
        conv[inp[0]] = i;
        rconv[i] = inp[0];
        inputs.pb(inp);
    }
    for (auto& x : inputs){
        int len = x.size();
        int a = conv[x[0]];
        for (int i=1;i<len;i++){
            adj[a].pb(conv[x[i]]);
        }
    }
    find_bridges();
    for (auto& x : bridges){
        x.fi = rconv[x.fi];
        x.se = rconv[x.se];
    }
    sort(bridges.begin(), bridges.end());
    cout << bridges.size() << el;
    for (auto& x : bridges){
        cout << x.fi << '-' << x.se << el;
    }

    return 0;
}