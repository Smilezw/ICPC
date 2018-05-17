// 初始化的小技巧    light oj 筛因数
 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 5 ;
const int INF = 0x3f3f3f3f;
int a[MAXN];
 
int main (){
    int T; cin >> T;
    int  t = 0;
    while (T--){
        int P ,L;
        scanf("%d%d", &P, &L);
        int n = P - L;
        int ans = 0;
        int flag = 0;
        if(L >= n) { printf("Case %d: impossible\n", ++t); continue;}
        for(int i = 1;  i <= (int)sqrt(n); i++){
            if(n % i == 0)
                a[ans++] = i;
            if(i > L) flag = 1;
            if((n / i) > L) flag = 1;
        }
        if(flag == 0) {printf("Case %d: impossible\n", ++t); continue; }
        printf("Case %d:", ++t);
        for(int i = 0; i < ans; i++){
            if(a[i] > L) printf(" %d", a[i]);
        }
        if(a[ans - 1]* a[ans - 1] == n) ans--;
        for(int i = ans -1; i >= 0; i--){
            if( (n/a[i]) > L) printf(" %d", n/a[i]);
        }
        printf("\n");
    }
    return 0;
    //system("pause");
}