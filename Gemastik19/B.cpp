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

ll p2[61], p10[19];
ll mx;
string s;
ll cur;
int cnt=0;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=0;i<61;i++){
        p2[i]=((ll)1 << i);
    }

    p10[0]=1;
    for (int i=1;i<=18;i++){
        p10[i]=p10[i-1]*10;
    }

    cin >> mx >> s;
    int len=s.length();

    reverse(s.begin(),s.end());
    for (int i=0;i<len;i++){
        if (s[i]=='1') cur+=((ll)1 << i);
    }
//    cout << cur << el;
    reverse(s.begin(),s.end());

    ll carry=1;
    if (cur <= mx){
        cout << cnt << el;
        return 0;
    }
    for (int i=1;i<len;i++){
        //cout << s[i] << el;
        carry*=2;
        if (s[i]=='1'){
            cnt++;
            carry++;
            cur-=carry*p2[len-i-1];
        //    cout << i << el << el;;
            carry>>=1;
            cur+=carry*p2[len-i-1];
        } 
        //cout << cur << " " << carry << el;
        if (cur <= mx){
            cout << cnt << el;
            return 0;
        }
    }

    while (cur>mx){
        cnt++;
        cur/=2;
    }

    cout << cnt << el;

    return 0;
}