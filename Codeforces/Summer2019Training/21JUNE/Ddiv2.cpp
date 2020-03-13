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

map <pair<int,int>,int> cek;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;
    bool udh[n][m];


    for (int i=1;i<=n/2;i++){
        for (int j=1;j<=m;j++){
            if (i%2){
                cout << i << " " << j << el;
                cout << n-i+1 << " " << m-j+1 << el;
            } else{
                cout << i << " " << m-j+1 << el;
                cout << n-i+1 << " " << j << el;
            }
        }
    }
    
    if (n%2){
        for (int i=1;i<=(m+1)/2;i++){
            if (i==(m+1)/2){
                cout << n/2+1 << " " << i << el;
                break;
            }
            cout << n/2+1 << " " << i << el;
            cout << n/2+1 << " " << m-i+1 << el;
        }
    }

    return 0;
}