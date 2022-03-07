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

const int N = 3e5 + 10;

int n;
int ar[N];
int pre[N];
int od[N], ev[N]; // from right;
ll ans;

int popcnt(ll x){
    int ret = 0;
    for (int i=0;i<61;i++){
        if (x & (1LL << i)) ret++;
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        ll a;
        cin >> a;
        int temp = popcnt(a);//__builtin_popcount(a);
        ar[i] = temp;
    }
    for (int i=1;i<=n;i++){
        pre[i] = pre[i - 1] + ar[i];
    }
    for (int i=n;i>=1;i--){
        od[i] = od[i + 1];
        ev[i] = ev[i + 1];
        if (pre[i] & 1) od[i]++;
        else ev[i]++;
    }
    for (int l=1;l<=n;l++){
        int temp = 0;
        for (int r=l;r<=n;r++){
            temp = max(temp, ar[r]);
            if (pre[r] - pre[l - 1] > 120){
                if (pre[l - 1] & 1) ans += (ll)od[r];
                else ans += (ll)ev[r];
                break;
            } else if ((pre[r] - pre[l - 1]) % 2 == 0){
                if ((pre[r] - pre[l - 1]) >= 2 * temp){
                    ans++;
                }
            }
        }
    }
    cout << ans << el;

    return 0;
}