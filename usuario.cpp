#include <iostream>
#include <vector>
#include <string>

#include "perfil.hpp"
#include "usuario.hpp"
#include "musica.hpp"
#include "playlist.hpp"
#include "artista.hpp"

std::vector<Usuario*> Usuario::usuarios_cadastrados;


Usuario::Usuario(std::string email, std::string nome) {
    _email = email;
    _nome_usuario = nome;
    _premium = false;
    _artista = false;
    usuarios_cadastrados.push_back(this);
    _perfil = new Perfil(this);
}

Usuario::~Usuario() {
    _musicas_curtidas.clear();
    _artistas_curtidos.clear();
    _playlists_curtidas.clear();
    _playlists.clear();
    delete _perfil;
}

Perfil* Usuario::get_perfil() {
    return _perfil;
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

bool Usuario::get_premium(){
    return _premium;
}

bool Usuario::get_artista(){
    return _artista;
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
    bool achei = false;
    for (int i = 0; i < this-> get_quant_musicas_curtidas(); i++) {
        if (musica->get_titulo() == this-> get_musica_curtida(i)->get_titulo()) {
            std::cout << "Essa musica ja foi curtida!" << std::endl;
            achei = true;
            break;
        }
    }

    if (!achei) {
        _musicas_curtidas.push_back(musica);
        std::cout << "Musica curtida com sucesso!!" << std::endl;
    }
}

void Usuario::criar_playlist() {
    std::string nome;
    int quant = 0;
    int indice = 0;

    std::cout << "Digite o nome da sua playlist: " << std::endl;
    std::cin >> nome;

    _playlists.push_back(new Playlist(nome));

    std::cout << "Quantas musicas terao a sua playlist?" << std::endl;
    std::cin >> quant;

    std::cout << "Essas são as musicas disponiveis em Computify, digite o numero das musicas que deseja adicionar: " << std::endl;

    Musica::get_musicas_cadastradas();

    for (int i = 0; i < quant; i++) {
        std::cin >> indice;
        _playlists[_playlists.size() - 1]->adicionar_musica(Musica::get_musica_cadastrada(indice));
    }

    std::cout << "Playlist criada com sucesso!!" << std::endl;
    std::cout << std::endl;
}

void Usuario::descurtir_musica(Musica *musica) {
    int quant = this-> get_quant_musicas_curtidas();
    if (quant > 0) {
        int cont = 0;
        int pos = 0;
        for (int i = 0; i < quant; i++) {
            if (this-> _musicas_curtidas[i]->get_titulo() == musica->get_titulo()) {
                this-> _musicas_curtidas[i] = nullptr;
                pos = i;
                break;
            }
            else {
                cont++;
            }
        }

        if (cont == quant) {
            std::cout << "Essa musica ainda nao foi curtida por voce!" << std::endl;
        }
        else {
            for (int i = pos; i < (quant - 1); i++) {
                this-> _musicas_curtidas[i] = this-> _musicas_curtidas[i + 1];
            }
            _musicas_curtidas.pop_back();

            std::cout << "Musica descurtida com sucesso!!" << std::endl;
        }
    }
    else {
        std::cout << "Voce ainda nao tem musicas curtidas! :(" << std::endl;
    }

    std::cout << std::endl;
}

void Usuario::curtir_playlist(Playlist *playlist) {
    bool achei = false;
    for (int i = 0; i < this-> get_quant_playlists(); i++) {
        if (playlist->get_nome() == this-> get_playlist_curtida(i)->get_nome()) {
            achei = true;
            std::cout << "Essa playlist ja foi curtida!" << std::endl;
            break;
        }
    }

    if(!achei) {
        this-> _playlists_curtidas.push_back(playlist);
        std::cout << "Playlist curtida com sucesso!!" << std::endl;
    }
    std::cout << std::endl;
}

void Usuario::descurtir_playlist(Playlist *playlist) {
    int quant = this-> get_quant_playlists_curtidas();
    if (quant > 0) {
        int pos = 0;
        for (int i = 0; i < quant; i++) {
            if (this-> _playlists_curtidas[i]->get_nome() == playlist->get_nome()) {
                this-> _playlists_curtidas[i] = nullptr;
                pos = i;
                break;
            }
        }

        for (int i = pos; i < (quant - 1); i++) {
            this-> _playlists_curtidas[i] = this-> _playlists_curtidas[i + 1];
        }
        _playlists_curtidas.pop_back();

        std::cout << "Artista descurtido com sucesso!!" << std::endl;
    }
    else {
        std::cout << "Voce ainda nao tem playlists curtidas! :(" << std::endl;
    }
}

void Usuario::curtir_artista(Artista *artista) {
    bool achei = false;
    for (int i = 0; i < this-> get_quant_artistas_curtidos(); i++) {
        if (artista->get_nome() == this-> get_artista_curtido(i)->get_nome()) {
            achei = true;
            std::cout << "Esse artista ja foi curtido!" << std::endl;
            break;
        }
    }

    if (!achei) {
        _artistas_curtidos.push_back(artista);
        std::cout << "Artista curtido com sucesso!!" << std::endl;
    }
    std::cout << std::endl;
}

void Usuario::descurtir_artista(Artista *artista) {
    int quant = this-> get_quant_artistas_curtidos();

    if (quant > 0) {
        int pos = 0;
        for (int i = 0; i < quant; i++) {
            if (this-> _artistas_curtidos[i]->get_nome() == artista->get_nome()) {
                this-> _artistas_curtidos[i] = nullptr;
                pos = i;
                break;
            }
        }

        for (int i = pos; i < (quant - 1); i++) {
            this-> _artistas_curtidos[i] = this-> _artistas_curtidos[i + 1];
        }
        _artistas_curtidos.pop_back();

        std::cout << "Artista descurtido com sucesso!!" << std::endl;
    }
    else {
        std::cout << "Voce ainda nao tem artistas curtidos! :(" << std::endl;
    }
}

void Usuario::tocar_playlist(Playlist *playlist){       
// Verificar se realmente será void.
}

void Usuario::definir_musica_perfil(Musica *musica) {

}

Usuario* Usuario::encontrar_usuario(std::string nome){
    for (int i = 0; i < usuarios_cadastrados.size(); i++){
        if(nome == usuarios_cadastrados[i]->get_nome()){
            return usuarios_cadastrados[i];
        }
    }
    
    throw std::invalid_argument("Este usuário não está cadastrado");
}