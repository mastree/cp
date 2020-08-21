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

const ll INF = 1e18;

ll x;
ll ans = INF;
ll p1, p2;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> x;
    for (ll i=1;i*i<=x;i++){
        if (x % i != 0) continue;
        ll a = i, b = x/i;
        // cout << a << " " << b << el;
        ll gcc = __gcd(a,b);
        // if (ans > max(a * gcc, b)){
        //     p1 = a * gcc;
        //     p2 = b;
        //     ans = max(a * gcc, b);
        // }
        // if (ans > max(a, b * gcc)){
        //     p1 = a;
        //     p2 = b * gcc;
        //     ans = max(a, b * gcc);
        // }
        if (gcc == 1){
            if (ans > max(a, b)){
                ans = max(a, b);
                p1 = a;
                p2 = b;
            } 
        }
    }
    cout << p1 << " " << p2 << el;

    return 0;
}