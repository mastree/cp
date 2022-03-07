// SCC for directed graph
const int N = 2e5 + 10;

int n, m;
vector<int> adj[N];
int comp[N];
int compNum;
int low[N], tin[N], timer;
bool onStack[N];
stack<int> st;

void dfs_scc(int node){
    low[node] = tin[node] = ++timer;
    st.push(node);
    onStack[node] = 1;
    for (auto x : adj[node]){
        // if (x == p) continue;  // add parent as parameter and add this line for undirected graph
        if (tin[x] == 0){
            dfs_scc(x);
            low[node] = min(low[node], low[x]);
        } else if (onStack[x]){
            low[node] = min(low[node], tin[x]);
        }
    }
    if (low[node] == tin[node]){
        ++compNum;
        while (1){
            auto temp = st.top();
            st.pop();
            comp[temp] = compNum;
            onStack[temp] = 0;
            if (temp == node || st.empty()) break;
        }
    }
}

void tarjan(){
    compNum = timer = 0;
    fill(low, low + N, 0);
    fill(tin, tin + N, 0);
    fill(onStack, onStack + N, 0);
    while (!st.empty()) st.pop();

    for (int i=1;i<=n;i++){
        if (tin[i] == 0) dfs_scc(i);
    }
}

// SCC for undirected graph
const int N = 2e5 + 10;

int n;
vector<int> adj[N];
int tin[N], low[N], comp[N];
int timer, compNum;
vector<int> st;

void dfs_scc(int node, int p){
    st.pb(node);
    tin[node] = low[node] = ++timer;
    for (auto x : adj[node]){
        if (x == p) continue;
        if (tin[x]){
            low[node] = min(low[node], tin[x]); 
        } else {
            dfs_scc(x, node);
            low[node] = min(low[node], low[x]);
        }
    }
    if (low[node] == tin[node]){
        compNum++;
        while (st.back() != node){
            comp[st.back()] = compNum;
            st.pop_back();
        }
        comp[st.back()] = compNum;
        st.pop_back();
    }
}
void tarjan(){
    for (int i=1;i<=n;i++){
        tin[i] = low[i] = comp[i] = 0;
    }
    timer = compNum = 0;
    st.clear();
    for (int i=1;i<=n;i++){
        if (tin[i] == 0){
            dfs_scc(i, i);
        }
    }
}