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

vector <char> le,ri;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string tm,s="0";
    cin >> tm;
    s+=tm;

    int n=s.length()-1;
    int cnt=0,l=1,r=n;
    
    while (l<r){
    //    cerr << l << " " << r << el;
        if (r-l<3){
            le.pb(s[l]);
        //    cerr << "tes" << el;
            break;
        }

        bool udh=0;
        for (int pl=0;pl<=1;pl++){
            
            for (int mr=0;mr<=1;mr++){
                if (s[l+pl]==s[r-mr]){
                 //   cerr << l+pl << " " << r-mr << el;
                    le.pb(s[l+pl]);
                    ri.pb(s[r-mr]);
                    l=l+pl+1;
                    r=r-(mr+1);
                    udh=1;
                    break;
                }
            }
            if (udh) break;
        }
    }

    for (auto x : le) cout << x;
    reverse(ri.begin(),ri.end());
    for (auto x : ri) cout << x;
    cout << el;

    return 0;
}