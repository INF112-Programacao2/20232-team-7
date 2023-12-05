#include <iostream>
#include <vector>
#include "perfil.hpp"

Perfil::Perfil(Usuario* usuario){
    this->_usuario = usuario;
    std::vector<Usuario*> _seguidores;
    std::vector<Usuario*> _seguindo;
}

Perfil::~Perfil(){
    _seguidores.clear();
    _seguindo.clear();
}

Usuario* Perfil::get_usuario(){
    return this->_usuario;
}

int Perfil::get_quant_seguidores(){
    return _seguidores.size();
}

int Perfil::get_quant_seguindo(){
    return _seguindo.size();
}

void Perfil::exibir_seguidores(){
    if (_seguidores.size() != 0){
        for (int i = 0; i < _seguidores.size(); i++){
            _seguidores[i]->exibir_infos();
        }
    } else {
        std::cout << "Não há seguidores.\n";
    }
}

void Perfil::exibir_seguindo(){
    if (_seguindo.size() != 0){
        for (int i = 0; i < _seguindo.size(); i++){
            _seguindo[i]->exibir_infos();
        }
    } else {
        std::cout << "Não está seguindo ninguém.\n";
    }
}

void Perfil::seguir(Usuario* usuario){
    _seguidores.push_back(usuario);
}

void Perfil::tocar_musica_perfil(){
    std::cout << "Tocando a música " << _usuario->get_musica_perfil() << std::endl;
}
void Perfil::exibir_musicas_curtidas(){
    for (int i = 0; i < _usuario->get_quant_musicas_curtidas(); i++){
        _usuario->get_musica_curtida(i);
    }
}
void Perfil::exibir_artistas_curtidos(){
    for (int i = 0; i < _usuario->get_quant_artistas_curtidos(); i++){
        _usuario->get_artista_curtido(i);
    }
}
void Perfil::exibir_playlist_curtidas(){
    for (int i = 0; i < _usuario->get_quant_playlists_curtidas(); i++){
        _usuario->get_playlist_curtida(i);
    }
}
void Perfil::exibir_playlists(){
    for (int i = 0; i < _usuario->get_quant_playlists(); i++){
        _usuario->get_playlist(i);
    }
}
void Perfil::exibir_usuario(){
    _usuario->exibir_infos();
}