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

int n;
string s[1005],op;
string temp[1005];

char rot(char c){
    if (c=='.') return c;
    if (c=='^') return '>';
    if (c=='>') return 'v';
    if (c=='v') return '<';
    return '^';
}

void show(){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout << s[i][j];
        } cout << el;
    }
}

void rotateR(){
    for (int i=n-1;i>=0;i--){
        for (int j=0;j<n;j++){
            temp[j][n-i-1]=rot(s[i][j]);
        }
    }

    for (int i=0;i<n;i++) s[i]=temp[i];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> op;

    for (int i=0;i<n;i++){
        cin >> s[i];
        temp[i]=s[i];
    }

    int len=op.length(),rop=0;
    for (int i=0;i<len;i++){
        if (op[i]=='R') rop++;
        else rop--;
    }

    rop%=4;
    if (rop<0){
        rop*=-3;
        rop%=4;
    }

    for (int i=0;i<rop;i++){
        rotateR();
    }

    show();

    return 0;
}