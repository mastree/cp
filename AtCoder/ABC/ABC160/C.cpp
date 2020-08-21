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

const int N = 2e5 + 10;
const ll INF = 1e18;

ll k, n;
ll ar[N];
ll ans;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> k >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }

    ans = INF;
    for (int i=1;i<=n;i++){
        int fin = i - 1;
        if (fin == 0) fin = n;
        if (ar[fin] < ar[i]){
            ans = min(ans, k - ar[i] + ar[fin]);
        } else{
            ans = min(ans, ar[fin] - ar[i]);
        }
    }
    cout << ans << el;

    return 0;
}