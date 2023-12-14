#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../include/perfil.hpp"
#include "../include/usuario_premium.hpp"
#include "../include/artista.hpp"


Perfil::Perfil(Usuario* usuario){
    //define qual usuário é o dono do perfil
    this->_usuario = usuario;
    //inicializa os vectors
    std::vector<Usuario*> _seguidores;
    std::vector<Usuario*> _seguindo;
}

Perfil::~Perfil(){
    //limpa os vectors
    _seguidores.clear();
    _seguindo.clear();
}

Usuario* Perfil::get_usuario(){
    return this->_usuario; //retorna de qual usuário é o perfil
}

int Perfil::get_quant_seguidores(){
    return _seguidores.size(); //retorna quantos seguidores ele tem
}

int Perfil::get_quant_seguindo(){
    return _seguindo.size(); //retorna quantas pessoas ele está seguindo
}

void Perfil::exibir_seguidores(){ //exibe todos os seguidores
    int tamanho = _seguidores.size();
    if (tamanho != 0){
        for (int i = 0; i < tamanho; i++){
            std::cout << (i + 1) << "- " << _seguidores[i]->get_nome() << std::endl;
        }
    } else {
        std::cout << "Não há seguidores.\n";
    }
}

void Perfil::exibir_seguindo(){ //exibe todas as pessoas que ele segue
    int tamanho = _seguindo.size();
    if (tamanho != 0){
        for (int i = 0; i < tamanho; i++){
           std::cout << (i + 1) << "- " << _seguindo[i]->get_nome() << std::endl;
        }
    } else {
        std::cout << "Não está seguindo ninguém.\n";
    }
}

void Perfil::seguir(Usuario* usuario){
    for (int i = 0; i < usuario->get_perfil()->get_quant_seguindo(); i++) {
        //impede de seguir mais de uma vez o mesmo usuário
        if (usuario->get_perfil()->_seguindo[i]->get_nome() == this-> get_usuario()->get_nome()) {
            std::cerr << "Voce ja segue esse usuario!!!" << std::endl;
            return;
        }
    }

    //coloca cada um no determinado vetor de seguidor e seguindo
    this-> _seguidores.push_back(usuario);
    usuario->get_perfil()->_seguindo.push_back(this-> _usuario);

    std::cout << "Voce esta seguindo usuario!" << std::endl;
}

void Perfil::parar_seguir(Usuario* usuario) {
    int cont_seguindo = 0;
    int seguindo = usuario->get_perfil()->get_quant_seguindo();
    for (int i = 0; i < seguindo; i++) {
        if (usuario->get_perfil()->_seguindo[i]->get_nome() != this-> get_usuario()->get_nome()) {
            cont_seguindo++;
        }
    }

    //verifica se o usuário que vai parar de seguir segue ou não o usuário em questão
    if (cont_seguindo == seguindo) {
        std::cerr << "Voce nao segue esse usuario!!!" << std::endl;
        return;
    }

    int pos = -1;
    int seguidores = _seguidores.size();
    for (int i = 0; i < seguidores; i++) {
        if (usuario->get_nome() == _seguidores[i]->get_nome()) {
            pos = i;
            break;
        }
    }

    if (pos != -1) {
        for (int i = pos; i < (seguidores - 1); i++) {
            _seguidores[i] = _seguidores[i + 1];
        }
        _seguidores.pop_back();

        int user_seguindo = usuario->get_perfil()->get_quant_seguindo();
        for (int i = 0; i < user_seguindo; i++) {
            if (usuario->get_nome() == usuario->get_perfil()->_seguindo[i]->get_nome()) {
                pos = i;
                break;
            }
        }

        for (int i = pos; i < (user_seguindo - 1); i++) {
            usuario->get_perfil()->_seguindo[i] = usuario->get_perfil()->_seguindo[i + 1];
        }
        usuario->get_perfil()->_seguindo.pop_back();

        std::cout << "Voce deixou de seguir esse usuario!" << std::endl;
    }
}

void Perfil::tocar_musica_perfil(){
    //verifica se o usuário é premium e não tem uma música de perfil definida
    if (get_usuario()->get_premium() && _usuario->retorna_premium()->get_musica_perfil() == nullptr) {
        std::cerr << "O usuario nao adicionou musica ao perfil! :(" << std::endl;
    }
    else if (!get_usuario()->get_premium()){ //se não é premium
        std::cerr << "O usuario nao e premium! :(" << std::endl;
    }
    else { //imprime qual música ele escolheu
        std::cout << "Tocando a música " << _usuario->retorna_premium()->get_musica_perfil() << std::endl;
    }
}
void Perfil::exibir_musicas_curtidas(Usuario* usuario_visualizador){
    int tamanho = _usuario->get_quant_musicas_curtidas(); //pega a quantidade
    std::string opcao;

    if (tamanho > 0) { //mostra quais são
        for (int i = 0; i < tamanho; i++){
            std::cout << (i + 1) << "- " <<get_usuario()->get_musica_curtida(i)->get_titulo() << " by " << get_usuario()->get_musica_curtida(i)->get_artista()->get_nome() << std::endl;
        }

        while(true) {
            try { //pergunta se quer escutar
                std::cout << "Deseja escutar alguma musica? (s/n)" << std::endl;
                std::cin >> opcao;
                //impede de digitar algo diferente do esperado
                if (opcao != "s" && opcao != "S" && opcao != "n" && opcao != "N") {
                    throw std::invalid_argument("Entrada invalida. Digite novamente!");
                }

                break;
            }
            catch(std::invalid_argument &e) {
                std::cerr << "Erro: " << e.what() << std::endl;
            }
        }

        if (opcao == "s" || opcao == "S") { //se ele quer escutar
            int indice;
            std::string entrada;
            std::cout << "Digite o indice da musica que deseja escutar: " <<std::endl;
            std::cin >> indice;
            indice--;

            this->_usuario->get_musica_curtida(indice)->tocar_musica();

            while(true) { //menu
                std::cout << "O que deseja fazer?" << std::endl;
                std::cout << "1- Curtir musica " << std::endl;
                std::cout << "2- Descurtir musica " << std::endl;
                std::cout << "0- voltar " << std::endl;
                std::cin >> entrada;

                if (entrada == "0") {
                    break;
                }
                else if (entrada != "1" && entrada != "2") {
                    std::cerr << "Erro: entrada invalida. Digite novamente!" << std::endl;
                }


                if(entrada == "1") {
                    usuario_visualizador->curtir_musica(this->_usuario->get_musica_curtida(indice));
                }
                else if(entrada == "2") {
                    usuario_visualizador->descurtir_musica(this->_usuario->get_musica_curtida(indice));
                }
            }
        }
        else if (opcao == "n" || opcao == "N") {
            return;
        }
    }
    else {
        std::cout << "Esse usuario nao tem musicas curtidas!" << std::endl;
    }
}
void Perfil::exibir_artistas_curtidos(Usuario* usuario_visualizador){
    int tamanho = _usuario->get_quant_artistas_curtidos(); //pega quantidade
    std::string opcao;

    if (tamanho > 0) { //exibe todos
        for (int i = 0; i < tamanho; i++){
            std::cout << (i + 1) << "- " <<get_usuario()->get_artista_curtido(i)->get_nome() << std::endl;
        }

        while(true) {
            try {
                std::cout << "Deseja acessar algum artista? (s/n)" << std::endl;
                std::cin >> opcao;
                //força a digitar o esperado
                if (opcao != "s" && opcao != "S" && opcao != "n" && opcao != "N") {
                    throw std::invalid_argument("Entrada invalida. Digite novamente!");
                }

                break;
            }
            catch(std::invalid_argument &e) {
                std::cerr << "Erro: " << e.what() << std::endl;
            }
        }

        if (opcao == "s" && opcao == "S") {
            int indice;
            std::cout << "Digite o indice do artista que deseja visualizar o perfil: " <<std::endl;
            std::cin >> indice;
            indice--;
            //mostra o escolhido
            this->_usuario->get_artista_curtido(indice)->get_perfil()->exibir_usuario(usuario_visualizador);
        }
        else if (opcao == "n" || opcao == "N") {
            return;
        }
    }
    else {
        std::cout << "Esse usuario nao tem artistas curtidos!" << std::endl;
    }
}
void Perfil::exibir_playlist_curtidas(Usuario* usuario_visualizador){
    int tamanho = _usuario->get_quant_playlists_curtidas(); //pega a quantidade
    std::string opcao;
    if (tamanho > 0) {
        for (int i = 0; i < tamanho; i++){ //exibe todas
            std::cout << (i + 1) << "- " << get_usuario()->get_playlist_curtida(i)->get_nome() << " - by " << get_usuario()->get_playlist_curtida(i)->get_usuario()->get_nome() << std::endl;
        }

        while(true) {
            try {
                std::cout << "Deseja acessar alguma playlist? (s/n)" << std::endl;
                std::cin >> opcao;
                //força a digitar o esperado
                if (opcao != "s" && opcao != "S" && opcao != "n" && opcao != "N") {
                    throw std::invalid_argument("Entrada invalida. Digite novamente!");
                }

                break;
            }
            catch(std::invalid_argument &e) {
                std::cerr << "Erro: " << e.what() << std::endl;
            }
        }

        if (opcao == "s" && opcao == "S") {
            int indice;
            std::cout << "Digite o indice da playlist que deseja escutar: " <<std::endl;
            std::cin >> indice;
            indice--;
            //faz o que o usuário selecionou
            this->get_usuario()->get_playlist_curtida(indice)->tocar_playlist(usuario_visualizador);
        }
        else if (opcao == "n" || opcao == "N") {
            return;
        }
    }
    else {
        std::cout << "Esse usuario nao tem playlists curtidas!" << std::endl;
    }
}
void Perfil::exibir_playlists(Usuario* usuario_visualizador){
    int tamanho = _usuario->get_quant_playlists(); //pega a quantidade
    std::string opcao;

    if (tamanho > 0) {
        for (int i = 0; i < tamanho; i++){ //exibe todas
            std::cout << (i + 1) << "- " << get_usuario()->get_playlist(i)->get_nome() << std::endl;
        }

        while(true) {

            std::cout << "Deseja acessar alguma playlist? (s/n)" << std::endl;
            std::cin >> opcao;
            //força o usuário a digitar o esperado
            if (opcao != "s" && opcao != "S" && opcao != "n" && opcao != "N") {
                std::cerr << "Erro: entrada invalida. Digite novamente!" << std::endl;
            }

            break;

        }

        if (opcao == "s" || opcao == "S") {
            int indice;
            std::cout << "Digite o indice da playlist que deseja escutar: " <<std::endl;
            std::cin >> indice;
            indice--;
            //faz o que o usuário pediu
            this->get_usuario()->get_playlist(indice)->tocar_playlist(usuario_visualizador);
        }
        else if (opcao == "n" || opcao == "N") {
            return;
        }
    }
    else {
        std::cout << "Esse usuario nao tem playlists criadas!" << std::endl;
    }
}
void Perfil::exibir_usuario(Usuario* usuario_visualizador){
    if (this->get_usuario()->get_premium() && this->get_usuario()->retorna_premium()->get_musica_perfil() != nullptr) {
        Musica* musica_perfil = this->get_usuario()->retorna_premium()->get_musica_perfil();
        sf::SoundBuffer musica;

        if (!musica.loadFromFile(musica_perfil->get_caminho())) {
            throw std::runtime_error("Não foi possível carregar o arquivo de áudio");
        }
        sf::Sound som(musica);

        std::cout << "Tocando agora\n";
        std::cout << musica_perfil->get_titulo() << std::endl;
        std::cout << musica_perfil->get_artista() << std::endl;
        std::cout << std::endl;
        
        //toca o arquivo
        som.play();
    }

    //mantém o programa em execução enquanto estiver tocando
    while (true) {
        while (true) {
            std::string opcao;
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

                    if (std::stoi(opcao) == 0) {
                        opcao = "0";
                        break;
                    }

                    int tamanho = opcao.size();
                    for (int i = 0; i < tamanho; i++) {
                        if (!isdigit(opcao[i])) {
                            throw std::invalid_argument("Opcao invalida. Digite novamente!");
                            break;
                        }
                    }
               
                    if (std::stoi(opcao) < 0 || std::stoi(opcao) > 7) {
                        throw std::invalid_argument("Opcao invalida. Digite novamente!");
                    }

                    break;
                } 
                catch (std::invalid_argument &e) {
                    std::cerr << e.what() << std::endl;
                }
            }

            switch (std::stoi(opcao)) {
                case 0: 
                    break;
                case 1: 
                    this-> exibir_artistas_curtidos(usuario_visualizador);
                    break;
                case 2: 
                    this-> exibir_musicas_curtidas(usuario_visualizador);
                    break;
                case 3:
                    this-> exibir_playlist_curtidas(usuario_visualizador);
                    break;
                case 4:
                    this-> exibir_playlists(usuario_visualizador);
                    break;
                case 5:
                    if(_usuario->get_premium()) {
                        tocar_musica_perfil();
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

            if (std::stoi(opcao) == 0) {
                return;
            }
            
        }
    }
}