# a^b % p

二进制快速幂

将b以二进制按位划分，那么a累乘时可以省去多余重复运算，边乘边取模防止越界。

```c++
ll quickmod(ll a,ll b,ll p)
{
    ll t=1;
    while(b){
        if(b&1)t=(t*(a%p))%p;
        a=( (a%p)*(a%p) )%p;
        b>>=1;
    }return t%p;
}

int main()
{
    ll a,b,p;
    std::cin>>a>>b>>p;
    std::cout<<quickmod(a,b,p)<<'\n';
    return 0;
}
```

