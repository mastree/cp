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

const int N = 1e5 + 10;

ll val[26];
string s;
map<ll, ll> ar[26];
ll pc[N];
ll ans;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=0;i<26;i++){
        cin >> val[i];
    }   
    cin >> s;
    int len = s.length();
    s = "*" + s;
    for (int i=1;i<=len;i++){
        ll dig = (ll)(s[i] - 'a');
        pc[i] = pc[i-1] + val[dig];

        ans += ar[dig][pc[i-1]];
        ar[dig][pc[i]]++;
    }

    cout << ans << el;

    return 0;
}