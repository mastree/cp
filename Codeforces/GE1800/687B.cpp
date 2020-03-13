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

ll n, k;
ll cur = 1;

ll __lcm(ll a, ll b){
    return a * b / __gcd(a, b);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=0;i<n;i++){
        ll temp;
        cin >> temp;
        ll gcc = __gcd(k, temp);
        cur = __lcm(gcc, cur);
    }

    if (__gcd(cur, k) == k){
        cout << "Yes" << el;
    } else{
        cout << "No" << el;
    }

    return 0;
}