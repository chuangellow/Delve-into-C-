# Chapter 0. Preliminary

## 1. C++ template and stdin/out

### C++ template

在程式競賽中，為了避免引入多個標頭檔的繁雜，會引入一個萬用的 header 為 ```<bits/stdc++.h>```，下面是常用的 template：

```
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	return 0;
}
```

可以實際打開來看 ```<bits/stdc++.h>``` 的內容：

```
// 17.4.1.2 Headers

// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <csetjmp>
#include <cstdarg>
#include <cstddef>
#include <cstdlib>

#if __cplusplus >= 201103L
#include <cstdint>
#endif

// C++
// #include <bitset>
// #include <complex>
#include <algorithm>
#include <bitset>
#include <functional>
#include <iterator>
#include <limits>
#include <memory>
#include <new>
#include <numeric>
#include <typeinfo>
#include <utility>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <initializer_list>
#include <ratio>
#include <scoped_allocator>
#include <tuple>
#include <typeindex>
#include <type_traits>
#endif

#if __cplusplus >= 201402L
#endif

#if __cplusplus >= 201703L
#include <any>
// #include <execution>
#include <optional>
#include <variant>
#include <string_view>
#endif

#if __cplusplus >= 202002L
#include <bit>
#include <compare>
#include <concepts>
#include <numbers>
#include <ranges>
#include <span>
#include <source_location>
#include <version>
#endif

#if __cplusplus > 202002L
#include <expected>
#include <stdatomic.h>
#if __cpp_impl_coroutine
# include <coroutine>
#endif
#endif

#if _GLIBCXX_HOSTED
// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cuchar>
#endif

// C++
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#if __cplusplus >= 201402L
#include <shared_mutex>
#endif

#if __cplusplus >= 201703L
#include <any>
#include <charconv>
// #include <execution>
#include <filesystem>
#include <optional>
#include <memory_resource>
#include <variant>
#endif

#if __cplusplus >= 202002L
#include <barrier>
#include <bit>
#include <compare>
#include <concepts>
#include <format>
#include <latch>
#include <numbers>
#include <ranges>
#include <span>
#include <stop_token>
#include <semaphore>
#include <source_location>
#include <syncstream>
#include <version>
#endif

#if __cplusplus > 202002L
#include <expected>
#include <spanstream>
#if __has_include(<stacktrace>)
# include <stacktrace>
#endif
#include <stdatomic.h>
#include <stdfloat>
#endif

#endif // HOSTED
```

可以發現包山包海，幾乎把所有會用到的 library 都 include 了，但就有了一些缺點：

- 多引入了很多不必要的 library，增加了 compile & link 的時間
- 不在 C++ standard 的定義中，因此不可移植

### C++ standard I/O

而雖然 C++ 中最常用的輸入和輸出方式是：```cin/cout``` 來簡化輸入輸出的繁瑣過程，

但他的效率不佳，原因是 C++ 為了和 C 相容，為了保證使用者使用 ```std::printf``` 和 ```std::cout``` 不會混亂，而將 output stream 綁在一起，

如果我們在我們的程式中混用 ```cout``` 和 ```printf```，C++ 會幫助我們做同步，導致最後輸出結果仍如我們預期的順序，

但這樣的同步就會造成額外的 I/O overhead。

所以，一種優化 cin 和 cout 的方式是將其關閉：

```
std::ios::sync_with_stdio(0);
```

再來是一般來說預設情況下， ```std::cin``` 綁定的是 ```std::cout``` 的 output stream，也就是說，在 ```std::cin``` 的 I/O operation 前，勢必得先清空 ```std::cout``` 的 output buffer，

這是為了在如：

```
cout << "Type your name" << endl;
cin >> name;
```

這種情況下，能確保 prompt 會在等待輸入前出現。

因此，每次使用 ```<<<``` 時，都要呼叫 flush，增加 IO overhead，可以透過下面方式解除綁定，增加效率：

```
std::cin.tie(0);
```

但這樣一來，我們就必須手動進行 ```std::cout.flush()```，以清空 output buffer。

當然使用透過下面的 template：

```
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	return 0;
}
```

我們仍可以有效率的使用 ```std::cin``` 和 ```std::cout```，但就有些非同步的情形而需要注意而造成 bug 的風險。

因此，另一種方式是使用 C 的 standard I/O 如：```printf``` 和 ```scanf``` 來處理 I/O。 

## 2. Program Testing

在 C/C++ 中，有三個系統定義的輸入/輸出裝置，分別為：
- stdin
- stdout
- stderr

在程式中執行 ```scanf/cin``` 時，就是從 ```stdin``` 中去抓資料，而 ```printf/stdout``` 則是將資料輸出至 stdout。

但我們可以透過 I/O redirection 來將輸入和輸出的裝置做 redirection：

```
freopen("test.in", "r", stdin);
freopen("test.out", "w", stdout);
```

或是在 UNIX-like system 中，可以直接在 command line 上做 redirection:

```
./main < test.in > test.out
```

## 3. Time Complexity

要評估程式的執行效率，準確的方法是量測時間，但我們同時也可以使用數學上的定義來幫助我們估算輸入資料量和程式的執行時間關係。

這裡需要引入數學上的 Asymptotic Notation 的定義。

### Asymptotic Notation
而Asymptotic Notation的定義如下

假設$f,g:\mathbb Z^+ \to \mathbb R^+ \cup\{ 0\}$為兩個函數

$$
O(g(n))=\{f(n):\exists c>0,n_0>0 \ni 0\le f(n) \le cg(n),\forall n\ge n_0 \}
$$

意義為蒐集所有成長不比$g(n)$來的快的函數集合

舉例來說：

$f(n)=1 \in O(n^2)$，$f(n)=n \in O(n^2)$，$f(n)=n^3 \notin O(n^2)$

$$
\Omega(g(n))=\{f(n):\exists c>0,n_0>0 \ni 0\le cg(n) \le f(n),\forall n\ge n_0 \}
$$

意義為蒐集所有成長不比$g(n)$來的慢的函數集合

$$
\theta(g(n))=\{f(n):\exists c_1, c_2>0,n_0>0 \ni 0\le c_1g(n) \le f(n)\le c_2g(n),\forall n\ge n_0 \}
$$

$$
o(g(n))=\{f(n):\forall c>0,\exists n_0>0 \ni 0\le f(n) < cg(n),\forall n\ge n_0 \}
$$

舉例來說：

$f(n)=1 \in O(n^2)$，$f(n)=n \notin o(n^2)$

$$
\omega(g(n))=\{f(n):\forall c>0,\exists n_0>0 \ni 0\le cg(n)< f(n),\forall n\ge n_0 \}
$$

而Asymptotic Notation的意義為：用來衡量一個演算法隨著input size成長時，執行速度的成長趨勢

可以由上面的數學定義看出其實Asymptotic Notation就是一個關係，下面會探討這種關係上面的性質，如反身性、對稱性和遞移性

若滿足：$f(x)\in O(g(x))$，則我們就稱$g(x)$會為$f(x)$的upper bound

而另一方面，$f(x)$會為$g(x)$的lower bound

Note：

1. $f(n)\in O(g(n))$我們通常會記作：$f(n)=O(g(n))$，但要記住：$O(g(n))$的本質仍然是集合
2. $f(n)= O(g(n)) \leftrightarrow g(n) = \Omega (f(n))$
3. $f(n)= \theta (g(n)) \leftrightarrow f(n) = O(g(n)) \ and\ f(n) =\Omega (g(n))$
4. $f(n)= o (g(n)) \leftrightarrow f(n) = O(g(n)) \ and\ f(n) \ne \theta (g(n))$
5. 若：$f(x)\in \theta(g(x))$，則當n夠大時，可以視$f(n)$和$g(n)$為同一等級。

### Asymptotic Notation的一些性質

1. O, $\Omega$, $\theta$, o, $\omega$具有tranitive的性質，即設：$f(n)=O(g(n))$且$g(n)=O(h(n))$，則：$f(n)=O(h(n))$
2.  $\theta$具有symmetric性質，即：$f(n)=\theta(g(n))$則：$g(n)=\theta(f(n))$
3. O, $\Omega$, $\theta$都具有reflexive性質，即：$f(n)=O(f(n))$
4. Asymptotic Notation未必滿足trichotomy(三一律)，即可能發生$f(n)=O(g(n))$和$f(n)=\Omega(g(n))$皆不成立的情形

透過該 Asymptotic Notation 的定義，可以幫助我們理論分析一個程式的執行時間和其 input size 間的關係。

### Time Complexity Analysis 中需要注意的事情

- 使用 Asymptotic Notation 分析時，不能完全忽略常數帶來的影響
- 注意 pseudo-polynomial 的情形
- 通常 Big-O 估計是在講 tight-bound


## 4. Something We Should Know

### Integer Overflow

C++ 的 built-in integer data type 有 ```char, short, int, long long int```，每個 data type 有他可以表示的範圍，

實際的範圍在 standard 中為 undefined behavior，因此，需要查看各個 compiler 的規範，

如果發生 overflow，我們可以使用下面的方式來偵測是否 overflow：

```
assert(...condition);
fprintf(stderr, "...", xxx);
```

而在解題時，需要注意 overflow 的問題，因此，多數時間使用 ```long long int``` 來多佔一點記憶體避免該問題。

### Floating-Point Numbers Rounding Error

而另一點則會發生在 floating point number 時，做 type-casting 可能造成 precision loss。

或是浮點數的表示法造成的 rounding error，原因在於電腦的儲存空間有限。

如下面的例子：

```
#include <bits/stdc++.h>

using namespace std;

int main(void) {
	printf("literal constant 0.3: %.20f\n", 0.3);
	double a = 0.3, b = 0.1 + 0.2;
	printf("a: %.20f\n", a);
	printf("b: %.20f\n", b);
	return 0;
}
```

可以發現結果都不相同。

### Short Circuit Evaluation

在 C 或是 C++ 中，針對布林運算會採取 Short Circuit Evaluation 來加速：

舉例來說：

```
bool isBird = 1;
bool isCat = 1;
bool isBirdOrCat = (isBird) || (isCat);
```
在 isBirdOrCat 中，會從左至右判斷，而因為 isBird 已經為真，無論後面的 isCat 是否為真，都不會影響結果，所以會直接不計算。

在撰寫布林運算時，必須注意到這件事避免出現錯誤。

### Compiler Optimization

在一般程式競賽中，會使用下面的 optimization flag ```-O2``` 來在編譯時，幫助程式變的更快，

以下面這個為例，會計算一個 string 中有多少個空格

```
int main(void) {
	char str[MAXLEN];
	scanf("%s", str);
	int count = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == ' ')
			count++;
	}
	printf("count: %d\n", count);
	return 0;
}
```

但依照 C 中 for loop 的行為，每次 body 執行結束後，會再進到迴圈的進入條件來看是否成立，

如果這樣寫就會呼叫 ```strlen(str)``` 共 $ O(n) $ 次，又一次 ```strlen``` 為 $ O(n) $，時間複雜度就被拉到 $ O(n^2) $

但如果開了編譯器優化，編譯器可能就會將 ```strlen``` 拉到迴圈之外，來節省呼叫次數。

但就算我們開了優化，也必須知道為什麼開了優化可以造成我們的程式變快。