#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using plll = pair<pair<ll, ll>, ll>;

plll mp3(const ll& a, const ll& b, const ll& c){
    return mp(mp(a, b), c);
}

const int N = 1e6 + 10;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int q;
int n, k;
ll L[N], W[N], H[N];
ll LR[5], WR[5], HR[5];
ll per[N];

void init(){
    for (int i=k + 1;i<=n;i++){
        L[i] = (LR[1] * L[i - 2] + LR[2] * L[i - 1] + LR[3]) % LR[4] + 1LL;
        W[i] = (WR[1] * W[i - 2] + WR[2] * W[i - 1] + WR[3]) % WR[4] + 1LL;
        H[i] = (HR[1] * H[i - 2] + HR[2] * H[i - 1] + HR[3]) % HR[4] + 1LL;
    }
}
void debug(){
    cout << el;
    for (int i=1;i<=n;i++){
        cout << L[i] << " ";
    }
    cout << el;
    for (int i=1;i<=n;i++){
        cout << W[i] << " ";
    }
    cout << el;
    for (int i=1;i<=n;i++){
        cout << H[i] << " ";
    }
    cout << el;
    for (int i=1;i<=n;i++){
        cout << per[i] << " ";
    }
    cout << el;
}

void solve(){
    cin >> n >> k;
    for (int i=1;i<=k;i++){
        cin >> L[i];
    }
    for (int i=1;i<=4;i++){
        cin >> LR[i];
    }
    for (int i=1;i<=k;i++){
        cin >> W[i];
    }
    for (int i=1;i<=4;i++){
        cin >> WR[i];
    }
    for (int i=1;i<=k;i++){
        cin >> H[i];
    }
    for (int i=1;i<=4;i++){
        cin >> HR[i];
    }
    init();
    
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("perimetric_chapter_3_input.txt", "r", stdin);
    freopen("A3.out", "w", stdout);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}