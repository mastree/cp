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
        string s;

        cin >> s;
        int len = s.length();
        vector <int> od,ev;

        for (int i=0;i<len;i++){
            int tm=(int)(s[i]-'0');

            if (tm&1){
                od.pb(tm);
            } else{
                ev.pb(tm);
            }
        }

        int idod=0,idev=0;
        int lenod=od.size(), lenev=ev.size();
        while (idod<lenod || idev<lenev){
            if (idod<lenod && idev<lenev){
            //    cout << od[idod] << " " << ev[idev] << el;
                if (od[idod]<ev[idev]){
                    cout << od[idod];
                    idod++;
                } else{
                    cout << ev[idev];
                    idev++;
                }
            } else if (idod<lenod){
                cout << od[idod];
                idod++;
            } else{
                cout << ev[idev];
                idev++;
            }
        }

        cout << el;

    }

    return 0;
}