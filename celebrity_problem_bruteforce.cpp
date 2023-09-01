#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int ans=0;
        
        // Loop through each person (i) and check if they know anyone (j).
        for(int i=0; i<n; i++){
            bool rowCheck=true; // Initialize to true
            int rowCount=0;
            for(int j=0; j<n; j++){
                if(M[i][j]==0){
                    rowCount++;
                }
                else{
                    rowCheck=false;
                    break;
                }
            }
            if(rowCount==n){
                rowCheck=true;
                ans=i;
                break; // No need to continue checking
            }
        }
        
        // Loop through each person (i) again and check if the potential celebrity (ans) knows them (i).
        int colCount=0; // Initialize outside the loop
        for(int i=0; i<n; i++){
            bool colCheck=false;
            if(M[i][ans]==1){
                colCount++;
            }
        }
        
        if(colCount==n-1){ // Moved the condition outside the loop
            return ans;
        }
        
        return -1;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

