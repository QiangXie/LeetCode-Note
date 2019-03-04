class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<char, int> hash;
        for(int i = 0; i < 9; ++i){
            for(int i = 1; i <= 9; ++i){
                hash[static_cast<char>('0'+i)] = 0;
            }
            for(int j = 0; j < 9; ++j){
                if(board[i][j] != '.'){
                    if(hash[board[i][j]] != 0){
                        return false;
                    }
                    else{
                        hash[board[i][j]] = 1;
                    }
                } 
            }
            
            for(int i = 1; i <= 9; ++i){
                hash[static_cast<char>('0'+i)] = 0;
            }
            for(int j = 0; j < 9; ++j){
                if(board[j][i] != '.'){
                    if(hash[board[j][i]] != 0){
                        return false;
                    }
                    else{
                        hash[board[j][i]] = 1;
                    }
                } 
            }
        }
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                for(int i = 1; i <= 9; ++i){
                    hash[static_cast<char>('0'+i)] = 0;
                }
                for(int k = 0; k < 3; ++k){
                    for(int h = 0; h < 3; ++h){
                        if(board[i*3+k][j*3+h] != '.'){
                            if(hash[board[i*3+k][j*3+h]] != 0){
                                return false;
                            }
                            else{
                                hash[board[i*3+k][j*3+h]] = 1;
                            }
                        } 
                    }
                }
                for(int i = 1; i <= 9; ++i){
                    hash[static_cast<char>('0'+i)] = 0;
                }
                for(int k = 0; k < 3; ++k){
                    for(int h = 0; h < 3; ++h){
                        if(board[j*3+h][i*3+k] != '.'){
                            if(hash[board[j*3+h][i*3+k]] != 0){
                                return false;
                            }
                            else{
                                hash[board[j*3+h][i*3+k]] = 1;
                            }
                        } 
                    }
                }
            }
        }
        return true;
    }
};