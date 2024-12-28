/*
 * ArvoreBinaria.h
 *
 *  Created on: Dec 17, 2024
 *      Author: andre
 */

#ifndef ARVOREBINARIA_H_
#define ARVOREBINARIA_H_

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "Item.h"

using namespace std;

template<class TipoChave> class ArvoreBinaria{
private:
	class No{
		friend class ArvoreBinaria<TipoChave>;
	private:
		Item<TipoChave> *reg;
		No *esq, *dir;
		No(){ reg = 0; }
		~No(){ if(reg != 0) delete reg;}
	};

	No *raiz;

	void central(No *p) const;
	Item<TipoChave> *pesquisa (Item<TipoChave> *reg, No *p) const;
	No *insere(Item<TipoChave> *reg, No *p);
	No *antecessor(No *q, No *r);
	No *retira(Item<TipoChave> *reg, No *p);
	void liberaMemoria(No *p);
public:
	ArvoreBinaria();
	Item<TipoChave> *pesquisa(Item<TipoChave> *reg);
	void insere(Item<TipoChave> *reg);
	void retira(Item<TipoChave> *reg);
	void imprime() const;
	~ArvoreBinaria();
private:
	void testa (No *p) const;
public:
	void testa() const;
};

template<class TipoChave>
void ArvoreBinaria<TipoChave>::central(No *p) const{
	if(p != NULL){
		central(p->esq);
		cout << p->reg->toString() << endl;
		central(p->dir);
	}
}

template<class TipoChave>
Item<TipoChave> *ArvoreBinaria<TipoChave>::pesquisa(Item<TipoChave> *reg, No *p) const{
	if(p == NULL){
		cout << endl << "Erro: registro não encontrado" << endl;
		return NULL;
	}
	else if(reg->compara (p->reg) < 0) return pesquisa (reg, p->esq);
	else if(reg->compara (p->reg) > 0) return pesquisa (reg, p->dir);
	else return p->reg;
}

template<class TipoChave>
typename ArvoreBinaria<TipoChave>::No *ArvoreBinaria<TipoChave>::insere(Item<TipoChave> *reg, No *p){
	if(p == NULL){
		p = new No(); p->reg = reg;
		p->esq = NULL; p->dir = NULL;
	}
	else if(reg->compara(p->reg) < 0) p->esq = insere(reg, p->esq);
	else if(reg->compara(p->reg) > 0) p->dir = insere(reg, p->dir);
	else cout << "Erro: Registro já existente" << endl;

	return p;
}

template<class TipoChave>
typename ArvoreBinaria<TipoChave>::No *ArvoreBinaria<TipoChave>::antecessor(No *q, No *r){
	if(r->dir != NULL) r->dir = antecessor(q, r->dir);
	else{
		delete q->reg; q->reg = r->reg;
		r->reg = NULL;
		No *aux = r; r = r->esq; delete aux;
	}

	return r;
}

template<class TipoChave>
typename ArvoreBinaria<TipoChave>::No *ArvoreBinaria<TipoChave>::retira(Item<TipoChave> *reg, No *p){
	if(p == NULL) cout << "Erro: registro não encontrado" << endl;
	else if(reg->compara(p->reg) < 0) p->esq = retira(reg, p->esq);
	else if(reg->compara(p->reg) > 0) p->dir = retira(reg, p->dir);
	else{
		if(p->dir == NULL){
			No* aux = p; p = p->esq; delete aux;
		}
		else if(p->esq == NULL){
			No* aux = p; p = p->dir; delete aux;
		}
		else p->esq = antecessor(p, p->esq);
	}
	return p;
}

template<class TipoChave>
void ArvoreBinaria<TipoChave>::liberaMemoria(No *p){
	if(p != NULL){
		liberaMemoria(p->esq); liberaMemoria(p->dir); delete p;
	}
}

template<class TipoChave>
ArvoreBinaria<TipoChave>::ArvoreBinaria(){
	this->raiz = NULL;
}

template<class TipoChave>
Item<TipoChave> *ArvoreBinaria<TipoChave>::pesquisa(Item<TipoChave> *reg){
	return this->pesquisa(reg, this->raiz);
}

template<class TipoChave>
void ArvoreBinaria<TipoChave>::insere(Item<TipoChave> *reg){
	this->raiz = this->insere(reg, this->raiz);
}

template<class TipoChave>
void ArvoreBinaria<TipoChave>::retira(Item<TipoChave> *reg){
	this->raiz = this->retira(reg, this->raiz);
}

template<class TipoChave>
void ArvoreBinaria<TipoChave>::imprime() const{
	this->central(this->raiz);
}

template<class TipoChave>
ArvoreBinaria<TipoChave>::~ArvoreBinaria(){
	this->liberaMemoria(this->raiz);
}

template<class TipoChave>
void ArvoreBinaria<TipoChave>::testa(No *p) const{
	if(p == NULL) return;

	if(p->esq != NULL){
		if(p->reg->compara(p->esq->reg) < 0){
			cout << "Erro: Pai " << p->reg->toString() << " menor que filho a esquerda " << p->esq->reg->toString();
			exit(1);
		}
	}
	if(p->dir != NULL){
		if(p->reg->compara(p->dir->reg) > 0){
			cout << "Erro: Pai " << p->reg->toString() << " maior que filho a direita " << p->dir->reg->toString();
			exit(1);
		}
	}

	testa(p->esq);
	testa(p->dir);
}

template<class TipoChave>
void ArvoreBinaria<TipoChave>::testa() const{
	this->testa(this->raiz);
}

#endif /* ARVOREBINARIA_H_ */
