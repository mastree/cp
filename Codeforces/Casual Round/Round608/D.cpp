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

ll n,k;

ll cek(ll a, ll b){
    if (a*2>b){
        ll res = 1;
        if (a&1) return res;
        return res+1;
    }

    ll res = b - (a*2) + 1;
    ll t2 = a*2;
    if (a&1) res++;
    else res+=2;
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    ll low=1;
    ll high=n;

    if (k>n){
        cout << -1 << el;
        return 0;
    }
    if (k==n){
        cout << 1 << el;
        return 0;
    }

    ll mid;
    while (low<high){
        mid = (low+high+1)/2;

        ll cnt = cek(mid, n);
        if (cnt>=k){
            low = mid;
        } else{
            high = mid-1;
        }
    }
    cout << low << el;

    return 0;
}