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

const int N = 5e5 + 10;
const int M = 19;

int n, q;
vector<int> adl[N];
int par[N];
int ar[N];
string s;

int dep[N], lowest_dep[N];
vector<vector<int>> node_on_dep(N);
vector<vector<vector<bool>>> pc_on_dep(N);
int index_on_dep[N];

int le[N][M], ri[N][M];

vector<bool> kurang(vector<bool> a, vector<bool> b){
    vector<bool> ret(26, 0);
    for (int i=0;i<26;i++){
        ret[i] = a[i] ^ b[i];
    }
    return ret;
} 
bool is_palindrom(vector<bool> a){
    int cnt = 0;
    for (int i=0;i<26;i++){
        if (a[i]) cnt++;
    }
    return (cnt <= 1);
}

void dfs_init(int node){
    dep[node] = dep[par[node]] + 1;
    int dd = dep[node];
    lowest_dep[node] = dd;
    if (node_on_dep[dd].empty()){
        node_on_dep[dd].pb(-1);
        // vector<int> temp(26, 0);
        // pc_on_dep[dd].pb(temp);
    }
    int last = node_on_dep[dd].size();
    index_on_dep[node] = last;
    vector<bool> temp(26, 0);
    if (last >= 2) temp = pc_on_dep[dd][last - 2];
    temp[ar[node]] = !temp[ar[node]];
    
    // push
    node_on_dep[dd].pb(node);
    pc_on_dep[dd].pb(temp);
    int ncnt = adl[node].size();
    if (ncnt){
        le[node][0] = adl[node][0];
        ri[node][0] = adl[node][ncnt - 1];
    }
    for (auto x : adl[node]){
        dfs_init(x);
        lowest_dep[node] = max(lowest_dep[node], lowest_dep[x]);
    }
}

void init_leri(){
    for (int i=1;i<=lowest_dep[1];i++){
        int len = (int)node_on_dep[i].size() - 1;
        for (int j=2;j<=len;j++){
            int node = node_on_dep[i][j];
            int bef = node_on_dep[i][j - 1];
            if (ri[node][0] == 0) ri[node][0] = ri[bef][0];
        }
        for (int j=len - 1;j>=1;j--){
            int node = node_on_dep[i][j];
            int bef = node_on_dep[i][j + 1];
            if (le[node][0] == 0) le[node][0] = le[bef][0];
        }
    }
    for (int j=1;j<M;j++){
        for (int i=1;i<=n;i++){
            le[i][j] = le[le[i][j - 1]][j - 1];
            ri[i][j] = ri[ri[i][j - 1]][j - 1];
        }
    }
}

void sol(int a, int b){
    int turun = b - dep[a];
    if (turun <= 0 || b > lowest_dep[a]){
        cout << "Yes" << el;
        return;
    }
    int lt = a;
    int rt = a;
    int cur;
    cur = 0;
    for (int i=M - 1;i>=0;i--){
        if (cur + (1 << i) <= turun){
            cur += (1 << i);
            lt = le[lt][i];
            rt = ri[rt][i];
        }
    }
    int dd = b;
    int le_id = index_on_dep[lt];
    int ri_id = index_on_dep[rt];
    // cout << le_id << " " << ri_id << " " << pc_on_dep[dd].size() << el;
    vector<bool> temp1 = pc_on_dep[dd][ri_id - 1];
    vector<bool> temp2(26, 0);
    if (le_id > 1){
        temp2 = pc_on_dep[dd][le_id - 2];
    }
    if (is_palindrom(kurang(temp1, temp2))){
        cout << "Yes" << el;
    } else{
        cout << "No" << el;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    par[1] = 1;
    for (int i=2;i<=n;i++){
        cin >> par[i];
        adl[par[i]].pb(i);
    }
    cin >> s;
    for (int i=1;i<=n;i++){
        sort(adl[i].begin(), adl[i].end());
        ar[i] = s[i - 1] - 'a';
    }
    dfs_init(1);
    init_leri();
    while (q--){
        int a, b;
        cin >> a >> b;
        sol(a, b);
    }

    return 0;
}