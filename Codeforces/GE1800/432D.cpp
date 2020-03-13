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

string s;
int n;

int pref[N];
int dp[N];

vector <int> v;
ll ans[N];
ll tony[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill(pref, pref + N, 1);

    cin >> s;
    n = s.length();
    s = "*" + s;
    int id = 1;
    for (int i=2;i<=n;i++){
        while (s[id] != s[i]){
            if (id == 1) break;
            id = pref[id - 1];
        }
        if (s[i] == s[id]) id++;
        pref[i] = id;
    }
    // for (int i=1;i<=n;i++){
    //     cout << pref[i] << " ";
    // }
    // cout << el;
    int cur = n;
    v.pb(n);
    while (cur > 1){
        cur = pref[cur - 1];
        v.pb(cur);
    }

    tony[1] = 1;
    pref[n+1] = 1;
    for (int i=1;i<=n;i++){
        if (pref[i] > pref[i+1]){
            tony[1]++;
            tony[pref[i]]--;
            cout << pref[i] << " ";
        }
    }
    cout << el;

    ll now = 0;
    for (int i=1;i<=n;i++){
        now += tony[i];
        ans[i] += now;
    }
    ans[1]++;

    sort(v.begin(), v.end());
    for (auto x : v){
        cout << x << " " << ans[x] << el;
    }

    return 0;
}