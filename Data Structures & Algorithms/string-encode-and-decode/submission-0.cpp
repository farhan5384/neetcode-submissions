class Solution {
public:

    string encode(vector<string>& strs) {

        // hellow, world 
        
        string s_1="";

        for(string s: strs){
            int len= s.length();
             string len_s = to_string(len)+"#"+s;
             s_1+=len_s;
            
            

        }

        return s_1;
    }

    vector<string> decode(string s) {
       int i=0;
       vector<string>d;

       while(i< s.length()){
        string st="";
           while(s[i]!='#'){
            st+=s[i];
            i++;

           }
          int num= stoi(st);
          string temp="";
          i++;
          for(int k=1 ; k<= num ;k++){
            temp+=s[i];
            i++;
          }
          d.push_back(temp);


       }
       return d;

    }
};
