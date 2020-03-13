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

int n,m,k;
vector <pii> obs, sortR, sortC;
//map<int,int> cntR, cntC;
pii batesR, batesC;

ll sisa, need;

// pii rotate(int times){
//     times%=4;

//     if ()
// }

void sol(pii bR, pii bC, int rot){
    // cout << "Row : " << bR.fi << ", " << bR.se << el;
    // cout << "Col : " << bC.fi << ", " << bC.se << el;
    // cout << "Need : " << need  << ", Rotation : " << rot << el;
    // cout << "+++++++++++" << el;
    rot%=4;
    if (rot==0){
        pii pos=mp(bR.fi, bC.fi);
        auto tm = lower_bound(sortR.begin(), sortR.end(), pos);
    //    cout << pos.fi << " " << pos.se << " " << (*tm).fi << " " << (*tm).se << el;
        if (tm!=sortR.end()){
            if ((*tm)==pos){
                need+=(ll)(bR.se-bR.fi+1)*(ll)(bC.se-bC.fi+1);
                return;
            }
        }
        if (bR.fi>bR.se || bC.fi>bC.se) return;
        int a=bR.fi;
        auto it = lower_bound(sortR.begin(), sortR.end(), pos);
        if (it==sortR.end() || (*it).se>bC.se || (*it).se<bC.fi || (*it).fi!=a){
            bR.fi++;
            sol(bR, bC, ++rot);
        } else{
        //    cout << it->fi << " " << it->se << el;
            need+=(ll)(bC.se-(*it).se+1)*(ll)(bR.se-bR.fi+1);
            bR.fi++;
            bC.se=(*it).se-1;
            sol(bR, bC, ++rot);
        }
    } else if (rot==1){
        pii pos=mp(bC.se, bR.fi);
        auto tm = lower_bound(sortC.begin(), sortC.end(), pos);
        if (tm!=sortC.end()){
            if ((*tm)==pos){
                need+=(ll)(bR.se-bR.fi+1)*(ll)(bC.se-bC.fi+1);
                return;
            }
        }
        if (bR.fi>bR.se || bC.fi>bC.se) return;
        int a=bC.se;
        auto it = lower_bound(sortC.begin(), sortC.end(), mp(a,bR.fi));
        if (it==sortR.end() || (*it).se>bR.se || (*it).se<bR.fi || (*it).fi!=a){
            bC.se--;
            sol(bR, bC, ++rot);
        } else{
            need+=(ll)(bR.se-(*it).se+1)*(ll)(bC.se-bC.fi+1);
            bC.se--;
            bR.se=(*it).se-1;
            sol(bR, bC, ++rot);
        }
    } else if (rot==2){
        pii pos=mp(bR.se, bC.se);
        auto tm = lower_bound(sortR.begin(), sortR.end(), pos);
        if (tm!=sortR.end()){
            if ((*tm)==pos){
                need+=(ll)(bR.se-bR.fi+1)*(ll)(bC.se-bC.fi+1);
                return;
            }
        }
        if (bR.fi>bR.se || bC.fi>bC.se) return;
        int a=bR.se;
        auto it = upper_bound(sortR.begin(), sortR.end(), mp(a,bC.fi));
        it--;
        if (it==sortR.end() || (*it).se>bC.se || (*it).se<bC.fi || (*it).fi!=a){
            bR.se--;
            sol(bR, bC, ++rot);
        } else{
            need+=(ll)((*it).se-bC.fi+1)*(ll)(bR.se-bR.fi+1);
            bR.se--;
            bC.fi=(*it).se+1;
            sol(bR, bC, ++rot);
        }
    } else if (rot==3){
        pii pos=mp(bC.fi, bR.se);
        auto tm = lower_bound(sortC.begin(), sortC.end(), pos);
    //    cout << pos.fi << " " << pos.se << " " << (*tm).fi << " " << (*tm).se << el;
        if (tm!=sortC.end()){
            if ((*tm)==pos){
                need+=(ll)(bR.se-bR.fi+1)*(ll)(bC.se-bC.fi+1);
                return;
            }
        }
        if (bR.fi>bR.se || bC.fi>bC.se) return;
        int a=bC.fi;
        auto it = upper_bound(sortC.begin(), sortC.end(), mp(a,bC.fi));
        it--;
        if (it==sortC.end() || (*it).se>bR.se || (*it).se<bR.se || (*it).fi!=a){
            bC.fi++;
            sol(bR, bC, ++rot);
        } else{
            need+=(ll)((*it).se-bR.fi+1)*(ll)(bC.se-bC.fi+1);
            bC.fi++;
            bR.fi=(*it).se+1;
            sol(bR, bC, ++rot);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    sisa=k;
    batesR=mp(1,n);
    batesC=mp(1,m);

    for (int i=0;i<k;i++){
        int a, b;
        cin >> a >> b;
        sortR.pb(mp(a,b));
        sortC.pb(mp(b,a));
    //    cntR[a]++;
    //    cntC[b]++;
    }

    sort(sortR.begin(), sortR.end());
    sort(sortC.begin(), sortC.end());

    sol(batesR,batesC,0);

//    cout << need << el;
    if (need > sisa) {
        cout << "NO" << el;
    } else{
        cout << "YES" << el;
    }

    return 0;
}