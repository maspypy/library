// maspy-ai-test: expand
// TST-0040: exp(k log(1+ax)) を一般化二項係数と比較する。
// 素数法で n 未満が可逆な長さだけを使い、定数項は0。
// 0/1要素、2冪の前後、疎密切替の非零項数320/321・3000/3001、
// NTT可・不可の法について、切り捨て長と全係数を検証する。
#include "my_template.hpp"
#include "other/io.hpp"
#include "poly/fps_exp.hpp"

template<class M>
void run() {
  int tot = 0, calls = 0;
  auto eq = [&](const vc<M>& expected, const vc<M>& actual, int k, const char* tag) {
    ++calls;
    if (expected.size() != actual.size()) {
      std::cerr << tag << ": length " << actual.size() << " != " << expected.size() << '\n';
      std::abort();
    }
    for (size_t i = 0; i < actual.size(); ++i) {
      ++tot;
      if (actual[i] != expected[i]) {
        std::cerr << tag << ": mod=" << M::get_mod() << " n=" << actual.size()
                  << " k=" << k << " i=" << i << '\n';
        std::abort();
      }
    }
  };
  for (auto n : {0,1,2,3,7,8,9,31,32,33,63,64,65,127,128,129}) {
    for (int k : {0,1,2,7,-1,-3,-11}) {
      vc<M> f(n), a(n);
      if(n) a[0]=1;
      M p=1;
      for(int i=1;i<n;++i) {
        p*=M(7);
        f[i]=p*M(k)/M(i);
        if(i%2==0) f[i]=-f[i];
        a[i]=a[i-1]*M(k-i+1)*M(7)/M(i);
      }
      eq(a,fps_exp(f),k,"dispatch");
      eq(a,fps_exp_dense(f),k,"dense");
      eq(a,fps_exp_sparse(f),k,"sparse");
    }
  }
  const int threshold = M::can_ntt() ? 320 : 3000;
  for (int n : {threshold,threshold+1,threshold+2}) {
    for (int k : {1,-3}) {
      vc<M> f(n), a(n);
      a[0]=1;
      M p=1;
      for(int i=1;i<n;++i) {
        p*=M(-11);
        f[i]=p*M(k)/M(i);
        if(i%2==0) f[i]=-f[i];
        a[i]=a[i-1]*M(k-i+1)*M(-11)/M(i);
      }
      eq(a,fps_exp(f),k,"threshold");
    }
  }
  // 単項式 exp(cx^d) では次数djの係数のみ c^j/j!。
  for(int d:{1,2,15,64,129}) {
    vc<M> f(137),a(137);
    f[d]=17;
    a[0]=1;
    for(int i=d;i<137;i+=d)a[i]=a[i-d]*M(17)/M(i/d);
    eq(a,fps_exp(f),d,"monomial");
    eq(a,fps_exp_dense(f),d,"monomial dense");
  }
  std::cout << M::get_mod() << ": " << calls << " calls, " << tot << " coefficients\n";
}
int main(){run<modint998>();run<modint107>();}
