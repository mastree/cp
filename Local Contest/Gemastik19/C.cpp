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

int a,b;
int m,n;
vector <int> inp;
int w[100][100];
ll dp[100][100];
queue <pii> qu; // node, depth
ll ans=0;

int sqr(int a){
    int i;
    for (i=1;i*i<=a;i++){
    }

    if (i*i>a) i--;
    return i;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> m;

    int cc;
    while (cin >> cc){
        inp.pb(cc);
    }

    int len=inp.size();
    n=sqr(len);
    int id=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            w[i][j]=inp[id];
            id++;
    //        cerr << w[i][j] << " ";
        }
    //    cerr << el;
    }

    dp[a][0]=1;
    for (int i=0;i<m;i++){ // depth
        for (int j=0;j<n;j++){ // row
            for (int k=0;k<n;k++){ // col
                if (w[j][k]) dp[k][i+1]+=dp[j][i];
            }
        }
    }

    cout << dp[b][m] << el;


    return 0;
}