#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

#include "../include/artista.hpp"

//vector static que vai guardar todos os artistas que forem cadastrados
std::vector<Artista*> Artista::artistas_cadastrados;

                                                          //HERANÇA
Artista::Artista(std::string email, std::string nome) : Usuario_Premium(email, nome) {
    //variável que marca se este usuário é artista
    this->_artista = true;
    //inicializa os vetores
    std::vector<Musica*> _musicas_publicadas;
    std::vector<Album*> _albuns_publicados;
    artistas_cadastrados.push_back(this); //inclui o artista no vector static
}

Artista::~Artista() {
    //limpa todos os vectors
    _musicas_publicadas.clear();
    _albuns_publicados.clear();
    _musicas_curtidas.clear();
    _artistas_curtidos.clear();
    _playlists_curtidas.clear();
    _playlists.clear();
}

int Artista::get_quant_musicas_publicadas(){
    return _musicas_publicadas.size(); //retorna a quantidade de músicas do artista
}

Musica* Artista::get_musica_publicada(int posicao){
    return _musicas_publicadas[posicao]; //retorna um ponteiro Música de uma das músicas do artista na
                                        //posição solicitada
}

int Artista::get_quant_albuns_publicados(){
    return _albuns_publicados.size(); //retorna quantos álbums o artista tem
}

Album* Artista::get_album_publicado(int posicao){
    return _albuns_publicados[posicao]; //retorna um ponteiro Album na posição solicitada
}

void Artista::publicar_musica(std::string titulo, int duracao_segundos, bool explicito, std::string genero, Artista* artista, std::string caminho) {
    //insere um novo elemento no vetor de músicas do artista, alocação dinâmica
    _musicas_publicadas.push_back(new Musica(titulo, duracao_segundos, explicito, genero, this, caminho));
}

void Artista::publicar_album(std::string titulo, std::string genero) {
    //insere um novo elemento no vetor de albuns do artista, alocação dinâmica
    _albuns_publicados.push_back(new Album(titulo, this, genero));
}

Artista* Artista::encontrar_artista(std::string nome){
    //verifica se um artista está cadastrado no sistema a partir do nome
    int quant = artistas_cadastrados.size();
    for (int i = 0; i < quant; i++){
        if(nome == artistas_cadastrados[i]->get_nome()){
            return artistas_cadastrados[i];
        }
    }

    throw std::invalid_argument("Este artista não está cadastrado");
}