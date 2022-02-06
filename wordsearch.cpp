class Solution {
public:
    int n,m;
    
    bool solve(int idx,int i,int j,vector<vector<char>>& board,string word){
        if(idx==word.size()) return 1;
        
        if(i==n || i<0 || j==m || j<0) return 0;
        if(board[i][j]!=word[idx]) return 0;
        char c=board[i][j];
        board[i][j]='$';
        bool left = solve(idx+1,i,j-1,board,word);
        bool right=solve(idx+1,i,j+1,board,word);
        bool top=solve(idx+1,i-1,j,board,word);
        bool down = solve(idx+1,i+1,j,board,word);
        board[i][j]=c;
        return left||right||top||down;
    }
    bool exist(vector<vector<char>>& board, string word) {
       n=board.size();
        m=board[0].size();
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++){
                bool ans = solve(0,i,j,board,word);
                if(ans==1) return 1;
                
            }
        }
        return 0;
        
    }
};