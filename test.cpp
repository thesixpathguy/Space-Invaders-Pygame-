#include<bits/stdc++.h>
//#include <ext/pb_ds/;assoc_container.hpp>
//using namespace __gnu_pbds
using namespace std;
 
#define ff              first
#define ss              second
#define lint             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define t(x)            int x=1; cin>>x; while(x--)
#define fori(i,n)        for(lint i=0;i<n;i++)
#define fo(k,i,n)        for(lint i=k;i<n;i++)
//#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
//mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 bool cmp(pii p1,pii p2)
 {
 	return p1.first-p1.second>p2.first -p2.second;
 }

int main()
{
	c_p_c();
            
       t(x)
       {
           lint n,k,w;
           cin>>n>>k>>w;
           vector<lint> l1;
           fori(i,k)
           {
               lint u;
               cin>>u;
               l1.pb(u);
           }
           lint al,bl,cl,dl;
           cin>>al>>bl>>cl>>dl;
           vector<lint> h1;
           fori(i,k)
           {    lint v;
                cin>>v;
                h1.pb(v);
           }
           lint ah,bh,ch,dh;
           cin>>ah>>bh>>ch>>dh;
           lint p[n];
           p[0]=l1[0]+w;
           lint h3[500000]={0};
          lint per[n];
           fori(i,n)
           {
               lint l,h;
               if(i>=k)
               {
                   l=(al*l1[i-2] + bl*l1[i-1] +cl)%dl +1;
                   l1.pb(l);
                   h=(ah*h1[i-2] + bh*h1[i-1] +ch)%dh +1;
                   h1.pb(h);
               }
               else
               {
                   l=l1[i];
                   h=h1[i];
               }
               if(i==0)
               {
                   per[i]=2*(h+w);
                   for(int j=l;j<=l+w;j++)
                            {
                                h3[j]=max(h3[j],h);
                            }
               }
               else
               {
                   if(p[i-1]<l)
                   {
                       per[i]=(per[i-1] + 2*(h+w))%mod;
                       p[i]=l+w;
                       for(int j=l;j<=l+w;j++)
                            {
                                h3[j]=max(h3[j],h);
                            }
                       
                       
                   }
                   else
                   {
                       if(h1[i]<h3[l])
                       {    per[i]= (per[i-1] + 2*(l+w-p[i-1]))%mod;
                            p[i]=l+w;
                            for(int j=l;j<=l+w;j++)
                            {
                                h3[j]=max(h3[j],h);
                            }
                            
                           
                       }
                       else
                       {
                            per[i]= (per[i-1] + 2*(h+w) - 2*(p[i-1]-l) -2*h3[l])%mod;
                            p[i]=l+w;
                            for(int j=l;j<=l+w;j++)
                            {
                                h3[j]=max(h3[j],h);
                            }
                           
                       }
                   }
               }
               
           }
           lint res=1;
           fori(i,n)
           {
               res*=per[i];
               res%=mod;
               cout<<per[i]<<" ";
           }
           
           cout<<endl;
           cout<<res%mod<<endl;
           
       }
       
    return 0;
    		
}