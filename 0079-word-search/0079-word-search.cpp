class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();
        int index;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(solve(board,word,i,j,0))
                return true;
            }
        }
        return false;
    }
    bool solve(vector<vector<char>>& board, string word,int i,int j,int index){
        if(index==word.size()){
            return true;
        }
        if(i<0 ||j<0 ||i>=board.size() || j>=board[0].size() || board[i][j]!=word[index]){
            return false;
        }
        char temp=board[i][j];
        board[i][j]='#';
        bool up = solve(board, word, i-1, j, index+1);
        bool down = solve(board, word, i+1, j, index+1);
        bool left = solve(board, word, i, j-1, index+1);
        bool right = solve(board, word, i, j+1, index+1);
        board[i][j] = temp;
        return up || down || left || right;
    }
};