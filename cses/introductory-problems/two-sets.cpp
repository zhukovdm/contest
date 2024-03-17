/**
 * https://cses.fi/problemset/task/1092
 */

#include <iostream>
#include <vector>

#define ll long long
#define ull unsigned long long

auto main(int, char **) -> int
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> v;

    if (n % 4 == 1 || n % 4 == 2) {
        std::cout << "NO" << '\n';
    }

    else {
        std::cout << "YES" << '\n';
        int offset = (n % 4 == 0) ? 1 : 0;
        std::cout << n / 2 << '\n';

        for (int i = 1; i <= n; ++i) {
            if ((i - offset) % 4 == 0 || (i - offset) % 4 == 3) {
                std::cout << i << ' ';
            }
            else {
                v.push_back(i);
            }
        }

        std::cout << '\n';
        std::cout << v.size() << '\n';

        for (auto &&i : v) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}

/*

Součet aritmetické řády $\sum\limits^{n}_{i=1} i = \frac{n(n+1)}{2}$.

$[0]$ můžeme reprezentovat jako $[]$ a $[]$.

$[1]$ nebo $1$ nemůžeme reprezentovat jako dvě množiny se stejným součtem.
Součet je lichý, nelze rozdělit na dvě množiny.

$[2]$ nebo $1, 2$ nemůžeme. Součet je zase lichý.

$[3]$ nebo $1, 2, 3$ můžeme na $[1, 2]$ a $[3]$.

$[4]$ nebo $1, 2, 3, 4$ můžeme na $[1, 4]$ a $[2, 3]$.

$[5]$ nebo $1, 2, 3, 4, 5$ nemůžeme, součet $\sum^{5}_{i=1} i = 15$ je lichý.

$[6]$ nebo $1, 2, 3, 4, 5, 6$ nemůžeme, součet $21$ je lichý.

$[7]$ můžeme jako $[1, 2, 4, 7]$ a $[3, 5, 6]$.

\vspace{0.5em}

\textbf{Tvrzení}
Součet $\sum\limits^{4k}_{i=1} i$ je sudý pro každé $k \in \mathbb{N}_{0}$.

\vspace{0.5em}

\textit{Důkaz} \enspace Dokázujeme indukcí. Platí pro $4k$, pak pro $4(k+1)$
mějme součet.

\begin{equation*}
\frac{(4(k+1)) \cdot ((4k+1) + 1)}{2} =
\frac{2 \cdot (2 \cdot (k + 1))((4(k + 1) + 1))}{2} = 2 \cdot (k+1) \cdot
(4(k+1) + 1)
\end{equation*}

\hfill $\square$

\vspace{0.5em}

\textbf{Tvrzení} \enspace Pro každé $k \in \mathbb{N}_{0}$ můžeme rozložit
součet na dvě množiny pro $[4k]$ a $[4k + 3]$, ale pro $[4k + 1]$ a $[4k + 2]$
nemůžeme.

\vspace{0.5em}

\textit{Důkaz} \enspace Dokázali jsme pro $0$, a $4$. Indukční předpoklad, že
tvrzení platí pro $4k$. Dokázujeme pro $4(k + 1)$, musíme uvážit celkem $4$ případy.

\vspace{0.5em}

$[4(k + 1)] = \ldots, 4k, 4k + 1, 4k + 2, 4k + 3, 4k + 4$. Umíme rozklad $[4k]$,
do jedné množiny dáme $4k+1$ a $4k+4$, do druhé dáme $4k+2$ a $4k+3$.

\vspace{0.5em}

$[4(k + 1) + 1]$ rozložit nemůžeme. $S = \sum\limits^{4k}_{i=1} i$ je sudé z
pomocného tvrzení, ale $S + \left( 4(k + 1) + 1 \right)$ je liché.

\vspace{0.5em}

$[4(k + 1) + 2]$ rozložit nemůžeme ze stejného důvodu co i předchozí. K lichému
součtu přičteme $4(k + 1) + 2$ sudé a dostaneme zase lichý součet.

\vspace{0.5em}

$[4(k + 1) + 3]$ není na první pohled vidět. Umíme rozložit $[4k + 3]$, potom
do jedné množiny dáme $4(k + 1)$ a $4(k + 1) + 3$, do druhé $4(k + 1) + 1$ a
$4(k + 1) + 2$.

\hfill $\square$

*/
