#include <iostream>
#include <string>
#include "musica.hpp"

int Musica::_views = 0;

Musica::Musica(std::string titulo, int segundos, bool explicito, std::string generos){
    _titulo = titulo;
    _segundos = segundos;
    _explicito = explicito;
    _generos = generos;
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

void Musica::set_views(){
    _views++;
}

int Musica::get_views(){
    return _views;
}

bool Musica::get_explicito(){
    return _explicito;
}