class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans1 = (1ll * need1 * cost1) + (1ll * need2 * cost2) ;
        long long ans2 = (1ll * max(need1 , need2) * costBoth);
        long long ans3 = 0;
        if(need1 > need2){
            ans3 = max(0ll ,(1ll * need2 * costBoth) + (1ll * (need1 - need2) * cost1));
        }
        else{
            ans3 = max(0ll , (1ll * need1 * costBoth) + (1ll * (need2 - need1) * cost2));

        }
        return min(ans1 , min(ans2 , ans3));
    }
};