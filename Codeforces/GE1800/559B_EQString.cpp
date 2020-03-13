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

string sa,sb;

bool sol(int a,int b,int a2,int b2){
    int len=b-a+1;
    bool sama=1;
    if (len%2){
        for (int i=0;i<len;i++){
            if (sa[a+i]!=sb[a2+i]) sama=0;
        }

        if (sama) return 1;
        else return 0;
    }
    else {
        bool res1 = (sol(a,len/2+a-1,a2,len/2+a2-1) && sol(len/2+a,b,len/2+a2,b2));
        if (res1) return 1;
        bool res2 = (sol(a,len/2+a-1,len/2+a2,b2) && sol(len/2+a,b,a2,len/2+a2-1));
    //    cerr << res1 << " " << res2 << el;
        return res2;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> sa >> sb;

    int len=sa.length();
    bool ans = sol(0,len-1,0,len-1);
    if (ans) cout << "YES" << el;
    else cout << "NO" << el;

    return 0;
}