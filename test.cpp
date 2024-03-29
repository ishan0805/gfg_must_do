#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//#define ll cpp_int
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define fi(a, b, c, d) for (int a = b; a < c; a += d)
#define fl(a, b, c, d) for (ll a = b; a < c; a += d)
#define fei(a, b, c, d) for (int a = b; a <= c; a += d)
#define fel(a, b, c, d) for (ll a = b; a <= c; a += d)
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define vll vector<ll>
#define viip vector<pair<int, int>>
#define vllp vector<pair<ll, ll>>
#define pb emplace_back
// pairs
#define pi pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define F first
#define S second
// using boost::multiprecision::cpp_int;
using namespace std;
bool iseven(ll n)
{
    if (n % 2 == 0)
        return true;
    else
    {
        return false;
    }
}
ll position(ll a)
{
    // vector<ll>p(30,0);
    // unordered_set<ll>s;
    ll s = 0;
    long double x = a;
    int i = 0;
    while (a > 0)
    {
        if ((a & 1) == 1)
        {
            // s.insert(i);
            s++;
        }

        a = a >> 1;
        i++;
    }

    return s;
}
ll power(ll x, unsigned ll y)
{
    ll res = 1; // Initialize result

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = res * x;

        // y must be even now
        y = y >> 1; // y = y/2
        x = x * x;  // Change x to x^2
    }
    return res;
}
void print(vector<ll> a, ll n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}
bool sec(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
    if (a.first == b.first)
        return (a.second > b.second);
    else
    {
        return (a.first > b.first);
    }
}
vector<ll> suffixsum(vll &a, ll n)
{
    vll pre(n, 0);
    pre[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        pre[i] = pre[i + 1] + a[i];
    }
    return pre;
}
vector<ll> preffixsum(vll &a, ll n)
{
    vll pre(n, 0);
    pre[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }
    return pre;
}

void whenEqual(vector<ll>&a,int &i,int &j,vector<ll>&ans)
{ 
    int l=i,r=j;
    if(i==j)
    {
        ans.push_back(a[i]);
        i++;
        j--;
        return;
    }
    while(l!=r&&a[l]==a[r])
    {
        l++;
        
        r--;

    }
    if(a[l]>a[r])
    {
        if(a[l]>a[i])
        {
            while(i<=l)
            {
                ans.push_back(a[i]);
                i++;
            }
        }
        else
        {
            int t=l-i;
            t*=2;
            while(t--)
            {
                ans.push_back(a[i]);
            }
            i=l;
            j=r;
        }
        
    }
    else
    {
        if(a[r]>a[j])
        {
            while(j>=r)
            {
                ans.push_back(a[j]);
                j--;
            }
        }
        else
        {
            int t=l-i;
            t*=2;
            while(t--)
            {
                ans.push_back(a[i]);
            }
            i=l;
            j=r;
        }
    }

}

void solve()
{
   ll n;
   cin>>n;
   vll a(n);
   rep(i,n)
   {
       cin>>a[i];
   }
   vll ans;
   int i=0,j=n-1;
   while(i<=j)
   {
       if(a[i]==a[j])
       {
           whenEqual(a,i,j,ans);
       }
       else if(a[i]>a[j])
       {
           ans.push_back(a[i]);
           i++;
       }
       else
       {
           ans.push_back(a[j]);
           j--;
       }
       
   }
   print(ans,n);


    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    //cin>>t;
    while(t--)
    {
       solve();
    }
    
    return 0;
}
