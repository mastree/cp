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

const int N = 100007;

int n;
ll arr[N];
ll k;
map <ll,ll> cek;
vector <ll> ar;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=0;i<n;i++){
        cin >> arr[i];
        cek[arr[i]]++;
    }

    for (auto x : cek){
        ar.pb(x.fi);
    }

    n=ar.size();    
    int idmin=0, idmax=n-1;
    bool masih=1;

    while (masih && idmin!=idmax && k){
        ll cntmin=cek[ar[idmin]];
        ll cntmax=cek[ar[idmax]];
    //    cout << ar[idmin] << " " << ar[idmax] << el;

        if (cntmin<=cntmax){
            ll jalanmk=k/cntmin;
            if (k>=cntmin*(ar[idmin+1]-ar[idmin])){
                k-=cntmin*(ar[idmin+1]-ar[idmin]);
                idmin++;
                cek[ar[idmin]]+=cntmin;
            } else{
                cek[ar[idmin]+jalanmk]=cntmin;
                ar[idmin]+=jalanmk;
                k-=cntmin*jalanmk;
            }
            if (jalanmk==0) masih=0;
        } else{
            ll jalanmk=k/cntmax;
            if (k>=cntmax*(ar[idmax]-ar[idmax-1])){
                k-=cntmax*(ar[idmax]-ar[idmax-1]);
                idmax--;
                cek[ar[idmax]]+=cntmax;
            } else{
                cek[ar[idmax]-jalanmk]=cntmax;
                ar[idmax]-=jalanmk;
                k-=cntmax*jalanmk;
            }
            if (jalanmk==0) masih=0;
        }
    }

    cout << ar[idmax]-ar[idmin] << el;

    return 0;
}