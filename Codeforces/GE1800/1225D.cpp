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
int n, k;
vector<ll> v;

map <vector<int>, ll> cek[N];

ll cnt1;

void mpow(ll a){
    ll temp = 1;

    vector <int> pangkat;
    for (ll i=2;i*i<=a;i++){
        if (a % i == 0){
            ll cur = 0;
            while (a % i == 0){
                cur++;
                a /= i;
            }
            cur %= k;
            if (cur){
                temp *= i;
                pangkat.pb(cur);
            }
        }
    }
    if (a > 1){
        temp *= a;
        pangkat.pb(1);
    }
    cek[temp][pangkat]++;
}

ll sol(ll a){
    ll temp = 1;

    vector <int> pangkat;
    for (ll i=2;i*i<=a;i++){
        if (a % i == 0){
            ll cur = 0;
            while (a % i == 0){
                cur++;
                a /= i;
            }
            cur %= k;
            if (cur){
                temp *= i;
                pangkat.pb(cur);
            }
        }
    }
    if (a > 1){
        temp *= a;
        pangkat.pb(1);
    }

    cek[temp][pangkat]--;
    for (int i=0;i<pangkat.size();i++){
        pangkat[i] = (k - pangkat[i]) % k;
    }
    return cek[temp][pangkat];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=1;i<=n;i++){
        ll a;
        cin >> a;
        // if (a == 1) continue;
        v.pb(a);
        mpow(a);
    }
    ll temp = 0;
    for (auto x : v){
        temp += sol(x);
    }
    cout << temp << el;

    return 0;
}