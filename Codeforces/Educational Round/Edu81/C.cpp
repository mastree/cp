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
string s, t;

vector <int> v[26];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> s >> t;
        int slen, tlen;
        slen = s.length();
        tlen = t.length();
        
        for (int i=0;i<26;i++){
            v[i].clear();
        }
        for (int i=0;i<slen;i++){
            int dig = s[i] - 'a';
            v[dig].pb(i);
        }

        int ans = 1;
        int last = -1;
        int bin = -1;
        while (last < tlen-1){
            int dig = t[last + 1] - 'a';
            // cout << dig << el;

            auto pos = upper_bound(v[dig].begin(), v[dig].end(), bin);
            if (pos == v[dig].end()){
                if (bin == -1){
                    ans = -1;
                    break;
                }
                ans++;
                bin = -1;
                continue;
            }

            auto isi = *pos;
            last++;
            bin = isi;
        }
        cout << ans << el;
    }

    return 0;
}