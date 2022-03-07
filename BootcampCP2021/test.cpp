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
const int INF = 1e9 + 10;

int q;
int n, c;
int ar[N];

bool bisa(int mx){
    int cur = 0;
    int last = -INF;
    for (int i=1;i<=n;i++){
        if (ar[i] - last >= mx){
            cur++;
            last = ar[i];
        }
        if (cur >= c) return 1;
    }
    return 0;
}

void solve(){
    cin >> n >> c;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    sort(ar + 1, ar + n + 1);
    int l = 0, r = INF;
    while (l < r){
        int m = l + (r - l + 1) / 2;
        if (bisa(m)){   
            l = m;
        } else{
            r = m - 1;
        }
    }
    cout << r << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }    

    return 0;
}