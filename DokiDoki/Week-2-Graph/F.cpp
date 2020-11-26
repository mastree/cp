#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 27;

vector<int> adj[N];
int in[N];
bool ada[N];

void add_edge(const string& a, const string& b){
    int mn = (int)min(a.size(), b.size());
    int pos = -1;
    for (int i=0;i<mn;i++){
        if (a[i] != b[i]){
            pos = i;
            break;
        }
    }
    if (pos != -1){
        int ia = a[pos] - 'A' + 1;
        int ib = b[pos] - 'A' + 1;
        adj[ia].pb(ib);
        in[ib]++;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    {
        string bef;
        string cur;
        while (cin >> cur){
            if (cur == "#") break;
            add_edge(bef, cur);
            for (auto x : cur){
                ada[x - 'A' + 1] = 1;
            }
            bef.swap(cur);
        }
    }
    queue<int> qu;
    int cntall = 0;
    for (int i=1;i<N;i++){
        if (in[i] == 0 && ada[i]) qu.push(i);
        if (ada[i]) cntall++;
    }
    string ans;
    while (!qu.empty()){
        int node = qu.front();
        ans.pb(node + 'A' - 1);
        qu.pop();
        for (auto x : adj[node]){
            if (--in[x] == 0){
                qu.push(x);
            }
        }
    }
    if (ans.size() == cntall) cout << ans << el;

    return 0;
}