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

int q;
int n, m;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> m;
        int tot = n * m;
        if (n % 2 == 0 || m % 2 == 0){
            cout << tot / 2 << el;
            continue;
        }
        int ans = (n / 2) * m + (m / 2) + 1;
        cout << ans << el;
    }

    return 0;
}