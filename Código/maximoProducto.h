#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Producto{
	private:
		int max_neg = INT_MIN;
		int count_neg = 0, count_zero = 0;
		int prod = 1;
		int i;
	public: 
		int maxProductSubset(int a[], int n);	
};

Producto::maxProductSubset(int a[], int n){
	if (n == 1)
		return a[0];
	// Encuentra el recuento de números negativos,
	// conteo de ceros, números negativos
	// con el menor valor absoluto
	// y producto de números distintos de cero
	for (int i = 0; i < n; i++) {

		// Si el numero es 0, no 
		// lo multiplicamos con el producto
		if (a[i] == 0) {
			count_zero++;
			continue;
		}

		// Cuenta los negativos y mantiene
		// una bandera del número negativo
		// con el menor valor absoluto
		if (a[i] < 0) {
			count_neg++;
			max_neg = max(max_neg, a[i]);
		}
		prod = prod * a[i];
	}

	// Si todos son ceros
	if (count_zero == n)
		return 0;

	//Si hay un número impar de
	//números negativos
	if (count_neg & 1) {

		// Caso excepcional: si solo hay
		// negativos y todos los demás son ceros
		if (count_neg == 1 && 
			count_zero > 0 && 
			count_zero + count_neg == n)
			return 0;

		// De lo contrario, el resultado es producto de
		// todos los números distintos de cero divididos por
		// un número negativo con  el mínimo valor absoluto.	
		prod = prod / max_neg;
	}

	return prod;
}
