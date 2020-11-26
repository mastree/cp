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
int ar[N];
int t[4 * N][6];
bool udh[4 * N][3], part[4 * N][3];

void merge(int v){
    int vl = v * 2;
    int vr = v * 2 + 1;
    for (int i=0;i<6;i++){
        t[v][i] = t[vl][i] + t[vr][i];
    }
    for (int i=0;i<3;i++){
        if (udh[vl][i] && udh[vr][i]){
            udh[v][i] = 1;
        }
    }
}

void build(int v, int tl, int tr){
    if (tl == tr){
        t[v][ar[tl] + 3] = 1;
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    merge(v);
}

void update(int v, int tl, int tr, int l, int r, int id){
    if (l > r || tr < l || r < tl || udh[v][id]) return;
    else if (l <= tl && tr <= r && !part[v][id]){
        udh[v][id] = 1;
        int nid = id - 1;
        if (nid < 0) nid += 3;
        t[v][nid] += t[v][id + 3];
        t[v][id + 3] = 0;
        return;
    }
    int tm = (tl + tr) / 2;
    part[v][id] = 1;
    update(v * 2, tl, tm, l, r, id);
    update(v * 2 + 1, tm + 1, tr, l, r, id);
    merge(v);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    {
        string s;
        cin >> s;
        for (int i=1;i<=n;i++){
            if (s[i - 1] == 'R'){
                ar[i] = 0;
            } else if (s[i - 1] == 'G'){
                ar[i] = 1;
            } else{
                ar[i] = 2;
            }
        }
    }    
    build(1, 1, n);
    for (int i=1;i<=m;i++){
        int l, r;
        cin >> l >> r;
        for (int j=0;j<3;j++) update(1, 1, n, l, r, j);
        int tot[3] = {0, 0, 0};
        for (int j=0;j<6;j++){
            tot[j % 3] += t[1][j];
        }
        for (int j=0;j<3;j++){
            cout << tot[j] << " ";
        }
        cout << el;
    }

    return 0;
}