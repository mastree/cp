#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

// struct FlowEdge {
//     int v, u;
//     int cap, flow = 0;
//     FlowEdge(int v, int u, int cap) : v(v), u(u), cap(cap) {}
// };

// struct Dinic {
//     const int flow_inf = 1e9 + 1;
//     vector<FlowEdge> edges;
//     vector<vector<int>> adj;
//     int n, m = 0;
//     int s, t;
//     vector<int> level, ptr;
//     queue<int> q;

//     Dinic(int n, int s, int t) : n(n), s(s), t(t) {
//         adj.resize(n);
//         level.resize(n);
//         ptr.resize(n);
//     }

//     void add_edge(int v, int u, int cap) {
//         edges.emplace_back(v, u, cap);
//         edges.emplace_back(u, v, 0);
//         adj[v].push_back(m);
//         adj[u].push_back(m + 1);
//         m += 2;
//     }

//     bool bfs() {
//         while (!q.empty()) {
//             int v = q.front();
//             q.pop();
//             for (int id : adj[v]) {
//                 if (edges[id].cap - edges[id].flow < 1)
//                     continue;
//                 if (level[edges[id].u] != -1)
//                     continue;
//                 level[edges[id].u] = level[v] + 1;
//                 q.push(edges[id].u);
//             }
//         }
//         return level[t] != -1;
//     }

//     int dfs(int v, int pushed) {
//         if (pushed == 0)
//             return 0;
//         if (v == t)
//             return pushed;
//         for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
//             int id = adj[v][cid];
//             int u = edges[id].u;
//             if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
//                 continue;
//             int tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
//             if (tr == 0)
//                 continue;
//             edges[id].flow += tr;
//             edges[id ^ 1].flow -= tr;
//             return tr;
//         }
//         return 0;
//     }

//     long long flow() {
//         long long f = 0;
//         while (true) {
//             fill(level.begin(), level.end(), -1);
//             level[s] = 0;
//             q.push(s);
//             if (!bfs())
//                 break;
//             fill(ptr.begin(), ptr.end(), 0);
//             while (long long pushed = dfs(s, flow_inf)) {
//                 f += pushed;
//             }
//         }
//         return f;
//     }
// };
struct MPM{
    struct FlowEdge{
        int v, u;
        int cap, flow;
        FlowEdge(){}
        FlowEdge(int _v, int _u, int _cap, int _flow)
            : v(_v), u(_u), cap(_cap), flow(_flow){}
        FlowEdge(int _v, int _u, int _cap)
            : v(_v), u(_u), cap(_cap), flow(0ll){}
    };
    const int flow_inf = 1e9 + 1;
    vector<FlowEdge> edges;
    vector<char> alive;
    vector<int> pin, pout;
    vector<list<int> > in, out;
    vector<vector<int> > adj;
    vector<int> ex;
    int n, m = 0;
    int s, t;
    vector<int> level;
    vector<int> q;
    int qh, qt;
    void resize(int _n){
        n = _n;
        ex.resize(n);
        q.resize(n);
        pin.resize(n);
        pout.resize(n);
        adj.resize(n);
        level.resize(n);
        in.resize(n);
        out.resize(n);
    }
    MPM(){}
    MPM(int _n, int _s, int _t){resize(_n); s = _s; t = _t;}
    void add_edge(int v, int u, int cap){
        edges.push_back(FlowEdge(v, u, cap));
        edges.push_back(FlowEdge(u, v, 0));
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }
    bool bfs(){
        while(qh < qt){
            int v = q[qh++];
            for(int id : adj[v]){
                if(edges[id].cap - edges[id].flow < 1)continue;
                if(level[edges[id].u] != -1)continue;
                level[edges[id].u] = level[v] + 1;
                q[qt++] = edges[id].u;
            }
        }
        return level[t] != -1;
    }
    int pot(int v){
        return min(pin[v], pout[v]);
    }
    void remove_node(int v){
        for(int i : in[v]){
            int u = edges[i].v;
            auto it = find(out[u].begin(), out[u].end(), i);
            out[u].erase(it);
            pout[u] -= edges[i].cap - edges[i].flow;
        }
        for(int i : out[v]){
            int u = edges[i].u;
            auto it = find(in[u].begin(), in[u].end(), i);
            in[u].erase(it);
            pin[u] -= edges[i].cap - edges[i].flow;
        }
    }
    void push(int from, int to, int f, bool forw){
        qh = qt = 0;
        ex.assign(n, 0);
        ex[from] = f;
        q[qt++] = from;
        while(qh < qt){
            int v = q[qh++];
            if(v == to)
                break;
            int must = ex[v];
            auto it = forw ? out[v].begin() : in[v].begin();
            while(true){
                int u = forw ? edges[*it].u : edges[*it].v;
                int pushed = min(must, edges[*it].cap - edges[*it].flow);
                if(pushed == 0)break;
                if(forw){
                    pout[v] -= pushed;
                    pin[u] -= pushed;
                }
                else{
                    pin[v] -= pushed;
                    pout[u] -= pushed;
                }
                if(ex[u] == 0)
                    q[qt++] = u;
                ex[u] += pushed;
                edges[*it].flow += pushed;
                edges[(*it)^1].flow -= pushed;
                must -= pushed;
                if(edges[*it].cap - edges[*it].flow == 0){
                    auto jt = it;
                    ++jt;
                    if(forw){
                        in[u].erase(find(in[u].begin(), in[u].end(), *it));
                        out[v].erase(it);
                    }
                    else{
                        out[u].erase(find(out[u].begin(), out[u].end(), *it));
                        in[v].erase(it);
                    }
                    it = jt;
                }
                else break;
                if(!must)break;
            }
        }
    }
    long long flow(){
        long long ans = 0;
        while(true){
            pin.assign(n, 0);
            pout.assign(n, 0);
            level.assign(n, -1);
            alive.assign(n, true);
            level[s] = 0;
            qh = 0; qt = 1;
            q[0] = s;
            if(!bfs())
                break;
            for(int i = 0; i < n; i++){
                out[i].clear();
                in[i].clear();
            }
            for(int i = 0; i < m; i++){
                if(edges[i].cap - edges[i].flow == 0)
                    continue;
                int v = edges[i].v, u = edges[i].u;
                if(level[v] + 1 == level[u] && (level[u] < level[t] || u == t)){
                    in[u].push_back(i);
                    out[v].push_back(i);
                    pin[u] += edges[i].cap - edges[i].flow;
                    pout[v] += edges[i].cap - edges[i].flow;
                }
            }
            pin[s] = pout[t] = flow_inf;
            while(true){
                int v = -1;
                for(int i = 0; i < n; i++){
                    if(!alive[i])continue;
                    if(v == -1 || pot(i) < pot(v))
                        v = i;
                }
                if(v == -1)
                    break;
                if(pot(v) == 0){
                    alive[v] = false;
                    remove_node(v);
                    continue;
                }
                long long f = pot(v);
                ans += f;
                push(v, s, f, false);
                push(v, t, f, true);
                alive[v] = false;
                remove_node(v);
            }
        }
        return ans;
    }
};

const int N = 1e6 + 10;
const ll INF = 1e9 + 1;

int q;
int n;
ll ar[N], br[N];

void solve(){
    int nlen = n + n + 2;
    MPM dinic(nlen + 1, 1, nlen);
    for (int i=1;i<=n;i++){
        dinic.add_edge(1, i + 1, ar[i]);
        dinic.add_edge(i + 1, n + 1 + i, INF);
        if (i != n) dinic.add_edge(i + 1, n + 1 + i + 1, INF);
        else dinic.add_edge(i + 1, n + 2, INF);
    }
    ll tot = 0;
    for (int i=1;i<=n;i++){
        dinic.add_edge(n + 1 + i, nlen, br[i]);
        tot += br[i];
    }
    ll temp = dinic.flow();
    if (temp == tot){
        cout << "YES" << el;
    } else{
        cout << "NO" << el;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        for (int i=1;i<=n;i++){
            cin >> br[i];
        }
        for (int i=1;i<=n;i++){
            cin >> ar[i];
        }
        solve();
    }

    return 0;
}