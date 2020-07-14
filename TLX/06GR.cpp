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

const int N = 20;

ll n, uang;
pair<ll, int> ar[N];
ll har[N];
vector <ll> cnt(N, 0);

vector<ll> sol(int dig){
    ll tuang = uang;
    if (dig != 0){
        ll retl = tuang / har[dig] - 1;
        tuang -= retl * har[dig];
        int dig2;
        for (int i=dig;i<=n;i++){
            if (tuang >= har[i]) dig2 = i;
        }
        vector <ll> ret(N, 0);
        ret[dig] = retl;
        ret[dig2]++;
    } else{
        ll retl = tuang / har[dig] - 1;
        tuang -= retl * har[dig];
        int dig2;
        for (int i=dig;i<=n;i++){
            if (tuang >= har[i]) dig2 = i;
        }
        vector <ll> ret(N, 0);
        ret[dig] = retl;
        ret[dig2]++;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<=(int)n;i++){
        ll a;
        cin >> a;
        ar[i] = mp(a, i);
        har[i] = a;
    }
    sort(ar, ar + n + 1);
    cin >> uang;
    if (ar[0].se != 0){
        if (uang - ar[0].fi < 0){
            cout << 0 << el;
            return 0;
        }
        ll sup = uang / ar[0].fi;
        for (int i=0;i<=n;i++){
            if (uang / ar[i].fi == sup){
                vector <ll> temp = sol(ar[i].se);
            }
        }
    } else{
        if (uang - ar[1].fi <= 0){
            cout << 1 << el << 0 << el << 0 << el;
            return 0;
        }
    }

    return 0;
}