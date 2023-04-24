# 64位整数乘法 a*b%p

## 方法一：思想同二进制快速幂，将b按二进制分解

```c++
ll mul(ll a,ll b,ll p) //return a*b mod p
{
    ll ans=0;
    while(b){
        if(b&1)ans+=a,ans%=p;
        a*=2;
        a%=p;
        b>>=1;
    }return ans;
}
int main()
{
    ll a,b,p;
    std::cin>>a>>b>>p;
    std::cout<<mul(a,b,p)<<'\n';
    return 0;
}
```

## 方法二：利用 a*b%p=a*b-floor(a*b/p)*p  //其中floor(a)表示a向下取整

![image-20210327114803414](C:\Users\pengxin\AppData\Roaming\Typora\typora-user-images\image-20210327114803414.png)

```c++

ll mul(ll a,ll b,ll p)
{
    a%=p,b%=p;
    ll c=(long double)a*b/p;
    ll ans=a*b-c*p;
    if(ans<0)ans+=p;
    else if(ans>p)ans%=p;
    return ans;
}
int main()
{
    ll a,b,p;
    std::cin>>a>>b>>p;
    std::cout<<mul(a,b,p)<<'\n';
    return 0;
}
```

