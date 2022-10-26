class Solution {
public:
    unordered_set<string> can, cannot;
    unordered_map<string, vector<string>> m;
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        for(auto &s: supplies)
            can.insert(s);
        int n = recipes.size();
        for(int i = 0; i<n; i++) {
            m[recipes[i]] = ingredients[i];
        }
        unordered_set<string> rec;
        vector<string> ans;
        for(int i = 0; i<n; i++) {
            string recipe = recipes[i];
            if(cannot.count(recipe) > 0) {
                continue;
            }
            else if(can.count(recipe) > 0 || possible(recipe, rec)) {
                ans.push_back(recipe);
            }
        }
        return ans;
    }
    
    bool possible(string item, unordered_set<string> &rec) {
        if(can.count(item))
            return true;
        if(cannot.count(item))
            return false;
        if(m[item].size() == 0)
            return false;
        if(rec.count(item) > 0) {
            for(auto &it: rec) {
                cannot.insert(it);
            }
            return false;
        }
        rec.insert(item);
        bool all = true;
        for(auto &ig: m[item]) {
            all = all && possible(ig, rec);
        }
        if(all == false) {
            cannot.insert(item);
            rec.erase(item);
            return false;
        }
        can.insert(item);
        rec.erase(item);
        return true;
    }
};