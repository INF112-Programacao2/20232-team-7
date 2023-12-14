#include <iostream>
#include <string>
#include <vector>
#include "../include/album.hpp"

Album::Album(std::string titulo, Artista* artista, std::string generos){
    //atribui os dados
    _titulo = titulo;
    _artista = artista;
    _generos = generos;
    _duracao = 0;
    //inicializa o vector
    std::vector<Musica*> _musicas;
}

void Album::set_musica(Musica* musica){
    _musicas.push_back(musica); //adiciona música no vetor
    _duracao += musica->get_segundos(); //incrementa a duração do álbum todo
}

Musica* Album::get_musica(int posicao){
    return _musicas[posicao]; //retorna um ponteiro Música que está na posição solicitada
}

Artista* Album::get_artista() {
    return _artista; //retorna o artista
}

std::string Album::get_titulo(){
    return _titulo; //retorna o título
}

int Album::get_quantidade(){
    return _musicas.size(); //retorna quantas músicas tem no álbum
}

int Album::get_duracao(){
    return _duracao; //retorna a duração do álbum
}

std::string Album::get_generos(){
    return _generos; //retorna o gênero do álbum
}