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

const int N = 2e5 + 10;
const ll INF = 1e18;

int n, m;
ll ar[N];
ll lazy[4 * N], t[4 * N];

void push(int v){
    lazy[v * 2] += lazy[v];
    lazy[v * 2 + 1] += lazy[v];
    t[v * 2] += lazy[v];
    t[v * 2 + 1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, ll add){
    if (l > r){
        return;
    } else if (tl == l && r == tr){
        t[v] += add;
        lazy[v] += add;
        return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, min(tm, r), add);
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
}

ll query(int v, int tl, int tr, int l, int r){
    if (l > r){
        return INF;
    } else if (l <= tl && tr <= r){
        return t[v];
    }
    push(v);
    int tm = (tl + tr) / 2;
    return min(query(v * 2, tl, tm, l, min(tm, r)), query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

ll ask(int l, int r){
    if (l <= r){
        return query(1, 1, n, l, r);
    }
    return min(query(1, 1, n, l, n), query(1, 1, n, 1, r));
}

void upd(int l, int r, ll add){
    if (l <= r){
        update(1, 1, n, l, r, add);
        return;
    }
    update(1, 1, n, l, n, add);
    update(1, 1, n, 1, r, add);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        update(1, 1, n, i, i, ar[i]);
    }

    cin >> m;
    cin.ignore();
    while (m--){
        string s;
        getline(cin, s);
        vector <int> v;

        stringstream ss(s);
        int temp;
        while (ss >> temp){
            v.pb(temp);
        }
        int l, r;
        l = ++v[0];
        r = ++v[1];
        if (v.size() == 2){
            cout << ask(l, r) << el;
        } else{
            ll add = v[2];
            upd(l, r, add);
        }
    }

    return 0;
}