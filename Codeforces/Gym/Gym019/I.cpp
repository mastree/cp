#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 510;
const int INF = 1e9;

int n;
string names[N];
map<string, int> getid;
vector<int> adj[N];

bool vis[N];
int bfs_len(int st){
    fill(vis, vis + N, 0);
    queue<pii> qu;
    qu.push(mp(st, 0));
    vis[st] = 1;
    while (!qu.empty()){
        auto tp = qu.front();
        qu.pop();
        for (auto x : adj[tp.fi]){
            if (x == st){
                return tp.se + 1;
            }
            if (!vis[x]){
                qu.push(mp(x, tp.se + 1));
                vis[x] = 1;
            }
        }
    }
    return INF;
}
int parent[N];
void print_path(int st){
    fill(vis, vis + N, 0);
    queue<pii> qu;

    qu.push(mp(st, 0));
    vis[st] = 1;
    int last = -1;
    while (!qu.empty()){
        auto tp = qu.front();
        parent[tp.fi] = tp.se;
        qu.pop();
        for (auto x : adj[tp.fi]){
            if (x == st){
                last = tp.fi;
                break;
            }
            if (!vis[x]){
                qu.push(mp(x, tp.fi));
                vis[x] = 1;
            }
        }
        if (last != -1) break;
    }
    vector<string> ans;
    while (last != st){
        ans.pb(names[last]);
        last = parent[last];
    }
    ans.pb(names[last]);
    reverse(ans.begin(), ans.end());
    for (auto x : ans){
        cout << x << " ";
    }
    cout << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> names[i];
        getid[names[i]] = i;
    }
    for (int i=1;i<=n;i++){
        string name;
        int len;
        cin >> name >> len;
        int id = getid[name];

        if (len) cin.ignore();
        for (int j=0;j<len;j++){
            string line;
            getline(cin, line);
            stringstream ss(line);
            string s;
            while (ss >> s){
                if (s == "import") continue;
                if (s.back() == ',') s.pop_back();
                adj[id].pb(getid[s]);
            }
        }
    }
    // for (int i=1;i<=n;i++){
    //     cout << i << " => ";
    //     for (auto x : adj[i]){
    //         cout << x << " ";
    //     }
    //     cout << el;
    // }
    int mn = INF, id = -1;
    for (int i=1;i<=n;i++){
        int temp = bfs_len(i);
        if (temp < mn){
            mn = temp;
            id = i;
        }
    }
    if (id == -1){
        cout << "SHIP IT" << el;
        return 0;
    }
    print_path(id);

    return 0;
}