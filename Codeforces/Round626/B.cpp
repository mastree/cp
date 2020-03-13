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

const int N = 4e4 + 10;

int n, m;
ll k;
ll ar1[N], ar2[N];
ll inp[N];

vector <ll> fac;

ll cnt[N], pc[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i=1;i<=n;i++){
        cin >> inp[i];
    }

    int bef = -1;
    int cur = 0;
    for (int i=1;i<=n;i++){
        if (bef == -1){
            bef = inp[i];
            cur = 1;
            continue;
        } 

        if (bef == inp[i]) cur++;
        else{
            if (bef == 1) ar1[cur]++;
            bef = inp[i];
            cur = 1;
        }
    }
    if (bef == 1) ar1[cur]++;
    for (int i=1;i<=m;i++){
        cin >> inp[i];
    }

    bef = -1;
    cur = 0;
    for (int i=1;i<=m;i++){
        if (bef == -1){
            bef = inp[i];
            cur = 1;
            continue;
        } 

        if (bef == inp[i]) cur++;
        else{
            if (bef == 1) ar2[cur]++;
            bef = inp[i];
            cur = 1;
        }
    }
    if (bef == 1) ar2[cur]++;

    for (ll i=1;i*i<=k;i++){
        if (k % i == 0){
            fac.pb(i);
            if (k/i != i) fac.pb(k/i);
        }
    }

    for (ll i=N-2;i>0;i--){
        pc[i] = pc[i+1] + ar2[i] * i;
        cnt[i] = cnt[i+1] + ar2[i];
    }

    ll ans = 0;
    for (auto x : fac){
        ll a = x;
        ll b = k / a;
        if (b >= N) continue;

        for (ll i=a;i<=n;i++){
            ans += ar1[i] * (i - a + 1LL) * (pc[b] - (cnt[b] * (b - 1)));
        }
    }
    cout << ans << el;

    return 0;
}