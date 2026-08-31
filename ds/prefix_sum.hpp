#include "ds/static_range_product_group.hpp"

template <typename T>
using Prefix_Sum = Static_Range_Product_Group<Monoid_Add<T>>;
