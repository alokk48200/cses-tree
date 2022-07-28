#include<bits/stdc++.h>
#define mod1 998244353
#define mod 1000000007
#define pi pair<int, int>
#define ll long long int
#define pll pair<ll, ll>
#define ppll pair<pll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pi>
#define vpll vector<pll>
#define vppll vector<pair<pll, ll>>
#define vvll vector<vector<ll>>
#define vvpll vector<vector<pll>>
#define repi(i,a,n) for(ll i=a;i<n;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define pb push_back
#define ff first
#define ss second  
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define pr(i,v) for(auto i:v)
static int dx[5] = {-1, 0, 1, 0, -1};
static int dy[4] = {0, -1, 1, 0};
static int dagb[4] = {1, -1, 1, -1};
static int daga[4] = {1, -1, -1, 1};
 #define inf 12345678912345678
 
using namespace std;
ll expo(ll a, ll b, ll mo) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mo; a = (a * a) % mo; b = b >> 1;} return res;}
 ll expo1(ll a, ll b) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) ; a = (a * a) ; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll ddiv(ll a, ll b){ return a%b==0?  a/b: a/b+1;}

vll v[2000001];
vll vis(2000001, 0);
vll seg(2000001, 0);
unordered_map<ll,ll>mp , mp1;
vll el;
void build(ll id, ll l, ll r, vll &a){
if(l==r){
  seg[id]=a[el[l]-1];
  return;
}
 ll mid=(l+r)/2;
 build(2*id+1, l, mid, a);
 build(2*id+2, mid+1, r,a);
  seg[id]=seg[2*id+1]+seg[2*id+2];

}
void update(ll id, ll ind, ll l, ll r, vll &a){
  if(l==r  &&  ind==l){
  seg[id]=a[el[l]-1];
  return;
}
 ll mid=(l+r)/2;
 if(ind<=mid)update( 2*id+1, ind, l, mid, a);
 else update( 2*id+2, ind, mid+1, r, a);
  seg[id]=seg[2*id+1]+seg[2*id+2];
}
ll query(ll id, ll l, ll r,ll l1, ll r1){
  if(l1<=l && r1>=r){
    return seg[id];
  }
  else if(l1>r || r1<l)return 0;

  ll mid=(l+r)/2;
  ll left =query(2*id+1, l, mid, l1, min(r1, mid));
  ll right =query(2*id+2, mid+1, r, max(mid+1, l1), r1 );
  return left+right;
}
void dfs(ll x){
  vis[x]=1;
  el.push_back(x);
  
    mp[x]=el.size();
  for(auto i:v[x]){
    if(vis[i]==0) dfs(i);
  }
  el.push_back(x);
  mp1[x]=el.size();
  return ;
}
void solve(){
      
   //  memset(dp, -1, sizeof(dp));
     string s,s1,s3="",res, s2;
   
    ll n,m,l=-1, k,h,r,x=0, y=0, z=0,w=0, mn=+1e18, e=0,cnt=0,sum=0,de=1,mx=0, mx1=-1e7;
    
    cin>>n>>m;
    
vll a(n);

repi(i,0,n)cin>>a[i];

     repi(i,0,n-1){
      cin>>x>>y;
      v[x].pb(y);
      v[y].pb(x);
     }

       dfs(1);
    
       //for(auto i:el)cout<<i<<" ";
       // cout<<endl;
      build(0,0, el.size()-1, a);
       repi(i,0,m){
            cin>>x;
            if(x==1){
              cin>>y>>z;
              a[y-1]=z;
              //cout<<mp[y]<<" "<<mp1[y]<<endl;
              update(0,mp[y]-1, 0, el.size()-1, a);
              update(0,mp1[y]-1, 0, el.size()-1,a);
            } 
            else{
              cin>>y;
              cout<<query(0, 0, el.size()-1, mp[y]-1, mp1[y]-1 )/2 <<endl;

            }    
       }

      



}
 
 

 
int main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
     #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r"  ,stdin);  
        freopen("output.txt" , "w" ,stdout);
       
     #endif 
          
 
         
                
      ll _=1;
     //cin>>_;
    
   repi(ii,1, _ +1){
    //cout<<"Case #"<<ii<<": ";
    
          solve();
 
     }
   return 0;
}