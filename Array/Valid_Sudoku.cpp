Leetcode Question Link: 

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<char,int> rowmap;
        vector<map<char,int>> colmap(9);
        vector<map<char,int>> boxmap(9);
        int boxIdx;
        
        for( int i = 0; i < 9; ++i ) {
            rowmap.clear();
            
            for( int j = 0; j < 9; ++j ) {
                if( board[i][j] == '.' ) continue;
                
                rowmap[board[i][j]]++;
                if( rowmap[board[i][j]] > 1 ) return false;
                
                colmap[j][board[i][j]]++;
                if( colmap[j][board[i][j]] > 1 ) return false;
                
                boxIdx = ((i/3) * 3) + (j/3); 
                boxmap[boxIdx][board[i][j]]++;
                if( boxmap[boxIdx][board[i][j]] > 1 ) return false;
            }
        }
        
        return true;
    }
};
