#include <iostream>
#include "maximoProducto.h"


int main(int argc, char** argv) {
	
	Producto p;
	// Con datos quemados
	int a[] = { -1, -1, -2, 4, 3 };
	int n = sizeof(a) / sizeof(a[0]);
	
	cout<<"\nEl maximo producto de los elementos del vector ==> ";
	for(int i=0;i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n\nes: "
		<< p.maxProductSubset(a, n);

	return 0;
}
