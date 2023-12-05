#include <iostream>
#include <vector>
#include "playlist.hpp"

Playlist::Playlist(std::string nome){
    this->_nome = nome;
    std::vector<Musica*> _musicas;
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
        delete _musicas[posicao];  // Libera a memória alocada dinamicamente
        for (int i = posicao; i < _musicas.size(); i++) {
            _musicas[i] = _musicas[i + 1];             // Organiza as musicas na playlist.
        }  
        _musicas.pop_back();   // Remove a última música do vetor
    } else {
        std::cerr << "Índice inválido. Não foi possível apagar o eleitor." << std::endl;
    }
}