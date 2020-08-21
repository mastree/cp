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

int n, q;
string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> s;
        n = s.length();
        int cnt[4];
        fill(cnt, cnt + 4, 0);
        int l = 0, r = 0;
        cnt[s[0] - '0']++;

        int ans = MOD;
        while (r < n){
            r++;
            int dig = s[r] - '0';
            cnt[dig]++;
            while (cnt[1] && cnt[2] && cnt[3]){
                ans = min(ans, r - l + 1);
                cnt[s[l] - '0']--;
                l++;
            }
        }
        if (ans == MOD){
            cout << 0 << el;
        } else{
            cout << ans << el;
        }
    }   

    return 0;
}