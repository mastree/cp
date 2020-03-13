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

int t;
double center[3], rad;
double s[3], t[3];

double dist(double a[3], double b[3]){
    double res = 0;
    for (int i=0;i<3;i++){
        double temp = b[i] - a[i];
        res += temp * temp;
    }

    return sqrt(res);
}

double[3] 

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--){
        cin >> center[0] >> center[1] >> center[2] >> r;
        for (int i=0;i<3;i++){
            cin >> s[i];
        }
        for (int i=0;i<3;i++){
            cin >> t[i];
        }


    }

    return 0;
}