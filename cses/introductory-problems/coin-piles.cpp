/**
 * https://cses.fi/problemset/task/1754
 */

#include <iostream>

using namespace std;

using ll = long long;

auto main(int, char **) -> int
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll a, b;
        cin >> a >> b;
        ((a > 2 * b) || (b > 2 * a) || ((a + b) % 3 != 0)) ? (cout << "NO" << '\n') : (cout << "YES" << '\n');
    }

    return 0;
}

/*

Proč invarianty $\left[ a \leq 2b \right]$, $\left[ b \leq 2a \right]$,
$\left[ a + b \equiv 0 \text{ mod } 3 \right]$ zafungují?

\vspace{0.5em}

Nesplnění nerovností, tj. $a > 2b$ znamena, že i kdybychom iterovali $b - 1$ a
$a - 2$, dostaneme $a = 0$ a $b > 0$. Tedy neexistuje způsob jakým obě položky
redukovat na nuly.

\vspace{0.5em}

Budeme se opírat na to, že $(a, b) \rightarrow (a - 1, b - 2)$ nebo $(a, b) \rightarrow (a - 2, b - 1)$
nemůže změnit vztah $\left[ a + b \stackrel{?}{\equiv} 0 \text{ mod } 3 \right]$. Celkem jsme odečetli $3$.
Dále uvažujeme celkem $4$ případy.

\vspace{0.5em}

$a = b$, $a + b \not\equiv \text{ mod } 3$, pak $a \equiv b \equiv 1 \text{ mod } 3$
nebo $a \equiv b \equiv 2 \text{ mod } 3$. Pro první kongruenci v jednom kroce algoritmu
dostáváme $a \equiv 0 \text{ mod } 3$ a $b \equiv 2 \text{ mod } 3$ nebo naopak.
Pro druhou kongruenci dostáváme $a \equiv 0 \text{ mod } 3$ a $b \equiv 1 \text{ mod } 3$
nebo naopak. Nikdy nedosáhneme nuly na obou číslech, ale musíme obě čísla redukovat na nulu.

\vspace{0.5em}

$a \neq b$ může být $a < b$, $a + b \not\equiv \text{ mod } 3$. Stejnou úvahou dospějeme k tomu,
$a < b \leq 2a$, potom po nejvýše $2a$ krocích dostaneme $a = b$ tak, že budeme iterovat
$(a, b) \rightarrow (a-1, b-2)$. Tím, že se invariant zachová, rovnocenně můžeme redukovat
obě strany $(a, b) \rightarrow (a - 3, b - 3)$. Abychom získali nulu, je třeba aby obě čísla
byla dělitelná třemi, ale to je v rozporu z invariantem.

\vspace{0.5em}

Stejnou úvahu můžeme provést pro $a = b$ a $a < b$ pro které platí invariant. Tedy vyjde,
že redukcí na $a = b$ musíme dostat číslo dělitelné $3$.

\vspace{0.5em}

\hfill $\square$

*/
