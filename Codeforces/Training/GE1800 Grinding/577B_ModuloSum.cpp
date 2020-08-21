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

const int N=1000007;

int n,m;
int ar[N];
bitset<1000> bit, net;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=0;i<n;i++){
        int a;
        cin >> a;
        ar[i]=a%m;
        if (ar[i]==0){
            cout << "YES" << el;
            return 0;
        }
    }

    if (m<n){
        cout << "YES" << el;
        return 0;
    }

    for (int i=0;i<m;i++){
        net[i]=1;
    }

    for (int i=0;i<n;i++){
        bit = (bit | (bit << ar[i]) | (bit >> (m-ar[i])));
        bit[ar[i]]=1;
        bit&=net;
       // cout << bit << el;
        if (bit[0]){
            cout << "YES" << el;
            return 0;
        }
    }

    cout << "NO" << el;

    return 0;
}