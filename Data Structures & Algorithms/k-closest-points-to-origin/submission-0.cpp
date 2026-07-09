class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
     // min heap;
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
      for(int i=0 ;i< points.size();i++){
           int x= points[i][0];
           int y= points[i][1];
           int dist= (x*x)+(y*y);

         pq.push({dist,i});


      }
      vector<vector<int>>ans;

      while(!pq.empty() &&  k--){
          int row= pq.top().second;
          int x=points[row][0];
          int y = points[row][1];
          vector<int>choto;
          choto.push_back(x);
          choto.push_back(y);
          ans.push_back(choto);
          pq.pop();

      }

      return ans;
        
    }
};