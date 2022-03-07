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

const int N = 1e9 + 10;

int q;
int n, k;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> k;
        int ans = n;
        for (int i = 1;i * i <= n;i++){
            if (n % i == 0){
                int j = n / i;
                if (i <= k) ans = min(ans, n / i);
                if (j <= k) ans = min(ans, n / j);
            }
        }
        cout << ans << el;
    }

    return 0;
}