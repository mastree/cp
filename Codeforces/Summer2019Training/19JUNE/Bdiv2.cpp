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


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    while (n--){
        string s,t;
        cin >> s >> t;
        int slen=s.length(),tlen=t.length();

        vector <pair<int,char>> comp1,comp2; // compress

        char bef=s[0];
        int cnt=1;
        for (int i=1;i<slen;i++){
            if (bef!=s[i]){
                comp1.pb(mp(cnt,bef));
                bef=s[i];
                cnt=1;
            }
            else {
                cnt++;
            }
        }

        comp1.pb(mp(cnt,bef));

        bef=t[0];
        cnt=1;
        for (int i=1;i<tlen;i++){
            if (bef!=t[i]){
                comp2.pb(mp(cnt,bef));
                bef=t[i];
                cnt=1;
            } else{
                cnt++;
            }
        }

        comp2.pb(mp(cnt,bef));

        int alen=comp1.size(),blen=comp2.size();

        if (alen!=blen){
            cout << "NO" << el;
            continue;
        }

        bool bisa=1;
        for (int i=0;i<alen;i++){
        //    cerr << comp1[i].fi << " " << comp2[i].fi << el;
            if (comp1[i].fi<=comp2[i].fi && comp1[i].se==comp2[i].se) continue;
            bisa=0;
            break;
        }

        if (bisa) cout << "YES" << el;
        else cout << "NO" << el;

    }

    return 0;
}