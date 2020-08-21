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

string s[9];
int n;

bool cek(int r1,int c1,int r2,int c2){
    int cnt=0;

    for (int i=r1;i<=r2;i++){
        for (int j=c1;j<=c2;j++){
            if (s[i][j]=='0') cnt++;
        }
    }

    return (cnt==(r2-r1+1)*(c2-c1+1));
}

char sol(int col){
    bool u=cek(1,col+1,1,col+4);
    bool d=cek(7,col+1,7,col+4);
    bool l=cek(1,col+1,7,col+1);
    bool r=cek(1,col+4,7,col+4);

    if (u&&d&&l&&r) return 'B';
    if (r) return 'A';
    if (d) return 'C';
    return ' ';
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    

    for (int i=0;i<9;i++){
        cin >> s[i];
    }

    n=s[0].length()/5;

    int col=0;
    for (int i=0;i<n;i++){
        cout << sol(col);
        col+=5;
    }
    cout << el;

    return 0;
}