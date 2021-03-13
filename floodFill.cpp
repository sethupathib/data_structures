//flood fill algorithm
//very useful algorithm on array's
#include<bits/stdc++.h>
#include <list>
#include <algorithm>
#include <map>

using namespace std;

int R,C;

void printMat(char input[][50]){

    for (int i = 0; i < R; ++i)

    {
        for (int j= 0; i < C; ++j)
        {
            cout<<input[i][j];
        }
        cout<<endl;
    }
}

//W,N,E,S
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};




void floodFill(char mat[][50],int i, int j, char ch, char color){

    //base case
    if(i<0 || j<0 || i>=R || j>=C){
        return;
    }

    //edge case

    if(mat[i][j]!= ch){
        return;
    }

    //recursive case

    mat[i][j] = color;
    printMat(mat);

    for(int k=0;k<4;k++){
        floodFill(mat,i+dx[k],j+dy[k],ch,color);
    }
}

int main(){
    //row and column
    cin>>R>>C;
    char input_array[15][50];
    for(int i=0;i<R;i++){
        for(j=0;j<C;j++){
            cin>>input_array[i][j];
        }
    }
    printMat(input_array);
    floodFill(input_array,8,13,'.','r');
    floodFill(input_array,0,0,'.','!');

    printMat(input_array);

    
    return 0;
}
