long Solution::stackingMoney(vector<int> &A)
{
    int n = A.size();
    vector<int> next_greater(n, n), prev_greater(n, -1);
    vector<int> next_smaller(n, n), prev_smaller(n, -1);
    stack<int> st;
    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && A[st.top()] < A[i])
        {
            next_greater[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    for (int i = n - 1; i >= 0; --i)
    {
        while (!st.empty() && A[st.top()] <= A[i])
        {
            prev_greater[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && A[st.top()] > A[i])
        {
            next_smaller[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    for (int i = n - 1; i >= 0; --i)
    {
        while (!st.empty() && A[st.top()] >= A[i])
        {
            prev_smaller[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        long long mx = (long long)(i - prev_greater[i]) * (next_greater[i] - i);
        long long mn = (long long)(i - prev_smaller[i]) * (next_smaller[i] - i);
        ans += (long long)A[i] * (mx - mn);
    }
    return ans;
}
