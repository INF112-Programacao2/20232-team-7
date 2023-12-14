#include <iostream>
#include <stdexcept>
#include <vector>
#include "../include/playlist.hpp"
#include "../include/usuario.hpp"

//vector static com todas as playlists cadastradas
std::vector<Playlist*> Playlist::playlists_cadastradas;

Playlist::Playlist(std::string nome, Usuario* usuario){
    //atribui os dados
    this->_nome = nome;
    std::vector<Musica*> _musicas;
    _usuario = usuario;
    playlists_cadastradas.push_back(this); //insere no vector static a nova playlist
}

Playlist::~Playlist(){
    _musicas.clear(); //limpa o vector
}

std::string Playlist::get_nome(){
    return this->_nome; //retorna o nome
}

Usuario* Playlist::get_usuario() {
    return this-> _usuario; //retorna o usuário que criou a playlist
}

int Playlist::get_quant_musicas(){
    return _musicas.size(); //retorna quantas músicas tem na playlist
}

Musica* Playlist::get_musica(int posicao){
    return _musicas[posicao]; //retorna uma música específica da playlist
}

void Playlist::adicionar_musica(Musica* musica){
    _musicas.push_back(musica); //adiciona uma música na playlist
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
    //encontra a playlist dentre todas as playlists cadastradas 
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
    int qtde_musicas = this-> get_quant_musicas(); //máximo
    for (int i = 0; i < qtde_musicas;) {
        this->get_musica(i)->tocar_musica(); //o que faz o som funcionar

        while (opcoes != 3 || opcoes != 4) { //menu
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
                case 5: //pula e toca
                    if (i + 1 < qtde_musicas) {
                        i = i + 1;
                        this->get_musica(i)->tocar_musica();
                    } 
                    else {
                        std::cout << "Você já está na última música da playlist." << std::endl;
                    }
                    break;
                case 6: //volta e toca
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