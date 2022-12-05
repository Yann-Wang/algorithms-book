#include<stdio.h>
#define maxSize 7
#define INF 65535

typedef struct MGraph{
    int n;
    int edges[maxSize][maxSize];
} MGraph;


void printfPath(int path[], int a){
    int stack[maxSize],top=-1;

    while(path[a]!=-1){
        stack[++top]=a;
        a=path[a];
    }
    stack[++top]=a;
    while(top!=-1){
        printf("%d ",stack[top--]);
    }
    printf("\n");

}

void Dijkstra(MGraph g, int v, int dist[],int path[]){
    int set[maxSize];
    int min,i,j,u;
    for(i=1;i<=g.n;++i){
        dist[i]= g.edges[v][i];
        set[i]=0;
        if(g.edges[v][i]<INF)
            path[i]=v;
        else
            path[i]=-1;
    }
    set[v]=1;
    path[v]=-1;

    for(i=1;i<=g.n;++i){
        min=INF;
        for(j=1;j<=g.n;++j)
            if(set[j]==0&&dist[j]<min){
                u=j;
                min=dist[j];
            }
        set[u]=1;

        for(j=1;j<=g.n;++j){
            if(set[j]==0&&dist[u]+g.edges[u][j]<dist[j]){
                dist[j]= dist[u]+g.edges[u][j];
                path[j]=u;
            }
        }

    }
}

void main(){
    int dist[maxSize+1];
    int path[maxSize+1];
    int i;
    MGraph g={7,
        0,4,6,6,INF,INF,INF,
        INF,0,1,INF,7,INF,INF,
        INF,INF,0,INF,6,4,INF,
        INF,INF,2,0,INF,5,INF,
        INF,INF,INF,INF,0,INF,6,
        INF,INF,INF,INF,INF,1,0,8,
        INF,INF,INF,INF,INF,INF,INF
        };

    Dijkstra(g,0,dist,path);

    for(i=1;i<g.n;++i){
        printfPath(path,i);
    }
}
