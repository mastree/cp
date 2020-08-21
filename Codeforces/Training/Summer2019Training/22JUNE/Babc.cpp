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


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,l;
    cin >> n >> l;
    int ar[n],tot=0;
    for (int i=0;i<n;i++){
        ar[i]=i+l;
        tot+=ar[i];
    }

    int mn=MOD,id=0;
    for (int i=0;i<n;i++){
        if (abs(ar[i])<mn){
            mn=abs(ar[i]);
            id=i;
        }
    }

    cout << tot-ar[id] << el;

    return 0;
}