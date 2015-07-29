int getMostWork(vector<int> & folders, int n){
    int low = *max_elelement(folders.begin(), folders.end());
    int high = accumulate(folders.begin(), folders.end(), 0);
    while(low < high){
        int x = low + (high - low) / 2;
        int required = 1;
        int current_load = 0;
        for(auto & f: folders){
            if(current_load + f > x){
                ++required;
                current_load = f;
            } else {
                current_load += f;
            }
        }
        if(required <= x){
            high = x;
        } else {
            low = x + 1;
        }
    }
    return low;

}
