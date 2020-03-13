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

const int N = 2e5 + 7, MAX = 1e6 + 1;
int n, ar[N];
int cek[MAX];
int ans;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        cek[ar[i]] = 1;
    }
    sort(ar + 1, ar + n + 1);
    for (int i=2;i<MAX;i++){
        if (!cek[i]) continue;

        for (int j=i+i;j<MAX*2;j+=i){
            auto it = lower_bound(ar + 1, ar + n + 1, j);
            int id = (int)(it - ar) - 1;
            // cout << j << " " << ar[id] << el;
            ans = max(ans, ar[id] % i);
            if (id == n) break;
        }
    }
    cout << ans << el;

    return 0;
}