#include <stdio.h> //dfs
struct vertex{
int num;
int visit;
}S[50],v[50],t;
int adj[50][50],n,top=-1;
void push(struct vertex v){
  top++;
  S[top]=v;
}
struct vertex pop(){
  return(S[top--]);
}
int sempty(){
if(top==-1) return 1; else return 0;
}
void dfs(){
  int i;
  push(v[1]);v[1].visit=1;
  while(!sempty()){
  t=pop();
  printf("V%d->",t.num);
  for(i=n;i>=1;i--)
  if(adj[t.num][i]==1 && v[i].visit==0){
    push(v[i]);v[i].visit=1;}
   }
}
void read(){
  int ad,i;
  printf("Enter the Number of vertices\n");
  scanf("%d",&n);
    for(i=1;i<=n;i++){
      v[i].num=i;v[i].visit=0;
    }
    for(i=1;i<=n;i++){
        printf("Enter the list of vertices adjacent to v%d. Click (-1) to stop\n",i);
    while(1){
        scanf("%d",&ad);
        if(ad==-1) break;
        adj[i][ad]=1;
    }
  }
}//end of read
void disp(){
printf("Adjacency Matrix..\n");
for(int i=1;i<=n;i++){
  for(int j=1;j<=n;j++)
  printf("%5d",adj[i][j]);
 printf("\n");
 }
}
void main(){
  read();
  disp();
  printf("Depth First Search VisitList: \n");
  dfs();
}
