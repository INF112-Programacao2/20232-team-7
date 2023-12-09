#include <iostream>
#include <vector>
#include <string>

#include "usuario.hpp"
#include "musica.hpp"
#include "playlist.hpp"
#include "artista.hpp"

Usuario::Usuario(std::string email, std::string nome) {
    _email = email;
    _nome_usuario = nome;
}

Usuario::~Usuario() {
    _musicas_curtidas.clear();
    _artistas_curtidos.clear();
    _playlists_curtidas.clear();
    _playlists.clear();
}

std::string Usuario::get_nome() {
    return _nome_usuario;
}

void Usuario::set_nome(std::string nome) {
    _nome_usuario = nome;
}

std::string Usuario::get_email() {
    return _email;
}

void Usuario::set_email(std::string email) {
    _email = email;
}

int Usuario::get_quant_musicas_curtidas() {
    return _musicas_curtidas.size();
}

int Usuario::get_quant_artistas_curtidos() {
    return _artistas_curtidos.size();
}

int Usuario::get_quant_playlists_curtidas() {
    return _playlists_curtidas.size();
}

int Usuario::get_quant_playlists() {
    return _playlists.size();
}

Musica* Usuario::get_musica_curtida(int posicao) {
    return _musicas_curtidas[posicao];
}

Artista* Usuario::get_artista_curtido(int posicao) {
    return _artistas_curtidos[posicao];
}

Playlist* Usuario::get_playlist_curtida(int posicao) {
    return _playlists_curtidas[posicao];
}

Playlist* Usuario::get_playlist(int posicao) {
    return _playlists[posicao];
}

Musica* Usuario::get_musica_perfil() {
    return _musica_perfil; ///////// MODIFICAR
}

void Usuario::curtir_musica(Musica *musica) {
    _musicas_curtidas.push_back(musica);
}

void Usuario::curtir_playlist(Playlist *playlist) {
    _playlists_curtidas.push_back(playlist);
}

void Usuario::curtir_artista(Artista *artista) {
    _artistas_curtidos.push_back(artista);
}

void Usuario::tocar_playlist(Playlist *playlist){       
// Verificar se realmente será void.
}

void Usuario::definir_musica_perfil(Musica *musica) {

}