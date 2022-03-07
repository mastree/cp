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

const int N = 4e3;

int q;
int n, m, k;
int ar[N], dp[N];

bool cek(int x){
    fill(dp, dp + n + 1, 0);

    int depan = m-1;
    for (int i=0;i<=depan;i++){
        int cur = max(ar[i+1], ar[n - (depan - i)]);
        if (cur >= x){
            dp[i] = 1;
        }
    }

    for (int i=depan-1;i>=0;i--){
        if (dp[i]){
            dp[i] += dp[i+1];
        }
    }

    for (int i=0;i<=depan;i++){
        if (i > k || dp[i] == 0) continue;
        int bebas = dp[i] - 1;
        int milih = depan - bebas;
        if (milih <= k) return 1;
    }
    return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> m >> k;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
        }
        int low = 1, high = 1e9;
        while (low < high){
            int mid = (low + high + 1) / 2;
            if (cek(mid)){
                low = mid;
            } else{
                high = mid-1;
            }
        }
        cout << low << el;

    }

    return 0;
}