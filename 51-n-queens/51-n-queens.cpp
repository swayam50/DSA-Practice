class Solution {
public:
    
    void func(int col,int n, vector<vector<string>> &ans,vector<string> &board,
             vector<int> &leftRow ,vector<int> &upperDiagonal, vector<int> &lowerDiagonal){
        if(col==n){
            ans.push_back(board);
            return ;
        }
         
        for(int row = 0; row < n; row++){
            if(leftRow[row]==0 && upperDiagonal[n-1 + col - row] == 0 && lowerDiagonal[col+row]==0){
                board[row][col]='Q';
                leftRow[row]=1;
                upperDiagonal[n-1 + col - row] = 1;
                lowerDiagonal[row+col]=1;
                func(col+1,n,ans,board,leftRow,upperDiagonal,lowerDiagonal);
                
                //backtrack
                board[row][col]='.';
                leftRow[row]=0;
                upperDiagonal[n-1 + col - row] = 0;
                lowerDiagonal[row+col]=0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
         vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        int col=0;
        
        vector<int> leftRow(n,0) , upperDiagonal(2*n-1,0) , lowerDiagonal(2*n-1 , 0); 
        
        func(col,n,ans,board,leftRow,upperDiagonal,lowerDiagonal);
        
        return ans;
    }
};