#include <iostream>
#include <stdexcept>
#include <string>
#include "musica.hpp"
#include "artista.hpp"

std::vector<Musica*> Musica::musicas_cadastradas;

Musica::Musica(std::string titulo, int segundos, bool explicito, std::string generos, Artista* artista){
    _titulo = titulo;
    _segundos = segundos;
    _explicito = explicito;
    _generos = generos;
    _artista = artista;
    musicas_cadastradas.push_back(this);
}

void Musica::set_titulo(std::string titulo){
    _titulo = titulo;
}

std::string Musica::get_titulo(){
    return _titulo;
}

Artista* Musica::get_artista() {
    return _artista;
}

int Musica::get_segundos(){
    return _segundos;
}

bool Musica::get_explicito(){
    return _explicito;
}

Musica* Musica::encontrar_musica(std::string nome){
    for (int i = 0; i < musicas_cadastradas.size(); i++){
        if(nome == musicas_cadastradas[i]->get_titulo()){
            return musicas_cadastradas[i];
        }
    }
    
    throw std::invalid_argument("Esta música não está cadastrada");
}

void Musica::get_musicas_cadastradas(){
    for (int i = 0; i < musicas_cadastradas.size(); i++){
        std::cout << (i + 1) << "- " << musicas_cadastradas[i]->get_titulo() << std::endl;
    }
}

Musica* Musica::get_musica_cadastrada(int indice) {
    return musicas_cadastradas[indice - 1];
}