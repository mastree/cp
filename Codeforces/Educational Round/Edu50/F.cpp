#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const ll BORD = 1e18;

int q;
ll n;

ll bates[60];

ll fpow(ll a, ll b){
    if (b == 0) return 1;
    ll temp = fpow(a, b / 2);
    temp = temp * temp;
    if (b & 1) temp = temp * a;
    return temp;
}

long double ffpow(long double a, ll b){
    if (b == 0) return 1.0;
    long double temp = ffpow(a, b / 2);
    temp = temp * temp;
    if (b & 1) temp = temp * a;
    return temp;
}

ll calc(ll n, ll p){
    ll low = 1, high = bates[p] - 1;
    while (low < high){
        ll mid = (low + high + 1) / 2;
        if (fpow(mid, p) <= n){
            low = mid;
        } else{
            high = mid - 1;
        }
    }
    return low - 1LL;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    bates[2] = 1e9 + 1;
    ll tempid = 59;
    for (ll i=2;tempid>2;i++){
        long double temp = ffpow((long double)i, tempid);
        while (temp > 1e18){
            bates[tempid] = i;
            tempid--;
            temp = ffpow((long double)i, tempid);
        }
    }

    cin >> q;
    while (q--){
        cin >> n;

        ll ans = 0;
        ll count[60];
        fill(count, count + 60, 1);
        for (ll i=2;i<60;i++){
            ans += count[i] * calc(n, i);
            for (ll j=i + i;j<60;j+=i){
                count[j] -= count[i];
            }
        }
        cout << n - ans - 1LL << el;
    }

    return 0;
}