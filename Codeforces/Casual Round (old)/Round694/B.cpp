#pragma gcc optimize("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 3e5 + 10;
const int MX = 1e6 + 10;

int tc;
int n;
int ar[N];
int q;

bool sieve[MX];
vector<int> factors[MX];

int hit = 0;

bool odfac(int a, int b){
    int cnt = 0;
    while (a % b == 0){
        cnt++;
        a /= b;
        hit++;
    }
    return (cnt & 1) == 1;
}

void init(){
    sieve[0] = 1;
    sieve[1] = 1;
    for (int i=2;i<MX;i++){
        if (sieve[i]) continue;
        factors[i].pb(i);
        for (int j=i + i;j<MX;j+=i){
            sieve[j] = 1;
            if (odfac(j, i)) factors[j].pb(i);
        }
    }
}

void solve(){
    cin >> n;
    map<vector<int>, int> cek;

    int ans0 = 0;
    int odev = 0;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        ++cek[factors[ar[i]]];
    }
    for (auto& x : cek){
        ans0 = max(ans0, x.se);
        if (x.fi.size() == 0){
            odev += x.se;
            continue;
        }
        if (x.se & 1 ^ 1){
            odev += x.se;
        }
    }
    cin >> q;
    while (q--){
        ll t;
        cin >> t;
        if (t == 0){
            cout << ans0 << el;
        } else{
            cout << max(ans0, odev) << el;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    cin >> tc;
    while (tc--){
        solve();
    }

    return 0;
}