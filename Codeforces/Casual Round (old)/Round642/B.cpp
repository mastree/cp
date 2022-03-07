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

const int N = 50;

int q;
int n, k;
int ar1[N], ar2[N]; 

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> k;
        for (int i=1;i<=n;i++){
            cin >> ar1[i];
        }
        for (int i=1;i<=n;i++){
            cin >> ar2[i];
        }
        sort(ar1 + 1, ar1 + n + 1);
        sort(ar2 + 1, ar2 + n + 1, greater<int>());
        int ans = 0;
        for (int i=1;i<=n;i++){
            if (i <= k) ans += max(ar1[i], ar2[i]);
            else ans += ar1[i];
        }
        cout << ans << el;
    }

    return 0;
}