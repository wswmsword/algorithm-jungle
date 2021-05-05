// #include<cstdio>
// #include<iostream>
// #include<algorithm>
// #include<cmath>
// using namespace std;
// const int MAX_L=9999999;
// const int MAX_SQRT_B=9999999;
// bool is_prime[MAX_L],is_prime_small[MAX_SQRT_B];
// int sum=0;
// void segment_sieve(long long a,long long b)
// {
// 	for(int i=0;(long long)i*i<b;i++)
// 	   is_prime_small[i]=true;
// 	for(int i=0;i<b-a;i++)
// 	   is_prime[i]=true;
// 	for(int i=2;(long long)i*i<b;i++)
// 		if(is_prime_small[i])
// 		{
// 			for(int j=2*i;(long long)j*j<b;j+=i)
// 			   is_prime_small[j]=false;
// 			for(long long j=max(2LL,(a+i-1)/i)*i;j<b;j+=i)
// 				is_prime[j-a]=false;
// 		}
// 	return;
// }
// int main()
// {
// 	long long a,b;
// 	cin>>a>>b;   //区间【a，b】
// 	segment_sieve(a,b+1);   //区间筛
// 	for(long long i=a;i<=b;i++)
// 		if(is_prime[i-a])
// 		   sum++;
// 	printf("%d\n",sum);
// 	return 0;
// }
#include<cstdio>
const long long N=460897024;
int isprime[N];
long long prime[N],tot;
long long amount;
int main()
{
   long long vN=N;
   long long i,j;
   for(i=2;i<vN+1;i++)
   {
      amount++;
      if(!isprime[i])
         prime[tot++]=i;
      while(!(vN%prime[tot-1]))
      {
         amount++;
         vN/=prime[tot-1];
      }
      if(vN==1)
         break;
      for(j=0;j<tot&&i*prime[j]<vN+1;j++)
      {
         amount++;
         isprime[i*prime[j]]=1;
         if(i%prime[j]==0)
            break;
      }
   }
   printf("%lld,%lld",prime[tot-1],amount);
   return 0;
}

// #include<iostream>
// using namespace std;
// long long amount;
// int euler(int n) {
//     int maxx = 0;
//     int tem = n;
//     for (int i = 2; i <=n && tem != 1; i ++) {
//           amount++;
//         if (tem % i == 0){
//             maxx = max(maxx, i);
//             while(tem % i == 0) {
//                   amount++;
//                 tem /= i;
//             }
//         }
//     }
//     return amount;
// }
// int main() {
//     int n = 460897024;
//     cout << euler(n);
// }
// #include<iostream> 
// #include<vector>
// using namespace std;
// int main()
// {
//    long long n;
//    long long i,j;
//    cin>>n; //求n以内素数
//    vector<long long> prime;
//    vector<bool> isPrime(n+1);   //表示是否为质数
//    for(i=1;i<=n;++i)
//       isPrime[i]=true;   //初始化为质数
//    for(i=2;i<=n;++i)
//    {   //处理到i时它还没被删掉，则i为素数 prime.push_back(i);
//       if(isPrime[i])
//          prime.push_back(i);
//       for(j=0;j<prime.size();++j)
//       {
//          if(i*prime[j]<=n)
//             isPrime[i*prime[j]]=false;
//          else
//             break;
//          if(i%prime[j]==0)
//             break;
//       }
//    }
//    for(i=0;i<prime.size();++i)
//        cout<<prime[i]<<endl;
//    return 0;
// }