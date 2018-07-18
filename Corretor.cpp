/* 
 * File:   Corretor.cpp
 * Author: 
 * Renato Araujo Rizzo          RA: 587788
 * Renato Candido Kurosaki      RA: 587834
 * Gustavo Leite                RA: 552615
 *
 * Created on 18 de Julho de 2018, 07:57
 */

#include "Corretor.h"
#include <iostream>
#include <list>

Corretor::Corretor(){
    texto.clear();
    erros.clear();
}

Corretor::~Corretor(){
    texto.clear();
    erros.clear();
}

void Corretor::salvar(){
    string nomeTexto;
    cout << "Nome do arquivo texto: " << endl;
    cin >> nomeTexto;
    if(textoOriginal.salvarTexto(nomeTexto, texto))
        cout << "Salvo com sucesso!" << endl;
    else
        cout << "Erro ao salvar os arquivos!" << endl;
}

void Corretor::carregarTexto(){
    string nomeArquivo;
    cout << "Nome do arquivo texto para ser aberto: " << endl;
    cin >> nomeArquivo;
    textoOriginal.setNomeArquivo(nomeArquivo);
    textoOriginal.lerArquivo();
    texto = textoOriginal.getTexto();
}

void Corretor::corrigirPalavra(string &palavra){
    cout << "Corrigir a palavra: " << palavra << endl;
    cin >> palavra;
}

void Corretor::principal(){
    int opcao;
    carregarTexto();

}
