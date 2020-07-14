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

const ll N = 5e5 + 10;

ll n;
ll cnt[N];
ll ans[N];

bool isPrime[N];
bool vis[N];
vector <ll> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    fill(isPrime + 1, isPrime + n + 2, 1);
    for (int i=2;i * i<=n;i++){
        if (!isPrime[i]) continue;
        for (int j = i * i;j <= n;j += i){
            isPrime[j] = 0;
        }
    }
    for (int i=1;i<=n;i++){
        if (isPrime[i]){
            v.pb(i);
        }
    }
    int len = v.size();
    for (int i=1;i<=len;i++){
        ans[i] = 1;
    }
    
    int curid = len + 1;
    for (ll i=2;i<=n;i++){
        if (curid>n) break;

        for (ll j=1;j<len;j++){
            int temp = v[j] * i;
            if (temp > n) break;
            if (vis[temp]) continue;
            vis[temp] = 1;
            ans[curid] = i;
            curid++;
            if (curid>n) break;
        }
    }

    for (int i=2;i<=n;i++){
        cout << ans[i] << " ";
    }
    cout << el;

    return 0;
}