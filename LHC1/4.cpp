//Ans_4
#include<iostream>
using namespace std;
int main()
{
    int matrix[3][3]
    {
        {11,2,4},
        {4,5,6},
        {10,8,-12},
        
    };
    int leftsum=0,rightsum=0;
    int n=sizeof(matrix)/sizeof(matrix[0]);
    for(int i=0;i<n;i++)
    {
        leftsum=leftsum+matrix[i][i];
        rightsum=rightsum+matrix[i][n-i-1];
    }
    cout<<"leftsum= "<<leftsum<<endl;
    cout<<"rightsum= "<<rightsum<<endl;
    cout<<"Absolut= "<<abs(leftsum-rightsum)<<endl;
    
    
}