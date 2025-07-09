---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/mul.hpp
    title: alg/monoid/mul.hpp
  - icon: ':question:'
    path: ds/sliding_window_aggregation.hpp
    title: ds/sliding_window_aggregation.hpp
  - icon: ':question:'
    path: linalg/matrix_mul.hpp
    title: linalg/matrix_mul.hpp
  - icon: ':question:'
    path: mod/crt3.hpp
    title: mod/crt3.hpp
  - icon: ':heavy_check_mark:'
    path: mod/factorial998.hpp
    title: mod/factorial998.hpp
  - icon: ':question:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: poly/convolution.hpp
    title: poly/convolution.hpp
  - icon: ':question:'
    path: poly/convolution_karatsuba.hpp
    title: poly/convolution_karatsuba.hpp
  - icon: ':question:'
    path: poly/convolution_naive.hpp
    title: poly/convolution_naive.hpp
  - icon: ':question:'
    path: poly/lagrange_interpolate_iota.hpp
    title: poly/lagrange_interpolate_iota.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  - icon: ':question:'
    path: poly/prefix_product_of_poly.hpp
    title: poly/prefix_product_of_poly.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/1_mytest/factorial_998.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if\
    \ defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
    // https://codeforces.com/blog/entry/126772?#comment-1154880\n#include <bits/allocator.h>\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n#pragma GCC target(\"avx2,popcnt\"\
    )\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using u8 = uint8_t;\nusing u16 = uint16_t;\nusing u32 = uint32_t;\nusing u64 =\
    \ uint64_t;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\nusing f128\
    \ = __float128;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate <>\nconstexpr\
    \ int infty<int> = 1'010'000'000;\ntemplate <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\n\
    template <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64\
    \ infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>)\
    \ * 2'000'000'000'000'000'000;\ntemplate <>\nconstexpr double infty<double> =\
    \ infty<ll>;\ntemplate <>\nconstexpr long double infty<long double> = infty<ll>;\n\
    \nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate <class T>\nusing\
    \ vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class\
    \ T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing\
    \ pq_max = priority_queue<T>;\ntemplate <class T>\nusing pq_min = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\n#define vv(type, name, h, ...) \\\n  vector<vector<type>>\
    \ name(h, vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...)   \\\n\
    \  vector<vector<vector<type>>> name( \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n\
    #define vvvv(type, name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>>\
    \ name( \\\n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
    \ vector<type>(__VA_ARGS__))))\n\n// https://trap.jp/post/1224/\n#define FOR1(a)\
    \ for (ll _ = 0; _ < ll(a); ++_)\n#define FOR2(i, a) for (ll i = 0; i < ll(a);\
    \ ++i)\n#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)\n#define FOR4(i,\
    \ a, b, c) for (ll i = a; i < ll(b); i += (c))\n#define FOR1_R(a) for (ll i =\
    \ (a) - 1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = (a) - 1; i >= ll(0);\
    \ --i)\n#define FOR3_R(i, a, b) for (ll i = (b) - 1; i >= ll(a); --i)\n#define\
    \ overload4(a, b, c, d, e, ...) e\n#define overload3(a, b, c, d, ...) d\n#define\
    \ FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n#define\
    \ FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\n#define\
    \ all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define elif else if\n\
    \n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n#define\
    \ fi first\n#define se second\n\n#define stoi stoll\n\nint popcnt(int x) { return\
    \ __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x))\
    \ & 1 ? -1 : 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ?\
    \ -1 : 1); }\nint popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u64 x) { return (__builtin_parityll(x) & 1 ? -1 : 1);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\n\
    T kth_bit(int k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T\
    \ x, int k) {\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit\
    \ {\n  struct iter {\n    UINT s;\n    iter(UINT s) : s(s) {}\n    int operator*()\
    \ const { return lowbit(s); }\n    iter &operator++() {\n      s &= s - 1;\n \
    \     return *this;\n    }\n    bool operator!=(const iter) const { return s !=\
    \ 0; }\n  };\n  UINT s;\n  all_bit(UINT s) : s(s) {}\n  iter begin() const { return\
    \ iter(s); }\n  iter end() const { return iter(0); }\n};\n\ntemplate <typename\
    \ UINT>\nstruct all_subset {\n  static_assert(is_unsigned<UINT>::value);\n  struct\
    \ iter {\n    UINT s, t;\n    bool ed;\n    iter(UINT s) : s(s), t(s), ed(0) {}\n\
    \    int operator*() const { return s ^ t; }\n    iter &operator++() {\n     \
    \ (t == 0 ? ed = 1 : t = (t - 1) & s);\n      return *this;\n    }\n    bool operator!=(const\
    \ iter) const { return !ed; }\n  };\n  UINT s;\n  all_subset(UINT s) : s(s) {}\n\
    \  iter begin() const { return iter(s); }\n  iter end() const { return iter(0);\
    \ }\n};\n\ntemplate <typename T>\nT floor(T a, T b) {\n  return a / b - (a % b\
    \ && (a ^ b) < 0);\n}\ntemplate <typename T>\nT ceil(T x, T y) {\n  return floor(x\
    \ + y - 1, y);\n}\ntemplate <typename T>\nT bmod(T x, T y) {\n  return x - y *\
    \ floor(x, y);\n}\ntemplate <typename T>\npair<T, T> divmod(T x, T y) {\n  T q\
    \ = floor(x, y);\n  return {q, x - q * y};\n}\n\ntemplate <typename T, typename\
    \ U>\nT SUM(const U &A) {\n  return std::accumulate(A.begin(), A.end(), T{});\n\
    }\n\n#define MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n\
    #define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c,\
    \ x) distance((c).begin(), upper_bound(all(c), (x)))\n#define UNIQUE(x) \\\n \
    \ sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\ntemplate\
    \ <typename T>\nT POP(deque<T> &que) {\n  T a = que.front();\n  que.pop_front();\n\
    \  return a;\n}\ntemplate <typename T>\nT POP(pq_min<T> &que) {\n  T a = que.top();\n\
    \  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(pq_max<T> &que) {\n\
    \  T a = que.top();\n  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(vc<T>\
    \ &que) {\n  T a = que.back();\n  que.pop_back();\n  return a;\n}\n\ntemplate\
    \ <typename F>\nll binary_search(F check, ll ok, ll ng, bool check_ok = true)\
    \ {\n  if (check_ok) assert(check(ok));\n  while (abs(ok - ng) > 1) {\n    auto\
    \ x = (ng + ok) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return ok;\n}\ntemplate\
    \ <typename F>\ndouble binary_search_real(F check, double ok, double ng, int iter\
    \ = 100) {\n  FOR(iter) {\n    double x = (ok + ng) / 2;\n    (check(x) ? ok :\
    \ ng) = x;\n  }\n  return (ok + ng) / 2;\n}\n\ntemplate <class T, class S>\ninline\
    \ bool chmax(T &a, const S &b) {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate\
    \ <class T, class S>\ninline bool chmin(T &a, const S &b) {\n  return (a > b ?\
    \ a = b, 1 : 0);\n}\n\n// ? \u306F -1\nvc<int> s_to_vi(const string &S, char first_char)\
    \ {\n  vc<int> A(S.size());\n  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] -\
    \ first_char : -1); }\n  return A;\n}\n\ntemplate <typename T, typename U>\nvector<T>\
    \ cumsum(vector<U> &A, int off = 1) {\n  int N = A.size();\n  vector<T> B(N +\
    \ 1);\n  FOR(i, N) { B[i + 1] = B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n\
    \  return B;\n}\n\n// stable sort\ntemplate <typename T>\nvector<int> argsort(const\
    \ vector<T> &A) {\n  vector<int> ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids),\n\
    \       [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });\n\
    \  return ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate <typename T>\nvc<T> rearrange(const\
    \ vc<T> &A, const vc<int> &I) {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n\
    \  return B;\n}\n\ntemplate <typename T, typename... Vectors>\nvoid concat(vc<T>\
    \ &first, const Vectors &...others) {\n  vc<T> &res = first;\n  (res.insert(res.end(),\
    \ others.begin(), others.end()), ...);\n}\n#endif\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 4 \"test/1_mytest/factorial_998.test.cpp\"\n\n\
    #line 1 \"mod/factorial998.hpp\"\n// 1<<20\nint factorial998table[1024] = {1,467742124,703158536,849331177,183632821,786787592,708945888,623860151,442444797,339076928,916211838,827641482,982515753,303461550,466748179,669060208,789885751,915736046,189957301,934038903,728735046,774755699,649374308,602288735,492352484,958678776,943233257,148504501,352124178,569334038,927469492,343841688,432351202,700916755,170721982,8283809,875807278,931632987,330722936,603566523,391470976,157944106,826756015,278928878,178606531,522053153,175494307,16217485,310769109,430912024,970167731,302127847,960178710,607169580,211863227,918097328,664502958,598427325,415194799,38321157,375608821,557298612,497769749,114695383,77784134,629192790,339438380,348348875,713806860,526342541,671850855,414726935,844082152,412454739,351143550,868784407,834684152,186057224,996072584,619190001,24770542,765280770,513490122,468949120,867194196,866447292,937135640,560788103,308335177,703539315,252044620,119916775,298069903,43651994,148641017,730387621,856452172,74265901,626807500,980602375,42825068,348086475,162321900,207340584,151258454,461547160,320321845,361026143,882876292,842563318,257705870,158156446,292795459,984763947,917068833,811332379,782439665,944504775,298167161,141501910,155584237,149720256,71954352,666430555,580966229,884747116,616367471,918981127,310328833,724405658,383796145,256700166,487819118,642491144,181867555,524937737,222137750,445244561,79921588,253457448,405659726,260707689,740044210,654653354,229885020,230551611,616689587,939003921,565960348,904184966,133298693,859220865,186139683,765071679,247651638,451157944,929341123,503724944,768266737,142218056,910573117,274579400,151387843,212671109,815271666,406331931,154251304,642676789,570372925,976277122,442985463,928799971,817581666,797627351,100113334,877639265,541537097,434482347,300960222,270085755,481153328,236088097,686884498,323505794,897572220,900787550,277507290,157634146,892066519,616420589,46056764,697140618,592483685,896871487,896388868,106444279,115102765,191484323,62322499,434613622,426026852,378184205,194359325,415197585,965735328,598860936,653751428,942602959,475099103,642401460,77868208,464952529,549976420,705774928,635299526,704085554,809044086,670938184,799176916,58985566,402328281,182103192,921913660,674272214,428301920,520916749,127424638,296779896,166780239,19634060,95873539,708947606,532272305,980167862,7015847,370183454,45567119,866949818,374428494,25583689,351370758,835388325,232690098,42002598,17055285,985022727,214528454,122907290,793349516,609331634,87133548,248246624,448572380,502875867,183097664,536117329,170926160,381772251,37038194,374439881,94285547,880631489,452052533,739811514,675382782,587926712,179133902,694266603,338843576,281485671,813341519,616512705,222785194,382494725,471654428,961907947,442140830,702296161,548575377,388901073,19119024,545916498,947169254,801677200,377657430,634980290,246239186,13175103,239754689,656729178,364003283,646568868,584909084,690387116,452007054,131381944,908149670,807287523,802277179,745423153,893994782,197548253,376096720,105840336,687751559,170787791,928507410,620382696,446955151,139665212,882526402,494793004,107171423,753993075,467588754,207595897,269813018,941027990,856873596,717085190,245280646,792026805,548741735,523767341,637697735,261200153,89666563,344573088,15832984,558492246,825051585,923222974,826620400,558080789,657328927,991078225,706029275,738905108,401212366,980043233,895405022,597894231,636951913,947342478,786075225,395095090,188433847,121279219,860403973,396099425,240442489,521535558,280382318,58023116,735594008,8696133,477645338,223630480,816606673,680021043,362424474,181667447,504295826,332167472,766361494,992840497,417671938,376941230,11880047,275790726,106186450,150546053,966438917,431896075,158021876,734833661,328332504,632143386,962477966,638741189,728804571,753715698,20536106,45105841,271673172,982138522,604809222,199722980,211807634,478008419,194715230,246865373,316443541,869035744,202922168,245262975,136244583,650969410,566222746,55188168,495968583,571946805,188658038,353720239,830419870,669127165,86710835,810103736,630008035,764354348,209246227,277861984,725469211,151404581,894191013,775554083,634671016,170299187,471849450,575347258,505276194,636730506,40086858,386228700,789875034,998219457,359035788,843760715,864829665,794240359,241486050,48334220,583177582,714653706,617669563,132782021,779225352,333301287,520569296,508276228,689073648,573645847,200419842,911561316,310562870,204959007,879280837,762843188,103128368,133300147,648946778,287218789,662474952,587555465,105622721,648151526,517033362,729251452,850555187,708613432,874408867,345608416,690718720,10813958,42384375,882264058,825490058,252850511,652942840,202604098,277615259,862885671,582470925,190843016,534488148,187675153,911660635,377262012,642854978,359397276,712333871,580131409,841639861,925383257,213683380,25291651,974815450,32032244,119030165,443676106,555727293,170519648,171131074,839941962,789829593,140975543,845347712,303299112,530420097,857005350,249174130,224087061,311280308,404814306,567648772,766512373,470895965,294358155,625218604,89534510,513216330,78173719,22818060,254922573,292417477,415060121,208989124,960117615,570018845,237661008,442774488,871349246,161574942,548661451,313471555,448096394,587422360,987939533,254478574,113844945,268886375,927289435,664834607,983476167,390569280,363763327,935767957,159015901,508613041,134148582,127417680,484767855,825835285,43847241,972918293,151969014,768480291,729490470,76727400,384998943,648970509,764966281,391326774,585299643,661473977,530021579,368308424,81083443,981417794,185781362,169555925,934957641,56005264,296483160,853982963,489694611,73207251,20297311,431253211,168162850,36271383,689526671,397669110,705876730,785504919,764896820,936514026,350141918,784778738,682324919,140913543,862125900,723248565,369074340,146936534,226913694,277886748,856792647,13654547,141461269,255233971,979535193,747662027,452683681,338311679,399620140,306913085,817524367,333578440,943193170,387930488,964713035,554372227,524201507,267870305,698863503,695139108,399857384,830659092,479624682,594238820,768224890,956955770,940576967,920740072,282055556,621677930,847367415,619094041,432519599,192780811,912052381,263304046,114280963,307107320,956809356,118706101,836710721,356893069,427113038,55360495,892694364,443807400,568616581,130165565,732273554,778059496,95936679,629634134,383940143,474733431,271200931,253893765,65679204,670721645,268831988,225698685,424701963,654858732,405695790,894299102,797306377,464723449,647679843,730366154,956550665,898568348,313188681,661403769,346715295,358990430,868898456,719464962,978551995,772931269,255694712,379904456,393101377,130818973,810783770,78951115,608848341,941552927,523163696,581658405,188869913,161971620,114600913,300038465,126906968,572973411,118017645,806069307,430432761,310699012,989119052,282768145,557792692,611036992,427168405,84497995,529589599,967936672,416953197,549641787,787274930,514952744,646568513,39329263,765390776,831388678,299074396,102522509,886062498,598990751,553048069,305737423,388746841,13007805,3445560,568306294,109543305,847740132,746222360,454654676,748993028,222910140,861308982,390243513,692742883,789475199,153430402,299806798,913070840,881332402,245792511,618823409,1817990,897836424,726794141,700802042,472214481,97004031,479899815,573979309,752576644,374801082,599964908,894966385,178103304,12240556,393873628,855241924,305678131,971858774,281586141,87362107,41844894,175133514,276243521,997376957,260427125,439339251,64661516,362212695,186181824,423316311,267640938,299252572,810040987,857956827,758991665,207700847,399398818,747579039,814755712,298373935,307448236,42074518,982127624,538863790,528558929,96501138,813255509,611769398,710541518,408153968,675346745,970094012,791931126,811516976,618049736,264048084,209805699,909045292,645349311,416989597,590393407,320547207,342653696,860169617,856611053,475149267,124801433,547187333,466598598,266454901,554467907,868909135,199244107,548833449,20952517,234169026,117025205,804238552,205574540,590283297,822322644,866010856,477388420,935768507,424373916,951967787,344871828,133969287,937034425,309380768,666909962,726492795,996576193,883938945,869749688,313581344,65216237,88860786,208895640,888760811,854567609,328142793,121852766,928690075,135269006,333105486,502240551,573712984,397698082,935117672,718828733,440474396,335628894,184935718,788258676,646732201,68099895,167036421,362572358,787671392,666366534,193503119,74429287,132805884,796935846,124574194,926012440,147265585,722608579,526866610,452261307,990444071,4595579,147427028,774597449,678783012,568563934,383628463,68242206,163493293,352851801,123192034,529859554,14733470,565063217,178575398,580871309,135817500,313966456,647215844,118781836,106243172,796669460,48496927,772979683,715961917,546863206,601711799,644312478,629259662,738295002,692301787,149995411,864799423,284186171,246177326,268779154,86400350,518698490,321709079,946212693,800553099,865864136,244789848,386206318,851633075,713794602,131117952,280474884,243820970,820033654,399700655,825581574,443639603,774376660,362476217,552383080,436759518,538430048,965968656,150434699,563163603,352073025,840124972,152029247,902082055,770264937,747653807,934664232,541451013,807031739,854866728,503502641,283479207,297947602,488469464,205196166,381583984,108455782,570592132,363674728,134077711,356931610,887112858,273780969,443297964,650953636,402662299,894089640,71844431,33030748,208583995,597099208,671156881,875032178,998244352,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};\n\
    \nint factorial998(ll n) {\n  constexpr int mod = 998244353;\n  if (n >= mod)\
    \ return 0;\n  auto [q, r] = divmod<int>(n, 1 << 20);\n  ll x = factorial998table[q];\n\
    \  int s = q << 20;\n  FOR(i, r) x = x * (s + i + 1) % mod;\n  return x;\n}\n\
    #line 2 \"mod/modint_common.hpp\"\n\nstruct has_mod_impl {\n  template <class\
    \ T>\n  static auto check(T &&x) -> decltype(x.get_mod(), std::true_type{});\n\
    \  template <class T>\n  static auto check(...) -> std::false_type;\n};\n\ntemplate\
    \ <class T>\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
    \ {};\n\ntemplate <typename mint>\nmint inv(int n) {\n  static const int mod =\
    \ mint::get_mod();\n  static vector<mint> dat = {0, 1};\n  assert(0 <= n);\n \
    \ if (n >= mod) n %= mod;\n  while (len(dat) <= n) {\n    int k = len(dat);\n\
    \    int q = (mod + k - 1) / k;\n    dat.eb(dat[k * q - mod] * mint::raw(q));\n\
    \  }\n  return dat[n];\n}\n\ntemplate <>\ndouble inv<double>(int n) {\n  assert(n\
    \ != 0);\n  return 1.0 / n;\n}\n\ntemplate <typename mint>\nmint fact(int n) {\n\
    \  static const int mod = mint::get_mod();\n  assert(0 <= n && n < mod);\n  static\
    \ vector<mint> dat = {1, 1};\n  while (len(dat) <= n) dat.eb(dat[len(dat) - 1]\
    \ * mint(len(dat)));\n  return dat[n];\n}\n\ntemplate <typename mint>\nmint fact_inv(int\
    \ n) {\n  static vector<mint> dat = {1, 1};\n  if (n < 0) return mint(0);\n  while\
    \ (len(dat) <= n) dat.eb(dat[len(dat) - 1] * inv<mint>(len(dat)));\n  return dat[n];\n\
    }\n\ntemplate <class mint, class... Ts>\nmint fact_invs(Ts... xs) {\n  return\
    \ (mint(1) * ... * fact_inv<mint>(xs));\n}\n\ntemplate <typename mint, class Head,\
    \ class... Tail>\nmint multinomial(Head &&head, Tail &&...tail) {\n  return fact<mint>(head)\
    \ * fact_invs<mint>(std::forward<Tail>(tail)...);\n}\n\ntemplate <typename mint>\n\
    mint C_dense(int n, int k) {\n  assert(n >= 0);\n  if (k < 0 || n < k) return\
    \ 0;\n  static vvc<mint> C;\n  static int H = 0, W = 0;\n  auto calc = [&](int\
    \ i, int j) -> mint {\n    if (i == 0) return (j == 0 ? mint(1) : mint(0));\n\
    \    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);\n  };\n  if (W <= k) {\n\
    \    FOR(i, H) {\n      C[i].resize(k + 1);\n      FOR(j, W, k + 1) { C[i][j]\
    \ = calc(i, j); }\n    }\n    W = k + 1;\n  }\n  if (H <= n) {\n    C.resize(n\
    \ + 1);\n    FOR(i, H, n + 1) {\n      C[i].resize(W);\n      FOR(j, W) { C[i][j]\
    \ = calc(i, j); }\n    }\n    H = n + 1;\n  }\n  return C[n][k];\n}\n\ntemplate\
    \ <typename mint, bool large = false, bool dense = false>\nmint C(ll n, ll k)\
    \ {\n  assert(n >= 0);\n  if (k < 0 || n < k) return 0;\n  if constexpr (dense)\
    \ return C_dense<mint>(n, k);\n  if constexpr (!large) return multinomial<mint>(n,\
    \ k, n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i, k) x *= mint(n - i);\n\
    \  return x * fact_inv<mint>(k);\n}\n\ntemplate <typename mint, bool large = false>\n\
    mint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0 <= k && k <= n);\n  if\
    \ (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n - k);\n  return\
    \ mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d](1-x)^{-n}\ntemplate <typename mint,\
    \ bool large = false, bool dense = false>\nmint C_negative(ll n, ll d) {\n  assert(n\
    \ >= 0);\n  if (d < 0) return mint(0);\n  if (n == 0) {\n    return (d == 0 ?\
    \ mint(1) : mint(0));\n  }\n  return C<mint, large, dense>(n + d - 1, d);\n}\n\
    #line 3 \"mod/modint.hpp\"\n\ntemplate <int mod>\nstruct modint {\n  static constexpr\
    \ u32 umod = u32(mod);\n  static_assert(umod < u32(1) << 31);\n  u32 val;\n\n\
    \  static modint raw(u32 v) {\n    modint x;\n    x.val = v;\n    return x;\n\
    \  }\n  constexpr modint() : val(0) {}\n  constexpr modint(u32 x) : val(x % umod)\
    \ {}\n  constexpr modint(u64 x) : val(x % umod) {}\n  constexpr modint(u128 x)\
    \ : val(x % umod) {}\n  constexpr modint(int x) : val((x %= mod) < 0 ? x + mod\
    \ : x){};\n  constexpr modint(ll x) : val((x %= mod) < 0 ? x + mod : x){};\n \
    \ constexpr modint(i128 x) : val((x %= mod) < 0 ? x + mod : x){};\n  bool operator<(const\
    \ modint &other) const { return val < other.val; }\n  modint &operator+=(const\
    \ modint &p) {\n    if ((val += p.val) >= umod) val -= umod;\n    return *this;\n\
    \  }\n  modint &operator-=(const modint &p) {\n    if ((val += umod - p.val) >=\
    \ umod) val -= umod;\n    return *this;\n  }\n  modint &operator*=(const modint\
    \ &p) {\n    val = u64(val) * p.val % umod;\n    return *this;\n  }\n  modint\
    \ &operator/=(const modint &p) {\n    *this *= p.inverse();\n    return *this;\n\
    \  }\n  modint operator-() const { return modint::raw(val ? mod - val : u32(0));\
    \ }\n  modint operator+(const modint &p) const { return modint(*this) += p; }\n\
    \  modint operator-(const modint &p) const { return modint(*this) -= p; }\n  modint\
    \ operator*(const modint &p) const { return modint(*this) *= p; }\n  modint operator/(const\
    \ modint &p) const { return modint(*this) /= p; }\n  bool operator==(const modint\
    \ &p) const { return val == p.val; }\n  bool operator!=(const modint &p) const\
    \ { return val != p.val; }\n  modint inverse() const {\n    int a = val, b = mod,\
    \ u = 1, v = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t *\
    \ b, b), swap(u -= t * v, v);\n    }\n    return modint(u);\n  }\n  modint pow(ll\
    \ n) const {\n    if (n < 0) return inverse().pow(-n);\n    assert(n >= 0);\n\
    \    modint ret(1), mul(val);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n\
    \      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n  static constexpr\
    \ int get_mod() { return mod; }\n  // (n, r), r \u306F 1 \u306E 2^n \u4E57\u6839\
    \n  static constexpr pair<int, int> ntt_info() {\n    if (mod == 120586241) return\
    \ {20, 74066978};\n    if (mod == 167772161) return {25, 17};\n    if (mod ==\
    \ 469762049) return {26, 30};\n    if (mod == 754974721) return {24, 362};\n \
    \   if (mod == 880803841) return {23, 211};\n    if (mod == 943718401) return\
    \ {22, 663003469};\n    if (mod == 998244353) return {23, 31};\n    if (mod ==\
    \ 1004535809) return {21, 582313106};\n    if (mod == 1012924417) return {21,\
    \ 368093570};\n    return {-1, -1};\n  }\n  static constexpr bool can_ntt() {\
    \ return ntt_info().fi != -1; }\n};\n\n#ifdef FASTIO\ntemplate <int mod>\nvoid\
    \ rd(modint<mod> &x) {\n  fastio::rd(x.val);\n  x.val %= mod;\n  // assert(0 <=\
    \ x.val && x.val < mod);\n}\ntemplate <int mod>\nvoid wt(modint<mod> x) {\n  fastio::wt(x.val);\n\
    }\n#endif\n\nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    #line 3 \"linalg/matrix_mul.hpp\"\n\r\ntemplate <class T, typename enable_if<has_mod<T>::value>::type*\
    \ = nullptr>\r\nvc<vc<T>> matrix_mul(const vc<vc<T>>& A, const vc<vc<T>>& B, int\
    \ N1 = -1,\r\n                     int N2 = -1, int N3 = -1) {\r\n  if (N1 ==\
    \ -1) { N1 = len(A), N2 = len(B), N3 = len(B[0]); }\r\n  vv(u32, b, N3, N2);\r\
    \n  FOR(i, N2) FOR(j, N3) b[j][i] = B[i][j].val;\r\n  vv(T, C, N1, N3);\r\n\r\n\
    \  if ((T::get_mod() < (1 << 30)) && N2 <= 16) {\r\n    FOR(i, N1) FOR(j, N3)\
    \ {\r\n      u64 sm = 0;\r\n      FOR(m, N2) sm += u64(A[i][m].val) * b[j][m];\r\
    \n      C[i][j] = sm;\r\n    }\r\n  } else {\r\n    FOR(i, N1) FOR(j, N3) {\r\n\
    \      u128 sm = 0;\r\n      FOR(m, N2) sm += u64(A[i][m].val) * b[j][m];\r\n\
    \      C[i][j] = T::raw(sm % (T::get_mod()));\r\n    }\r\n  }\r\n  return C;\r\
    \n}\r\n\r\ntemplate <class T, typename enable_if<!has_mod<T>::value>::type* =\
    \ nullptr>\r\nvc<vc<T>> matrix_mul(const vc<vc<T>>& A, const vc<vc<T>>& B, int\
    \ N1 = -1,\r\n                     int N2 = -1, int N3 = -1) {\r\n  if (N1 ==\
    \ -1) { N1 = len(A), N2 = len(B), N3 = len(B[0]); }\r\n  vv(T, b, N2, N3);\r\n\
    \  FOR(i, N2) FOR(j, N3) b[j][i] = B[i][j];\r\n  vv(T, C, N1, N3);\r\n  FOR(n,\
    \ N1) FOR(m, N2) FOR(k, N3) C[n][k] += A[n][m] * b[k][m];\r\n  return C;\r\n}\r\
    \n\r\n// square-matrix defined as array\r\ntemplate <class T, int N,\r\n     \
    \     typename enable_if<has_mod<T>::value>::type* = nullptr>\r\narray<array<T,\
    \ N>, N> matrix_mul(const array<array<T, N>, N>& A,\r\n                      \
    \           const array<array<T, N>, N>& B) {\r\n  array<array<T, N>, N> C{};\r\
    \n\r\n  if ((T::get_mod() < (1 << 30)) && N <= 16) {\r\n    FOR(i, N) FOR(k, N)\
    \ {\r\n      u64 sm = 0;\r\n      FOR(j, N) sm += u64(A[i][j].val) * (B[j][k].val);\r\
    \n      C[i][k] = sm;\r\n    }\r\n  } else {\r\n    FOR(i, N) FOR(k, N) {\r\n\
    \      u128 sm = 0;\r\n      FOR(j, N) sm += u64(A[i][j].val) * (B[j][k].val);\r\
    \n      C[i][k] = sm;\r\n    }\r\n  }\r\n  return C;\r\n}\r\n\r\n// square-matrix\
    \ defined as array\r\ntemplate <class T, int N,\r\n          typename enable_if<!has_mod<T>::value>::type*\
    \ = nullptr>\r\narray<array<T, N>, N> matrix_mul(const array<array<T, N>, N>&\
    \ A,\r\n                                 const array<array<T, N>, N>& B) {\r\n\
    \  array<array<T, N>, N> C{};\r\n  FOR(i, N) FOR(j, N) FOR(k, N) C[i][k] += A[i][j]\
    \ * B[j][k];\r\n  return C;\r\n}\r\n#line 2 \"alg/monoid/mul.hpp\"\n\r\ntemplate\
    \ <class T>\r\nstruct Monoid_Mul {\r\n  using value_type = T;\r\n  using X = T;\r\
    \n  static constexpr X op(const X &x, const X &y) noexcept { return x * y; }\r\
    \n  static constexpr X inverse(const X &x) noexcept { return X(1) / x; }\r\n \
    \ static constexpr X unit() { return X(1); }\r\n  static constexpr bool commute\
    \ = true;\r\n};\r\n#line 1 \"ds/sliding_window_aggregation.hpp\"\ntemplate <class\
    \ Monoid>\nstruct Sliding_Window_Aggregation {\n  using X = typename Monoid::value_type;\n\
    \  using value_type = X;\n  int sz = 0;\n  vc<X> dat;\n  vc<X> cum_l;\n  X cum_r;\n\
    \n  Sliding_Window_Aggregation() : cum_l({Monoid::unit()}), cum_r(Monoid::unit())\
    \ {}\n\n  int size() { return sz; }\n\n  void push(X x) {\n    ++sz;\n    cum_r\
    \ = Monoid::op(cum_r, x);\n    dat.eb(x);\n  }\n\n  void pop() {\n    --sz;\n\
    \    cum_l.pop_back();\n    if (len(cum_l) == 0) {\n      cum_l = {Monoid::unit()};\n\
    \      cum_r = Monoid::unit();\n      while (len(dat) > 1) {\n        cum_l.eb(Monoid::op(dat.back(),\
    \ cum_l.back()));\n        dat.pop_back();\n      }\n      dat.pop_back();\n \
    \   }\n  }\n\n  X lprod() { return cum_l.back(); }\n  X rprod() { return cum_r;\
    \ }\n\n  X prod() { return Monoid::op(cum_l.back(), cum_r); }\n};\n\n// \u5B9A\
    \u6570\u500D\u306F\u76EE\u306B\u898B\u3048\u3066\u9045\u304F\u306A\u308B\u306E\
    \u3067\u3001queue \u3067\u3088\u3044\u3068\u304D\u306F\u4F7F\u308F\u306A\u3044\
    \ntemplate <class Monoid>\nstruct SWAG_deque {\n  using X = typename Monoid::value_type;\n\
    \  using value_type = X;\n  int sz;\n  vc<X> dat_l, dat_r;\n  vc<X> cum_l, cum_r;\n\
    \n  SWAG_deque() : sz(0), cum_l({Monoid::unit()}), cum_r({Monoid::unit()}) {}\n\
    \n  int size() { return sz; }\n\n  void push_back(X x) {\n    ++sz;\n    dat_r.eb(x);\n\
    \    cum_r.eb(Monoid::op(cum_r.back(), x));\n  }\n\n  void push_front(X x) {\n\
    \    ++sz;\n    dat_l.eb(x);\n    cum_l.eb(Monoid::op(x, cum_l.back()));\n  }\n\
    \n  void push(X x) { push_back(x); }\n\n  void clear() {\n    sz = 0;\n    dat_l.clear(),\
    \ dat_r.clear();\n    cum_l = {Monoid::unit()}, cum_r = {Monoid::unit()};\n  }\n\
    \n  void pop_front() {\n    if (sz == 1) return clear();\n    if (dat_l.empty())\
    \ rebuild();\n    --sz;\n    dat_l.pop_back();\n    cum_l.pop_back();\n  }\n\n\
    \  void pop_back() {\n    if (sz == 1) return clear();\n    if (dat_r.empty())\
    \ rebuild();\n    --sz;\n    dat_r.pop_back();\n    cum_r.pop_back();\n  }\n\n\
    \  void pop() { pop_front(); }\n\n  X front() {\n    if (len(dat_l)) return dat_l.back();\n\
    \    return dat_r[0];\n  }\n\n  X lprod() { return cum_l.back(); }\n  X rprod()\
    \ { return cum_r.back(); }\n  X prod() { return Monoid::op(cum_l.back(), cum_r.back());\
    \ }\n  X prod_all() { return prod(); }\n\nprivate:\n  void rebuild() {\n    vc<X>\
    \ X;\n    reverse(all(dat_l));\n    concat(X, dat_l, dat_r);\n    clear();\n \
    \   int m = len(X) / 2;\n    FOR_R(i, m) push_front(X[i]);\n    FOR(i, m, len(X))\
    \ push_back(X[i]);\n    assert(sz == len(X));\n  }\n};\n#line 2 \"mod/mod_inv.hpp\"\
    \n\r\n// long \u3067\u3082\u5927\u4E08\u592B\r\n// (val * x - 1) \u304C mod \u306E\
    \u500D\u6570\u306B\u306A\u308B\u3088\u3046\u306B\u3059\u308B\r\n// \u7279\u306B\
    \ mod=0 \u306A\u3089 x=0 \u304C\u6E80\u305F\u3059\r\nll mod_inv(ll val, ll mod)\
    \ {\r\n  if (mod == 0) return 0;\r\n  mod = abs(mod);\r\n  val %= mod;\r\n  if\
    \ (val < 0) val += mod;\r\n  ll a = val, b = mod, u = 1, v = 0, t;\r\n  while\
    \ (b > 0) {\r\n    t = a / b;\r\n    swap(a -= t * b, b), swap(u -= t * v, v);\r\
    \n  }\r\n  if (u < 0) u += mod;\r\n  return u;\r\n}\r\n#line 2 \"mod/crt3.hpp\"\
    \n\nconstexpr u32 mod_pow_constexpr(u64 a, u64 n, u32 mod) {\n  a %= mod;\n  u64\
    \ res = 1;\n  FOR(32) {\n    if (n & 1) res = res * a % mod;\n    a = a * a %\
    \ mod, n /= 2;\n  }\n  return res;\n}\n\ntemplate <typename T, u32 p0, u32 p1>\n\
    T CRT2(u64 a0, u64 a1) {\n  static_assert(p0 < p1);\n  static constexpr u64 x0_1\
    \ = mod_pow_constexpr(p0, p1 - 2, p1);\n  u64 c = (a1 - a0 + p1) * x0_1 % p1;\n\
    \  return a0 + c * p0;\n}\n\ntemplate <typename T, u32 p0, u32 p1, u32 p2>\nT\
    \ CRT3(u64 a0, u64 a1, u64 a2) {\n  static_assert(p0 < p1 && p1 < p2);\n  static\
    \ constexpr u64 x1 = mod_pow_constexpr(p0, p1 - 2, p1);\n  static constexpr u64\
    \ x2 = mod_pow_constexpr(u64(p0) * p1 % p2, p2 - 2, p2);\n  static constexpr u64\
    \ p01 = u64(p0) * p1;\n  u64 c = (a1 - a0 + p1) * x1 % p1;\n  u64 ans_1 = a0 +\
    \ c * p0;\n  c = (a2 - ans_1 % p2 + p2) * x2 % p2;\n  return T(ans_1) + T(c) *\
    \ T(p01);\n}\n\ntemplate <typename T, u32 p0, u32 p1, u32 p2, u32 p3>\nT CRT4(u64\
    \ a0, u64 a1, u64 a2, u64 a3) {\n  static_assert(p0 < p1 && p1 < p2 && p2 < p3);\n\
    \  static constexpr u64 x1 = mod_pow_constexpr(p0, p1 - 2, p1);\n  static constexpr\
    \ u64 x2 = mod_pow_constexpr(u64(p0) * p1 % p2, p2 - 2, p2);\n  static constexpr\
    \ u64 x3 = mod_pow_constexpr(u64(p0) * p1 % p3 * p2 % p3, p3 - 2, p3);\n  static\
    \ constexpr u64 p01 = u64(p0) * p1;\n  u64 c = (a1 - a0 + p1) * x1 % p1;\n  u64\
    \ ans_1 = a0 + c * p0;\n  c = (a2 - ans_1 % p2 + p2) * x2 % p2;\n  u128 ans_2\
    \ = ans_1 + c * static_cast<u128>(p01);\n  c = (a3 - ans_2 % p3 + p3) * x3 % p3;\n\
    \  return T(ans_2) + T(c) * T(p01) * T(p2);\n}\n\ntemplate <typename T, u32 p0,\
    \ u32 p1, u32 p2, u32 p3, u32 p4>\nT CRT5(u64 a0, u64 a1, u64 a2, u64 a3, u64\
    \ a4) {\n  static_assert(p0 < p1 && p1 < p2 && p2 < p3 && p3 < p4);\n  static\
    \ constexpr u64 x1 = mod_pow_constexpr(p0, p1 - 2, p1);\n  static constexpr u64\
    \ x2 = mod_pow_constexpr(u64(p0) * p1 % p2, p2 - 2, p2);\n  static constexpr u64\
    \ x3 = mod_pow_constexpr(u64(p0) * p1 % p3 * p2 % p3, p3 - 2, p3);\n  static constexpr\
    \ u64 x4 = mod_pow_constexpr(u64(p0) * p1 % p4 * p2 % p4 * p3 % p4, p4 - 2, p4);\n\
    \  static constexpr u64 p01 = u64(p0) * p1;\n  static constexpr u64 p23 = u64(p2)\
    \ * p3;\n  u64 c = (a1 - a0 + p1) * x1 % p1;\n  u64 ans_1 = a0 + c * p0;\n  c\
    \ = (a2 - ans_1 % p2 + p2) * x2 % p2;\n  u128 ans_2 = ans_1 + c * static_cast<u128>(p01);\n\
    \  c = static_cast<u64>(a3 - ans_2 % p3 + p3) * x3 % p3;\n  u128 ans_3 = ans_2\
    \ + static_cast<u128>(c * p2) * p01;\n  c = static_cast<u64>(a4 - ans_3 % p4 +\
    \ p4) * x4 % p4;\n  return T(ans_3) + T(c) * T(p01) * T(p23);\n}\n#line 2 \"poly/convolution_naive.hpp\"\
    \n\r\ntemplate <class T, typename enable_if<!has_mod<T>::value>::type* = nullptr>\r\
    \nvc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\r\n  int n = int(a.size()),\
    \ m = int(b.size());\r\n  if (n > m) return convolution_naive<T>(b, a);\r\n  if\
    \ (n == 0) return {};\r\n  vector<T> ans(n + m - 1);\r\n  FOR(i, n) FOR(j, m)\
    \ ans[i + j] += a[i] * b[j];\r\n  return ans;\r\n}\r\n\r\ntemplate <class T, typename\
    \ enable_if<has_mod<T>::value>::type* = nullptr>\r\nvc<T> convolution_naive(const\
    \ vc<T>& a, const vc<T>& b) {\r\n  int n = int(a.size()), m = int(b.size());\r\
    \n  if (n > m) return convolution_naive<T>(b, a);\r\n  if (n == 0) return {};\r\
    \n  vc<T> ans(n + m - 1);\r\n  if (n <= 16 && (T::get_mod() < (1 << 30))) {\r\n\
    \    for (int k = 0; k < n + m - 1; ++k) {\r\n      int s = max(0, k - m + 1);\r\
    \n      int t = min(n, k + 1);\r\n      u64 sm = 0;\r\n      for (int i = s; i\
    \ < t; ++i) { sm += u64(a[i].val) * (b[k - i].val); }\r\n      ans[k] = sm;\r\n\
    \    }\r\n  } else {\r\n    for (int k = 0; k < n + m - 1; ++k) {\r\n      int\
    \ s = max(0, k - m + 1);\r\n      int t = min(n, k + 1);\r\n      u128 sm = 0;\r\
    \n      for (int i = s; i < t; ++i) { sm += u64(a[i].val) * (b[k - i].val); }\r\
    \n      ans[k] = T::raw(sm % T::get_mod());\r\n    }\r\n  }\r\n  return ans;\r\
    \n}\r\n#line 2 \"poly/convolution_karatsuba.hpp\"\n\n// \u4EFB\u610F\u306E\u74B0\
    \u3067\u3067\u304D\u308B\ntemplate <typename T>\nvc<T> convolution_karatsuba(const\
    \ vc<T>& f, const vc<T>& g) {\n  const int thresh = 30;\n  if (min(len(f), len(g))\
    \ <= thresh) return convolution_naive(f, g);\n  int n = max(len(f), len(g));\n\
    \  int m = ceil(n, 2);\n  vc<T> f1, f2, g1, g2;\n  if (len(f) < m) f1 = f;\n \
    \ if (len(f) >= m) f1 = {f.begin(), f.begin() + m};\n  if (len(f) >= m) f2 = {f.begin()\
    \ + m, f.end()};\n  if (len(g) < m) g1 = g;\n  if (len(g) >= m) g1 = {g.begin(),\
    \ g.begin() + m};\n  if (len(g) >= m) g2 = {g.begin() + m, g.end()};\n  vc<T>\
    \ a = convolution_karatsuba(f1, g1);\n  vc<T> b = convolution_karatsuba(f2, g2);\n\
    \  FOR(i, len(f2)) f1[i] += f2[i];\n  FOR(i, len(g2)) g1[i] += g2[i];\n  vc<T>\
    \ c = convolution_karatsuba(f1, g1);\n  vc<T> F(len(f) + len(g) - 1);\n  assert(2\
    \ * m + len(b) <= len(F));\n  FOR(i, len(a)) F[i] += a[i], c[i] -= a[i];\n  FOR(i,\
    \ len(b)) F[2 * m + i] += b[i], c[i] -= b[i];\n  if (c.back() == T(0)) c.pop_back();\n\
    \  FOR(i, len(c)) if (c[i] != T(0)) F[m + i] += c[i];\n  return F;\n}\n#line 2\
    \ \"poly/ntt.hpp\"\n\r\ntemplate <class mint>\r\nvoid ntt(vector<mint>& a, bool\
    \ inverse) {\r\n  assert(mint::can_ntt());\r\n  const int rank2 = mint::ntt_info().fi;\r\
    \n  const int mod = mint::get_mod();\r\n  static array<mint, 30> root, iroot;\r\
    \n  static array<mint, 30> rate2, irate2;\r\n  static array<mint, 30> rate3, irate3;\r\
    \n\r\n  assert(rank2 != -1 && len(a) <= (1 << max(0, rank2)));\r\n\r\n  static\
    \ bool prepared = 0;\r\n  if (!prepared) {\r\n    prepared = 1;\r\n    root[rank2]\
    \ = mint::ntt_info().se;\r\n    iroot[rank2] = mint(1) / root[rank2];\r\n    FOR_R(i,\
    \ rank2) {\r\n      root[i] = root[i + 1] * root[i + 1];\r\n      iroot[i] = iroot[i\
    \ + 1] * iroot[i + 1];\r\n    }\r\n    mint prod = 1, iprod = 1;\r\n    for (int\
    \ i = 0; i <= rank2 - 2; i++) {\r\n      rate2[i] = root[i + 2] * prod;\r\n  \
    \    irate2[i] = iroot[i + 2] * iprod;\r\n      prod *= iroot[i + 2];\r\n    \
    \  iprod *= root[i + 2];\r\n    }\r\n    prod = 1, iprod = 1;\r\n    for (int\
    \ i = 0; i <= rank2 - 3; i++) {\r\n      rate3[i] = root[i + 3] * prod;\r\n  \
    \    irate3[i] = iroot[i + 3] * iprod;\r\n      prod *= iroot[i + 3];\r\n    \
    \  iprod *= root[i + 3];\r\n    }\r\n  }\r\n\r\n  int n = int(a.size());\r\n \
    \ int h = topbit(n);\r\n  assert(n == 1 << h);\r\n  if (!inverse) {\r\n    int\
    \ len = 0;\r\n    while (len < h) {\r\n      if (h - len == 1) {\r\n        int\
    \ p = 1 << (h - len - 1);\r\n        mint rot = 1;\r\n        FOR(s, 1 << len)\
    \ {\r\n          int offset = s << (h - len);\r\n          FOR(i, p) {\r\n   \
    \         auto l = a[i + offset];\r\n            auto r = a[i + offset + p] *\
    \ rot;\r\n            a[i + offset] = l + r;\r\n            a[i + offset + p]\
    \ = l - r;\r\n          }\r\n          rot *= rate2[topbit(~s & -~s)];\r\n   \
    \     }\r\n        len++;\r\n      } else {\r\n        int p = 1 << (h - len -\
    \ 2);\r\n        mint rot = 1, imag = root[2];\r\n        for (int s = 0; s <\
    \ (1 << len); s++) {\r\n          mint rot2 = rot * rot;\r\n          mint rot3\
    \ = rot2 * rot;\r\n          int offset = s << (h - len);\r\n          for (int\
    \ i = 0; i < p; i++) {\r\n            u64 mod2 = u64(mod) * mod;\r\n         \
    \   u64 a0 = a[i + offset].val;\r\n            u64 a1 = u64(a[i + offset + p].val)\
    \ * rot.val;\r\n            u64 a2 = u64(a[i + offset + 2 * p].val) * rot2.val;\r\
    \n            u64 a3 = u64(a[i + offset + 3 * p].val) * rot3.val;\r\n        \
    \    u64 a1na3imag = (a1 + mod2 - a3) % mod * imag.val;\r\n            u64 na2\
    \ = mod2 - a2;\r\n            a[i + offset] = a0 + a2 + a1 + a3;\r\n         \
    \   a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));\r\n            a[i\
    \ + offset + 2 * p] = a0 + na2 + a1na3imag;\r\n            a[i + offset + 3 *\
    \ p] = a0 + na2 + (mod2 - a1na3imag);\r\n          }\r\n          rot *= rate3[topbit(~s\
    \ & -~s)];\r\n        }\r\n        len += 2;\r\n      }\r\n    }\r\n  } else {\r\
    \n    mint coef = mint(1) / mint(len(a));\r\n    FOR(i, len(a)) a[i] *= coef;\r\
    \n    int len = h;\r\n    while (len) {\r\n      if (len == 1) {\r\n        int\
    \ p = 1 << (h - len);\r\n        mint irot = 1;\r\n        FOR(s, 1 << (len -\
    \ 1)) {\r\n          int offset = s << (h - len + 1);\r\n          FOR(i, p) {\r\
    \n            u64 l = a[i + offset].val;\r\n            u64 r = a[i + offset +\
    \ p].val;\r\n            a[i + offset] = l + r;\r\n            a[i + offset +\
    \ p] = (mod + l - r) * irot.val;\r\n          }\r\n          irot *= irate2[topbit(~s\
    \ & -~s)];\r\n        }\r\n        len--;\r\n      } else {\r\n        int p =\
    \ 1 << (h - len);\r\n        mint irot = 1, iimag = iroot[2];\r\n        FOR(s,\
    \ (1 << (len - 2))) {\r\n          mint irot2 = irot * irot;\r\n          mint\
    \ irot3 = irot2 * irot;\r\n          int offset = s << (h - len + 2);\r\n    \
    \      for (int i = 0; i < p; i++) {\r\n            u64 a0 = a[i + offset + 0\
    \ * p].val;\r\n            u64 a1 = a[i + offset + 1 * p].val;\r\n           \
    \ u64 a2 = a[i + offset + 2 * p].val;\r\n            u64 a3 = a[i + offset + 3\
    \ * p].val;\r\n            u64 x = (mod + a2 - a3) * iimag.val % mod;\r\n    \
    \        a[i + offset] = a0 + a1 + a2 + a3;\r\n            a[i + offset + 1 *\
    \ p] = (a0 + mod - a1 + x) * irot.val;\r\n            a[i + offset + 2 * p] =\
    \ (a0 + a1 + 2 * mod - a2 - a3) * irot2.val;\r\n            a[i + offset + 3 *\
    \ p] = (a0 + 2 * mod - a1 - x) * irot3.val;\r\n          }\r\n          irot *=\
    \ irate3[topbit(~s & -~s)];\r\n        }\r\n        len -= 2;\r\n      }\r\n \
    \   }\r\n  }\r\n}\r\n#line 8 \"poly/convolution.hpp\"\n\r\ntemplate <class mint>\r\
    \nvector<mint> convolution_ntt(vector<mint> a, vector<mint> b) {\r\n  if (a.empty()\
    \ || b.empty()) return {};\r\n  int n = int(a.size()), m = int(b.size());\r\n\
    \  int sz = 1;\r\n  while (sz < n + m - 1) sz *= 2;\r\n\r\n  // sz = 2^k \u306E\
    \u3068\u304D\u306E\u9AD8\u901F\u5316\u3002\u5206\u5272\u7D71\u6CBB\u7684\u306A\
    \u3084\u3064\u3067\u640D\u3057\u307E\u304F\u308B\u306E\u3067\u3002\r\n  if ((n\
    \ + m - 3) <= sz / 2) {\r\n    auto a_last = a.back(), b_last = b.back();\r\n\
    \    a.pop_back(), b.pop_back();\r\n    auto c = convolution(a, b);\r\n    c.resize(n\
    \ + m - 1);\r\n    c[n + m - 2] = a_last * b_last;\r\n    FOR(i, len(a)) c[i +\
    \ len(b)] += a[i] * b_last;\r\n    FOR(i, len(b)) c[i + len(a)] += b[i] * a_last;\r\
    \n    return c;\r\n  }\r\n\r\n  a.resize(sz), b.resize(sz);\r\n  bool same = a\
    \ == b;\r\n  ntt(a, 0);\r\n  if (same) {\r\n    b = a;\r\n  } else {\r\n    ntt(b,\
    \ 0);\r\n  }\r\n  FOR(i, sz) a[i] *= b[i];\r\n  ntt(a, 1);\r\n  a.resize(n + m\
    \ - 1);\r\n  return a;\r\n}\r\n\r\ntemplate <typename mint>\r\nvector<mint> convolution_garner(const\
    \ vector<mint>& a, const vector<mint>& b) {\r\n  int n = len(a), m = len(b);\r\
    \n  if (!n || !m) return {};\r\n  static constexpr int p0 = 167772161;\r\n  static\
    \ constexpr int p1 = 469762049;\r\n  static constexpr int p2 = 754974721;\r\n\
    \  using mint0 = modint<p0>;\r\n  using mint1 = modint<p1>;\r\n  using mint2 =\
    \ modint<p2>;\r\n  vc<mint0> a0(n), b0(m);\r\n  vc<mint1> a1(n), b1(m);\r\n  vc<mint2>\
    \ a2(n), b2(m);\r\n  FOR(i, n) a0[i] = a[i].val, a1[i] = a[i].val, a2[i] = a[i].val;\r\
    \n  FOR(i, m) b0[i] = b[i].val, b1[i] = b[i].val, b2[i] = b[i].val;\r\n  auto\
    \ c0 = convolution_ntt<mint0>(a0, b0);\r\n  auto c1 = convolution_ntt<mint1>(a1,\
    \ b1);\r\n  auto c2 = convolution_ntt<mint2>(a2, b2);\r\n  vc<mint> c(len(c0));\r\
    \n  FOR(i, n + m - 1) { c[i] = CRT3<mint, p0, p1, p2>(c0[i].val, c1[i].val, c2[i].val);\
    \ }\r\n  return c;\r\n}\r\n\r\nvector<ll> convolution(vector<ll> a, vector<ll>\
    \ b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return {};\r\n  if\
    \ (min(n, m) <= 2500) return convolution_naive(a, b);\r\n\r\n  ll mi_a = MIN(a),\
    \ mi_b = MIN(b);\r\n  for (auto& x: a) x -= mi_a;\r\n  for (auto& x: b) x -= mi_b;\r\
    \n  assert(MAX(a) * MAX(b) <= 1e18);\r\n\r\n  auto Ac = cumsum<ll>(a), Bc = cumsum<ll>(b);\r\
    \n  vi res(n + m - 1);\r\n  for (int k = 0; k < n + m - 1; ++k) {\r\n    int s\
    \ = max(0, k - m + 1);\r\n    int t = min(n, k + 1);\r\n    res[k] += (t - s)\
    \ * mi_a * mi_b;\r\n    res[k] += mi_a * (Bc[k - s + 1] - Bc[k - t + 1]);\r\n\
    \    res[k] += mi_b * (Ac[t] - Ac[s]);\r\n  }\r\n\r\n  static constexpr u32 MOD1\
    \ = 1004535809;\r\n  static constexpr u32 MOD2 = 1012924417;\r\n  using mint1\
    \ = modint<MOD1>;\r\n  using mint2 = modint<MOD2>;\r\n\r\n  vc<mint1> a1(n), b1(m);\r\
    \n  vc<mint2> a2(n), b2(m);\r\n  FOR(i, n) a1[i] = a[i], a2[i] = a[i];\r\n  FOR(i,\
    \ m) b1[i] = b[i], b2[i] = b[i];\r\n\r\n  auto c1 = convolution_ntt<mint1>(a1,\
    \ b1);\r\n  auto c2 = convolution_ntt<mint2>(a2, b2);\r\n\r\n  FOR(i, n + m -\
    \ 1) { res[i] += CRT2<u64, MOD1, MOD2>(c1[i].val, c2[i].val); }\r\n  return res;\r\
    \n}\r\n\r\ntemplate <typename mint>\r\nvc<mint> convolution(const vc<mint>& a,\
    \ const vc<mint>& b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return\
    \ {};\r\n  if (mint::can_ntt()) {\r\n    if (min(n, m) <= 50) return convolution_karatsuba<mint>(a,\
    \ b);\r\n    return convolution_ntt(a, b);\r\n  }\r\n  if (min(n, m) <= 200) return\
    \ convolution_karatsuba<mint>(a, b);\r\n  return convolution_garner(a, b);\r\n\
    }\r\n#line 5 \"poly/lagrange_interpolate_iota.hpp\"\n\r\n// Input: f(0), ...,\
    \ f(n-1) and c. Return: f(c)\r\ntemplate <typename T, typename enable_if<has_mod<T>::value>::type\
    \ * = nullptr>\r\nT lagrange_interpolate_iota(vc<T> &f, T c) {\r\n  int n = len(f);\r\
    \n  if (int(c.val) < n) return f[c.val];\r\n  auto a = f;\r\n  FOR(i, n) {\r\n\
    \    a[i] = a[i] * fact_inv<T>(i) * fact_inv<T>(n - 1 - i);\r\n    if ((n - 1\
    \ - i) & 1) a[i] = -a[i];\r\n  }\r\n  vc<T> lp(n + 1), rp(n + 1);\r\n  lp[0] =\
    \ rp[n] = 1;\r\n  FOR(i, n) lp[i + 1] = lp[i] * (c - i);\r\n  FOR_R(i, n) rp[i]\
    \ = rp[i + 1] * (c - i);\r\n  T ANS = 0;\r\n  FOR(i, n) ANS += a[i] * lp[i] *\
    \ rp[i + 1];\r\n  return ANS;\r\n}\r\n\r\n// mod \u3058\u3083\u306A\u3044\u5834\
    \u5408\u3002\u304B\u306A\u308A\u4F4E\u6B21\u306E\u591A\u9805\u5F0F\u3092\u60F3\
    \u5B9A\u3057\u3066\u3044\u308B\u3002O(n^2)\r\n// Input: f(0), ..., f(n-1) and\
    \ c. Return: f(c)\r\ntemplate <typename T, typename enable_if<!has_mod<T>::value>::type\
    \ * = nullptr>\r\nT lagrange_interpolate_iota(vc<T> &f, T c) {\r\n  const int\
    \ LIM = 10;\r\n  int n = len(f);\r\n  assert(n < LIM);\r\n\r\n  // (-1)^{i-j}\
    \ binom(i,j)\r\n  static vvc<int> C;\r\n  if (C.empty()) {\r\n    C.assign(LIM,\
    \ vc<int>(LIM));\r\n    C[0][0] = 1;\r\n    FOR(n, 1, LIM) FOR(k, n + 1) {\r\n\
    \      C[n][k] += C[n - 1][k];\r\n      if (k) C[n][k] += C[n - 1][k - 1];\r\n\
    \    }\r\n    FOR(n, LIM) FOR(k, n + 1) if ((n + k) % 2) C[n][k] = -C[n][k];\r\
    \n  }\r\n  // f(x) = sum a_i binom(x,i)\r\n  vc<T> a(n);\r\n  FOR(i, n) FOR(j,\
    \ i + 1) { a[i] += f[j] * C[i][j]; }\r\n\r\n  T res = 0;\r\n  T b = 1;\r\n  FOR(i,\
    \ n) {\r\n    res += a[i] * b;\r\n    b = b * (c - i) / (1 + i);\r\n  }\r\n  return\
    \ res;\r\n}\r\n\r\n// Input: f(0), ..., f(n-1) and c, m\r\n// Return: f(c), f(c+1),\
    \ ..., f(c+m-1)\r\n// Complexity: M(n, n + m)\r\ntemplate <typename mint>\r\n\
    vc<mint> lagrange_interpolate_iota(vc<mint> &f, mint c, int m) {\r\n  if (m <=\
    \ 60) {\r\n    vc<mint> ANS(m);\r\n    FOR(i, m) ANS[i] = lagrange_interpolate_iota(f,\
    \ c + mint(i));\r\n    return ANS;\r\n  }\r\n  ll n = len(f);\r\n  auto a = f;\r\
    \n  FOR(i, n) {\r\n    a[i] = a[i] * fact_inv<mint>(i) * fact_inv<mint>(n - 1\
    \ - i);\r\n    if ((n - 1 - i) & 1) a[i] = -a[i];\r\n  }\r\n  // x = c, c+1, ...\
    \ \u306B\u5BFE\u3057\u3066 a0/x + a1/(x-1) + ... \u3092\u6C42\u3081\u3066\u304A\
    \u304F\r\n  vc<mint> b(n + m - 1);\r\n  FOR(i, n + m - 1) b[i] = mint(1) / (c\
    \ + mint(i - n + 1));\r\n  a = convolution(a, b);\r\n\r\n  Sliding_Window_Aggregation<Monoid_Mul<mint>>\
    \ swag;\r\n  vc<mint> ANS(m);\r\n  ll L = 0, R = 0;\r\n  FOR(i, m) {\r\n    while\
    \ (L < i) { swag.pop(), ++L; }\r\n    while (R - L < n) { swag.push(c + mint((R++)\
    \ - n + 1)); }\r\n    auto coef = swag.prod();\r\n    if (coef == 0) {\r\n   \
    \   ANS[i] = f[(c + i).val];\r\n    } else {\r\n      ANS[i] = a[i + n - 1] *\
    \ coef;\r\n    }\r\n  }\r\n  return ANS;\r\n}\r\n#line 4 \"poly/prefix_product_of_poly.hpp\"\
    \n\n// A[k-1]...A[0] \u3092\u8A08\u7B97\u3059\u308B\n// \u30A2\u30EB\u30B4\u30EA\
    \u30BA\u30E0\u53C2\u8003\uFF1Ahttps://github.com/noshi91/n91lib_rs/blob/master/src/algorithm/polynomial_matrix_prod.rs\n\
    // \u5B9F\u88C5\u53C2\u8003\uFF1Ahttps://nyaannyaan.github.io/library/matrix/polynomial-matrix-prefix-prod.hpp\n\
    template <typename T>\nvc<vc<T>> prefix_product_of_poly_matrix(vc<vc<vc<T>>>&\
    \ A, ll k) {\n  int n = len(A);\n\n  using MAT = vc<vc<T>>;\n  auto shift = [&](vc<MAT>&\
    \ G, T x) -> vc<MAT> {\n    int d = len(G);\n    vvv(T, H, d, n, n);\n    FOR(i,\
    \ n) FOR(j, n) {\n      vc<T> g(d);\n      FOR(l, d) g[l] = G[l][i][j];\n    \
    \  auto h = lagrange_interpolate_iota(g, x, d);\n      FOR(l, d) H[l][i][j] =\
    \ h[l];\n    }\n    return H;\n  };\n\n  auto evaluate = [&](vc<T>& f, T x) ->\
    \ T {\n    T res = 0;\n    T p = 1;\n    FOR(i, len(f)) {\n      res += f[i] *\
    \ p;\n      p *= x;\n    }\n    return res;\n  };\n\n  ll deg = 1;\n  FOR(i, n)\
    \ FOR(j, n) chmax(deg, len(A[i][j]) - 1);\n\n  vc<MAT> G(deg + 1);\n  ll v = 1;\n\
    \  while (deg * v * v < k) v *= 2;\n  T iv = T(1) / T(v);\n\n  FOR(i, len(G))\
    \ {\n    T x = T(v) * T(i);\n    vv(T, mat, n, n);\n    FOR(j, n) FOR(k, n) mat[j][k]\
    \ = evaluate(A[j][k], x);\n    G[i] = mat;\n  }\n\n  for (ll w = 1; w != v; w\
    \ *= 2) {\n    T W = w;\n    auto G1 = shift(G, W * iv);\n    auto G2 = shift(G,\
    \ (W * T(deg) * T(v) + T(v)) * iv);\n    auto G3 = shift(G, (W * T(deg) * T(v)\
    \ + T(v) + W) * iv);\n    FOR(i, w * deg + 1) {\n      G[i] = matrix_mul(G1[i],\
    \ G[i]);\n      G2[i] = matrix_mul(G3[i], G2[i]);\n    }\n    copy(G2.begin(),\
    \ G2.end() - 1, back_inserter(G));\n  }\n\n  vv(T, res, n, n);\n  FOR(i, n) res[i][i]\
    \ = 1;\n  ll i = 0;\n  while (i + v <= k) res = matrix_mul(G[i / v], res), i +=\
    \ v;\n  while (i < k) {\n    vv(T, mat, n, n);\n    FOR(j, n) FOR(k, n) mat[j][k]\
    \ = evaluate(A[j][k], i);\n    res = matrix_mul(mat, res);\n    ++i;\n  }\n  return\
    \ res;\n}\n\n// f[k-1]...f[0] \u3092\u8A08\u7B97\u3059\u308B\ntemplate <typename\
    \ T>\nT prefix_product_of_poly(vc<T>& f, ll k) {\n  vc<vc<vc<T>>> A(1);\n  A[0].resize(1);\n\
    \  A[0][0] = f;\n  auto res = prefix_product_of_poly_matrix(A, k);\n  return res[0][0];\n\
    }\n#line 7 \"test/1_mytest/factorial_998.test.cpp\"\n\nusing mint = modint998;\n\
    \nvoid test() {\n  FOR(10) {\n    int x = RNG(0, mint::get_mod());\n    // int\
    \ x = t;\n    int a = factorial998(x);\n    vc<mint> f = {1, 1};\n    int b =\
    \ prefix_product_of_poly(f, x).val;\n    assert(a == b);\n  }\n}\n\nvoid solve()\
    \ {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main()\
    \ {\n  test();\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"random/base.hpp\"\n\n#include \"mod/factorial998.hpp\"\n#include\
    \ \"poly/prefix_product_of_poly.hpp\"\n\nusing mint = modint998;\n\nvoid test()\
    \ {\n  FOR(10) {\n    int x = RNG(0, mint::get_mod());\n    // int x = t;\n  \
    \  int a = factorial998(x);\n    vc<mint> f = {1, 1};\n    int b = prefix_product_of_poly(f,\
    \ x).val;\n    assert(a == b);\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >>\
    \ a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n\
    \  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - random/base.hpp
  - mod/factorial998.hpp
  - poly/prefix_product_of_poly.hpp
  - linalg/matrix_mul.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - poly/lagrange_interpolate_iota.hpp
  - alg/monoid/mul.hpp
  - ds/sliding_window_aggregation.hpp
  - poly/convolution.hpp
  - mod/mod_inv.hpp
  - mod/crt3.hpp
  - poly/convolution_naive.hpp
  - poly/convolution_karatsuba.hpp
  - poly/ntt.hpp
  isVerificationFile: true
  path: test/1_mytest/factorial_998.test.cpp
  requiredBy: []
  timestamp: '2025-07-05 14:54:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/factorial_998.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/factorial_998.test.cpp
- /verify/test/1_mytest/factorial_998.test.cpp.html
title: test/1_mytest/factorial_998.test.cpp
---
