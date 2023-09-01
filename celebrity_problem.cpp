#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution 
{
    private:
    bool knows(vector<vector<int> >& M, int a, int b){
        if(M[a][b]==1){
            return true;
        }
        else{
            return false;
        }
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        
        //1. Push all elements in stack
        for(int i=0; i<n; i++){
            s.push(i);
        }
        
        //2. Finding potential celebrity
        while(s.size()>1){
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            if(knows(M,a,b)){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        int candidate=s.top();
        
        //3. Verifying potential candidate
        
        //row check
        bool rowCheck=false;
        int zeroCount=0;
        
        for(int i=0; i<n; i++){
            if(M[candidate][i]==0){
                zeroCount++;
            }
        }
        if(zeroCount==n){
            rowCheck=true;
        }
        
        //col ccheck
        bool colCheck=false;
        int oneCount=0;
        
        for(int i=0; i<n; i++){
            if(M[i][candidate]==1){
                oneCount++;
            }
        }
        if(oneCount==n-1){
            colCheck=true;
        }
        
        if(rowCheck==true && colCheck==true){
            return candidate;
        }
        else{
            return -1;
        }
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

