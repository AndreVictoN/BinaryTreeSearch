/*
 * CriaArvore.h
 *
 *  Created on: Dec 26, 2024
 *      Author: andre
 */

#ifndef CRIAARVORE_H_
#define CRIAARVORE_H_

#include "ArvoreBinaria.h"
#include "MeuItem.h"
#include <iostream>
#include <vector>
#include <string>

using std::vector;

template<class TipoChave> class CriaArvore{
public:
	static ArvoreBinaria<TipoChave> *main(vector<int> &chaves);
	static ArvoreBinaria<TipoChave> *main(vector<char> &chaves);
};

template<class TipoChave>
ArvoreBinaria<TipoChave> *CriaArvore<TipoChave>::main(vector<int> &chaves){
	ArvoreBinaria<TipoChave> *dicionario = new ArvoreBinaria<TipoChave>();
	TipoChave chave = 0;

	cout << "Insira as chaves para inserir na árvore ou 0 para interromper:" << endl;
	cin >> chave;

	while(chave != 0){
		Item<TipoChave> *item = new MeuItem<TipoChave>(chave);
		dicionario->insere(item);
		chaves.push_back(item->recuperaChave());

		cout << "Inseriu chave: " << item->toString() << endl;
		dicionario->testa();

		cin >> chave;
	}

	return dicionario;
}

template<class TipoChave>
ArvoreBinaria<TipoChave> *CriaArvore<TipoChave>::main(vector<char> &chaves){
	ArvoreBinaria<TipoChave> *dicionario = new ArvoreBinaria<TipoChave>();
	TipoChave chave = 0;

	cout << "Insira as chaves para inserir na árvore ou '/' para interromper:" << endl;
	cin >> chave;

	while(chave != '/'){
		Item<TipoChave> *item = new MeuItem<TipoChave>(chave);
		dicionario->insere(item);
		chaves.push_back(item->recuperaChave());

		cout << "Inseriu chave: " << item->toString() << endl;
		dicionario->testa();

		cin >> chave;
	}

	return dicionario;
}

#endif /* CRIAARVORE_H_ */
