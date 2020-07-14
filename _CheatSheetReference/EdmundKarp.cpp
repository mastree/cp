vector<int> adl[MAXN];
int cap[MAXN][MAXN];

int bfs(int s, int t, vector<int>& parent){
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pii> qu;
    qu.push(mp(s, INF));
    while (!qu.empty()){
        int cur = qu.front().fi;
        int flow = qu.front().se;
        qu.pop();

        for (auto x : adl[cur]){
            if (parent[x] == -1 && cap[cur][x]){
                parent[x] = cur;
                int nflow = min(flow, cap[cur][x]);
                if (x == t){
                    return nflow;
                }
                qu.push(mp(x, nflow));
            }
        }
    }
    return 0;
}

int maxflow(int s, int t){
    int flow = 0;
    vector<int> parent(n);
    int nflow;

    while (nflow = bfs(s, t, parent)){
        flow += nflow;
        int cur = t;
        while (cur != s){
            int ncur = parent[cur];
            cap[ncur][cur] -= nflow;
            cap[cur][ncur] += nflow;
            cur = ncur;
        }
    }
    return flow;
}