/*
対象：nt/crt.hpp の CRT。
独立オラクル：法の最小公倍数未満のxを直接列挙して、すべての合同式を満たす最小非負解、または不存在を決める。
負の剰余、法1、非互いに素な法、矛盾、多数の法（n>10）、返値の再剰余、coprime指定を確認する。
大きな法の分岐は小さい法との二元連立で直接求める。固定seed 0xC8A11231、値域を限定する。
*/
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/crt.hpp"

static mt19937_64 gen(0xC8A11231ULL);
static int randint(int l,int r) { return uniform_int_distribution<int>(l,r)(gen); }

static pair<bool,long long> reference(const vector<long long>& vals,const vector<long long>& mods) {
  long long lcm=1;
  for (long long m:mods) {
    lcm = lcm / gcd(lcm,m) * m;
    if (lcm > 4000000) { cerr << "reference exceeded limit\n"; abort(); }
  }
  for (long long x=0;x<lcm;++x) {
    bool good=true;
    for (int i=0;i<(int)mods.size();++i) {
      if ((x-vals[i])%mods[i] != 0) { good=false; break; }
    }
    if (good) return {true,x};
  }
  return {false,0};
}

static void check(const vector<long long>& vals,const vector<long long>& mods,int id) {
  auto want = reference(vals,mods);
  vector<long long> newmods={-1,1,2,7,97,1000000007};
  bool coprime=true;
  for (int i=0;i<(int)mods.size();++i)
    for (int j=0;j<i;++j) if (gcd(mods[i],mods[j])!=1) coprime=false;
  for (long long newmod:newmods) for (int c=0;c<(coprime?2:1);++c) {
    i128 got=CRT<long long>(vals,mods,newmod,c==1);
    long long expected=!want.first?-1LL:(newmod==-1?want.second:want.second%newmod);
    if (got==(i128)expected) continue;
    cerr << "CRT mismatch id=" << id << " newmod=" << newmod << " coprime=" << c << '\n';
    for (int i=0;i<(int)vals.size();++i)
      cerr << "  x == " << vals[i] << " (mod " << mods[i] << ")\n";
    cerr << "actual=" << (long long)got << " expected=" << expected << '\n';
    abort();
  }
}

static void large_coprime_case() {
  // Exercise CRT's >=2^31 arithmetic branch without brute-force scanning.
  const long long a=(1LL<<31)+1, b=17;
  if (gcd(a,b)!=1) abort();
  const long long p=-151, q=13;
  const long long x0=(p%a+a)%a;
  long long expected=-1;
  for (int k=0;k<b;++k) {
    long long x=x0+a*k;
    if ((x-q)%b==0) { expected=x; break; }
  }
  if (expected<0) abort();
  vector<long long> vals={p,q}, mods={a,b};
  for (long long newmod: {-1LL,1LL,1000000007LL}) {
    i128 actual=CRT<long long>(vals,mods,newmod,true);
    long long want=(newmod==-1?expected:expected%newmod);
    if (actual!=want) { cerr<<"CRT big branch mismatch\n";abort(); }
  }
}

int main() {
  int id=0;
  check({}, {}, ++id);
  for (int m1=1;m1<=12;++m1) for (int m2=1;m2<=12;++m2)
    for (int a=-3;a<=3;++a) for (int b=-3;b<=3;++b)
      check({a,b},{m1,m2},++id);
  for (int n=1;n<=7;++n) for(int trial=0;trial<2600;++trial) {
    vector<long long> val(n), mod(n);
    for(int i=0;i<n;++i) mod[i]=randint(1,12),val[i]=randint(-22,22);
    check(val,mod,++id);
  }
  // n>10 forces the prime-factor reduction branch rather than the
  // coprime-factorization branch used for small n.
  for(int trial=0;trial<800;++trial) {
    int n=randint(11,14);
    vector<long long> val(n),mod(n);
    for(int i=0;i<n;++i) mod[i]=randint(1,8),val[i]=randint(-10,10);
    check(val,mod,++id);
  }
  large_coprime_case();
  cout<<"PASS CRT cases="<<id<<'\n';
}
