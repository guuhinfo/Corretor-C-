/* 
 * File:   Arvore.h
 * Author: 
 * Renato Araujo Rizzo          RA: 587788
 * Renato Candido Kurosaki      RA: 587834
 * Gustavo Leite                RA: 552615
 *
 * Created on 10 de Maio de 2018
 */
#include"No.h"
#include<string>

using namespace std;

class Arvore

{

    public:

        // Construtor e destrutor padrões
        Arvore();

        ~Arvore();

        void Inserir(const string& word);

        bool Remover(const string& word);

        bool Buscar(const string& word);

        bool Vazia();
        
        void Limpar();

        // Para teste
        void Imprimir();

        static Arvore* Carregar(const char* path);

        bool Salvar(const char* path);

    private:

        No* raiz;

        // Rotações

        void rotacionaDuas(No*& no, Direcao dir);

        void rotacionaUma(No*& no, Direcao dir);

        // Rebalanceamentos

        void atualizaBal(No* tree,  Direcao dir);

        void rebalInserir(No*& tree, Direcao dir, bool& hChanged);

        void rebalRemover(No*& tree, Direcao dir, bool& hChanged);

        // Inserção e remoção recursivos

        void inserir(const string& word, No*& no, bool& hChanged);

        bool remover(const string& word, No*& no, bool& hChanged);

        // ----- //
        bool salvar(ofstream& stream, No* no);

        void imprimir(No* no);

        inline Direcao oposto(Direcao dir);

};

