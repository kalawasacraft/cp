#include <bits/stdc++.h>
using namespace std;
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef vector<ll> vll;

/* 
 * Fenwick Tree
 * "vll ft" almacenas la descomposicion de las sumas acumuladas paralelas a la representacion binaria del indice
 *
 * Podemos hacer las siguientes operaciones:
 *
 * (PU-RQ) ACTUALIZACION DE PUNTO Y CONSULTA DE RANGO
 * - Actualizar el valor de un punto en O(log(N))
 * - Consultar la suma en un rango [l, r] en O(log(N))
 *
 * (RU-PQ) ACTUALIZACION DE RANGO Y CONSULTA DE PUNTO
 * - Actualizar los valores de un rango [l, r] en O(log(N))
 * - Consultar el valor de un punto en O(log(N))
 *
 * OTRAS CARACTERISTICAS
 * - Se puede implementar para M dimensiones
 * - Uso de memoria O(N)
 */

vll ft;

/* 
 * (PU-RQ: Actualizar el valor de un punto) [✓]
 * (RU-PQ: Actualiza la posicion del extremo dado)
 */

void add(int j, ll e) {
	for (int i = j+1; i < (int)ft.size(); i += i&-i)
		ft[i] += e;
}

/* 
 * (PU-RQ: Consulta las suma total hasta la posicion dada)
 * (RU-PQ: Consultar el valor de un punto) [✓]
 */

ll sum(int j) { // ll point(int j) {
	ll r = 0;
	for (int i = j+1; i > 0; i -= i&-i)
		r += ft[i];
	return r;
}

/* 
 * (PU-RQ: Consultar la suma en un rango) [✓]
 */

ll rsum(int l, int r) {
	return sum(r) - sum(l-1);
}

/* 
 * (RU-PQ: Actualizar los valores de un rango) [✓]
 */

void radd(int l, int r, ll e) {
	add(l, e);
	add(r+1, -e);
}

int main() {FIN	
	
	int N = 1e7;	
	ft = vll(N+1);
	
	/* ~0.350s, actualiza el vector para todos los elementos del array */
	for (int i = 0; i < N; i++)
		add(i, i+1);
	
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


	ft = vll(N+2);

	/* ~0.730s, actualiza el vector para todos los rangos dados en el array */
	for (int i = 0; i < N-1000; i++)
		radd(i, i+1000, 1);

	cout << sum(0) << "\n";
	cout << sum(3) << "\n";
	cout << sum(1e7-1) << "\n";
	cout << sum(1000) << "\n";
	cout << sum(10000) << "\n";
	
	/* 
	 * 1 => [0, 1000]
	 * 4 => [0, 1000], [1, 1001], [2, 1002], [3, 1003]
	 * 1 => [9998999, 9999999]
	 * 1001 => [0, 1000], [1, 1001], ..., [1000, 2000]
	 * 1001 => [8000, 9000], [8001, 9001], ..., [9000, 10000]
	 */
	
	return 0;
}
