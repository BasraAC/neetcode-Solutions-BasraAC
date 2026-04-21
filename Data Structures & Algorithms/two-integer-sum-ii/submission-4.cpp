class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //  vector<int> res;
        //   map<int,int> tMap;
        //   for(int i =0 ; i< numbers.size();i++)
        //   {
        //     auto itr=tMap.find(target -numbers[i]);
        //      if(itr != tMap.end())
        //      {
        //         return {itr->second,i+1};
        //      }
        //     tMap[numbers[i]]=i+1;
        //   }
        //  return res;


        /******Using the 2 pointers***********/
        int l= 0;
        int r= numbers.size()-1;

        while(l <r)
        {
            int curSum =numbers[l]+numbers[r];
              if(curSum == target)
              {
                  return {l+1,r+1};
              }
            if(curSum > target)
            {
             //redudce amt
             r--;
            }
            else{
             l++;
            }
        }
        return {};
    }
};
