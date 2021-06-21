//
//  main.cpp
//  findPath
//
//  Created by Sethupathi on 17/03/20.
//  Copyright © 2020 Sethupathi. All rights reserved.
//

#include <iostream>
using namespace std;


void findPath(int maze[][20],int n, int x, int y, int path[][20])

{
    
    if(x<0 || x> n-1 || y<0 || y> n-1)
    {
        return;
    }
    
    if(x==n-1 &&  y==n-1)
    {
        path[x][y]=1;
   
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<path[i][j]<<" ";
                
            }
            
            cout<<endl;
        }
	cout<<endl;
        return;
}   

 
    if(maze[x][y]==0 || path[x][y]==1)
    {
        return;
    }
    
    path[x][y]=1;
     findPath(maze, n, x, y+1, path);
     findPath(maze, n, x, y-1, path);
     findPath(maze, n, x+1, y, path);
     findPath(maze, n, x-1, y, path);
	//when you have explored a path, reset that specific item so that you do not explore the same path again.
    path[x][y]=0;
}

void findPath(int maze[][20], int n)
{
    
    int path[20][20] = {0};
    findPath(maze, n, 0, 0, path);
}

int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    
    int n=3;
    int maze[20][20] = {{1,1,0},{1,1,0},{0,1,1}};
    findPath(maze, n);
    return 0;
}

