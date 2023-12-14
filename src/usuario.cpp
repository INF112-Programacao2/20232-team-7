#include <iostream>
#include <vector>
#include <string>

#include "../include/perfil.hpp"
#include "../include/usuario.hpp"
#include "../include/musica.hpp"
#include "../include/playlist.hpp"
#include "../include/artista.hpp"

//vector static que guarda todos os usuários cadastrados
std::vector<Usuario*> Usuario::usuarios_cadastrados;


Usuario::Usuario(std::string email, std::string nome) {
    //atribui os dados
    _email = email;
    _nome_usuario = nome;
    _premium = false;
    _artista = false;
    usuarios_cadastrados.push_back(this); //insere o novo usuário no vector static
    _perfil = new Perfil(this); //cria um perfil para esse usuário
}

Usuario::~Usuario() {
    //limpa todos os vectors
    _musicas_curtidas.clear();
    _artistas_curtidos.clear();
    _playlists_curtidas.clear();
    _playlists.clear();
    delete _perfil;
}

Perfil* Usuario::get_perfil() {
    return _perfil; //retorna o perfil do usuário
}

std::string Usuario::get_nome() {
    return _nome_usuario; //retorna o nome
}

void Usuario::set_nome(std::string nome) {
    _nome_usuario = nome; //altera o nome
}

std::string Usuario::get_email() {
    return _email; //retorna o email
}

void Usuario::set_email(std::string email) {
    _email = email; //altera o email
}

bool Usuario::get_premium(){
    return _premium; //retorna se o usuário é premium
}

bool Usuario::get_artista(){
    return _artista; //retorna se o usuário é artista
}

int Usuario::get_quant_musicas_curtidas() {
    return _musicas_curtidas.size(); //retorna quantas músicas o usuário curtiu
}

int Usuario::get_quant_artistas_curtidos() {
    return _artistas_curtidos.size(); //retorna quantos artistas o usuário curtiu
}

int Usuario::get_quant_playlists_curtidas() {
    return _playlists_curtidas.size(); //retorna quantas playlists o usuário curtiu
}

int Usuario::get_quant_playlists() {
    return _playlists.size(); //retorna quantas playlists são do usuário
}

Musica* Usuario::get_musica_curtida(int posicao) {
    return _musicas_curtidas[posicao]; //retorna uma música curtida 
}

Artista* Usuario::get_artista_curtido(int posicao) {
    return _artistas_curtidos[posicao]; //retorna um artista curtido
}

Playlist* Usuario::get_playlist_curtida(int posicao) {
    return _playlists_curtidas[posicao]; //retorna uma playlist curtida 
}

Playlist* Usuario::get_playlist(int posicao) {
    return _playlists[posicao]; //retorna uma playlist feita pelo usuário
}

Usuario_Premium* Usuario::retorna_premium() { //se um usuário premium for acessado por um 
    if (get_premium()) {                      //ponteiro do tipo Usuario
        return static_cast<Usuario_Premium*>(this);
    }
    else {
        return nullptr;
    }
}

void Usuario::curtir_musica(Musica *musica) { //curti uma música
    bool achei = false;
    for (int i = 0; i < this-> get_quant_musicas_curtidas(); i++) {
        //impede de curtir a mesma música mais de uma vez
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

void Usuario::criar_playlist(Usuario* usuario) { //cria uma playlist
    std::string nome;
    char nome_in[100];
    int quant = 0;
    int indice = 0;

    std::cout << "Digite o nome da sua playlist: " << std::endl;
    std::cin.ignore();
    std::cin.getline(nome_in, 100);
    nome = nome_in;
    _playlists.push_back(new Playlist(nome, usuario)); //instancia a nova playlist e já armazena no vector

    std::cout << "Quantas musicas terao a sua playlist?" << std::endl;
    std::cin >> quant;

    std::cout << "Essas são as musicas disponiveis em Computify, digite o numero das musicas que deseja adicionar: " << std::endl;

    Musica::get_musicas_cadastradas();

    for (int i = 0; i < quant; i++) { //coloca a quantidade de músicas selecionada pelo usuario
        std::cin >> indice;
        _playlists[_playlists.size() - 1]->adicionar_musica(Musica::get_musica_cadastrada(indice));
    }

    std::cout << "Playlist criada com sucesso!!" << std::endl;
    std::cout << std::endl;
}

void Usuario::descurtir_musica(Musica *musica) { //descurtir uma música
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

        if (cont == quant) { //impossível descurtir uma música que ainda não foi curtida
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
        //impede de curtir a mesma playlist mais de uma vez
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

        std::cout << "Playlist descurtida com sucesso!!" << std::endl;
    }
    else {
        std::cout << "Voce ainda nao tem playlists curtidas! :(" << std::endl;
    }
}

void Usuario::curtir_artista(Artista *artista) {
    bool achei = false;
    for (int i = 0; i < this-> get_quant_artistas_curtidos(); i++) {
        //impede de curtir o mesmo artista mais de uma vez
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
        //não tem como descurtir um artista se ainda não curtiu nenhum
        std::cout << "Voce ainda nao tem artistas curtidos! :(" << std::endl; 
    }
}

Usuario* Usuario::encontrar_usuario(std::string nome){
    //encontra um usuário dentre os cadastrados a partir do nome
    int tamanho = usuarios_cadastrados.size();
    for (int i = 0; i < tamanho; i++){
        if(nome == usuarios_cadastrados[i]->get_nome()){
            return usuarios_cadastrados[i];
        }
    }
    
    throw std::invalid_argument("Este usuário não está cadastrado");
}