/*
Intuition: 
Solution1:
Create a map of the frequency and element.
Put that map in the priority queue.

SOlution 2: Create a frequency count of all the nums.
Store elements which have a similar frequency count in a array.
Traverse from the back and store all elements in the result
/////////////////////////////////////////////////////
Solution1:
Time Complexity: O(NlogK), K = Kth element to be found, N = Total number of elements
Space Complexity:O(N), N = Total number of elements
/////////////////////////////////////////////////////
Solution2:
Time Complexity: O(N), N = Total number of elements
Space Complexity:O(N), N = Total number of elements
*/


struct comparator{
    bool operator()( pair<int,int> a, pair<int,int> b){
        return a.first > b.first;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        priority_queue< pair<int,int>, vector<pair<int,int>>, comparator > pq;
        
        map<int,int> map;
        for ( auto el: nums){
            map[el] += 1;
        }
        
        for ( auto KV: map){
            
            int num = KV.first;
            int count = KV.second;
            
            pq.push({count,num});
            if ( pq.size() > k){
                pq.pop();
            }
            
        }
        
        while ( pq.size() != 0){
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        
        return result;
        
        
    }
};



class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        map<int,int> map;
        for ( auto el: nums){
            map[el] += 1;
        }
        vector<vector<int>> buckets(nums.size()+1);

        for ( auto KV: map){
            int freq = KV.second;
            int num = KV.first;
            if ( buckets[freq].size() == 0){
                vector<int>newArray;
                buckets[freq] = newArray;
            }
            buckets[freq].push_back(num);
        
        }
        
        for ( int i = nums.size(); i >=0 and k > 0; i-- ){
            if ( buckets[i].size() != 0){
                
                vector<int> numsArray = buckets[i];
                for (int j = 0; j < numsArray.size() and k > 0; j++){
                    result.push_back(numsArray[j]);
                    k--;
                }
            }
        
        }
        
        
        return result;
        
        
    }
};