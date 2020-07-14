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

int q;
string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int cas=1;cas<=q;cas++){
        cin >> s;
        int n = s.length();
        int cur = 0;
        string ans = "";

        for (int i=0;i<n;i++){
            int dig = s[i] - '0';

            while (dig < cur){
                ans.pb(')');
                cur--;
            }
            while (dig > cur){
                ans.pb('(');
                cur++;
            }
            ans.pb(s[i]);
        }
        while (cur--){
            ans.pb(')');
        }
        cout << "Case #" << cas << ": " << ans << el;
    }

    return 0;
}