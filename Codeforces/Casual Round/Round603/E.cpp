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
// #define INF 1000000000000000000

using namespace std;

const int N = 1e6 + 10;
const int INF = 1e9;

int n;
string s;
char ch[N];
int cnt = 0;
bool bener=1;
int t[4*N], ar[N], lazy[4*N];
int t2[4*N], lazy2[4*N];
int st, ed, cur;
int tot=0;

void push(int v) {
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return INF;
    if (l <= tl && tr <= r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return min(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void push2(int v) {
    t2[v*2] += lazy2[v];
    lazy2[v*2] += lazy2[v];
    t2[v*2+1] += lazy2[v];
    lazy2[v*2+1] += lazy2[v];
    lazy2[v] = 0;
}

void update2(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t2[v] += addend;
        lazy2[v] += addend;
    } else {
        push2(v);
        int tm = (tl + tr) / 2;
        update2(v*2, tl, tm, l, min(r, tm), addend);
        update2(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t2[v] = max(t2[v*2], t2[v*2+1]);
    }
}

int query2(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return -INF;
    if (l <= tl && tr <= r)
        return t2[v];
    push2(v);
    int tm = (tl + tr) / 2;
    return max(query2(v*2, tl, tm, l, min(r, tm)), 
               query2(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> s;
    // s = '*' + s;
    // cout << s << el;
    st = 1;
    ed = N-2;
    cur = 1;

    for (int i=0;i<n;i++){
        int baru = s[i];
        // cout << i << " => ";
        if (baru == 'R'){
            cur++;
            if (tot==0){
                if (query(1, st, ed, st, ed) >= 0){
                    cout << query2(1, st, ed, st, ed) << " ";
                } else{
                    cout << -1 << " ";
                }
            } else{
                cout << -1 << " ";
            }
            continue;
        } else if (baru == 'L') {
            cur = max(1, cur-1);
            if (tot==0){
                if (query(1, st, ed, st, ed) >= 0){
                    cout << query2(1, st, ed, st, ed) << " ";
                } else{
                    cout << -1 << " ";
                }
            } else{
                cout << -1 << " ";
            }
            continue;
        }

        int tm;
        if (baru == '('){
            tm=1;
        } else if (baru == ')'){
            tm=-1;
        } else{
            tm=0;
        }
        int sel = tm-ar[cur];
        ar[cur] = tm;
        tot+=sel;

        update(1, st, ed, cur, ed, sel);
        update2(1, st, ed, cur, ed, sel);

        if (tot==0){
            if (query(1, st, ed, st, ed) >= 0){
                cout << query2(1, st, ed, st, ed) << " ";
            } else{
                cout << -1 << " ";
            }
        } else{
            cout << -1 << " ";
        }
    }
    cout << el;

    return 0;
}