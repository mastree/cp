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

const int N = 30 * 30;

int n, m;
string hor, ver;
vector<int> adl[N];
int comp[N];
int compNum;
int low[N], tin[N], timer;
bool onStack[N];
stack<int> st;

int getid(int i, int j){
    return (i - 1) * m + j; 
}

void dfs_scc(int node, int p){
    low[node] = tin[node] = ++timer;
    st.push(node);
    onStack[node] = 1;
    for (auto x : adl[node]){
        if (tin[x] == 0){
            dfs_scc(x, node);
            low[node] = min(low[node], low[x]);
        } else if (onStack[x]){
            low[node] = min(low[node], tin[x]);
        }
    }
    if (low[node] == tin[node]){
        compNum++;
        while (1){
            auto temp = st.top();
            st.pop();
            onStack[temp] = 0;
            comp[temp] = compNum;
            if (temp == node || st.empty()) break;
        }
    }
}

void tarjan(){
    timer = compNum = 0;
    for (int i=1;i<=n;i++){
        tin[i] = low[i] = 0;
    }
    while (!st.empty()) st.pop();
    for (int i=1;i<=n;i++){
        if (tin[i] == 0) dfs_scc(i, i);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cin >> hor >> ver;
    hor = "*" + hor;
    ver = "*" + ver;
    for (int i=1;i<=n;i++){
        int dj;
        if (hor[i] == '<') dj = -1;
        else dj = 1; 
        for (int j=1;j<=m;j++){
            int nj = j + dj;
            if (nj < 1 || nj > m) continue;
            adl[getid(i, j)].pb(getid(i, nj));
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            int di;
            if (ver[j] == 'v') di = 1;
            else di = -1;

            int ni = i + di;
            if (ni < 1 || ni > n) continue;
            adl[getid(i, j)].pb(getid(ni, j));
        }
    }
    n = n * m;
    tarjan();
    if (compNum > 1){
        cout << "NO" << el;
        return 0;
    }
    cout << "YES" << el;

    return 0;
} 