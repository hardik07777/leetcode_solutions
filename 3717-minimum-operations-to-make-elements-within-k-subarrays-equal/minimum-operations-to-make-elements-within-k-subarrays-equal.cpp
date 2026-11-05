class Solution {
public:
    long long arr[100001][16];
    void helper_to_calculate_cost(vector<long long>&cost ,vector<int>& nums , int x){
        // first lets find the median of array of value x at every index
        int n = nums.size();
        multiset<int>left;
        multiset<int>right;
        int i = 0;
        int j = 0;
        long long leftsum = 0;
        long long rightsum = 0;
        vector<int>median;
        while(j < n){
           
            if(left.empty() or left.size() <= right.size()){
                left.insert(nums[j]);
                leftsum += nums[j];
            }
            else{
                right.insert(nums[j]);
                rightsum += nums[j];
            }
            if(!left.empty() and !right.empty()){
                int left_lastelement = *(prev(left.end()));
                int right_firstelement = *(right.begin());
                if(left_lastelement > right_firstelement){
                    left.erase(prev(left.end()));
                    right.erase(right.begin());
                    rightsum -= right_firstelement;
                    rightsum += left_lastelement;
                    leftsum += right_firstelement;
                    leftsum -= left_lastelement;
                    left.insert(right_firstelement);
                    right.insert(left_lastelement);
                }
            }

            if(j-i +1 == x){
                // when the size os equal to x we will slid the median into our array
                int med = *(prev(left.end()));
                median.push_back(med); 
                // prev will find iterator just before the end  ,and end points to the last of the element.
                // i will find the value of i in both and will remove frome 1
                long long val =  (left.size() * med - leftsum) + (rightsum - right.size() * med);
                cost.push_back(val);

                if(left.find(nums[i]) != left.end()){
                    left.erase(left.find(nums[i]));
                    leftsum-= nums[i];
                }
                else{
                    right.erase(right.find(nums[i]));
                    rightsum -= nums[i];
                }
                i++;
            }
            j++;
        }
       

    }
    long long helper2(vector<int>&nums , vector<long long>&cost , int count , int k , int i , int x){
        if(count == k){
            return 0;
        }
        int subarrayeeded = k - count;
         int elementsneeded = subarrayeeded * x;
         if(nums.size() - i < elementsneeded ){
            return 1e15;
         }
        if(arr[i][count]!= -1){
            return arr[i][count];
        }
        long long take = cost[i] + helper2(nums , cost , count +1 , k , i + x , x );
        take = min(take , helper2(nums , cost , count , k , i+1 , x ));
        return arr[i][count] = take;
    }
    long long minOperations(vector<int>& nums, int x, int k) {
        vector<long long>cost; // min moves to find of size x at that index
        helper_to_calculate_cost(cost , nums , x);
        memset(arr ,-1 , sizeof(arr));
        return helper2(nums , cost , 0 , k , 0 , x );
        
    }
};