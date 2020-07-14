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
vector<pii> adj[N], edges; // dest, cap
int tot[N];

unordered_map<int, int> ans[N]; 

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
        edges.pb(mp(a, b));
        tot[a] += c;
        tot[b] += c;
    }
    for (int i=1;i<n;i++) tot[i] /= 2;
    tot[1] = 0;
    queue<int> qu;
    qu.push(1);
    while (!qu.empty()){
        auto node = qu.front();
        qu.pop();
        for (auto x : adj[node]){
            int dest = x.fi;
            int cap = x.se;
            if (tot[dest] == 0) continue;
            
            tot[dest] -= cap;
            ans[node][dest] = 1;
            if (tot[dest] == 0){
                qu.push(dest);
            }
        }
    }
    for (auto x : edges){
        cout << (ans[x.fi][x.se] ^ 1) << el;
    }

    return 0;
}

// #include <bits/stdc++.h>


// #define fi first
// #define se second
// #define pb(a) push_back(a)
// #define mp(a, b) make_pair(a, b)
// #define el '\n'

// using namespace std;
// using ll = long long;
// using pii = pair<int, int>;
// using pil = pair<int, ll>;
// using pli = pair<ll, int>;

// const int N = 2e5 + 10;
// const ll INF = 1e18;

// int n, m;
// vector<pil> adj[N], edges;
// ll out[N], in[N], tot[N];
// set<pli> setdah, setdah2; // tot / in, node

// unordered_map<int, int> cek[N];

// ll getras(int id){
//     ll ret = INF;
//     if (in[id]) ret = (tot[id] + in[id] - 1LL) / in[id];
//     return ret;
// }
// ll getras2(int id){
//     ll ret = INF;
//     if (out[id]) ret = (tot[id] + out[id] - 1LL) / out[id];
//     return ret;
// }

// int main () {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     cin >> n >> m;
//     for (int i=1;i<=m;i++){
//         int a, b;
//         ll c;
//         cin >> a >> b >> c;
//         adj[a].pb(mp(b, c));
//         adj[b].pb(mp(a, c));
//         edges.pb(mp(a, b));
//         if (a > b) swap(a, b);
//         if (a == 1) in[b] += c;
//         if (b == n) out[a] += c;
//         tot[a] += c;
//         tot[b] += c;

//         cek[a][b] = -1;
//         cek[b][a] = -1;
//     }
//     for (int i=2;i<n;i++){
//         setdah.insert(mp(getras(i), i));
//         setdah2.insert(mp(getras2(i), i));
//     }
//     while (!setdah.empty() && !setdah2.empty()){
//         auto temp = *setdah.begin();
//         int ras = temp.fi;
//         int node = temp.se;
//         if (ras == 2){
//             setdah.erase(temp);
//             for (auto x : adj[node]){
//                 if (x.fi == 1 || x.fi == n) continue;
//                 if (cek[node][x.fi] == -1){
//                     cek[node][x.fi] = 0;
//                     cek[x.fi][node] = 1;
//                     setdah.erase(mp(getras(x.fi), x.fi));
//                     setdah2.erase(mp(getras2(node), node));
//                     in[x.fi] += x.se; 
//                     out[node] += x.se;
//                     setdah.insert(mp(getras(x.fi), x.fi));
//                     setdah2.insert(mp(getras2(node), node));
//                 }
//             }
//         } else{
//             auto temp2 = *setdah2.begin();
//             setdah2.erase(temp2);
//             ras = temp2.fi;
//             node = temp2.se;
//             assert(ras == 2);
//             for (auto x : adj[node]){
//                 if (x.fi == 1 || x.fi == n) continue;
//                 if (cek[node][x.fi] == -1){
//                     cek[node][x.fi] = 1;
//                     cek[x.fi][node] = 0;
//                     setdah2.erase(mp(getras2(x.fi), x.fi));
//                     setdah.erase(mp(getras(node), node));
//                     in[node] += x.se; 
//                     out[x.fi] += x.se;
//                     setdah2.insert(mp(getras(x.fi), x.fi));
//                     setdah.insert(mp(getras(node), node));
//                 }
//             }
//         }
//     }
//     for (auto x : edges){
//         if (x.fi == 1 || x.se == n){
//             cout << 0 << el;
//             continue;
//         }
//         if (x.se == 1 || x.fi == n){
//             cout << 1 << el;
//             continue;
//         }
//         cout << cek[x.fi][x.se] << el;
//     }

//     return 0;
// }
