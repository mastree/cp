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


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x,y;
    cin >> x >> y;

    int up=0,ri=0,len;
    string s;
    cin >> s;
    len=s.length();

    for (int i=0;i<len;i++){
        if (s[i]=='u') up++;
        else if (s[i]=='s') up--;
        else if (s[i]=='t') ri++;
        else ri--;
    }

    cout << x-ri << " " << y-up << el;

    return 0;
}