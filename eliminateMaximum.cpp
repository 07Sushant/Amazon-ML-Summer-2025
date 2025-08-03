int Solution::eliminateMaximum(vector<int> &A, vector<int> &B)
{
    int n = A.size();
    vector<int> time(n);
    for (int i = 0; i < n; ++i)
        time[i] = (A[i] + B[i] - 1) / B[i];
    sort(time.begin(), time.end());
    for (int i = 0; i < n; ++i)
    {
        if (time[i] <= i)
            return i;
    }
    return n;
}
