/*
 * main.cpp
 *
 *  Created on: Dec 26, 2024
 *      Author: andre
 */

#include "CriaArvore.h"
#include "TestaArvoreBinaria.h"
#include <vector>

using namespace std;

int main(int argc, char **argv) {
	vector<int> chavesInt;
	ArvoreBinaria<int> *arvoreInt = CriaArvore<int>::main(chavesInt);

	cout << endl << "Árvore atual: " << endl;
	arvoreInt->imprime();

	cout << endl << "Tamanho da Árvore: " << chavesInt.size() << endl;

	TestaArvoreBinaria<int>::main(arvoreInt, chavesInt);

	cout << endl;

	vector<char> chavesChar;
	ArvoreBinaria<char> *arvoreChar = CriaArvore<char>::main(chavesChar);

	cout << endl << "Árvore atual: " << endl;
	arvoreChar->imprime();

	cout << endl << "Tamanho da Árvore: " << chavesChar.size() << endl;

	TestaArvoreBinaria<char>::main(arvoreChar, chavesChar);
}
