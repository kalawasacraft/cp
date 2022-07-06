#include <bits/stdc++.h>
using namespace std;
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef vector<ll> vll;

/* 
 * Fenwick Tree (para calcular sumas de rangos dinamicamente)
 * "vll ft" almacenas la descomposicion de las sumas acumuladas paralelas a la representacion binaria del indice
 * Podemos:
 * - Calcular la suma en un rango [l, r] en O(log(N))
 * - Actualizar el valor de un elemento o posicion en O(log(N))
 * - Se puede implementar para M dimensiones
 * - Uso de memoria O(N)
 */

vll ft;

void upd(int i, ll e) {
	for (++i; i < (int)ft.size(); i += i&(-i))
		ft[i] += e;
}

ll sum(int i) {
	ll r = 0;
	for (; i > 0; i -= i&(-i))
		r += ft[i];
	return r;
}

ll rsum(int l, int r) {
	return sum(r+1) - sum(l);
}

int main() {FIN	
	
	int N = 1e7;	
	ft = vll(N+1);
	
	/* ~0.350s, actualiza el vector para todos los elementos de un array */
	for (int i = 0; i < N; i++)
		upd(i, i+1);
	
	cout << rsum(0, 1) << "\n";
	cout << rsum(1, 3) << "\n";
	cout << rsum(1e7-2, 1e7-1) << "\n";
	cout << rsum(100, 1e5) << "\n";
	
	/* 
	 * 3 => [1 + 2]
	 * 9 => [2 + 3 + 4]
	 * 19999999 => [9999999 + 10000000]
	 * 5000144951 => [101 + ... + 100001]
	 */
	
	return 0;
}
