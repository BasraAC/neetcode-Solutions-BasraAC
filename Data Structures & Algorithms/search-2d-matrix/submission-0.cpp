class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> arr; 
        for(auto row : matrix)for(auto ai : row)arr.push_back(ai);
        int l = 0, r=arr.size();
        while(l <=  r){
            int mid = (r+l)/2;
            if(target < arr[mid]){
                r = mid - 1;
            }
            else if(target > arr[mid]){
                l = mid + 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
