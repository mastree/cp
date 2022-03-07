#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

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
const int MX = 3e5 + 10;

int n;
int ar[N];

int bit[MX];
ll bit2[MX];

void upd(int x, int val){
    while (x < MX){
        bit[x] += val;
        x += (x & (-x));       
    }
}
int ask(int a){
    int ret = 0;
    while (a > 0){
        ret += bit[a];
        a -= (a & (-a));
    }
    return ret;
}
int ask(int a, int b){
    return ask(b) - ask(a - 1);
}

void upd2(int x, ll val){
    while (x < MX){
        bit2[x] += val;
        x += (x & (-x));
    }
}
ll ask2(int a){
    ll ret = 0;
    while (a > 0){
        ret += bit2[a];
        a -= (a & (-a));
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    ll cur = 0;
    vector<ll> ans(n + 1, 0);
    for (int i=1;i<=n;i++){
        ll kur = 0;
        ll fac = 0;
        ans[i] = ans[i - 1] + ask2(ar[i]) + 1LL * (i - 1) * ar[i];
        for (int j=ar[i];j<MX;j+=ar[i]){
            int j2 = j + ar[i] - 1;
            fac++;
            kur += fac * ask(j, min(j2, MX - 1));
            upd2(j, -1LL * ar[i]);
        }
        ans[i] += cur - kur * ar[i];
        upd(ar[i], 1);
        cur += ar[i];
    }
    for (int i=1;i<=n;i++){
        cout << ans[i] << ' ';
    }
    cout << el;

    return 0;
}