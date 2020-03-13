#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1000000007100000000
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 50010;

struct hue{
    ll x,y,z;
    int id;
};

int n;
hue ar[N];
map <ll,int> cntx;
map <pair<ll,ll>,int> cnty;

bool cmp(hue a, hue b){
    if (a.x<b.x){
        return true;
    } else if (a.x>b.x){
        return false;
    }

    if (a.y<b.y){
        return true;
    } else if (a.y>b.y){
        return false;
    }

    if (a.z<b.z){
        return true;
    }
    return false;
}

ll jarak(hue a, hue b){
    ll delx=a.x-b.x;
    ll dely=a.y-b.y;
    ll delz=a.z-b.z;
    return delx*delx+dely*dely+delz*delz;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i].x >> ar[i].y >> ar[i].z;
        ar[i].id=i;
        cntx[ar[i].x]++;
        cnty[mp(ar[i].x,ar[i].y)]++;
    }

    sort(ar+1,ar+n+1,cmp);
    for (int i=1;i<=n;i+=2){
        if (ar[i].x!=ar[i+1].x){
            int byk=cntx[ar[i+1].x];
            if (byk>1){
                ll dist=INF;
                int cid=0;

                for (int plus=0;plus<byk;plus++){
                    ll tm=jarak(ar[i],ar[i+1+plus]);
                    if (tm<dist){
                        dist=tm;
                        cid=i+1+plus;
                    }
                }

                while (cid>i+1){
                    swap(ar[cid],ar[cid-1]);
                    cid--;
                }
            }
        } else if (ar[i].y!=ar[i].y){
            int byk=cnty[mp(ar[i+1].x,ar[i+1].y)];
            if (byk>1){
                ll dist=INF;
                int cid=0;

                for (int plus=0;plus<byk;plus++){
                    ll tm=jarak(ar[i],ar[i+1+plus]);
                    if (tm<dist){
                        dist=tm;
                        cid=i+1+plus;
                    }
                }

                while (cid>i+1){
                    swap(ar[cid],ar[cid-1]);
                    cid--;
                }
            }
        } 
        cout << ar[i].id << " " << ar[i+1].id << el;
        cntx[ar[i].x]--;
        cntx[ar[i+1].x]--;
        cnty[mp(ar[i].x,ar[i].y)]--;
        cnty[mp(ar[i+1].x,ar[i+1].y)]--;
    }

    

    return 0;
}