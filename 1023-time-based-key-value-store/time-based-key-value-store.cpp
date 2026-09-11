class TimeMap {
private:    
    unordered_map<string, vector<pair<int, string>>> mp;

public:
    TimeMap(){

    }

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()) return "";

        auto& history = mp[key];
        int st = 0, end = history.size() - 1;
        string res = "";

        while(st <= end){
            int mid = st + (end - st) / 2;

            if(history[mid].first <= timestamp){
                res = history[mid].second;
                st = mid + 1;
            }else {
                end = mid - 1;
            }
        }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */