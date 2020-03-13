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

const int N = 200010;

int n;
int ar[500][500];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int cur=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cur++;
            if (i&1) ar[j][i]=cur;
            else ar[n-j+1][i]=cur;
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cout << ar[i][j] << " ";
        }
        cout << el;
    }

    return 0;
}