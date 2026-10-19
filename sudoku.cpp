#include <iostream>
#define N 9
using namespace std;

bool isSafe(int grid[N][N], int row, int col, int num){
    for(int x=0; x<N; x++) if(grid[row][x]==num) return false;
    for(int x=0; x<N; x++) if(grid[x][col]==num) return false;
    int sr=row-row%3, sc=col-col%3;
    for(int i=0;i<3;i++) for(int j=0;j<3;j++)
        if(grid[i+sr][j+sc]==num) return false;
    return true;
}

bool solve(int grid[N][N]){
    int row=-1,col=-1; bool empty=true;
    for(int i=0;i<N;i++){ for(int j=0;j<N;j++) if(grid[i][j]==0){ row=i; col=j; empty=false; break; } if(!empty) break; }
    if(empty) return true;
    for(int num=1; num<=9; num++){
        if(isSafe(grid,row,col,num)){
            grid[row][col]=num;
            if(solve(grid)) return true;
            grid[row][col]=0;
        }
    }
    return false;
}

int main(){
    int grid[N][N] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    if(solve(grid)){
        cout << "Solved Sudoku:\n";
        for(int i=0;i<N;i++){ for(int j=0;j<N;j++) cout << grid[i][j] << " "; cout << endl; }
    } else cout << "No solution exists";
    return 0;
}