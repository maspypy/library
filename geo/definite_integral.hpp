template <typename Re, typename F>
Re definite_integral(Re a, Re b, F f, int n) {
  Re I = 0;
  Re dx = (b - a) / n;
  Re fl = 0, fr = f(a);
  FOR(i, n) {
    Re lx = a + dx * i;
    Re rx = lx + dx;
    fl = fr;
    fr = f(rx);
    Re fm = f((lx + rx) / 2);
    I += fl + 4 * fm + fr;
  }
  return I * dx / 6;
}