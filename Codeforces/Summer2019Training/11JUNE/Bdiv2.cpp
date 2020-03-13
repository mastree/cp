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

    string s[h+1];
    for (int i=0;i<h;i++){
        cin >> s[i];
        s[i].pb('.');
    }
    s[h]="";
    for(int i=0;i<w+1;i++){
        s[h].pb('.');
    }

    bool fail=0;

    pair<int,int> row[h];
    for (int i=0;i<h;i++){
        char bef='.';
        int cnt=0;
        row[i]={-1,-1};
        for (int j=0;j<w+1;j++){
            if (bef!=s[i][j]){
                bef=s[i][j];
                cnt++;
                if (cnt==1){
                    row[i].fi=j;
                } else {
                    row[i].se=j-1;
                }
            }
            if (cnt>2) fail=1;
        }
    }

    pair<int,int> col[w];
    for (int j=0;j<w;j++){
        char bef='.';
        int cnt=0;
        col[j]={-1,-1};
        for (int i=0;i<h+1;i++){
            if (bef!=s[i][j]){
                bef=s[i][j];
                cnt++;
                if (cnt==1){
                    col[j].fi=i;
                } else {
                    col[j].se=i-1;
                }
            }
            if (cnt>2) fail=1;
        }
    }

    if (fail){
        cout << "NO" << el;
        return 0;
    }

    int x=-1,y=-1;
    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            if (row[i].fi<j && row[i].se>j && col[j].fi<i && col[j].se>i){
                x=i;
                y=j;
            }
        }
    }
    if (x==-1){
        cout << "NO" << el;
        return 0;
    }

    for (int i=0;i<h;i++){
        if (i<col[y].fi || i>col[y].se){
            if (row[i].fi!=-1) fail=1;
        } else if (i!=x){
            if (row[i].fi!=row[i].se) fail=1;
        }
    }
    for (int i=0;i<w;i++){
        if (i<row[x].fi || i>row[x].se){
            if (col[i].fi!=-1) fail=1;
        } else if (i!=y){
            if (col[i].fi!=col[i].se) fail=1;
        }
    }

    if (fail){
        cout << "NO" << el;
        return 0;
    } 
    cout << "YES" << el;

    return 0;
}