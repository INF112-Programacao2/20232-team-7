#include <iostream>
#include <stdexcept>
#include <string>
#include "musica.hpp"

std::vector<Musica*> musicas_cadastradas;

Musica::Musica(std::string titulo, int segundos, bool explicito, std::string generos){
    _titulo = titulo;
    _segundos = segundos;
    _explicito = explicito;
    _generos = generos;
    musicas_cadastradas.push_back(this);
}

void Musica::set_titulo(std::string titulo){
    _titulo = titulo;
}

std::string Musica::get_titulo(){
    return _titulo;
}

int Musica::get_segundos(){
    return _segundos;
}

bool Musica::get_explicito(){
    return _explicito;
}

Musica* Musica::encontrar_musica(std::string nome){
    bool encontrou = false;
    for (int i = 0; i < musicas_cadastradas.size(); i++){
        if(nome == musicas_cadastradas[i]->get_titulo()){
            encontrou = true;
            return musicas_cadastradas[i];
        }
    }
    if (!encontrou){
        throw std::invalid_argument("Esta música não está cadastrada");
    }
}