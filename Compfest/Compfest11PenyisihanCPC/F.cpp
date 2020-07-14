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

const int N = 110;

int n, m;
ll cnt[26];
string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cin >> s;
    for (auto c : s){
        int dig = (c - 'A');
        cnt[dig]++;
    }
    while (m--){
        string a, b;
        cin >> a >> b;
        ll _cnt[26];
        fill(_cnt, _cnt + 26, 0);
        for (auto c : b){
            int dig = (c - 'A');
            _cnt[dig]++;
        }
        int dig = (a[0] - 'A');
        ll fac = cnt[dig];
        cnt[dig] = 0;
        for (int i=0;i<26;i++){
            cnt[i] += fac * _cnt[i];
        }
    }
    ll ans = 0;
    for (int i=0;i<26;i++) ans += cnt[i];
    cout << ans << el;

    return 0;
}