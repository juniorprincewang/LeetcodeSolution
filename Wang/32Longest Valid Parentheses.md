# Longest Valid Parentheses 

标签（空格分隔）： DP

---

## 32 Longest Valid Parentheses 
###描述
    Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

    For "(()", the longest valid parentheses substring is "()", which has length = 2.

    Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
###代码
* 利用栈来做,栈存储下标信息。如果是'('，入栈；如果是')',若栈顶为'('，则出栈，否则将')'的位置信息入栈。最终栈内存储的是未成功匹配的括号。那么就可以根据栈内存储的位置信息进行逐段的计算长度。 16ms
```
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int len = 0;
        if(s.empty())
            return 0;
        int n = s.size();
        int max_len;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else if(s[i] == ')')
            {
                if(!st.empty() && s[st.top()] == '(')
                {
                    st.pop();
                }
                else
                    st.push(i);
            }
        }
        int a=n;
        int b=0;
        if(st.empty())
            max_len = n;
        else 
            max_len = 0;
        while(!st.empty())
        {
            b = st.top();
            st.pop();
            max_len = max(max_len, a-b-1);
            a = b;
        }
        max_len = max(max_len, a);
        return max_len;
    }
};
```
* 动态规划算法：dp[i]存储当前到i位置成功匹配的最大连续括号数，若s[i]为'(',那么肯定没有匹配成功，dp[i]=0;若s[i]=')', 那么要看找前面为'('的位置：即当前位置 - 到前一个位置最大连续括号数 - 1，如果成功匹配，dp[i] = dp[i-1]+2 + dp[再在成功匹配位置前一个位置]。即dp[i]= dp[i-1]+2+dp[i-dp[i-1]-1 -1]，当然要判断位置存在。
```
class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n = s.size();
        int *dp = new int[n];
        for(int i=0; i<n; i++)
            dp[i] = 0;
        int max_len =0;
        for(int i=1; i<n; i++)
        {
            if(s[i] == ')' && i-dp[i-1]-1>=0 && s[i-dp[i-1]-1] =='(')
            {
                dp[i] = dp[i-1] + 2 + ((i-dp[i-1]-2>=0)? dp[i-dp[i-1]-2]:0);
                max_len = max(dp[i], max_len);
            }
        }
        return max_len;
    }
};
```