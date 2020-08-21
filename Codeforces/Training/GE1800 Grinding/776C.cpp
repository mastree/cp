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
int n;
ll ar[N], k; 
ll pc[N];

ll ans;
map <ll, ll> cek;
vector <ll> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }

    if (abs(k) != 1){
        for (ll i=1;abs(i)<(ll)N*(ll)MOD;i*=k){
            v.pb(i);
        }
    } else{
        v.pb(1);
        if (k == -1) v.pb(-1);
    }

    // cek[0]++;
    for (int i=1;i<=n;i++){
        pc[i] = pc[i-1] + ar[i];
        cek[pc[i]]++;
    }

    for (int i=0;i<=n;i++){
        if (i > 0 && cek.count(pc[i])) cek[pc[i]]--;
        for (auto x : v){
            if (cek.count(x + pc[i])){
                ans += cek[x + pc[i]];
            }
        }
    }
    cout << ans << el;

    return 0;
}