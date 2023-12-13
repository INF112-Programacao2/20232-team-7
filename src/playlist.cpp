#include <iostream>
#include <stdexcept>
#include <vector>
#include "../include/playlist.hpp"
#include "../include/usuario.hpp"

std::vector<Playlist*> Playlist::playlists_cadastradas;

Playlist::Playlist(std::string nome, Usuario* usuario){
    this->_nome = nome;
    std::vector<Musica*> _musicas;
    _usuario = usuario;
    playlists_cadastradas.push_back(this);
}

Playlist::~Playlist(){
    _musicas.clear();
}

std::string Playlist::get_nome(){
    return this->_nome;
}

Usuario* Playlist::get_usuario() {
    return this-> _usuario;
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
    int tamanho = _musicas.size();
    if (posicao >= 0 && posicao < tamanho) {
        _musicas[posicao] = nullptr;  // Remove o ponteiro para a musica da playlist.
        for (int i = posicao; i < tamanho; i++) {
            _musicas[i] = _musicas[i + 1];             // Organiza as musicas na playlist.
        }  
        _musicas.pop_back();   // Remove a última música do vetor
    } else {
        std::cerr << "Índice inválido. Não foi possível apagar o eleitor." << std::endl;
    }
}

Playlist* Playlist::encontrar_playlist(std::string nome){
    int tamanho = playlists_cadastradas.size();
    for (int i = 0; i < tamanho; i++){
        if(nome == playlists_cadastradas[i]->get_nome()){
            return playlists_cadastradas[i];
        }
    }

    throw std::invalid_argument("Esta playlist não está cadastrada");
}

void Playlist::tocar_playlist(Usuario* usuario) {
    int opcoes;
    int qtde_musicas = this-> get_quant_musicas();
    for (int i = 0; i < qtde_musicas;) {
        this->get_musica(i)->tocar_musica();

        while (opcoes != 3 || opcoes != 4) {
            std::cout << "1 - Curtir música" << std::endl;
            std::cout << "2 - Descurtir música" << std::endl;
            std::cout << "3 - Curtir artista" << std::endl;
            std::cout << "4 - Descurtir artista" << std::endl;
            std::cout << "5 - Proxima musica" << std::endl;
            std::cout << "6 - Musica anterior" << std::endl;
            std::cout << "0 - Voltar ao menu inicial" << std::endl;
            std::cin >> opcoes;

            switch(opcoes) {
                case 0:
                    break;
                case 1: 
                    usuario->curtir_musica(this->get_musica(i));
                    break;
                case 2:
                    usuario->descurtir_musica(this->get_musica(i));
                    break;
                case 3:
                    usuario->curtir_artista(this->get_musica(i)->get_artista());
                    break;
                case 4:
                    usuario->descurtir_artista(this->get_musica(i)->get_artista());
                    break;
                case 5:
                    if (i + 1 < qtde_musicas) {
                        i = i + 1;
                        this->get_musica(i)->tocar_musica();
                    } 
                    else {
                        std::cout << "Você já está na última música da playlist." << std::endl;
                    }
                    break;
                case 6:
                    if (i - 1 >= 0) {
                        i = i - 1;
                        this->get_musica(i)->tocar_musica();
                    } 
                    else {
                        std::cout << "Você já está na primeira música da playlist." << std::endl;
                    }
                    break;
                
            }

            if (opcoes == 0) {
            break;
            }
        }

        if (opcoes == 0) {
            break;
        }
    
    }
}