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

const int N = 2e5 + 9;
const ll MOD = 1e9 + 7;
const ll hund = 100;

int n, q;
ll ar[N];
ll pc1[N], pc2[N], pcc[N];

ll fpow(ll a, ll b){
    if (b==0) return 1;
    ll tm = fpow(a, b/2);
    tm = tm*tm%MOD;
    if (b&1){
        tm = tm*a%MOD; 
    }

    return tm;
}

ll inv(ll a){
    return fpow(a, MOD-2);
}

ll frac(ll a, ll b){
    ll gcc = __gcd(a,b);
    a = a/gcc;
    b = b/gcc;
    return a * inv(b) % MOD;
}

ll sol(int l, int r){
    ll a = (pc2[r-1] - pc2[l-1] + MOD) % MOD;
    ll b = pc1[r] * inv(pc1[l-1]) % MOD;
    return frac(1 + a, b);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }

    pcc[0] = 1;
    pc1[0] = 1;
    for (int i=1;i<=n;i++){
        pc1[i] = (pc1[i-1] * frac(ar[i], 100)) % MOD;
    }

    for (int i=1;i<=n;i++){
        pc2[i] = (pc2[i-1] + pc1[i]) % MOD;
    }

    cout << sol(1, n) << el;

    set <int> seg;
    seg.insert(1);
    seg.insert(n+1);
    ll cur = sol(1, n);
    while (q--){
        int baru;
        cin >> baru;

        auto upper = seg.lower_bound(baru);
        auto it = upper++;
        // cout << "find1 => " << *it << el;
        if (*it == baru){
            auto ita = --it;
            it++;
            auto itb = ++it;
            cur = (cur * inv(sol(baru, (*itb)-1))) % MOD;
            cur = (cur * inv(sol(*ita, baru-1))) % MOD;
            seg.erase(baru);
            cur = (cur * sol(*ita, (*itb)-1)) % MOD;
        } else{
            seg.insert(baru);
            it = seg.lower_bound(baru);
            auto ita = --it;
            it++;
            auto itb = ++it;
            // cout << *ita << " " << *itb << el;
            cur = (cur * inv(sol(*ita, *itb-1))) % MOD;
            // cout << cur << el;
            cur = (cur * sol(*ita, baru-1)) % MOD;
            cur = (cur * sol(baru, (*itb)-1)) % MOD;
            // cout << "range => " << baru << " " << (*it)-1 << el; 
        }
        cout << cur << el;
    }

    return 0;
}