    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int col[101];
        for(int i = 0; i<101; i++)
        col[i] = 0;
        for(int i = 0; i<n; i++) {
            if(!possible(graph, i, m, n, col))
                return false;
        }
        return true;
    }
    
    bool possible(bool graph[101][101], int v, int m, int n, int col[101]) { // v is the vertex
        if(col[v] > 0) 
            return true;
            
        vector<int> colors;
        for(int i = 1; i<=m; i++)
        colors.push_back(i);
        unordered_set<int> choices(colors.begin(), colors.end());
        for(int i = 0; i<n; i++) {
            if(i==v)
            continue;
            if(graph[i][v])
            choices.erase(col[i]);
        }
        if(choices.size() == 0)
            return false;
        
        while(!choices.empty()) {
            bool all = true;
            col[v] = *(choices.begin());
            for(int i = 0; i<n; i++) {
                if(i==v)
                continue;
                all = all && possible(graph, i, m, n, col);
                if(!all) {
                    choices.erase(col[v]);
                    col[v] = 0;
                }
            }
            if(all)
                return true;
        }
        
        return false;
    }
