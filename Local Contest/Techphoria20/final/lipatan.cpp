#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 30;

int q;
ll n;

ll p2[N];

// (4^(n/2) - 1)/3*4^(n/2)
// 1 - 2f(n + 1)

void func(ll n){
    ll x, y;
    if (n & 1 ^ 1){
        ll a = p2[n / 2] - 1;
        ll b = 3 * p2[n / 2];
        ll gcc = __gcd(a, b);
        x = a / gcc;
        y = b / gcc;
    } else{
        n++;
        ll a = p2[n / 2] - 1;
        ll b = 3 * p2[n / 2];
        a = b - 2 * a;
        ll gcc = __gcd(a, b);
        x = a / gcc;
        y = b / gcc; 
    }
    cout << x << " " << y;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    p2[0] = 1;
    for (int i=1;i<N;i++){
        p2[i] = p2[i - 1] * 4LL;
    }
    vector<ll> ans;
    cin >> q;
    for (int i=1;i<=q;i++){
        cin >> n;
        func(n);
        if (i != q){
            cout << " ";
        }
    }
    cout << el;

    return 0;
}