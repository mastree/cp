#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

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

int n;
int cnt[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> n;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        cnt[a]++;
    }
    for (int i=N - 1;i>=1;i--){
        int mx = 0;
        for (int j=i + i;j<N;j+=i){
            mx = max(mx, cnt[j]);
        }
        cnt[i] += mx;
    }
    int ans = 0;
    for (int i=1;i<N;i++){
        ans = max(ans, cnt[i]);
    }
    cout << ans << el;

    return 0;
}