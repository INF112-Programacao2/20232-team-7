#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

#include "artista.hpp"

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

void Artista::publicar_musica(Artista* artista) {
    std::string titulo_musica;
    int duracao_segundos;
    char s_n;
    bool explicito;
    std::string genero;

    std::cout << "Digite o titulo da musica: " << std::endl;
    std::cin >> titulo_musica;
    std::cout << "Digite a duracao em segundos da musica: " << std::endl;
    std::cin >> duracao_segundos;
    std::cout << "A musica contem conteudo explicito? Digite s/n!: " << std::endl;
    while (true) {
        try {
            std::cin >> s_n;
            if (s_n != 's' && s_n != 'S' && s_n != 'n' && s_n != 'N') {
                throw std::invalid_argument("Entrada diferente de s ou n. Digite novamente!");
            }
            break;
        }
        catch(std::invalid_argument &e) {
            std::cerr << "Erro: " << e.what() << std::endl;
        }
    }

    if (s_n == 's' || s_n == 'S') {
        explicito = true;
    }
    else {
        explicito = false;
    }

    std::cout << "Digite o genero da musica: " << std::endl;
    std::cin >> genero;

    _musicas_publicadas.push_back(new Musica(titulo_musica, duracao_segundos, explicito, genero, artista));
    std::cout << "Musica publicada com sucesso!! " << std::endl;
}

void Artista::publicar_album(Artista* artista) {
    std::string titulo_album;
    std::string genero;
    int cont;

    std::cout << "Digite o titulo do album: " << std::endl;
    std::cin >> titulo_album;

    std::cout << "Digite o genero do album: " << std::endl;
    std::cin >> genero;

    _albuns_publicados.push_back(new Album(titulo_album, artista, genero));

    std::cout << "Quantas musicas terao nesse album?" << std::endl;
    std::cin >> cont;

    for (int i = 0; i < cont; i++) {
        publicar_musica(artista);
        _albuns_publicados[_albuns_publicados.size() - 1]->set_musica(_musicas_publicadas[_musicas_publicadas.size() - 1]);
    }

    std::cout << "Album publicado com sucesso!! " << std::endl;
}

Artista* Artista::encontrar_artista(std::string nome){
    for (int i = 0; i < artistas_cadastrados.size(); i++){
        if(nome == artistas_cadastrados[i]->get_nome()){
            return artistas_cadastrados[i];
        }
    }

    throw std::invalid_argument("Este artista não está cadastrado");
}