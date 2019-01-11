#include<cstdio>
#include<vector>

using namespace std;
int dp[301][301];
int num[301][301];

int main(){
   int N, M;
   int K, before, input; 

   scanf("%d %d", &N, &M);


   for(int i=1; i<=N; i++){
      for(int j=1; j<=M; j++)
         scanf("%d", &num[i][j]);
   }
   
   dp[1][1] = num[1][1];

   for(int i=2; i<=M; i++)
      dp[1][i] = dp[1][i-1] + num[1][i];

   for(int i=2; i<=N; i++)
      dp[i][1] = dp[i-1][1] + num[i][1];

   for(int i=2; i<=N; i++){
      for(int j=2; j<=M; j++){
         dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+num[i][j];
      }
      
   }
   scanf("%d", &K);
   
   int u, v, x, y;
   int result;
   for(int i=0; i<K; i++){
      scanf("%d %d %d %d",&u, &v, &x, &y);

      if( u == x && v == y)
         printf("%d\n", num[u][v]);
      else if(u == 1 && v == 1)
         printf("%d\n", dp[x][y]);
      else{
		result = dp[x][y]-dp[x][v-1]-dp[u-1][y]+dp[u-1][v-1];
		printf("%d\n", result);
      }
   }

   return 0;
}