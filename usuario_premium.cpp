#include <iostream>
#include <vector>
#include <string>

#include "usuario_premium.hpp"

Usuario_Premium::Usuario_Premium(std::string email, std::string nome) : Usuario(email, nome) {}

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
    ///////////////////////////////////////////////////////
}