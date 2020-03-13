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

const int N = 2008;

int n;
int ar[N][N];
map <pii, bool> cek; // key = val from root, root; 

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> ar[i][j];
            if (i==j && ar[i][j]){
                cout << "NO" << el;
                return 0;
            }
            if (i==1){
                cek[mp(ar[i][j], j)]=1;
            }
        }
    }

    bool bisa=1;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (ar[i][j]!=ar[j][i]){
                cout << "NO" << el;
                return 0;
            }

        }
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            int a=ar[1][i];
            int b=ar[1][j];
            int del=((a+b)-ar[i][j])/2;

            if (cek[mp()]){
                
            } else{
                cout << "NO" << el;
                return 0;
            }

        }
    }

    return 0;
}