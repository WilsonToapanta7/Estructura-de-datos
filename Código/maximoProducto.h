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
	// Encuentra el recuento de n�meros negativos,
	// conteo de ceros, n�meros negativos
	// con el menor valor absoluto
	// y producto de n�meros distintos de cero
	for (int i = 0; i < n; i++) {

		// Si el numero es 0, no 
		// lo multiplicamos con el producto
		if (a[i] == 0) {
			count_zero++;
			continue;
		}

		// Cuenta los negativos y mantiene
		// una bandera del n�mero negativo
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

	//Si hay un n�mero impar de
	//n�meros negativos
	if (count_neg & 1) {

		// Caso excepcional: si solo hay
		// negativos y todos los dem�s son ceros
		if (count_neg == 1 && 
			count_zero > 0 && 
			count_zero + count_neg == n)
			return 0;

		// De lo contrario, el resultado es producto de
		// todos los n�meros distintos de cero divididos por
		// un n�mero negativo con  el m�nimo valor absoluto.	
		prod = prod / max_neg;
	}

	return prod;
}
