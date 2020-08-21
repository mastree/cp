#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;

ll ar[200005];
deque <ll> deq;
vector <ll> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n,q,maks=0,pos=0;
    cin >> n >> q;
    for (ll i=1;i<=n;i++){
        cin >> ar[i];
        if (maks<ar[i]){
            maks=ar[i];
            pos=i;
        }
    }

    pair<ll,ll> dp[n+1];

    for (ll i=1;i<=n;i++) deq.pb(ar[i]);

    for (ll i=1;i<pos;i++){
        ll a=deq.front();
        deq.pop_front();
        ll b=deq.front();
        deq.pop_front();
        dp[i]=mp(a,b);
        deq.pb(min(a,b));
        deq.push_front(max(a,b));
    }

    deq.pop_front();
    for (ll i=0;i<n-1;i++){
        v.pb(deq.front());
        deq.pop_front();
    }

    while (q--){
        ll query;
        cin >> query;
        if (query<pos){
            cout << dp[query].fi << " " << dp[query].se << el;
            continue;
        }

        cout << maks << " " << v[(query-pos)%(n-1)] << el;
    }

    return 0;
}