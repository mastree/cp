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

int n;
vector <int> pos,neg;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<n;i++){
        int tm;
        cin >> tm;
        if (tm>0) pos.pb(tm);
        else neg.pb(tm);
    }

    if (!neg.empty()) sort(neg.begin(),neg.end(),greater<int>());
    if (!pos.empty()) sort(pos.begin(),pos.end());
//    cerr << neg.size() << el;
    

    int totn=0,totp=0;
    for (auto x : neg) totn-=x;
    for (auto x : pos) totp+=x;

  //  cerr << totn << " " << totp << el;

 
    int plen=pos.size(),nlen=neg.size();
    if (plen>0 && nlen>0){
        cout << totp + totn << el;

        int idp=plen-1,idn=0,tot1=pos[0];
        while (idn<nlen-1){
            cout << tot1 << " " << neg[idn] << el;
            tot1-=neg[idn];
            idn++;
        }

        int tot2=neg[nlen-1];
        while (idp>0){
            cout << tot2 << " " << pos[idp] << el;
            tot2-=pos[idp];
            idp--;
        }
        cout << tot1 << " " << tot2 << el;

        return 0;
    }
    if (plen>0){
        if (plen==1){
            cout << totp << el;
            return 0;
        } else{
            cout << totp-pos[0]-pos[0] << el;
            int tot1=pos[0],idn=1;
            while (idn<plen-1){
                cout << tot1 << " " << pos[idn] << el;
                tot1-=pos[idn]; 
                idn++;
            }
            cout << pos[plen-1] << " " << tot1 << el;

            return 0;
        }
    } else {
        if (nlen==1){
            cout << totn << el;
            return 0;
        } else{
            cout << totn+neg[0]+neg[0] << el;
            int tot1=neg[0],idn=1;
            while (idn<nlen-1){
                cout << tot1 << " " << neg[idn] << el;
                tot1-=neg[idn];
                idn++;
            }
            cout << tot1 << " " << neg[nlen-1] << el;

            return 0;
        }
    }

    return 0;
}