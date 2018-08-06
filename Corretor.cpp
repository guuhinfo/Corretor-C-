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
#include "Palavra.h"
#include <iostream>
#include <list>

using namespace std;

Corretor::Corretor(){
    texto.clear();
    erros.clear();
}

Corretor::~Corretor(){
    texto.clear();
    erros.clear();
    semelhantes.clear();
    listaErros.clear();
}

void Corretor::salvar(){
    string nomeTexto;
    int salvar;
    cout << "Salvar arquivo texto?" << endl;
    cout << "1: sim / 2: nao" << endl;
    cin >> salvar;
    
    if(salvar != 1)
        return;
    
    cout << "Nome do arquivo texto: " << endl;
    cin >> nomeTexto;
    if(textoOriginal.salvarTexto(nomeTexto, texto))
        cout << "Salvo com sucesso!" << endl;
    else
        cout << "Erro ao salvar o arquivo!" << endl;
    
    return;
}

void Corretor::carregarTexto(){
    string nomeArquivo;
    cout << "Nome do arquivo texto para ser aberto: " << endl;
    cin >> nomeArquivo;
    textoOriginal.setNomeArquivo(nomeArquivo);
    textoOriginal.lerArquivo();
    texto = textoOriginal.getTexto();
}

/*void Corretor::corrigirPalavra(string palavra){
    string novaPalavra;
    cout << "Corrigir a palavra: " << palavra << endl;
    cin >> novaPalavra;
    
}*/

/*
 * Faz a interacao com o usuario. Primeiramente carrega o texto da classe Texto
 * para poder manipular na classe Corretor. Passa palavra por palavra do texto
 * verificando se ha alguma palavra errada ou inexistente no dicionario. 
 * Caso a encontre, mostra o contexto em que a palavra se encontra e em seguida
 * da as opcoes para o usuario escolher!
 * 1: Permite ao usuario corrigir a palavra;
 * 2: Ignora o erro e em seguida da a opcao de incluir essa palavra no dicionario.
 *    Caso seja dada uma opcao invalida, a palavra nao sera incluida no dicionario;
 * 3: Mostra uma lista de palavras semelhantes para que o usuario possa escolher
 *    e substituir a palavra errada pela escolhida!
 * A cada Palavra errada encontrada, a mesma sera adicionada a uma lista de erros.
 */
void Corretor::principal(){
    //Nova palavra caso seja necessario usar no primeiro caso do switch
    string novaPalavra;
    
    //Pega o texto da classe Texto
    carregarTexto();
    
    /*
     * it e usado para percorrer o texto palavra por palavra.
     * anterior e posterior sao usados para contextualizar a palavra errada.
     */
    list<Palavra>::iterator anterior;
    list<Palavra>::iterator it;
    list<Palavra>::iterator posterior;
    
    it = texto.begin();
    
    // Percorre todo o texto em busca de uma palavra que nao esteja no dicionario
    while(it != texto.end()){
        semelhantes.clear();
        
        //Caso encontre um erro, mostra o contexto e da as opcoes mencionadas acima
        if( dicionario.consultar(*it) == false ){
            int opcao = 0;
            
            cout << "Contexto da palavra errada: " << it->getPalavra() << endl;
            if(it == texto.begin()){
                posterior = it;
                posterior++;
                cout << it->getPalavra() << " " << posterior->getPalavra() << endl;
            }
            
            else if(it == texto.end()){
                anterior = it;
                anterior--;
                cout << anterior->getPalavra() << " " << it->getPalavra() << endl;
            }
            else{
                anterior = it;
                anterior--;
                posterior = it;
                posterior++;
                if(posterior == texto.end()){
                    cout << anterior->getPalavra() << " " << it->getPalavra() << endl;
                } else {
                    cout << anterior->getPalavra() << " " << it->getPalavra() << " " << posterior->getPalavra() << endl;
                }
            }
            
            cout << endl;
            cout << "Escolha uma opcao:" << endl;
            cout << "1: Corrigir a palavra" << endl;
            cout << "2: Ignorar o erro" << endl;
            cout << "3: Selecionar uma palavra semelhante" << endl;
            cin >> opcao;
            
            while(opcao != 1 && opcao != 2 && opcao != 3){
                cout << endl;
                cout << "Escolha uma opcao:" << endl;
                cout << "1: Corrigir a palavra" << endl;
                cout << "2: Ignorar o erro" << endl;
                cout << "3: Selecionar uma palavra semelhante" << endl;
                cin >> opcao;
            }
            
            switch(opcao){
                case 1:{// Corrige a palavra
                    
                    cout << "Entre com a nova palavra: " << endl;
                    cin >> novaPalavra;
                    it->setPalavra(novaPalavra);
                    break;
                }    
                case 2:{
                    //Ignorar o erro e dar a opcao de adicionar ao dicionario
                    int escolha;
                    cout << "Deseja adicionar a palavra ao dicionario?" << endl;
                    cout << "1: sim" << endl;
                    cout << "2: nao" << endl;
                    cin >> escolha;
                    //Se nao fornecer nenhuma opcao valida, nao sera adicionada
                    //ao dicionario
                    if(escolha != 1)
                        break;
                    dicionario.incluirPalavra(it->getPalavra());
                    break;
                }    
                case 3:{ // Mostra uma lista de palavras semelhantes
                    semelhantes = dicionario.getListaSemelhantes();
                    
                    //Verifica se a lista de semelhantes esta vazia
                    if(semelhantes.empty() == true){
                        cout << "Nao ha palavras semelhantes!" << endl;
                        break;
                    }
                    
                    list<Palavra>::iterator iterador = semelhantes.begin();
                    int contador = 1;
                    int nroSubstituto = 0;
                    
                    cout << "Escolha um numero (0 para prosseguir sem substituir): " << endl;
                    while(iterador != semelhantes.end()) {
                        cout << "\t" << contador << ": " << iterador->getPalavra() << endl;
                        iterador++;
                        contador++;
                    }
                    cin >> nroSubstituto;
                    
                    if(nroSubstituto == 0)
                        break;
                    
                    for(iterador = semelhantes.begin(), contador = 0; contador <= nroSubstituto - 1; contador++, iterador++ ){
                        it->setPalavra(iterador->getPalavra());
                    }
                    break;
                }
                    
                default:{
                    break;
                }                           
            }

            //Adiciona a palavra na lista de erros
            listaErros.push_back(*it);
        }
        
        it++;
    }
    
    //Pega a lista de erros e adiciona a lista de tuplas (pares)
    /*list<Palavra>::iterator iterador;
    list<pair<Palavra, int>>::iterator itpair = erros.begin();
    for(iterador = listaErros.begin(); iterador = listaErros.end(); iterador++){
        
    }*/
}
