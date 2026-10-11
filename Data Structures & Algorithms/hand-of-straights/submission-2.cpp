class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
       if(hand.size()%groupSize!=0)return false;

       sort(hand.begin(), hand.end());
       int n=hand.size();
       map<int, int> freq;

       for(int i=0; i<n; i++){
            freq[hand[i]]++;
       }

       int groups=n/groupSize;
       int i=0;
    for(int j=0; j<groups; j++){
     while(i<n && freq[hand[i]]==0){
        i++;
     }
     int start=hand[i];

     for(int k=0; k< groupSize; k++){
        if(freq[k+start]==0){
            return false;
        }
        freq[start+k]--;
     }
          
        }
        return true;
    }
    
    
};