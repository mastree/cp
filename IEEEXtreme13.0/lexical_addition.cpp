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

ll n,a,b;
vector <ll> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b;

    ll del=b-a+1;
    ll sisa=n%a;
    ll cnt=n/a;

    if (sisa>cnt*del){
        cout << "NO" << el;
        return 0;
    }

    ll tot=0;
    ll panjang=(n+b-1)/b;
    cout << "YES" << el;
    for (ll i=0;(i<panjang);i++){
        tot+=b;
        v.pb(b);
    }
    
    int len=v.size();
    for (int i=0;(i<len)&&(tot>n);i++){
        ll ubah=min(tot-n,del-1);
        v[i]-=ubah;
        tot-=ubah;
    }

    for (auto x : v){
        cout << x << " ";
    }

    cout << el;

    return 0;
}