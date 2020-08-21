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

int n;
ll ar[N];
ll k, x;
ll con = 1;

ll ans = 0;
ll le[N], ri[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> x;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }

    for (int i=0;i<k;i++){
        con *= x;
    }

    for (int i=1;i<=n;i++){
        le[i] = (le[i-1] | ar[i]);
    }
    for (int i=n;i>=1;i--){
        ri[i] = (ri[i+1] | ar[i]);
    }

    for (int i=1;i<=n;i++){
        ll temp = ar[i] * con;
        ans = max(ans, (temp | le[i-1] | ri[i+1]));
    }
    cout << ans << el;

    return 0;
}