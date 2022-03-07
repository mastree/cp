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

const int N = 510;

int k;
int n, m;
int mat[N][N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    mat[1][1] = (1 << 18) - 1;
    int temp = log2(k) + 1;
    mat[1][2] = (1 << temp);
    mat[2][1] = k;
    mat[3][1] = 0;
    mat[2][2] = (k | (1 << temp));
    mat[3][2] = k;
    cout << 3 << " " << 2 << el;
    for (int i=1;i<=3;i++){
        for (int j=1;j<=2;j++){
            cout << mat[i][j] << " ";
        }
        cout << el;
    }

    return 0;
}