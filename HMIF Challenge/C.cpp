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

const int N = 2e3 + 7;

int n;
ll k;
ll ar[N];
ll ans[N];

ll pcatas[N], pcbawah[N];

ll fpow(ll a, ll b){
    if (b==0){
        return 1;
    }

    ll tm = fpow(a, b/2);
    tm = (tm*tm) % MOD;
    if (b&1){
        tm = (tm*a) % MOD;
    }

    return tm;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }

    if (k == 0){
        for (int i=1;i<n;i++){
            cout << ar[i] << " ";
        }
        cout << ar[n] << el;

        return 0;
    }

    // k++;
    pcbawah[0] = 1;
    for (int i=1;i<=n;i++){
        pcbawah[i] = (i * pcbawah[i-1]) % MOD;
        // cout << pcbawah[i] << " ";
    }
    // cout << el;

    pcatas[0] = 1; 
    for (int i=1;i<=n;i++){
        pcatas[i] = ((k + i - 1) * pcatas[i-1]) % MOD;
        // cout << pcatas[i] << " ";
    }
    // cout << el;

    for (int i=1;i<=n;i++){
        int ka=0;
        for (int j=i;j<=n;j++){
            ll tm = pcatas[ka] * fpow(pcbawah[ka], MOD-2) % MOD;
            // cout << tm << " ";
            ans[j] = (ans[j] + tm * ar[i]) % MOD; 
            ka++;
        }
        // cout << el;
    }

    for (int i=1;i<n;i++){
        cout << ans[i] << " ";
    }
    cout << ans[n] << el;

    return 0;
}