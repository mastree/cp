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

const int N = 1e5 + 11;

int ans = 0;
int ar[N], len;
string s;

int main () {   
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    len = s.length();
    int id = 0;
    bool mul = 0;
    for (int i=len-1;i>=0;i--){
        if (s[i]!=0){
            mul = 1;
        } 
        if (mul){
            ar[id] = (int)(s[i]-'0');
            id++;
        }
    }
    for (int i=0;i<id/2;i++){
        swap(ar[i], ar[id-i-1]);
    }
    // for (int i=0;i<id;i++)cout << ar[i];cout << el;

    for (int i=id;i<len+10;i++){
        if (ar[i] >= 10){
            ar[i+1] += ar[i]/10;
            ar[i] %= 10;
        }
        if (ar[i] > 5){
            ar[i+1]++;
            ar[i] = 10 - ar[i];
        }  
        // cout << ar[i] << " ";
        ans += ar[i];
    }
    // cout << el;
    cout << ans << el;

    return 0;
}