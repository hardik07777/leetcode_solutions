class Solution {
public:
    int countDaysTogether(string arriveAlice, string leavelAlice, string arriveBob, string leaveBob) {
        vector<int>ans(366 , 0);
        vector<int> months = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int alicearrivemonth = stoi(arriveAlice.substr(0,2));
       int aliceleavemonth = stoi(leavelAlice.substr(0,2));

        int allicearriveday = stoi(arriveAlice.substr(3,2));
         int alliceleaveday = stoi(leavelAlice.substr(3,2));

        int bobarrivemonth = stoi(arriveBob.substr(0,2));
        int bobleavemonth = stoi(leaveBob.substr(0,2));
        int bobarriveday = stoi(arriveBob.substr(3,2));
        int bobleaveday = stoi(leaveBob.substr(3,2));
        int alicestartday = 0;
        int alicelastday = 0;
        for(int i = 1; i<alicearrivemonth; i++){
            alicestartday += months[i];
        }
        for(int i = 1; i<aliceleavemonth; i++){
            alicelastday += months[i];
        }
        alicelastday += alliceleaveday;
        alicestartday+= allicearriveday;
        for(int j = alicestartday; j<=alicelastday; j++ ){
            ans[j]++;
        }


        int bobstartday = 0;
        int boblastday = 0;
        for(int i = 1; i<bobarrivemonth; i++){
            bobstartday += months[i];
        }
        for(int i = 1; i<bobleavemonth; i++){
            boblastday += months[i];
        }
        boblastday += bobleaveday;
        bobstartday+= bobarriveday;
        for(int j = bobstartday; j<=boblastday; j++ ){
            ans[j]++;
        }
        int result  = 0;
        for(int i = 0; i<= 365; i++){
            if(ans[i] == 2){
                result++;
            }
        }
        return result;
      
        
    }
};