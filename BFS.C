#include<stdio.h>
 #define MAX 5

void bfs(int adj[][MAX],int visited[] ,int start)
{
    int queue[MAX],front=-1,rear=-1,i,k;
    for(k=0;k<MAX;k++)
    {
        visited[k]=0;

    }
    queue[++rear]=start;
    ++front;
    visited[start]=1;

    while(rear>=front)
    {
        start=queue[front++];
        printf("%c->",start+65);
        for(i=0;i<MAX;i++){
            if(adj[start][i]&&visited[i]==0){
                queue[++rear]=i;
                visited[i]=1;
            }
        }

    }

}
int main(){
int visited[MAX]={0};
    int adj[MAX][MAX],i,j,choice;

    printf("\n BFS traversal");
 


printf("\nEnter matrix values");{
                    for(i=0;i<MAX;i++){
                        for(j=0;j<MAX;j++){
                            scanf("%d",&adj[i][j]);
                        }
                    }
}
    printf("\nBFS traversal");
                    bfs(adj,visited,0);



     return 0;
}

