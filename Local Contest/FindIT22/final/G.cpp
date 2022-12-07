#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll egcd(ll a, ll b, ll &x, ll &y){
    if(a == 0){
        x = 0, y = 1;
        return b;
    }
    ll x1,y1;
    ll d = egcd(b%a,a,x1,y1);
    x = y1-(b/a)*x1;
    y = x1;
    return d;
}

ll inv(ll a, ll b){
    ll x,y;
    egcd(a,b,x,y);
    return (x%b+b)%b;
}

ll findMinX(ll num[], ll rem[], int k){
    ll prod = 1;
    for(int i=0;i<k;i++){
        prod *= num[i];
    }
    ll res = 0;
    for(int i=0;i<k;i++){
        ll pp = prod/num[i];
        res += (rem[i]*inv(pp,num[i])*pp)%prod;
    }
    return res%prod;
}

const int N = 100;

ll num[N];
ll rem[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // all of elements in num has to be coprime
    // int k = sizeof(num)/sizeof(num[0]);
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> rem[i];
    }
    cout << findMinX(num, rem, k) << "\n";

    return 0;
}