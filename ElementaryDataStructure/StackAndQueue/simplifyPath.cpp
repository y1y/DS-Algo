class simplifyPath{
public:
    string simplifyPath(string path);
};

string simplifyPath(string path){
    vector<string> dir;
    string cur_dir;
    path += "/";
    
    for(int i = 0; i < path.size(); ++i){
        if(path[i] == '/' && !cur_dir.empty()){
            if(cur_dir == ".."){
                if(!dir.empty()){
                    dir.pop_back();
                }
            } else if(cur_dir != "."){
                dir.push_back(move(cur_dir));
            }
            cur_dir = "";
        } else if (path[i] != '/'){
            cur_dir += move(path[i]);
        }
    }
    string ret;
    if(dir.empty()){
        return "/";
    }
    for(auto & folder: dir){
        ret += "/" + folder;
    }
    return ret;
}
