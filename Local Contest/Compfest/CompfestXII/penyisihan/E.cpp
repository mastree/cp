#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ld = long double;

const int N = 1e6 + 10;

ll n, k, l, r;
ll ar[N];

bool bisa(double mx){
    ll cnt = 0;
    ll udah = 0;
    ll tot = 0;

    for (ll i=1;i<=n;i++){
        cout << i << el;
        if (double(tot + ar[i]) / double(cnt + 1) <= mx){
            tot += ar[i];
            cnt++;
        } else{
            if (cnt == 0 || double(ar[i]) > mx) return 0;
            udah++;
            tot = ar[i];
            cnt = 1;
        }

        if ((k - (udah + 1)) * l >= (n - i) || cnt == r){ // cek udh harus ganti range apa blm
            udah++;
            tot = 0;
            cnt = 0;
        }
    }
    cout << mx << el;
    if (udah < k) return 0;
    return 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> l >> r;
    for (ll i=1;i<=n;i++){
        cin >> ar[i];
    }   

    double l = 1, r = 1e12;
    for (int i=1;i<=100;i++){
        double m = (l + r) / 2;
        if (bisa(m)){
            r = m;
        } else{
            l = m;
        }
    }
    cout << fixed << setprecision(11);
    cout << l << el;

    return 0;
}