#include <iostream>
#include <string>
#include <vector>
#include "album.hpp"

Album::Album(std::string titulo, std::string generos){
    _titulo = titulo;
    _generos = generos;
    _duracao = 0;
    std::vector<Musica*> _musicas;
}

void Album::set_musica(Musica* musica){
    _musicas.push_back(musica);
    _duracao += musica->get_segundos();
}

Musica* Album::get_musica(int posicao){
    return _musicas[posicao];
}

std::string Album::get_titulo(){
    return _titulo;
}

int Album::get_quantidade(){
    return _musicas.size();
}

int Album::get_duracao(){
    return _duracao;
}

std::string Album::get_generos(){
    return _generos;
}