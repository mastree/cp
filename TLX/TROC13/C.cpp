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

const int N = 1e4 + 10;
const int M = 32000;
const ll INF = 1e18;

ll n;
ll ar[N];
ll ans = INF;  

ll kel;

// vector<unordered_map<ll, ll>> cek; // id fac, sisa, count
vector<ll> fac;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        kel += ar[i];
    }   
    for (ll i=1;i * i<=kel;i++){
        if (kel % i == 0){
            ll j = kel / i;
            if (j <= (ll)n) fac.pb(i);
            if (i >= 3LL && i != j) fac.pb(j);
        }
    }
    sort(fac.begin(), fac.end());
    int len = fac.size();
    for (int id=0;id<len;id++){
        unordered_map<ll, int> cek;

        ll cur = 0;
        ll x = fac[id];
        ll butuh = kel / x;
        if (butuh < 3 || butuh > (ll)n) continue;
        for (int i=1;i<=n;i++){
            cur += ar[i];
            ll sisa = cur % x;
            cek[sisa]++;
        }
        for (auto y : cek){
            if (y.se == (int)butuh){
                cout << n - y.se << el;
                return 0;
            }
        }
    }
    cout << -1 << el;

    return 0;
}