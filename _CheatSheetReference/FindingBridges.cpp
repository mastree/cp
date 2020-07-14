const int N = 2e5 + 10;

int n, m;
int low[N], tin[N], timer;
vector<int> adl[N];
vector<pii> bridges;

void dfs_bridge(int node, int p){
    low[node] = tin[node] = ++timer;
    for (auto x : adl[node]){
        if (x == p) continue;
        if (tin[x]){
            low[node] = min(low[node], tin[x]);
        } else{
            dfs_bridge(x, node);
            low[node] = min(low[node], low[x]);
            if (low[x] > tin[node]){
                bridges.pb({ node, x });
            }
        }
    }
}

void find_bridge(){
    timer = 0;
    fill(low, low + N, 0);
    fill(tin, tin + N, 0);
    for (int i=1;i<=n;i++){
        if (tin[i] == 0){
            dfs_bridge(i, i);
        }
    }
}