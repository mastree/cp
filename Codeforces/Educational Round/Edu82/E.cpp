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

const int INF = 1e9;

int q;
string s, t;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> s >> t;

        int slen = s.length();
        int tlen = t.length();
        s = '*' + s;
        t = '*' + t;

        vector <int> le(slen + 2, 0), ri(slen + 2, 0);
        vector <pii> v[26];
        vector <int> all[26];

        for (int i=1;i<=slen;i++){
            all[s[i] - 'a'].pb(i);
        }
        
        bool bisa = 0;
        for (int i=1;i<=tlen;i++){
            fill(le.begin(), le.end(), INF);
            fill(ri.begin(), ri.end(), 0);
            int id = 1;
            for (int j=1;j<=slen;j++){
                if (s[j] == t[id]){
                    le[id] = j;
                    id++;
                }
                if (id > i) break;
            }
            if (id <= i) continue;
            id = i;
            for (int j=slen;j>=1;j--){
                if (s[j] == t[id]){
                    ri[id] = j;
                    id--;
                }
                if (id <= 0) break;
            }
            if (i == tlen){
                bisa = 1;
                break;
            }
            for (int j=1;j<=i;j++){
                v[t[j] - 'a'].pb(mp(le[j], ri[j]));
            }

            bisa = 1;
            int cur = 0;
            // for (int j=i+1;j<=tlen;j++){
            //     bool march = 0;
            //     for (auto x : v[t[j] - 'a']){
            //         if (cur < x.se && x.fi != x.se){
            //             auto it = upper_bound(all[t[j] - 'a'].begin(), all[t[j] - 'a'].end(), cur);
            //             if (*it == x.fi) it++;
            //             if (it == all[t[j] - 'a'].end()) continue;
            //             cur = *it;
            //             march = 1;
            //             break;
            //         }
            //     }
            //     if (march == 0){
            //         bisa = 0;
            //         break;
            //     }
            // }
            if (bisa) break;
        }
        if (bisa) cout << "YES" << el;
        else cout << "NO" << el;
    }

    return 0;
}