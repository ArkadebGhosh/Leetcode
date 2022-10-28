class DetectSquares {
public:
    unordered_map<int, multiset<int>> points;
    int op = 0;
    DetectSquares() {
        points.clear();
    }
    
    void add(vector<int> point) {
        ++op;
        int x = point[0];
        int y = point[1];
        points[x].insert(y);
    }
    
    int contains(int x, int y) {
        if(points.count(x) == 0)
            return 0;
        // if(op == 48)
        //     cout<<"Contains: "<<x<<" "<<y<<" "<<points[x].count(y)<<endl;
        return points[x].count(y);
    }
    
    int count(vector<int> point) {
        ++op;
        int x = point[0];
        int y = point[1];
        int squares = 0;
        // if(op == 48) {
        //     cout<<endl;
        //     for(auto &j: points[x])
        //         cout<<x<<","<<j<<"   ";
        //     cout<<endl;
        // }
        for(auto &j: points[x]) {
            int y_pt = j;
            
            int diff = y - y_pt;
            if(diff == 0)
                continue;
            int x1 = x - diff;
            int x2 = x + diff;
            squares += contains(x1, y_pt) * contains(x1, y);
            squares += contains(x2, y) * contains(x2, y_pt);
            // if(contains(x1, y_pt) && contains(x1, y))
            //     ++squares;
            // if(contains(x2, y) && contains(x2, y_pt))
            //     ++squares;
        }
        // if(squares == 7) {
        //     cout<<x<<" "<<y<<" "<<op<<endl;
        // }
        return squares;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
x-diff,y        x,y         x+diff,y
        
        
x-diff,y_pt     x,y_pt      x+diff,y_pt
 */