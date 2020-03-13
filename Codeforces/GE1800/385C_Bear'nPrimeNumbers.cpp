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

const int N=1000008, PN=10000009;

int n,q;
int ar[N];
ll cnt[PN];
vector <int> sieve;
bool sv[PN];

void conssieve(){
    sv[1]=1;
    for (int i=2;i*i<PN;i++){
        if (sv[i]) continue;
        sieve.pb(i);
        for (int j=i*i;j<PN;j+=i){
            sv[j]=1;
        }
    }

}

bool ada[PN];
void sol(int a){
    vector <int> plus;
    int len=sieve.size();

    for (int i=0;(i<len) && (sieve[i]*sieve[i]<=a);i++){
        if (!sv[a]) break;
        if (a%sieve[i]==0){
            cnt[sieve[i]]++;
        }
        
        while (a%sieve[i]==0 && a>1){
            a/=sieve[i];
        }
    }

    if (!sv[a]){
        cnt[a]++;
        
    }

}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<n;i++){
        cin >> ar[i];
    }

    conssieve();

    for (int i=0;i<n;i++){
        sol(ar[i]);
    }

    for (int i=2;i<PN;i++){
        cnt[i]+=cnt[i-1];
    }

    cin >> q;

    while (q--){
        int l,r;
        cin >> l >> r;
        if (l>=PN){
            cout << 0 << el;
            continue;
        }
        r=min(r,PN-1);
        cout << cnt[r]-cnt[l-1] << el;
    }

    return 0;
}   