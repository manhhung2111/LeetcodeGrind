class Solution {
public:
    vector<char> alphaNums = {
        // Lowercase letters
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        // Uppercase letters
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        // Digits
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
    };

    map<string, string> mp;

    string helper(string longUrl) {
        srand(NULL);

        string answer = "";
        for (int i = 0; i < 6; i++) {
            answer += alphaNums[rand() % alphaNums.size()];
        }

        return answer;
    }


    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string encodedStr = helper(longUrl);

        while (mp.find(encodedStr) != mp.end()) {
            encodedStr = helper(longUrl);
        }

        mp[encodedStr] = longUrl;
        return encodedStr;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));