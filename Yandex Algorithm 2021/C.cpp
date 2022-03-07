#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;
const int INF = N;

int n;
int ar[N];
int b[N];
int ans[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int btot = 0;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        btot += ar[i];
    }
    int mx = btot;
    for (int i=1;i<=n;i++){
        cin >> b[i];
        if (b[i] == 0) continue;
        mx = min(mx, ar[i] / b[i]);
    }
    for (int i=mx;i>=1;i--){
        if (btot % i == 0){
            mx = i;
            break;
        }
    }

    vector<int> sisa;
    vector<int> uniform;
    int tot = 0;
    for (int i=1;i<=n;i++){
        ans[i] = ar[i] / mx;
        tot += ans[i];
        int slen = ar[i] - ans[i] * mx;
        for (int j=0;j<ans[i];j++) uniform.pb(i);
        for (int j=0;j<slen;j++) sisa.pb(i);
    }
    int scrap = sisa.size() / mx;
    tot += scrap;
    cout << mx << " " << tot << el;
    for (int i=1;i<=mx;i++){
        for (auto& x : uniform) cout << x << ' ';
        for (int j=0;j<scrap;j++){
            cout << sisa.back() << ' ';
            sisa.pop_back();
        }
        cout << el;
    }

    return 0;
}