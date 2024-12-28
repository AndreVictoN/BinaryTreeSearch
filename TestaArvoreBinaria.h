/*
 * TestaArvoreBinaria.h
 *
 *  Created on: Dec 26, 2024
 *      Author: andre
 */

#ifndef TESTAARVOREBINARIA_H_
#define TESTAARVOREBINARIA_H_

#include "ArvoreBinaria.h"
#include "MeuItem.h"
#include "PermutacaoRandomica.h"
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

template <class TipoChave> class TestaArvoreBinaria{
public:
	static void main(ArvoreBinaria<TipoChave> *dicionario, vector<TipoChave> &chaves);
};

template <class TipoChave>
void TestaArvoreBinaria<TipoChave>::main(ArvoreBinaria<TipoChave> *dicionario, vector<TipoChave> &chaves){
	/*ArvoreBinaria<int> *dicionario = new ArvoreBinaria<int>();
	int max = 10;

	Item<int> *x = NULL;
	vector<int> vetor(max);

	for(int i = 0; i < max; i++)
		vetor.at(i) = i;

	PermutacaoRandomica<int>::permut(vetor, vetor.size());

	for(int i = 0; i < max; i++){
		x = new MeuItem<int>(vetor.at(i));
		dicionario->insere(x);

		cout << "Inseriu chave: " << x->toString() << endl;
		dicionario->testa();
	}

	for(int i = 0; i < max; i++){
		int k = rand() % max;
		int n = vetor.at(k);
		x = new MeuItem<int>(n);
		dicionario->retira(x);
		dicionario->testa();
		cout << "Retirou chave: " << x->toString() << endl;
		delete x;

		for(int j = 0; j < max; j++){
			k = rand() % 10;
			x = new MeuItem<int>(k);

			Item<int> *aux = x;
			Item<int> *reg = new MeuItem<int>(n);

			if(x->compara(reg) != 0){
				cout << "Pesquisando chave: " << x->toString();
				x = dicionario->pesquisa(aux);
				cout << ", encontrou: " << x->toString() << endl;
			}

			delete aux;
			delete reg;
		}

		x = new MeuItem<int>(n);
		dicionario->insere(x);

		cout << "Inseriu chave: " << x->toString() << endl;
		dicionario->testa();
	}

	for(int i = 0; i < max; i++){
		x = new MeuItem<int>(vetor.at(i));
		dicionario->retira(x);
		dicionario->testa();

		cout << "Retirou chave: " << x->toString() << endl;
		delete x;
	}*/

	Item<TipoChave> *x = NULL;
	TipoChave n;
	TipoChave k;

	cout << endl << "Qual chave inserida deseja retirar?" << endl;
	cin >> n;

	x = new MeuItem<TipoChave>(n);

	dicionario->retira(x);
	chaves.erase(find(chaves.begin(), chaves.end(), x->recuperaChave()));
	dicionario->testa();

	cout << "Retirou chave: " << x->toString() << endl;
	delete x;

	cout << endl << "Qual chave deseja pesquisar?" << endl;
	cin >> k;

	x = new MeuItem<TipoChave>(k);

	Item<TipoChave> *aux = x;
	Item<TipoChave> *reg = new MeuItem<TipoChave>(n);

	if(x->compara(reg) != 0){
		cout << "Pesquisando chave: " << x->toString();
		x = dicionario->pesquisa(aux);
		cout << ", encontrou: " << x->toString() << endl;
	}

	delete aux;
	delete reg;

	cout << endl << "Digite uma chave para inserir: " << endl;
	cin >> n;

	x = new MeuItem<TipoChave>(n);
	dicionario->insere(x);
	chaves.push_back(x->recuperaChave());

	cout << "Inseriu chave: " << x->toString() << endl;
	dicionario->testa();

	cout << "Árvore atual: " << endl;
	dicionario->imprime();

	for(size_t i = 0; i < chaves.size(); i++){
		x = new MeuItem<TipoChave>(chaves.at(i));
		dicionario->retira(x);
		dicionario->testa();

		cout << "Retirou chave: " << x->toString() << endl;
		delete x;
	}

	delete dicionario;
}

#endif /* TESTAARVOREBINARIA_H_ */
