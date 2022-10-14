class SnakeGame {
public:
    struct data {
        int x;
        int y;
    };
    
    int rowmax, colmax;
    deque<data> snake;
    bool over;
    vector<vector<bool>> snake_hash;
    vector<vector<int>> f;
    int fc;
    int score;
    
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        rowmax = height;
        colmax = width;
        snake.push_back({0, 0});
        over = false;
        snake_hash = vector<vector<bool>> (rowmax, vector<bool> (colmax, false));;
        snake_hash[0][0] = true;
        f = food;
        fc = 0;
        score = 0;
    }
    bool safe(int x, int y) {
        if(x<0 || y<0 || x>= rowmax || y>=colmax)
            return false;
        return true;
    }
    int move(string direction) {
        if(over)
            return -1;
        int nx = snake.front().x;
        int ny = snake.front().y;
        char dir = direction[0];
        if(dir == 'U')
            nx = nx - 1;
        else if(dir == 'D')
            nx = nx + 1;
        else if(dir == 'L')
            ny = ny - 1;
        else if(dir == 'R')
            ny = ny + 1;
        
        if(!safe(nx, ny)) {
            over = true;
            return -1;
        }
        
        if(fc < f.size() && nx == f[fc][0] && ny == f[fc][1]) {
            score+=1;
            fc+=1;
        }
        
        else {
            int tailx = snake.back().x;
            int taily = snake.back().y;
            snake_hash[tailx][taily] = false;
            snake.pop_back();
            if(snake_hash[nx][ny] == true) {
                over = true;
                return -1;
            }
        }
        snake.push_front({nx, ny});
        snake_hash[nx][ny] = true;
        // cout<<"Head: "<<nx<<","<<ny<<" Tail: "<<snake.back().x<<","<<snake.back().y<<endl;
        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */