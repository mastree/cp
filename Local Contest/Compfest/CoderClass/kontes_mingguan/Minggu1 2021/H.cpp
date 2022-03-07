#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;

int n, m, k;
vector<int> adj[N], radj[N];
vector<int> pos;
int deg[N];

int grun[N];
bool insta[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill(grun, grun + N, -1);
    cin >> n >> m >> k;
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        radj[b].pb(a);
        deg[a]++;
        if (b == 1){
            insta[a] = 1;
        }
    }
    grun[1] = 0;
    for (int i=0;i<k;i++){
        int a;
        cin >> a;
        pos.pb(a);
        if (insta[a]){
            cout << "Chanek" << el;
            return 0;
        }
    }
    queue<int> q;
    q.push(1);
    while (!q.empty()){
        int node = q.front();
        q.pop();
        if (!insta[node] && node != 1){
            grun[node] = 0;
            vector<int> vec;
            for (auto& x : adj[node]){
                vec.pb(grun[x]);
            }
            sort(vec.begin(), vec.end());
            for (auto& x : vec) if (grun[node] == x) grun[node]++;
        }
        for (auto& x : radj[node]){
            if (--deg[x] == 0){
                q.push(x);
            }
        }
    }
    int ans = 0;
    for (auto& x : pos) ans = (ans ^ grun[x]);
    if (ans == 0){
        cout << "Ganesh" << el;
    } else{
        cout << "Chanek" << el;
    }

    return 0;
}