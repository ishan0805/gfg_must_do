lass Solution{
    // start from the end traverse all the 1's in row 1 then start traversing
    // 1's in 2nd row form the last coloumn in 1'st row
    // as we need max 1's so traverse more than that in the next row
    public :
        int rowWithMax1s(vector<vector<int> > arr, int n, int m){
            int i = 0, j = m - 1;
int ans = -1;
while (i < n && j >= 0)
{
    if (arr[i][j] == 1)
    {
        j--;
        ans = i;
    }
    else
    {
        i++;
    }
}
return ans;
}
}
;