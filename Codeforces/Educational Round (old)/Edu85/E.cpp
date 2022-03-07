#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
// #define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const ll MXN = 1e15 + 2;
const ll MOD = 998244353;
const ll N = 2e5 + 10;

int q;
ll n, a, b;

vector <ll> v, fac;
unordered_map<ll, int> gid;
vector <pil> adl[N];

void get_factor(){
    ll temp = n;
    for (ll i=2;i*i<=temp;i++){
        if (temp%i == 0){
            fac.pb(i);
            while (temp%i) temp /= i;
        }
    }
    if (temp != 1) fac.pb(temp);
}

ll phi(ll ang){
    ll ret = 1;
    for (auto x : fac){
        ll temp = 0;
        while (ang % x == 0){
            temp++;
            ang /= x;
        }
        ret *= temp + 1;
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (ll i=1;i * i<=n;i++){
        if (i * i == n){
            v.pb(i);
        } else if (n % i == 0){
            v.pb(i);
            v.pb(n / i);
        }
    }
    get_factor();
    sort(v.begin(), v.end());
    int id = 0;
    for (auto x : v){
        cout << x << " ";
        id++;
        gid[x] = id;
    }
    cout << el;
    for (auto x : v){
        for (auto y : fac){
            ll ga = x, gb = x * y;
            if (n % gb != 0) continue;
            int a = gid[ga];
            int b = gid[gb];
            ll w = abs(phi(ga) - phi(gb));
            adl[a].pb(mp(b, w));
            adl[b].pb(mp(a, w));
        }
    }

    cin >> q;
    while (q--){
        cin >> a >> b;


    }

    return 0;
}