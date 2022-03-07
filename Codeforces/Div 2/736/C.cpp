#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;

int n, m;
set<int> adj[N];

set<int> vuln;

void solve(){
    int op;
    cin >> op;
    if (op == 1){
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
        if (a < b) vuln.insert(a);
        else vuln.insert(b);
    } else if (op == 2){
        int a, b;
        cin >> a >> b;
        adj[a].erase(b);
        adj[b].erase(a);
        if ((*adj[a].rbegin()) <= a) vuln.erase(a);
        if ((*adj[b].rbegin()) <= b) vuln.erase(b);
    } else{
        cout << n - vuln.size() << el;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        adj[i].insert(-1);
    }
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }    
    for (int i=1;i<=n;i++){
        if ((*adj[i].rbegin()) > i) vuln.insert(i);
    }
    int q;
    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}