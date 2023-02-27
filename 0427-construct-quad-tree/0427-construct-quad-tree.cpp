class Solution {
private:
    Node* helperFunc(int x, int n, int y, int m, vector<vector<int>> &grid){
        int ones = 0;
        int zeroes = 0;
        for(int i = x; i < n; i++){
            for(int j = y; j < m; j++){
                ones += (grid[i][j] == 1);
                zeroes += (grid[i][j] == 0);
            }
        }
        Node* rootNode = new Node(1, false);
        if( ones == 0 ){
            rootNode->val = 0;
            rootNode->isLeaf = true;
        }
        else if( zeroes == 0 ){
            rootNode->val = 1;
            rootNode->isLeaf = true;
        }
        else{
            //topLeftGrid -> x to n / 2, y to m / 2
            rootNode->topLeft = helperFunc(x, (n + x) / 2, y, (y + m) / 2, grid);
            
            //topRightGrid -> x to n / 2, m / 2 to m
            rootNode->topRight = helperFunc(x, (n + x) / 2, (m + y) / 2, m, grid);

            //bottomLeftGrid -> n / 2 to n, y to m / 2
            rootNode->bottomLeft = helperFunc((n + x) / 2, n, y, (y + m) / 2, grid);

            //bottomRightGrid -> n / 2 to n, m / 2 to m
            rootNode->bottomRight = helperFunc((n + x) / 2, n, (m + y) / 2, m, grid);
            
        }
        return rootNode;
    }

public:
    Node* construct(vector<vector<int>>& grid) {
        Node* root = helperFunc(0, (int)grid.size(), 0, (int)grid[0].size(), grid);
        return root;
    }
};