# [AcWing113特殊排序](https://www.acwing.com/problem/content/description/115/)

## 题意

一道交互题，n个元素，其大小关系具有反对称性和非传递性。通过不超过1w次提问，每次了解某两个元素的大小关系，要求将对其排序，每个元素小于右边相邻的元素，通过compare可以获得两个元素大小关系。

## 题解

假设现有已排序好的序列，可以先用二分找到新元素的位置，然后将新元素放到最后，从右往左交换相邻元素，直到其达到二分找到的位置。

## 代码

```c++
// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.

class Solution {
public:
    vector<int> specialSort(int N) {
        vector<int>ans;
        ans.push_back(1);
        for(int i=2;i<=N;i++){
            int l=0,r=ans.size()-1;
            while(l<=r){
                int mid=(l+r)>>1;
                if(compare(i,ans[mid]))r=mid-1;
                else l=mid+1;
            }
            ans.push_back(i);
            for(int j=ans.size()-1;j>l;j--)swap(ans[j],ans[j-1]);
        }
        return ans;
    }
};
```

