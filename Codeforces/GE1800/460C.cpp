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

ll n, m, w;
ll ar[N];
ll tony[N];

bool cek(ll h){
    fill(tony, tony + n + 1, 0);
    ll sisa = m;
    ll cur = 0;

    for (int i=1;i<=n;i++){
        cur += tony[i];
        if (ar[i] + cur < h){
            ll butuh = h - ar[i] - cur;

            if (butuh > sisa){
                return 0;
            }
            sisa -= butuh;
            tony[i] += butuh;
            tony[i + w] -= butuh;
            cur += butuh;
        }
    }

    return 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> w;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }

    ll low = 1, high = MOD + MOD;
    while (low < high){
        ll mid = (low + high + 1) / 2;
        if (cek(mid)){
            low = mid;
        } else{
            high = mid - 1;
        }
    }
    cout << low << el;

    return 0;
}