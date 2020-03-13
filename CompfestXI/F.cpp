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

ll cnt[26];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n,m;
    cin >> n >> m;


    string s;
    cin >> s;

    for (int i=0;i<s.length();i++){
        cnt[s[i]-'A']++;
    }

    
    for (int cas=0;cas<m;cas++){
        char c;
        string ub;
        cin >> c >> ub;
        ll tm[26],plus[26];
        for (int i=0;i<26;i++){
            tm[i]=0;
            plus[i]=0;
        }
        for (int i=0;i<ub.length();i++){
            tm[ub[i]-'A']++;
        }

        for (int i=0;i<26;i++){
            plus[i]+=cnt[c-'A']*tm[i];
        }
        cnt[c-'A']=0;

        for (int i=0;i<26;i++){
            cnt[i]+=plus[i];
        }

      //  for (auto x : cnt) cerr << x << " "; cerr << el;

    }

    ll ans=0;
    for (int i=0;i<26;i++) ans+=cnt[i];
    cout << ans << el;

    return 0;
}