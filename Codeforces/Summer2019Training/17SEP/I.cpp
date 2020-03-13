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

    int n=3,m=10;

    string s[3];
    for (int i=0;i<3;i++){
        cin >> s[i];
    }

    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<m;j++){
            if (s[i][j]=='=') break;
        }
        if (j!=m) break;
    }

    for (++j;j<m;j++){
        if (s[i][j]!='.') break; 
    }

    if (j!=m){
        cout << s[i][j] << el;
    } else{
        cout << "You shall pass!!!" << el;
    }

    return 0;
}