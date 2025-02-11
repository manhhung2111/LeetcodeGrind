class Solution {
public:
    vector<char> alphaNum = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
    };

    map<string, string> mp;

    string getCode(string url) {
        string result = "";

        for (int i = 1; i <= 6; i++) {
            result.push_back(alphaNum[rand() % (alphaNum.size() - 1)]);
        }

        return result;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string encodedUrl = getCode(longUrl);

        while (mp.find(encodedUrl) != mp.end()) {
            encodedUrl = getCode(longUrl);
        }

        mp[encodedUrl] = longUrl;
        return encodedUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];       
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));