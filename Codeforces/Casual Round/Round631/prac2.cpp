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


typedef pair<ll, ll> pll;
const int N = 1e5 + 10;
const ll INF = 1e18;

int n, m;
ll ar[N];
ll dist[N], pc[N];
int l, r;
ll le[N], ri[N];
pll t1[4 * N], t2[4 * N];

void build(int v, int tl, int tr){
    if (tl == tr){
        t1[v] = mp(le[tl], tl);
        return;
    } 
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    if (t1[v * 2].fi >= t1[v * 2 + 1].fi){
        t1[v] = t1[v * 2];
    } else{
        t1[v] = t1[v * 2 + 1];
    }
}
void build2(int v, int tl, int tr){
    if (tl == tr){
        t2[v] = mp(ri[tl], tl);
        return;
    } 
    int tm = (tl + tr) / 2;
    build2(v * 2, tl, tm);
    build2(v * 2 + 1, tm + 1, tr);
    if (t2[v * 2].fi >= t2[v * 2 + 1].fi){
        t2[v] = t2[v * 2];
    } else{
        t2[v] = t2[v * 2 + 1];
    }
}

pll ask(int v, int tl, int tr, int l, int r){
    if (l > r)
        return mp(-INF, 0);
    if (l == tl && r == tr){
        return t1[v];
    }
    int tm = (tl + tr) / 2;
    pll temp1 = ask(v * 2, tl, tm, l, min(r, tm));
    pll temp2 = ask(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    if (temp1.fi >= temp2.fi){
        return temp1;
    } else{
        return temp2;
    }
}
pll ask2(int v, int tl, int tr, int l, int r){
    if (l > r)
        return mp(-INF, 0);
    if (l == tl && r == tr){
        return t2[v];
    }
    int tm = (tl + tr) / 2;
    pll temp1 = ask2(v * 2, tl, tm, l, min(r, tm));
    pll temp2 = ask2(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    if (temp2.fi >= temp1.fi){
        return temp2;
    } else{
        return temp1;
    }
}
ll jarak(int l, int r){
    if (l == r) return 0;
    if (l < r){
        return pc[r - 1] - pc[l - 1];
    } else{
        return pc[n] - pc[l - 1] + pc[r - 1];
    }
}

pll query(int l, int r){
    if (l <= r){
        pll ret = ask(1, 1, n, l, r);
        ret.fi += jarak(1, l);
        return ret;
    } else{
        pll temp1, temp2;
        temp1 = ask(1, 1, n, l, n);
        temp2 = ask(1, 1, n, 1, r);

        temp1.fi += jarak(1, l);
        temp2.fi -= jarak(l, 1);

        if (temp1.fi >= temp2.fi){
            return temp1;
        } else{
            return temp2;
        }
    }
}

pll query2(int l, int r){
    if (l <= r){
        pll ret = ask2(1, 1, n, l, r);
        ret.fi += jarak(r, n);
        return ret;
    } else{
        pll temp1, temp2;
        temp2 = ask2(1, 1, n, 1, r);
        temp1 = ask2(1, 1, n, l, n);

        temp2.fi += jarak(r, n);//pc[n - 1] - pc[r - 1];
        temp1.fi -= jarak(n, r);//pc[r - 1] + dist[n];

        if (temp2.fi >= temp1.fi){
            return temp2;
        } else{
            return temp1;
        }
    }
}


void sol(){
    pll left, right;
    ll ans = 0;

    left = query(l, r);
    right = query2(l, r);
    if (left.se != right.se){   
        ans = left.fi + right.fi;
        ans += jarak(l, r);
    } else{
        pll temp1, temp2;
        ll sem = left.se - 1;
        if (sem == 0) sem = n;
        temp1 = query(l, sem);
        sem = left.se + 1;
        if (sem > n) sem = 1;
        temp2 = query2(sem, r);
        if (left.se == l){
            ans = left.fi + jarak(l, r) + temp2.fi;
        } else if (left.se == r){
            ans = right.fi + jarak(l, r) + temp1.fi;
        } else{
            ans = max(max(left.fi + temp2.fi + jarak(l, r), temp1.fi + right.fi + jarak(l, r)), temp1.fi + temp2.fi + jarak(l, r));
        }
    }

    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> dist[i];
    }
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        ar[i] *= 2;
    }

    ll delta = 0;
    for (int i=1;i<=n;i++){
        le[i] = ar[i] - delta;
        delta += dist[i];
    }
    delta = 0;
    for (int i=n;i>=1;i--){
        ri[i] = ar[i] - delta;
        delta += dist[i - 1];
    }
    pc[0] = 0;
    for (int i=1;i<=n;i++){
        pc[i] = pc[i - 1] + dist[i];
    }

    build(1, 1, n);
    build2(1, 1, n);

    while (m--){
        int a, b;
        cin >> a >> b;
        l = b % n + 1;
        r = a - 1;
        if (r == 0) r = n;

        sol();
    }

    return 0;
}