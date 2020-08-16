#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;
const ll INF = 1e18;

int n;
ll t;
ll ar[N];

bool bisa(int x){
    bool ret = 0;
    for (int i=1;i + x - 1<=n;i++){
        int j = i + x - 1;
        if (ar[j] <= 0) ret |= (-ar[i] <= t);
        else if (ar[i] >= 0) ret |= (ar[j] <= t);
        else{
            ll mn = min(2LL * ar[j] - ar[i], ar[j] - 2LL * ar[i]);
            ret |= (mn <= t);
        }
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> t;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }    
    int l = 0, r = N;
    while (l < r){
        int m = (l + r + 1) / 2;
        if (bisa(m)){
            l = m;
        } else{
            r = m - 1;
        }
    }
    cout << l << el;

    return 0;
}