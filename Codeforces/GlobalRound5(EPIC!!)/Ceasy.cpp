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

const int N = 2010;

struct hue{
    ll x,y,z;
    int id;
};

int n;
hue ar[N];
vector <pair<ll,pii>> v; // dist, id-pair

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
    } else{
        return false;
    }
}

bool cek[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i].x >> ar[i].y >> ar[i].z;
        ar[i].id=i;
    }

    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            ll dist=0;
            ll delx=ar[i].x-ar[j].x;
            ll dely=ar[i].y-ar[j].y;
            ll delz=ar[i].z-ar[j].z;
            dist=delx*delx+dely*dely+delz*delz;

            v.pb(mp(dist,mp(i,j)));
        }
    }

    sort(v.begin(),v.end());
    for (auto point : v){
        if (cek[point.se.fi] || cek[point.se.se]) continue;
        cout << point.se.fi << " " << point.se.se << el;
        cek[point.se.fi]=1;
        cek[point.se.se]=1;
    }

    return 0;
}