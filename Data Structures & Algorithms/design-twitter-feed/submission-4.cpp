class Twitter {
private :
  map<int,set<pair<int,int>>>mp;
  map<int,set<int>>followList;
  unsigned int ct=0;

public:
    
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        mp[userId].insert({ct++,tweetId});
    
}
    
    vector<int> getNewsFeed(int userId) {

        vector<int>ans;
         
       set<pair<int,int>>st;
       // follow list er modde nijekei nije rakhte hbe 
      for(auto  &p : followList[userId]){

     
          for(auto &q : mp[p]){
              st.insert(q);
          }

      }
        for(auto &q : mp[userId]){
              st.insert(q);
          }

    int ct =0;
    for(auto it=st.rbegin();it!=st.rend();it++){
        ans.push_back(it->second);
        ct++;
        if(ct==10) break;
          
    }

    return ans;


     
        
      




    
        
    }
    
    void follow(int followerId, int followeeId) {

        // 1--->2   2 er post 1 e isnet korbo
        followList[followerId].insert(followeeId);
      
       
        
    }
    
    void unfollow(int followerId, int followeeId) {
      

      followList[followerId].erase(followeeId );


        
    }
};
