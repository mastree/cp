#include <bits/stdc++.h>

#define fi first
#define se second
#define mp(a, b) make_pair(a, b)

using namespace std;
using pii = pair<int, int>;
using ll = long long;

const int N = 1e5 + 10;

int n, m;
vector<int> adj[N];
int indeg[N];

int main() {
    cin >> n >> m;
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
        indeg[a]++;
    }
    priority_queue<int> pq;
    for (int i=1;i<=n;i++){
        if (indeg[i] == 0){
            pq.push(i);
        }
    }
    vector<int> order, ans(n + 1);
    while (!pq.empty()){
        int node = pq.top();
        pq.pop();
        order.push_back(node);
        for (auto& x : adj[node]){
            if (--indeg[x] == 0){
                pq.push(x);
            }
        }
    }
    reverse(order.begin(), order.end());
    for (int i=0;i<n;i++) ans[order[i]] = i + 1;
    for (int i=1;i<=n;i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}
