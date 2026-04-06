class NumMatrix {
public:
    vector<vector<int>> out;
    NumMatrix(vector<vector<int>>& matrix) {    
        int m = matrix.size();
        int n = matrix[0].size();
        out.resize(m, vector<int>(n, 0));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++) {
                if(i > 0) out[i][j] += out[i-1][j];
                if(j > 0) out[i][j] += out[i][j-1];
                if(i > 0 && j > 0) out[i][j] -= out[i-1][j-1];
                out[i][j]+=matrix[i][j];
            }
        }
    }
    
    int sumRegion(int x1, int y1, int x2, int y2) {
        int sum = out[x2][y2];
        if(y2 > 0) sum -= out[x2][y1 - 1];
        if(x1 > 0) sum -= out[x1 - 1][y2];
        if(x1 > 0 && y1 > 0) sum += out[x1-1][y1-1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */