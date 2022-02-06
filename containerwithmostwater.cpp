class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int maxWater=0;
        int h,w;
        int area;
        while(i<j)
        {
             w=j-i;
             h=min(height[i],height[j]);
            area=h*w;
            maxWater=max(maxWater,area);
            height[i]>height[j]?j--:i++;
        }
        return maxWater;
    }
};