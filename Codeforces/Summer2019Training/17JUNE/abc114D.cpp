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

vector <int> v;


bool isPrime(int a){
    bool res=1;
    for (int i=2;i*i<=a;i++){
        if (a%i==0) res=0;
    }

    return res;
}

int fak(int t,int a){
    int res=0;
    int kal=a;
    while (t/a>0){
        res+=t/a;
        a*=kal;
    }

    return res+1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i=2;i+i<=n;i++){
        if (isPrime(i)){
            int tm=fak(n,i);
        //    cerr << i << " " << tm << el;
            if (tm>2) v.pb(tm);
        }
    }

    int len=v.size();
    ll cnt=0;

    for (int i=0;i<len-1;i++){
        for (int j=i+1;j<len;j++){
            for (int k=0;k<len;k++){
                if (k==i || k==j) continue;

                if (v[i]>=5 && v[j]>=5 && v[k]>=3) cnt++;
            }
        }
    }

    for (int i=0;i<len;i++){
        for (int j=0;j<len;j++){
            if (i==j) continue;
            if (v[i]>=25 && v[j]>=3) cnt++;
            if (v[i]>=15 && v[j]>=5) cnt++;
        }
    }

    for (int i=0;i<len;i++){
        if (v[i]>=75) cnt++;
    }

    cout << cnt << el;

    return 0;
}