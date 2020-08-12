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
const int INF = 1e9;

int q;
int n;
string s;
int ar[N];
int pp;

int solve(int l, int r, int cur){
    if (l == r){
        return (ar[l] != cur);
    }
    // cout << l << " " << r << " " << cur << el;
    int cntle = 0, cntri = 0;
    int range = r - l + 1;
    int i;
    for (i=l;i<l + range / 2;i++){
        if (ar[i] != cur) cntle++;
    }
    for (;i<=r;i++){
        if (ar[i] != cur) cntri++;
    }
    return min(cntle + solve(l + range / 2, r, cur + 1), cntri + solve(l, l + range / 2 - 1, cur + 1));
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        cin >> s;
        for (int i=0;i<n;i++){
            ar[i + 1] = (int)(s[i] - 'a');
        }
        int ans = solve(1, n, 0);
        cout << ans << el;
    }

    return 0;
}