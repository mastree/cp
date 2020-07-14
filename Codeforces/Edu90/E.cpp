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

const int N = 200;
const ll INF = 1e18;

int q;
ll n, k;
ll mn[N];

string itostr(ll a){
    string ret;
    if (a == 0) return "0";
    while (a){
        int dig = a % 10;
        ret.pb(char(dig + '0'));
        a /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

ll stoint(string s){
    ll ret = 0;
    reverse(s.begin(), s.end());
    for (auto x : s){
        ll dig = (ll)(x - '0');
        ret = ret * 10LL + dig;
    }
    return ret;
}

ll calc(ll a){
    ll ret = 0;
    while (a){
        ret += (ll)(a % 10);
        a /= 10LL;
    }
    return ret;
}
ll calc(ll a, ll k){
    ll ret = 0;
    for (ll i=0;i<=k;i++){
        ret += calc(a + i);
    }
    return ret;
}

ll getlen(ll a){
    ll ret = 0;
    if (a == 0) return 1;
    while (a){
        ret++;
        a /= 10LL;
    }
    return ret;
}

string smin(string a, string b){
    if (a.length() > b.length()) return b;
    if (a.length() < b.length()) return a;
    return min(a, b);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (ll i=1;i<=150;i++){
        ll cur = i;
        string temp = "";
        while (cur){
            if (cur < 10){
                temp.pb(char(cur + '0'));
                cur = 0;
            } else {
                temp.pb(char('9'));
                cur -= 9;
            }
        }
        ll res = stoint(temp);
        mn[i] = res;
    }

    cin >> q;
    while (q--){
        cin >> n >> k;

        string ans = "9999999999999999999999";
        for (ll i=0;i<100;i++){
            ll base = i;
            ll temp = calc(base, k);
            ll sisa = n - temp;
            if (sisa < 0 || (sisa % (k + 1))) continue;
            if (sisa == 0) ans = smin(ans, itostr(base));
            if (getlen(base) < getlen(base + k)){
                ll temp2 = mn[sisa / (k + 1)];
                ans = smin(ans, itostr(temp2) + "0" + itostr(base));
            } else{
                ll temp2 = mn[sisa / (k + 1)];
                ans = smin(ans, itostr(temp2) + itostr(base));
            }
        }
        if (ans == "9999999999999999999999"){
            cout << -1 << el;
            continue;
        }
        cout << ans << el;
    }
    return 0;
}