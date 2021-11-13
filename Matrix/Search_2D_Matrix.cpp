Leetcode Question Link: https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
int n=0,d=matrix[0].size()-1; // variables declaration and definition
while(n<matrix.size() && d>=0 ){
if(matrix[n][d]==target)
return true;
else if(matrix[n][d]>target)
d--;
else
n++;
}
return false;
}  
};
