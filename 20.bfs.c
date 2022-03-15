#include<stdio.h>     //bfs
struct vertex{
int num;
int visit;
}Q[50],v[50],t;
int adj[50][50],n,f=-1,r=-1;
void addq(struct vertex v){
  r++;
  Q[r]=v;
}
struct vertex deleteq(){
   ++f;
   return(Q[f]);
}
int qempty(){
  if(f==r) return 1; else return 0;
}
void bfs(){
    int i;
    addq(v[1]); v[1].visit=1;
    while(!qempty()){
    t=deleteq();
    printf("V%d->",t.num);
    for(i=1;i<=n;i++)
    if(adj[t.num][i]==1 && v[i].visit==0){
    addq(v[i]);v[i].visit=1;
    }
  }
}
void read(){
  int i,ad;
  printf("Enter the Number of vertices\n");
  scanf("%d",&n);
for(i=1;i<=n;i++) {
  v[i].num=i;
  v[i].visit=0;
}
for(i=1;i<=n;i++){
    printf("Enter the list of vertices adjacent to v%d. Click (-1) to stop\n",i);
    while(1){
     scanf("%d",&ad);
    if(ad == -1) break;
    adj[i][ad]=1;
    }
  }
}
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
printf("Breadth First Search VisitList:\n");
bfs();
}
