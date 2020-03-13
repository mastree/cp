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

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        string s, t;
        cin >> s >> t;

        bool sim = 0;
        int slen = s.length(), tlen = t.length();

        if (tlen<slen){
            cout << "NO" << el;
            continue;
        }
        sort(s.begin(), s.end());
        for (int i=0;i<tlen;i++){
            int j;
            bool sama=1;
            string tm1 = "";

            for (j=i;j<min(i+slen,tlen);j++){
                tm1.pb(t[j]);
                // if (t[j]!=s[j-i]){
                //     sama=0;
                //     break;
                // }
            }
            sort(tm1.begin(), tm1.end());
            // sort(tm2.begin(), tm2.end());
            // cout << el;
            if (tm1 == s){
                sim=1;
                break;
            }
        }

        if (sim) cout << "YES" << el;
        else cout << "NO" << el;
    }

    return 0;
}