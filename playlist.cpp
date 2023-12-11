#include <iostream>
#include <stdexcept>
#include <vector>
#include "playlist.hpp"

std::vector<Playlist*> Playlist::playlists_cadastradas;

Playlist::Playlist(std::string nome){
    this->_nome = nome;
    std::vector<Musica*> _musicas;
    playlists_cadastradas.push_back(this);
}

Playlist::~Playlist(){
    _musicas.clear();
}

std::string Playlist::get_nome(){
    return this->_nome;
}

bool Playlist::get_visibilidade(){
    return this->_visibilidade;
}

int Playlist::get_quant_musicas(){
    return _musicas.size();
}

Musica* Playlist::get_musica(int posicao){
    return _musicas[posicao];
}

void Playlist::adicionar_musica(Musica* musica){
    _musicas.push_back(musica);
}

void Playlist::apagar_musica(int posicao){
    if (posicao >= 0 && posicao < _musicas.size()) {
        _musicas[posicao] = nullptr;  // Remove o ponteiro para a musica da playlist.
        for (int i = posicao; i < _musicas.size(); i++) {
            _musicas[i] = _musicas[i + 1];             // Organiza as musicas na playlist.
        }  
        _musicas.pop_back();   // Remove a última música do vetor
    } else {
        std::cerr << "Índice inválido. Não foi possível apagar o eleitor." << std::endl;
    }
}

Playlist* Playlist::encontrar_playlist(std::string nome){
    for (int i = 0; i < playlists_cadastradas.size(); i++){
        if(nome == playlists_cadastradas[i]->get_nome()){
            return playlists_cadastradas[i];
        }
    }

    throw std::invalid_argument("Esta playlist não está cadastrada");
}