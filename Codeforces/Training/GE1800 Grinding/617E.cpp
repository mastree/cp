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
const int K = 1e6 + 10;

int n, m, k;
int ar[N];
int pc[N];

pair<pii, int> quer[N];
int sqr = ceil(sqrt(N));

ll ans[N];
ll cnt[2 * K];
ll cur;

bool comp(pair<pii, int> ca, pair<pii, int> cb){
    pii a = mp((ca.fi.fi - 1) / sqr, ca.fi.se);
    pii b = mp((cb.fi.fi - 1) / sqr, cb.fi.se);
    return a < b;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<=n;i++){
        pc[i] = pc[i - 1] ^ ar[i];
    }
    for (int i=1;i<=m;i++){
        cin >> quer[i].fi.fi >> quer[i].fi.se;
        quer[i].se = i;
    }
    sort(quer + 1, quer + m + 1, comp);
    cnt[0] = 1;
    int l = 0, r = 0;
    for (int i=1;i<=m;i++){
        int ql = quer[i].fi.fi - 1;
        int qr = quer[i].fi.se;
        while (r < qr){
            r++;
            cur += cnt[pc[r] ^ k];
            cnt[pc[r]]++;
        }
        while (l < ql){
            cnt[pc[l]]--;
            cur -= cnt[pc[l] ^ k];
            l++;
        }
        while (r > qr){
            cnt[pc[r]]--;
            cur -= cnt[pc[r] ^ k];
            r--;
        }
        while (l > ql){
            l--;
            cur += cnt[pc[l] ^ k];
            cnt[pc[l]]++;
        }
        ans[quer[i].se] = cur;
    }
    for (int i=1;i<=m;i++){
        cout << ans[i] << el;
    }

    return 0;
}