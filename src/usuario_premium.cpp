#include <iostream>
#include <vector>
#include <string>

#include "../include/usuario_premium.hpp"

//vector static para guardar todos os usuários premium
std::vector<Usuario_Premium*> Usuario_Premium::premium_cadastrados;
                                                                      //HERANÇA
Usuario_Premium::Usuario_Premium(std::string email, std::string nome) : Usuario(email, nome) {
    //atribui os dados
    this->_premium = true; //define como premium
    this->_artista = false;
    premium_cadastrados.push_back(this); //insere no vector static
}

Usuario_Premium::~Usuario_Premium() {
    //limpa todos os vectors
    _musicas_curtidas.clear();
    _artistas_curtidos.clear();
    _playlists_curtidas.clear();
    _playlists.clear();
}

void Usuario_Premium::definir_musica_perfil(Musica *musica) {
    _musica_perfil = musica; //define qual música vai tocar quando exibir o perfil do usuário
}

Musica* Usuario_Premium::get_musica_perfil() {
    if (get_premium()) {
        return _musica_perfil; //retorna qual a música do usuário
    }
    else {
        return nullptr; //se não houver nenhuma
    }
}

Usuario_Premium* Usuario_Premium::encontrar_usuario(std::string nome){
    //encontra um usuário dentre todos os premium
    int tamanho = premium_cadastrados.size();
    for (int i = 0; i < tamanho; i++){
        if(nome == premium_cadastrados[i]->get_nome()){
            return premium_cadastrados[i];
        }
    }
    
    throw std::invalid_argument("Este usuário não está cadastrado");
}