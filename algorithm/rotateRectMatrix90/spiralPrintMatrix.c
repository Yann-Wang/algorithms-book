void printEdge(int m[][4],int tR,int tC,int dR,int dC);
void spiralOrderPrint(int matrix[][4],int row,int column){
    int tR = 0;
    int tC = 0;
    int dR = row - 1;
    int dC = column - 1;
    while(tR<=dR && tC<=dC){
        printEdge(matrix,tR++,tC++,dR--,dC--);
    }
    printf("\n");
}

void printEdge(int m[][4],int tR,int tC,int dR,int dC){
    if(tR == dR){
        int i;
        for(i=tC;i<dC;++i){
            printf("%d ",m[tR][i]);
        }
    }
    else if(tC == dC){
        int i;
        for(i=tR;i<=dR;++i){
            printf("%d ",m[i][tC]);
        }
    }
    else{
        int curC = tC;
        int curR = tR;

        while(curC != dC){
            printf("%d ",m[tR][curC]);
            curC++;
        }
        while(curR != dR){
            printf("%d ",m[curR][dC]);
            curR++;
        }
        while(curC != tC){
            printf("%d ",m[dR][curC]);
            curC--;
        }
        while(curR != tR){
            printf("%d ",m[curR][tC]);
            curR--;
        }
    }
}
