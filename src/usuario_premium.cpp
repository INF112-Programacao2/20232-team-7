#include <iostream>
#include <vector>
#include <string>

#include "../include/usuario_premium.hpp"

std::vector<Usuario_Premium*> Usuario_Premium::premium_cadastrados;

Usuario_Premium::Usuario_Premium(std::string email, std::string nome) : Usuario(email, nome) {
    this->_premium = true;
    this->_artista = false;
    premium_cadastrados.push_back(this);
}

Usuario_Premium::~Usuario_Premium() {
    _musicas_curtidas.clear();
    _artistas_curtidos.clear();
    _playlists_curtidas.clear();
    _playlists.clear();
}

void Usuario_Premium::tocar_playlist(Playlist *playlist) {       
    // Verificar se realmente será void.
}

void Usuario_Premium::definir_musica_perfil(Musica *musica) {
    _musica_perfil = musica;
}

Musica* Usuario_Premium::get_musica_perfil() {
    if (get_premium()) {
        return _musica_perfil;
    }
    else {
        return nullptr;
    }
}

Usuario_Premium* Usuario_Premium::encontrar_usuario(std::string nome){
    int tamanho = premium_cadastrados.size();
    for (int i = 0; i < tamanho; i++){
        if(nome == premium_cadastrados[i]->get_nome()){
            return premium_cadastrados[i];
        }
    }
    
    throw std::invalid_argument("Este usuário não está cadastrado");
}