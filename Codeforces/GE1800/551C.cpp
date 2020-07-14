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

const int N = 1e5 + 10;
const ll MXTIME = 1e15;

int n, m;
ll ar[N];
ll ans;

bool bisa(ll mid){
    ll car[n + 1];
    for (int i=1;i<=n;i++) car[i] = ar[i];
    int last = 1;
    for (int i=1;i<=m;i++){
        ll stime = mid - (ll)last;
        while (last <= n && stime > 0){
            if (car[last] <= stime){
                stime -= car[last];
                car[last] = 0;
                if (stime){
                    stime--;
                    last++;
                }
            } else{
                car[last] -= stime;
                stime = 0;
            }
        }
    }
    bool ret = 1;
    for (int i=1;i<=n;i++) if (car[i]) ret = 0;
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    if (m == 1){
        for (int i=1;i<=n;i++){
            ans++;
            ans += ar[i];
        }
        cout << ans << el;
        return 0;
    }
    ll low = 1, high = MXTIME;
    while (low < high){
        ll mid = (low + high) / 2;
        if (bisa(mid)){
            high = mid;
        } else{
            low = mid + 1;
        }
    }
    cout << high << el;

    return 0;
}