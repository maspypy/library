// https://ac.nowcoder.com/acm/contest/81599/K

/*
type=0: empty
type=1: a
type=2: a*b*c
type=3: a*b+c+d*e
左端(a,c,e)の桁数の10べきももつ
*/
template <typename mint>
struct Arithmetic_Expression {
  int type;
  mint a, b, c, d, e, ten;
  Arithmetic_Expression(char ch = ' ') {
    if (ch == ' ') { type = 0; }
    elif (ch == '+') { type = 3, a = 0, b = 1, c = 0, d = 1, e = 0, ten = 1; }
    elif (ch == '*') { type = 2, a = 0, b = 1, c = 0, ten = 1; }
    elif ('0' <= ch && ch <= '9') { type = 1, a = (ch - '0'), ten = 10; }
    else {
      assert(0);
    }
  }
  mint eval() {
    if (type == 0) return 0;
    if (type == 1) return a;
    if (type == 2) return a * b * c;
    if (type == 3) return a * b + c + d * e;
    assert(0);
    return 0;
  }
};

template <typename mint>
struct Monoid_Arithmetic_Expression {
  using value_type = Arithmetic_Expression<mint>;
  using X = value_type;
  static X op(const X& L, const X& R) {
    if (L.type == 0) return R;
    if (R.type == 0) return L;
    assert(1 <= L.type && L.type <= 3);
    assert(1 <= R.type && R.type <= 3);
    X ANS;
    if (L.type == 1 && R.type == 1) {
      ANS.type = 1, ANS.a = L.a * R.ten + R.a;
      ANS.ten = L.ten * R.ten;
    }
    if (L.type == 1 && R.type == 2) {
      ANS.type = 2, ANS.a = L.a * R.ten + R.a, ANS.b = R.b, ANS.c = R.c;
      ANS.ten = L.ten * R.ten;
    }
    if (L.type == 1 && R.type == 3) {
      ANS.type = 3, ANS.a = L.a * R.ten + R.a, ANS.b = R.b, ANS.c = R.c, ANS.d = R.d, ANS.e = R.e;
      ANS.ten = L.ten * R.ten;
    }
    if (L.type == 2 && R.type == 1) {
      ANS.type = 2, ANS.a = L.a, ANS.b = L.b, ANS.c = L.c * R.ten + R.a;
      ANS.ten = L.ten;
    }
    if (L.type == 2 && R.type == 2) {
      ANS.type = 2;
      ANS.a = L.a, ANS.b = L.b * (L.c * R.ten + R.a) * R.b, ANS.c = R.c;
      ANS.ten = L.ten;
    }
    if (L.type == 2 && R.type == 3) {
      ANS.type = 3;
      ANS.a = L.a, ANS.b = L.b * (L.c * R.ten + R.a) * R.b, ANS.c = R.c, ANS.d = R.d, ANS.e = R.e;
      ANS.ten = L.ten;
    }
    if (L.type == 3 && R.type == 1) {
      ANS.type = 3;
      ANS.a = L.a, ANS.b = L.b, ANS.c = L.c, ANS.d = L.d, ANS.e = (L.e * R.ten + R.a);
      ANS.ten = L.ten;
    }
    if (L.type == 3 && R.type == 2) {
      ANS.type = 3;
      ANS.a = L.a, ANS.b = L.b, ANS.c = L.c, ANS.d = L.d * (L.e * R.ten + R.a) * R.b, ANS.e = R.c;
      ANS.ten = L.ten;
    }
    if (L.type == 3 && R.type == 3) {
      ANS.type = 3;
      ANS.a = L.a, ANS.b = L.b, ANS.c = L.c + L.d * (L.e * R.ten + R.a) * R.b + R.c, ANS.d = R.d, ANS.e = R.e;
      ANS.ten = L.ten;
    }
    return ANS;
  }
  static constexpr X unit() { return X(); }
  static constexpr bool commute = 0;
};
