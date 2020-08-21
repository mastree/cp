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

void find_prefix(){
    int j = 0;
    for (int i=1;i<n;i++){
        while (s[i] != s[j] && j != 0) j = pref[j - 1];
        if (s[i] == s[j]) j++;
        pref[i] = j;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = s.length();

    find_prefix();
    for (int i=0;i<n;i++){
        dp[pref[i]]++;
    }
    for (int i=n-1;i>=0;i--){
        dp[pref[i - 1]] += dp[i];
    }
    for (int i=1;i<=n;i++){
        dp[i]++;
    }

    vector <int> v;
    int cur = n;
    while (cur > 0){
        v.pb(cur);
        cur = pref[cur - 1];
    }
    sort(v.begin(), v.end());
    cout << v.size() << el;
    for (auto x : v){
        cout << x << " " << dp[x] << el;
    }

    return 0;
}