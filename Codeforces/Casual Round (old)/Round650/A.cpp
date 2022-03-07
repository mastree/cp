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
    while (q--){
        cin >> s;
        string ans = "";
        ans.pb(s[0]);
        int len = s.length();
        for (int i=1;i<len;i+=2){
            ans.pb(s[i]);
        }
        cout << ans << el;
    }

    return 0;
}