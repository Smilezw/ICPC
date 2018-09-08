//fill 函数的使用  可用memset  3f 代替 
//深搜  转弯数组的使用 
//hdu 1175 
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int maxn=1005,inf=1<<30;  

int n,m;
int Map[maxn][maxn],turn[maxn][maxn];  
bool flag;  
int q,sx,sy,ex,ey;  
int dir[][2]={  {0,1},{-1,0},{0,-1},{1,0}  };  

void dfs(int x,int y, int cnt ,int f){
	if(cnt<=2 && x==ex && y==ey ){ flag=1; return;}
	
	for(int i=0;i<4;i++){
		int dx=x+dir[i][0],dy=y+dir[i][1];
		if(1<=dx && dx<=n && 1<=dy && dy<=m &&(Map[dx][dy]==0||(dx==ex&&dy==ey))){
			if(i==f||f==-1){
				turn[dx][dy]=cnt;  
                dfs(dx,dy,cnt,i);   //保存变量  
                if(flag) return ;    //结束标志 
			}
			else if(cnt<2&&turn[dx][dy]>turn[x][y]){
				turn[dx][dy]=cnt+1;
				dfs(dx,dy,cnt+1,i);
				if(flag) return;
			}
		}
		    
	}
}

int main(){
	 while(cin>>n>>m&&(n+m))  
    {  
        for(int i=1;i<=n;i++)  
            for(int j=1;j<=m;j++)  
            cin>>Map[i][j];  
        cin>>q;  
        for(int i=0;i<q;i++)  
        {  
            cin>>sx>>sy>>ex>>ey;  
            if(Map[sx][sy]!=Map[ex][ey]) {cout<<"NO"<<endl;continue;}  
            if(Map[sx][sy]==0) {cout<<"NO"<<endl;continue;}  
            flag=0;  
            fill(&turn[0][0],&turn[maxn][0],inf);
            dfs(sx,sy,0,-1);  
            if(flag) cout<<"YES"<<endl;  
            else cout<<"NO"<<endl;  
        }  
    }  
    return 0;  
}