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

ll a, b;
ll ans, x;

ll lcm(ll a, ll b){
    return a * b / __gcd(a, b);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
    if (a > b) swap(a, b);
    ll beda = b - a;
    ll gcc = __gcd(a, b);
    ans = a * b / gcc;
    x = 0;
    for (ll i=1;i*i<=beda;i++){
        if (beda % i == 0){
            ll j = beda / i;
            if (a % i == b % i){
                ll sisa = (i - a % i) % i;
                ll temp = lcm(a + sisa, b + sisa);
                if (temp < ans){
                    ans = temp;
                    x = sisa;
                }
            }
            if (a % j == b % j){
                ll sisa = (j - a % j) % j;
                ll temp = lcm(a + sisa, b + sisa);
                if (temp < ans){
                    ans = temp;
                    x = sisa;
                }
            }
        }
    }

    cout << x << el;

    return 0;
}