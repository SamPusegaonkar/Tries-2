/*
Intuition: use a 2 pointer approach
Process each query individually. For each query check if the characters match.
Time Complexity:O(N+M), N = number of queries, M = Average length of each query
Space Complexity:O(1)


*/

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> result;
        for ( auto query: queries){
            int j = 0;
            bool flag = false;
            for( int i = 0;i < query.size(); i++){
            
                char c = query[i];
                if ( j < pattern.size() and c == pattern[j]){
                    j++;
                    if ( j == pattern.size()){
                        flag = true;
                        
                    }
                }
                else if ( isupper(c)){
                    flag = false;
                    break;

                }

            }
            result.push_back(flag);
        
        
        }
        return result;
    }
};