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

const int N = 1e5 + 10;

int n, q;
string s;

vector<vector<int>> t(4 * N, vector<int>(26, 0));
int lazy[4 * N], stat[4 * N]; // 0 = nothing, 1 = asc, 2 = desc

void build(int v, int tl, int tr){
    if (tl == tr){
        int dig = s[tl] - 'a';
        t[v][dig] = 1;
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    for (int i=0;i<26;i++){
        t[v][i] = t[v * 2][i] + t[v * 2 + 1][i];
    }
}
void push(int v, int range){
    if (lazy[v]){
        stat[v * 2] = lazy[v * 2] = lazy[v];
        stat[v * 2 + 1] = lazy[v * 2 + 1] = lazy[v];
        lazy[v] = 0;
        if (!stat[v]) return;
        vector<int> depan(26, 0);
        int cfront = (range + 1) / 2;

        if (stat[v] == 1){
            for (int i=0;i<26;i++){
                int kur = min(cfront, t[v][i]);
                cfront -= kur;
                t[v * 2][i] = kur;
                t[v * 2 + 1][i] = t[v][i] - kur;
            }
        } else{
            for (int i=26 - 1;i>=0;i--){
                int kur = min(cfront, t[v][i]);
                cfront -= kur;
                t[v * 2][i] = kur;
                t[v * 2 + 1][i] = t[v][i] - kur;
            }
        }
    }
}
vector<int> nt(26);
void update(int v, int tl, int tr, int l, int r, bool asc){
    if (r < tl || tr < l) return;
    else if (l <= tl && tr <= r){
        if (asc) lazy[v] = 1;
        else lazy[v] = 2;
        stat[v] = lazy[v];

        int take = tr - tl + 1;
        if (stat[v] == 1){
            for (int i=0;i<26;i++){
                int kur = min(take, nt[i]);
                take -= kur;
                t[v][i] = kur;
                nt[i] -= kur;
            }
        } else{
            for (int i=25;i>=0;i--){
                int kur = min(take, nt[i]);
                take -= kur;
                t[v][i] = kur;
                nt[i] -= kur;
            }
        }
        return;
    }
    push(v, tr - tl + 1);
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, r, asc);
    update(v * 2 + 1, tm + 1, tr, l, r, asc);
    for (int i=0;i<26;i++){
        t[v][i] = t[v * 2][i] + t[v * 2 + 1][i];
    }
}
vector<int> plus_vec(const vector<int>& a, const vector<int>& b){
    vector<int> ret(26);
    for (int i=0;i<26;i++) ret[i] = a[i] + b[i];
    return ret;
}
vector<int> ask(int v, int tl, int tr, int l, int r){
    if (l > r) return vector<int>(26, 0);
    else if (l <= tl && tr <= r){
        return t[v];
    }
    push(v, tr - tl + 1);
    int tm = (tl + tr) / 2;
    return plus_vec(ask(v * 2, tl, tm, l, min(tm, r)), ask(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
void pushall(int v, int tl, int tr){
    if (tl == tr){ 
        int dig;
        for (int i=0;i<26;i++){
            if (t[v][i]){
                dig = i;
                break;
            }
        }
        char temp = (char)(dig + 'a');
        s[tl] = temp;
        return;
    }
    push(v, tr - tl + 1);
    int tm = (tl + tr) / 2;
    pushall(v * 2, tl, tm);
    pushall(v * 2 + 1, tm + 1, tr);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    cin >> s;
    s = "*" + s;
    build(1, 1, n);
    while (q--){
        int l, r;
        bool asc;
        cin >> l >> r >> asc;
        nt = ask(1, 1, n, l, r);
        update(1, 1, n, l, r, asc);
    }
    pushall(1, 1, n);
    for (int i=1;i<=n;i++) cout << s[i];cout << el;

    return 0;
}