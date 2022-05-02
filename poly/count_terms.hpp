#pragma once
template<typename mint>
int count_terms(const vc<mint>& f){
  int t = 0;
  FOR(i, len(f)) if(f[i] != mint(0)) ++t;
  return t;
}