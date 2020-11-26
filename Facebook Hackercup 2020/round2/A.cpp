#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e6 + 10;

int q;
int n, k;
ll s[N], x[N], y[N];

ll sf[4], xf[4], yf[4];

void debug(){
    cout << el;
    for (int i=1;i<=n;i++){
        cout << s[i] << " ";
    }
    cout << el;
    for (int i=1;i<=n;i++){
        cout << x[i] << " ";
    }
    cout << el;
    for (int i=1;i<=n;i++){
        cout << y[i] << " ";
    }
    cout << el << el;
}

void init(){
    for (int i=k + 1;i<=n;i++){
        s[i] = (sf[0] * s[i - 2] + sf[1] * s[i - 1] + sf[2]) % sf[3];
        x[i] = (xf[0] * x[i - 2] + xf[1] * x[i - 1] + xf[2]) % xf[3];
        y[i] = (yf[0] * y[i - 2] + yf[1] * y[i - 1] + yf[2]) % yf[3];
    }
}

void solve(){
    cin >> n >> k;
    for (int i=1;i<=k;i++){
        cin >> s[i];
    }
    for (int i=0;i<4;i++){
        cin >> sf[i];
    }
    for (int i=1;i<=k;i++){
        cin >> x[i];
    }
    for (int i=0;i<4;i++){
        cin >> xf[i];
    }
    for (int i=1;i<=k;i++){
        cin >> y[i];
    }
    for (int i=0;i<4;i++){
        cin >> yf[i];
    }
    init();
    ll atas = 0, bawah = 0, tot = 0, mx = 0, mn = 0;
    for (int i=1;i<=n;i++){
        tot += s[i];
        mn += x[i];
        mx += x[i] + y[i];
        if (s[i] < x[i]){
            bawah += x[i] - s[i];
        } 
        if (s[i] > x[i] + y[i]){
            atas += s[i] - (x[i] + y[i]); 
        }
    }
    if (tot < mn || tot > mx){
        cout << -1 << el;
        return;
    }
    ll ans = min(atas, bawah);
    atas -= ans;
    bawah -= ans;
    ans += atas + bawah;
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("capastaty_input.txt", "r", stdin);
    freopen("A.out", "w", stdout);
    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}