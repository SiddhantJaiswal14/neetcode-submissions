class Solution {
public:

    string encode(vector<string>& strs) {
        int n = strs.size();
        if(n == 0)
            return "";
        string encodedString = "";
        vector<int> sizes;
        for(auto s:strs)
            sizes.push_back(s.size());
        
        for(auto sz:sizes)
            encodedString += to_string(sz) + ',';
        encodedString += '#';

        for(auto s: strs)
            encodedString += s;
        cout<<encodedString;
        return encodedString;
    }

    vector<string> decode(string s) {
        int n = s.size();
        if(n == 0)
            return {};
        vector<string> decodedStrings;
        vector<int> sizes;
        int i=0;
        while(s[i] != '#'){
            string len = "";
            while(s[i] != ','){
                len += s[i];
                i++;
            }
            sizes.push_back(stoi(len));
            i++;
        }
        i++;
        
        for(auto sz:sizes){
            decodedStrings.push_back(s.substr(i,sz));
            i+=sz;
        }
        return decodedStrings;
    }
};
