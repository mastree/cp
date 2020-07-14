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

int ar1[100100],ar2[100100],cnt[100100];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin >> n >> k;

    for (int i=0;i<n;i++){
        cin >> ar1[i];
        cnt[ar1[i]]++;
    }

    for (int i=0;i<n;i++){
        cin >> ar2[i];
        cnt[ar2[i]]++;
    }

    int mk=0;
    for (int i=1;i<=100000;i++){
        mk=max(mk,cnt[i]-n);
    }

 //   cerr << mk << el;
    if (mk<=k) cout << "Ya" << el;
    else cout << "Tidak" << el;

    return 0;
}