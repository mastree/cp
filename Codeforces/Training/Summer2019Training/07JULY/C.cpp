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

bool cekx[51],ceky[51];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int len=4*n+1;

    pii ar[len];
    vector <int> vxx,vyy;
    for (int i=0;i<len;i++){
        cin >> ar[i].fi >> ar[i].se;
        if (!cekx[ar[i].fi]){
            vxx.pb(ar[i].fi);
            cekx[ar[i].fi]=1;
        }

        if (!ceky[ar[i].se]){
            vyy.pb(ar[i].se);
            ceky[ar[i].se]=1;
        }
    }

    vector <int> vx,vy;
    if (vxx.size()>=4){
        int tm=vxx.size();
        vx.pb(vxx[0]);vx.pb(vxx[1]);
        vx.pb(vxx[tm-1]);vx.pb(vxx[tm-2]);
    } else{
        for (auto x : vxx) vx.pb(x);
    }

    if (vyy.size()>=4){
        int tm=vyy.size();
        vy.pb(vyy[0]);vy.pb(vyy[1]);
        vy.pb(vyy[tm-1]);vy.pb(vyy[tm-2]);
    } else{
        for (auto x : vyy) vy.pb(x);
    }


    for (auto xa : vx){
        for (auto xb : vx){
            if (xb<=xa) continue;
            for (auto ya : vy){
                for (auto yb : vy){
                    if (yb<=ya) continue;
                    int cnt=0,id=-1,cx1=0,cx2=0,cy1=0,cy2=0;
                    for (int i=0;i<len;i++){
                        if (ar[i].fi==xa || ar[i].fi==xb){
                            if (ar[i].se>=ya && ar[i].se<=yb){
                                if (ar[i].fi==xa) cx1++;
                                if (ar[i].fi==xb) cx2++;
                                if (ar[i].se==ya) cy1++;
                                if (ar[i].se==yb) cy2++;
                                continue;
                            }
                        }
                        if (ar[i].se==ya || ar[i].se==yb){
                            if (ar[i].fi>=xa && ar[i].fi<=xb){
                                if (ar[i].fi==xa) cx1++;
                                if (ar[i].fi==xb) cx2++;
                                if (ar[i].se==ya) cy1++;
                                if (ar[i].se==yb) cy2++;
                                continue;
                            }
                        }

                        cnt++;id=i;
                    }

                    if (cnt==1 && (cx1>=n && cx2>=n && cy1>=n && cy2>=n)){
                    //    cerr << el;
                    //    cerr << xa << " " << xb << el;
                    //    cerr << ya << " " << yb << el;
                        cout << ar[id].fi << " " << ar[id].se << el;
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}