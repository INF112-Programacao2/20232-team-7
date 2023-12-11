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
            //_seguidores[i]->exibir_infos();
        }
    } else {
        std::cout << "Não há seguidores.\n";
    }
}

void Perfil::exibir_seguindo(){
    if (_seguindo.size() != 0){
        for (int i = 0; i < _seguindo.size(); i++){
           // _seguindo[i]->exibir_infos();
        }
    } else {
        std::cout << "Não está seguindo ninguém.\n";
    }
}

void Perfil::seguir(Usuario* usuario){
    this-> _seguidores.push_back(usuario);
    usuario->get_perfil()->_seguindo.push_back(this-> _usuario);

    std::cout << "Voce esta seguindo usuario!" << std::endl;
}

void Perfil::parar_seguir(Usuario* usuario) {
    int pos = -1;

    for (int i = 0; i < _seguindo.size(); i++) {
        if (usuario->get_nome() == _seguindo[i]->get_nome()) {
            pos = i;
            break;
        }
    }

    if (pos != -1) {
        for (int i = pos; i < (_seguindo.size() - 1); i++) {
            _seguindo[i] = _seguindo[i + 1];
        }

        _seguindo.pop_back();

        parar_seguindo(usuario);

        std::cout << "Voce deixou de seguir esse usuario!" << std::endl;
    } 
    else {
        std::cout << "Voce nao estava seguindo esse usuario!" << std::endl;
    }
}

void Perfil::parar_seguindo(Usuario* usuario) {
    int pos = -1;

    for (int i = 0; i < _seguidores.size(); i++) {
        if (usuario->get_nome() == _seguidores[i]->get_nome()) {
            pos = i;
            break;
        }
    }

    if (pos != -1) {
        for (int i = pos; i < (_seguidores.size() - 1); i++) {
            _seguidores[i] = _seguidores[i + 1];
        }

        _seguidores.pop_back();
    }     
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
        std::cout << _usuario->get_artista_curtido(i) << std::endl;;
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
void Perfil::exibir_usuario(Usuario* usuario_visualizador){
    sf::Sound som = this->_usuario->get_musica_perfil()->tocar_musica();
    //toca o arquivo
    som.play();

    //mantém o programa em execução enquanto estiver tocando
    while (som.getStatus() == sf::Music::Playing) {
        while (true) {
            int opcao;
            std::cout << "Nome de usuario: " << this-> get_usuario()->get_nome() << std::endl;
            std::cout << "E-mail: " << this-> get_usuario()->get_email() << std::endl;
            std::cout << "Seguidores: " << this-> get_quant_seguidores() << std::endl;
            std::cout << "Seguindo: " << this-> get_quant_seguindo() << std::endl;
        
            std::cout << "1 - Ver artistas curtidos" << std::endl;
            std::cout << "2 - Ver musicas curtidas" << std::endl;
            std::cout << "3 - Ver playlists curtidas" << std::endl;
            std::cout << "4 - Ver playlists" << std::endl;

            if (this-> _usuario->get_premium()) {
                std::cout << "5 - Ouvir musica do perfil" << std::endl;
            }
            
            if (this->_usuario->get_nome() != usuario_visualizador->get_nome()) {
                std::cout << "6 - Seguir usuario" << std::endl;
                std::cout << "7 - Deixar de seguir" << std::endl;
            }
            std::cout << "0 - Voltar " << std::endl;

            while (true) {
                try {
                    std::cin >> opcao;

                    if (opcao == 0) {
                        break;
                    }

                    if (opcao < 0 || opcao > 7) {
                        throw std::invalid_argument("Opcao invalida. Digite novamente!");
                    }
                    break;
                }
                catch (std::invalid_argument &e) {
                    std::cerr << e.what() << std::endl;
                }
            }

            switch (opcao) {
                case 0: 
                    break;
                case 1: 
                    this-> exibir_artistas_curtidos();
                    break;
                case 2: 
                    this-> exibir_musicas_curtidas();
                    break;
                case 3:
                    this-> exibir_playlist_curtidas();
                    break;
                case 4:
                    this-> exibir_playlists();
                    break;
                case 5:
                    if(_usuario->get_premium()) {
                        //Implementar musica perfil.
                    }
                    else {
                        std::cout << "O usuario nao possui o pacote premium para obter musica personalizada no perfil!" << std::endl;
                    }
                    break;
                case 6:
                    if (this->_usuario->get_nome() != usuario_visualizador->get_nome()) {
                        this->seguir(usuario_visualizador);
                    }
                    else {
                        std::cout << "Voce não pode se seguir!" << std::endl;
                    }
                    break;
                case 7: 
                    if (this->_usuario->get_nome() != usuario_visualizador->get_nome()) {
                            usuario_visualizador->get_perfil()->parar_seguir(this-> _usuario);
                            this-> parar_seguir(usuario_visualizador);

                        }
                        else {
                            std::cout << "Voce não pode deixar de se seguir!" << std::endl;
                        }
                        break;
            }

            if (opcao == 0) {
                return;
            }
            
        }
    }
}