#include <type_traits>
template<typename T> struct IsArithmetic {
	typedef typename std::enable_if<std::is_arithmetic<T>::value, T>::type type;
};

template<typename T> typename IsArithmetic<T>::type
  get_median(T a[], size_t n) {
	return (a[(n - 1) / 2] + a[(n + 1) / 2]) / 2;
}

template<typename T> typename IsArithmetic<T>::type
  get_median_slow(T a1[], T a2[], size_t n) {
	std::vector<T> m;
	m.insert(m.end(), a1, a1 + n);
	m.insert(m.end(), a2, a2 + n);
	std::sort(m.begin(), m.end());
	return get_median(&m[0], n * 2);
}

template<typename T> typename IsArithmetic<T>::type
  get_median(T a1[], T a2[], size_t n) {
	if (n <= 2) return get_median_slow(a1, a2, n);

	T m1 = get_median(a1, n);
	T m2 = get_median(a2, n);

	if (m1 > m2) std::swap(a1, a2);

	return get_median(a1 + (n - 1) / 2, a2, (n + 2) / 2);
}
