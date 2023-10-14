# Chapter 1. Recursion

## 1. Recursion Algorithm

遞迴在數學上的定義為：**直接或間接定義自己**，而在程式上的定義為：**直接或間接呼叫自己**

通常遞迴的使用時機為：

1. 根據定義來實作
2. 以遞迴來進行窮舉暴搜

而Recursion Algorithm的種類主要有三種：

- Direct Recursion：一個function可以自我呼叫，則稱之為Direct Recursion
- Indirect Recursion：一個function可能會呼叫其他的function，而這個被他呼叫function可能呼叫回原來的function，形成一個call cycle，則稱之為Indirect Recursion
- Tail Recursion：在程式的END敘述之前，存在一個recursive call的敘述，即為tail recursion，又會為direct recursion的一種

## 2. Recurence Relation

如果一個程式有用到自我呼叫也就是遞迴的關係，則其總執行時間可以寫作如下：

若設計一個遞迴的program，其所需執行時間為：$T(n)$，其中n為輸入大小

而此程式每次遞迴都會產生a個子問題，且每個子問題的大小為：$\frac{n}{b}$

則除了遞迴迭代外所需的時間為$f(n)$，則可以寫出此遞迴的執行時間如下：

$$
T(n)=aT(\frac{n}{b})+f(n)
$$

而如果其中：a, b都會為大於等於1的實數、f(n)會為隨著n增加的正成長函數

欲解此一Time function有多種方法，分別為：

- 展開代入法
- Recursion Tree法
- Master Theory
- Extended Master Theory
- 離散數學中的特徵值法
- 近似法

由上列的方法可以猜測出一Time function的upper bound或是lower bound，但是欲驗證其正確性必須透過substitution method來驗證

substitution method的概念就是透過數學歸納法的證明，只是我們不必去證起始步驟，因為只要在取夠大的c時，起始步驟必定會滿足

之後，我們透過inductive step的假設，來證得所猜的bound的正確性

猜測的流程應為：

先判斷子問題的分法，若為：

$$
T(n)=aT(\frac{n}{b})+f(n)
$$

則先用Master Theory來判斷，若是不能用Master Theory的case，再來用展開代入法求

而其他種的則可以用Recursion Tree，先判斷他的level cost是否一致，若一樣，則為：$\theta(f(n)*logn)$，反之若為等比關係，則為：$\theta(f(n))$

## 3. Some Examples

如同上述所說，遞迴的使用條件通常為

1. 根據定義來實作
2. 以遞迴來進行窮舉暴搜

### By Definition

根據定義的遞迴實作上通常很容易，困難之處在於構思出遞迴關係。

#### factorial

數學定義為：
$$
n!=\begin{cases}1, \ \ if \ n=0 \\ (n-1)!· n \ \ if \ n>0\end{cases}
$$

```
long long int factorial(long long int n) {
	if (n == 0) return 1;
	return (n * (factorial(n - 1)));
}
```

#### Fibonacci

數學定義為：

$$
F_n=\begin{cases}0 \ \ if \ n=0 \\1 \ \ if \ n=1\\ F_{n-1}+F_{n-2} \ \ otherwise\end{cases}
$$

```
long long int fibonacci(long long int n) {
	if (n == 0 || n == 1) return n;
	return (fibonacci(n - 1) + fibonacci(n - 2));
}
```

## 4. Intuition of Designing a Recurence Relation

遞迴關係式一定會有一個邊界條件，通常的寫法是先寫邊界條件， 