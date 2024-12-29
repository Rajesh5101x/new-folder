#include<stdio.h>

void reco(int maze[6][5], int path[6][5], int i, int j){
    if(i == 5 && j == 4){
        path[i][j] = 1;
        for(i = 0; i < 6; i++){
            for(j = 0; j < 5; j++){
                printf("%d ",path[i][j]);
            }
            printf("\n");
        }
        path[i][j] = 0;
        return ;
    }
    path[i][j] = 1;
    if (i + 1 < 6 && maze[i + 1][j] != 0 && path[i + 1][j] == 0) {
        reco(maze, path, i + 1, j);
    }

    if (j + 1 < 5 && maze[i][j + 1] != 0 && path[i][j + 1] == 0) {
        reco(maze, path, i, j + 1);
    }

    if (j - 1 >= 0 && maze[i][j - 1] != 0 && path[i][j - 1] == 0) {
        reco(maze, path, i, j - 1);
    }

    if (i - 1 >= 0 && maze[i - 1][j] != 0 && path[i - 1][j] == 0) {
        reco(maze, path, i - 1, j);
    }

    path[i][j] = 0;
}

void main(){
    int maze[6][5] = {
    {1, 1, 1, 1, 0},
    {0, 0, 0, 1, 0},
    {1, 1, 0, 1, 0},
    {1, 1, 1, 1, 0},
    {1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1}};
    int path[6][5] = {0};
    reco(maze, path, 0, 0);
}