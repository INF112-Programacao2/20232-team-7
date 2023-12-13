#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

#include "../include/artista.hpp"

std::vector<Artista*> Artista::artistas_cadastrados;

Artista::Artista(std::string email, std::string nome) : Usuario_Premium(email, nome) {
    this->_artista = true;
    std::vector<Musica*> _musicas_publicadas;
    std::vector<Album*> _albuns_publicados;
    artistas_cadastrados.push_back(this);
}

Artista::~Artista() {
    _musicas_publicadas.clear();
    _albuns_publicados.clear();
    _musicas_curtidas.clear();
    _artistas_curtidos.clear();
    _playlists_curtidas.clear();
    _playlists.clear();
}

int Artista::get_quant_musicas_publicadas(){
    return _musicas_publicadas.size();
}

Musica* Artista::get_musica_publicada(int posicao){
    return _musicas_publicadas[posicao];
}

int Artista::get_quant_albuns_publicados(){
    return _albuns_publicados.size();
}

Album* Artista::get_album_publicado(int posicao){
    return _albuns_publicados[posicao];
}

void Artista::publicar_musica(std::string titulo, int duracao_segundos, bool explicito, std::string genero, Artista* artista, std::string caminho) {
    _musicas_publicadas.push_back(new Musica(titulo, duracao_segundos, explicito, genero, this, caminho));
}

void Artista::publicar_album(std::string titulo, std::string genero) {
    _albuns_publicados.push_back(new Album(titulo, this, genero));
}

Artista* Artista::encontrar_artista(std::string nome){
    int quant = artistas_cadastrados.size();
    for (int i = 0; i < quant; i++){
        if(nome == artistas_cadastrados[i]->get_nome()){
            return artistas_cadastrados[i];
        }
    }

    throw std::invalid_argument("Este artista não está cadastrado");
}