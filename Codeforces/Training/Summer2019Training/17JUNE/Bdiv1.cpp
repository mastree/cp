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

ll n;
vector <ll> adl[200006];
ll ar[200006];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (ll i=0;i<n-1;i++){
        ll a,b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
        ar[a]++;ar[b]++;
    }

    sort(ar+1,ar+n+1,greater<ll>());

    return 0;
}