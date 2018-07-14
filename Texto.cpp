/* 
 * File:   Palavra.h
 * Author: 
 * Renato Araujo Rizzo          RA: 587788
 * Renato Candido Kurosaki      RA: 587834
 * Gustavo Leite                RA: 552615
 *
 * Created on 14 de Julho de 2018, 07:22
 */

#include "Texto.h"
#include "Palavra.h"
#include <iostream>
#include <fstream>
#include <string>
#include <c++/6/bits/stl_list.h>

using namespace std;

Texto::Texto(){
    nome_arquivo = "";
    texto.clear();
}

Texto::~Texto(){
    texto.clear();
}

void Texto::setNomeArquivo(const string& arquivo){
    nome_arquivo = arquivo;
}

void Texto::lerArquivo(const string& arquivo) const{
    ifstream textoArquivo;
    //Tenta carregar o texto a partir do arquivo para a memoria
    try{
        textoArquivo.open(arquivo);
        if(!textoArquivo.is_open())
            throw 200;
    }
    catch(int e){
        cout << "Erro ao carregar o texto!" << endl;
        return;
    }
    
    string aux;
    string linha;
    
    //separador e uma lista de caracteres a serem descartados
    string separador{" \t\r\n,.!?;:"};
    
    //busca palavra por palavra do arquivo de texto descartando os separadores
    //definidos anteriormente
    //Faz a operacao linha por linha
    while(getline(textoArquivo, linha)){
        size_t e, s=0; //e -> final da proxima palavra; s -> offset da proxima palavra
        
        do{
            Palavra auxPalavra;
            //pula os caracteres separadores e para se nao ha mais palavras
            s = linha.find_first_not_of(separador, s);
            if(s == string::npos)
                break;
            
            //Acha o proximo separador e monta a palavra
            e = linha.find_first_of(separador, s);
            string aux(linha.substr(s, e-s));
            
            //Seta a string na classe Palavra e adiciona a palavra na lista
            auxPalavra.setPalavra(aux);
            texto.push_back(auxPalavra);
            
            //Posicao depois do separador
            s = e+1;
            
        //Ate chegar o final da linha
        } while(e != string::npos);
    }
    
    textoArquivo.close();
}

bool Texto::alterarPalavra(Palavra &atual){
    
}

bool Texto::salvarTexto(const string& nomeArquivo){
    
}