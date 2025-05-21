class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        queue<pair<int, int>> q;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(matrix[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

       if(q.empty()) return;

       while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        int a = p.first;
        int b = p.second;

            for(int i = 0; i < m; i++) {
                matrix[i][b] = 0;
            }

            for(int j = 0; j < n; j++) {
                matrix[a][j] = 0;
            }    
       } 
    }
};