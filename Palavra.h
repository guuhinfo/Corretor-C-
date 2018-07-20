/* 
 * File:   Palavra.h
 * Author: 
 * Renato Araujo Rizzo          RA: 587788
 * Renato Candido Kurosaki      RA: 587834
 * Gustavo Leite                RA: 552615
 *
 * Created on 26 de Junho de 2018, 07:23
 */

#include<string>

using namespace std;

class Palavra{
private:
    string palavra;
    
public:
    //Construtor 
    Palavra(string palavra);
    
    //Setar a palavra a partir de uma Palavra
    void setPalavra(Palavra palavra);
    
    //Setar a palavra a partir de uma string
    void setPalavra(string palavra);
    
    //Recuperar a palavra
    void getPalavra();
    
    //Verifica se as palavras sao semelhantes comparando as duas primeiras letras
    bool semelhante(const Palavra &palavra);
    
    //Sobrecarga do operador == para verificar se sao identicas duas palavras
    bool operator==(Palavra &palavra);
    
};