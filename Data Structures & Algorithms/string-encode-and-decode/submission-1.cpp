class Solution {
public:
    string encode(vector<string>& strs) {
        int n = strs.size();
        if(n == 0)
            return "";
        string encodedString;
        for(auto s: strs)
            encodedString += to_string(s.size()) + '#' + s;          
        
        return encodedString;
    }

    vector<string> decode(string s) {
        int n = s.size();
        if(n == 0)
            return {};
        vector<string> decodedStrings;
        int i=0;
        while(i<n){
            int j = i;
            while(s[j] != '#')
                j++;
            int len = stoi(s.substr(i,j-i));
            i = j+1;
            j = i + len;
            decodedStrings.push_back(s.substr(i,len));
            i = j;
        }

        return decodedStrings;
    }
};
