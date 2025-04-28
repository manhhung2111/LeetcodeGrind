class Solution {
public:
    vector<string> normalize(string path) {
        vector<string> paths;

        string fileDir = "";
        for (int i = 1; i < path.size(); i++) {
            if (path[i] == '/') {
                if (fileDir != "") {
                    paths.push_back(fileDir);
                    fileDir = "";
                } else {
                    continue;
                }
            } else {
                fileDir += path[i];
            }
        }

        if (fileDir != "") {
            paths.push_back(fileDir);
        }

        return paths;
    }

    string simplifyPath(string path) {
        vector<string> paths = normalize(path);
        stack<string> stk;
        
        for (string fileDir : paths) {
            if (fileDir == "..") {
                if (!stk.empty()) {
                    stk.pop();
                }
            } else if (fileDir == ".") {
                // do nothing
            } else {
                stk.push(fileDir);
            }
        }

        if (stk.empty()) {
            return "/";
        }

        string result = "";
        while (!stk.empty()) {
            result = "/" + stk.top() + result;
            stk.pop();
        }

        return result;
    }
};