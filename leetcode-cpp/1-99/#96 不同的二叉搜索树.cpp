Tags: 动态规划, 二叉树
给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

示例:

输入: 3
输出: 5
解释:
给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-binary-search-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

class Solution {
public:
    int numTrees(int n) {   //动态规划，思路来自于某点的方法数取决于左边和右边，而左右两边的数量已计算过，相乘取排列组合即可。
        if(n<2)
            return 1;
        int dp[n+1] = {};
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        for(int i=3; i<n+1; i++){
            for(int j=0; j<i; j++){
                dp[i] += dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};  //1,1,2,5,14