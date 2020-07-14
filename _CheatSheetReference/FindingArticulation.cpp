const int N = 2e5 + 10;

int n, m;
vactor<int> adl[N];
int low[N], tin[N], timer;
set<int> artic;

void dfs_artic(int node, int p){
    low[node] = tin[node] = ++timer;
    int child = 0;
    for (auto x : adl[node]){
        if (x == p) continue;
        if (tin[x]){
            low[node] = min(low[node], tin[x]);
        } else{
            dfs_artic(x, node);
            low[node] = min(low[node], low[x]);
            if (low[x] >= tin[node] && p != node){
                artic.insert(node);
            }
            child++;
        }
    }
    if (p == node && child > 1){ 
        artic.insert(node);
    }
}

void find_artic(){
    timer = 0;
    fill(low, low + N, 0);
    fill(tin, tin + N, 0);
    for (int i=1;i<=n;i++){
        if (tin[i] == 0){
            dfs_artic(i, i);
        }
    }
}
