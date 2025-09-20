class Spreadsheet {
    vector<vector<int>> grid;
    int rows;

    pair<int,int> parseCell(const string &cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        return {row, col};
    }

    int getOperandValue(const string &op) {
        if (isalpha(op[0])) {
            auto [r, c] = parseCell(op);
            return grid[r][c];
        } else {
            return stoi(op);
        }
    }

public:
    Spreadsheet(int rows) {
        this->rows = rows;
        grid.assign(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        auto [r, c] = parseCell(cell);
        grid[r][c] = value;
    }
    
    void resetCell(string cell) {
        auto [r, c] = parseCell(cell);
        grid[r][c] = 0;
    }
    
    int getValue(string formula) {
        string body = formula.substr(1); 
        int plusPos = body.find('+');
        string left = body.substr(0, plusPos);
        string right = body.substr(plusPos + 1);
        return getOperandValue(left) + getOperandValue(right);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */