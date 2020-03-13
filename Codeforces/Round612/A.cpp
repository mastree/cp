#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;

int q;
int k;
string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> k;
        cin >> s;

        vector <int> v;
        int ans = 0;
        int len = s.length();
        for (int i=0;i<len;i++){
            if (s[i] == 'A'){
                v.pb(i);
            }
        }
        v.pb(len);

        int vlen = v.size();
        for (int i=0;i<vlen-1;i++){
            ans = max(ans, v[i+1] - v[i] - 1);
        }

        cout << ans << el;
    }

    return 0;
}