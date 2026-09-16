class Solution {
public:
    bool helper(int mid , int h , vector<int>& piles){
        int k = mid;
        int sum = 0;
        for(int i = 0; i< piles.size(); i++){
            if(piles[i] %k == 0){
                sum += piles[i] /k;
            }
            else{
                sum += (piles[i] / k ) + 1;
            }
        }
        if(sum <= h){
            return true;
        }
        return false;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = *(max_element(piles.begin() , piles.end()));
        int ans = INT_MAX;
        while(s <= e){
            int mid = e - (e- s)/2;
            if(helper(mid , h , piles)){
                e = mid -1;
                ans = min(ans , mid);
            }
            else{
                s = mid +1;

            }


        }
        return ans;
        
    }
};