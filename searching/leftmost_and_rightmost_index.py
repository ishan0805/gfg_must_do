"""
In binary search always increase the begin = mid+1 to avoid infinite loop 
this is because for floor nature of division 

"""


class Solution:
    def indexes(self, v, x):
        ans = [-1, -1]
        begin = 0
        end = len(v)

        while(begin < end):
            #print(begin, end=" ")
            # print(end)
            mid = int((begin+end)/2)
            if(v[mid] < x):
                begin = mid+1
            if(v[mid] >= x):
                end = mid
        if(end == len(v) or v[end] != x):
            return ans
        ans[0] = end

        begin = 0
        end = len(v)
        while(begin < end):
            mid = int((begin+end)/2)
            if(v[mid] <= x):
                begin = mid+1
            if(v[mid] > x):
                end = mid
        ans[1] = begin-1
        return ans
