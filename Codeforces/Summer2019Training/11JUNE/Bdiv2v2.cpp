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

    int h,w;
    cin >> h >> w;

    string s[h];
    for (int i=0;i<h;i++) cin >> s[i];

    int pc[h+1][w+1];
    for (int i=0;i<h+1;i++){
        for (int j=0;j<w+1;j++) pc[i][j]=0;
    }

    for (int i=1;i<=h;i++){
        for (int j=1;j<=w;j++){
            pc[i][j]=pc[i-1][j]+pc[i][j-1]-pc[i-1][j-1]+(s[i-1][j-1]=='*');
        }
    }

    bool fail=0;
    int x=-1,y=-1;
    for (int i=2;i<=h-1;i++){
        for (int j=2;j<=w-1;j++){
            if (pc[i-1][j-1]==0){
                if (pc[i-1][w]-pc[i-1][j]==0){
                    if (pc[h][j-1]-pc[i][j-1]==0){
                        if (pc[h][w]-pc[i][w]-pc[h][j]+pc[i][j]==0){
                            x=i;y=j;
                            break;
                        }
                    }
                }
            }
        }
    }
    if (x==-1){
        cout << "NO" << el;
        return 0;
    }

    if (!(s[x-1][y-1]=='*' && s[x][y-1]=='*' && s[x-1][y]=='*' && s[x-2][y-1]=='*' && s[x-1][y-2]=='*')){
        cout << "NO" << el;
        return 0;
    }

    char bef='.';
    int cnt=0;
    pair<int,int> r={-1,-1},c={-1,-1};
    for (int i=0;i<h;i++){
        if (s[i][y-1]!=bef){
            bef=s[i][y-1];
            cnt++;
            if (cnt==1) r.fi=i+1;
            else r.se=i+1;
        }
    }
    if (cnt==1) r.se=h;
    if (cnt>2 || (r.fi>x && r.se<x)) fail=1;

    bef='.';
    cnt=0;
    for (int i=0;i<w;i++){
        if (s[x-1][i]!=bef){
            bef=s[x-1][i];
            cnt++;
            if (cnt==1) c.fi=i+1;
            else c.se=i+1;
        }
    }
    if (cnt==1) c.se=w;
    if (cnt>2 || (c.fi>y && c.se<y)) fail=1;


    if (fail){
        cout << "NO" << el;
    } else cout << "YES" << el;

    return 0;
}