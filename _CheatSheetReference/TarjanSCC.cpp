// SCC for undirected graph

const int N = 2e5 + 10;

int n, m;
vector<int> adl[N];
int comp[N];
int compNum;
int low[N], tin[N], timer;
bool onStack[N];
stack<int> st;

void dfs_scc(int node){
    low[node] = tin[node] = ++timer;
    st.push(node);
    onStack[node] = 1;
    for (auto x : adl[node]){
        // if (x == p) continue;  // add parent as parameter and add this line for directed graph
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