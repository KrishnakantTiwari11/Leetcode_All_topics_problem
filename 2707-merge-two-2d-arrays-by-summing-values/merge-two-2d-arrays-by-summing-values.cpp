class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2){
        int n1=nums1.size(),n2=nums2.size();
        int i=0,j=0;
        vector<vector<int>>ans;
        while(i<n1 && j<n2){
            vector<int>temp(2);
            if(nums1[i][0]==nums2[j][0]){
                int val=nums1[i][1]+nums2[j][1];
                temp[0]=nums1[i][0];
                temp[1]=val;
                ans.push_back(temp);
                i++;
                j++;
            }
            else if(nums1[i][0]<nums2[j][0]){
                temp[0]=nums1[i][0];
                temp[1]=nums1[i][1];
                ans.push_back(temp);
                i++;
            }
            else{
                temp[0]=nums2[j][0];
                temp[1]=nums2[j][1];
               ans.push_back(temp);
               j++;
            }
        }
        while(i<n1){
            vector<int>temp(2);
            temp[0]=nums1[i][0];
            temp[1]=nums1[i][1];
            ans.push_back(temp);
            i++;
        }
        while(j<n2){
            vector<int>temp(2);
            temp[0]=nums2[j][0];
            temp[1]=nums2[j][1];
            ans.push_back(temp);
            j++;
        }
        return ans;
    }
};