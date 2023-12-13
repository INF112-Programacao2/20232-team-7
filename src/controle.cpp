#include <iostream>
#include <stdexcept>
#include <string>
#include <limits>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "../include/controle.hpp"
#include "../include/usuario.hpp"
#include "../include/usuario_premium.hpp"
#include "../include/artista.hpp"

Controle::Controle(){}

void Controle::comptify(Artista *artista){
    //variáveis de controle
    Playlist* playlist = nullptr;
    int opcao;
    int quantidade;
    while(true){ //menu 
        std::cout << "0 - Sair" << std::endl;
        std::cout << "1 - Exibir perfil" << std::endl;
        std::cout << "2 - Alterar nome" << std::endl;
        std::cout << "3 - Alterar e-mail" << std::endl;
        std::cout << "4 - Músicas curtidas" << std::endl;
        std::cout << "5 - Artistas curtidos" << std::endl;
        std::cout << "6 - Suas playlists" << std::endl;
        std::cout << "7 - Playlists curtidas" << std::endl;
        std::cout << "8 - Buscar música" << std::endl;
        std::cout << "9 - Buscar artista" << std::endl;
        std::cout << "10 - Buscar playlist" << std::endl;
        std::cout << "11 - Buscar outro usuário" << std::endl;
        std::cout << "12 - Criar playlist" << std::endl;
        std::cout << "13 - Escutar músicas" << std::endl;
        std::cout << "14 - Definir música de perfil" << std::endl;
        std::cout << "15 - Publicar música" << std::endl;
        std::cout << "16 - Publicar álbum" << std::endl;
        std::cout << "17 - Minhas músicas" << std::endl;
        std::cout << "18 - Meus álbuns" << std::endl;

        std::cin >> opcao;
        std::cout << std::endl;

        //variáveis que podem ser digitadas em entradas do usuário
        std::string genero;
        char titulo_[100];
        std::string titulo;
        int duracao_segundos;
        char s_n;
        bool explicito;
        std::string caminho;
        char entrada_in[100];
        std::string entrada;
        int indice;

        switch (opcao){ //verifica qual opção foi escolhida pelo usuário e faz a funcionalidade escolhida
            case 0:
                return; //volta para o menu do main
            case 1:
                artista->get_perfil()->exibir_usuario(artista); //exibe o perfil do próprio usuário
                break;
            case 2:
                std::cout << "Qual o novo nome de usuário?" << std::endl;
                std::cin >> entrada;
                artista->set_nome(entrada); //muda o atributo _nome
                break;
            case 3:
                std::cout << "Qual o novo e-mail?" << std::endl;
                std::cin >> entrada;
                artista->set_email(entrada); //muda o atributo _email
                break;
            case 4:
                if (artista->get_quant_musicas_curtidas() > 0) {
                    std::cout << "Suas músicas curtidas: " << std::endl;
                    quantidade = artista->get_quant_musicas_curtidas();
                    for(int i=0; i<quantidade; i++){
                        std::cout << (i + 1) << "- " << artista->get_musica_curtida(i)->get_titulo() << " - by " << artista->get_musica_curtida(i)->get_artista()->get_nome() << std::endl;
                    }
                }
                else {
                    std::cout << "Voce ainda nao tem musicas curtidas! :(" << std::endl;
                }
                std::cout << std::endl;
                break;
            case 5:
                if (artista->get_quant_artistas_curtidos() > 0) {
                    std::cout << "Seus artistas curtidos: " << std::endl;
                    quantidade = artista->get_quant_artistas_curtidos();
                    for(int i=0; i<quantidade; i++){
                        std::cout << (i + 1) << "- " << artista->get_artista_curtido(i)->get_nome() << std::endl;
                    }
                }
                else {
                    std::cout << "Voce nao tem nenhum artista curtido! :(" << std::endl;
                }
                std::cout << std::endl;
                break;
            case 6:
                if (artista->get_quant_playlists() > 0) {
                    std::cout << "Suas playlists: " << std::endl;
                    quantidade = artista->get_quant_playlists();
                    for(int i=0; i<quantidade; i++){
                        std::cout << (i + 1) << "- "<< artista->get_playlist(i)->get_nome() << std::endl;
                    }

                    while (true) {
                        int opcoes;
                        try {
                            std::cout << "Deseja acessar alguma playlist?" << std::endl;
                            std::cout << "1 - SIM " << std::endl;
                            std::cout << "0 - NAO " << std::endl;
                            std::cin >> opcoes;

                            if (opcoes == 0) {
                                break;
                            }

                            if (opcoes != 1) {
                                throw std::invalid_argument("Opcao invalida. Digite novamente!");
                            }
                            
                        }
                        catch(std::invalid_argument &e) {
                            std::cerr << e.what() << std::endl;
                        }

                        switch(opcoes) {
                            case 0:
                                break;
                            case 1: 
                                std::cout << "Digite o indice da playlist que deseja acessar: " << std::endl;
                                std::cin >> opcoes;
                                opcoes--;
                                Playlist* playlist = Playlist::encontrar_playlist(artista->get_playlist(opcoes)->get_nome());

                                playlist->tocar_playlist(artista);
                                break;
                        }
                    }
                }
                else {
                    std::cout << "Voce ainda nao tem nenhuma playlist! :(" << std::endl;
                }
                std::cout << std::endl;
                break;
            case 7:
                if (artista->get_quant_playlists_curtidas() > 0) {
                    std::cout << "Suas playlists curtidas: " << std::endl;
                    quantidade = artista->get_quant_playlists_curtidas();
                    for(int i=0; i<quantidade; i++){
                        std::cout << artista->get_playlist_curtida(i)->get_nome() << std::endl;
                    }

                    while (true) {
                        int opcoes;
                        try {
                            std::cout << "Deseja acessar alguma playlist?" << std::endl;
                            std::cout << "1 - SIM " << std::endl;
                            std::cout << "0 - NAO " << std::endl;
                            std::cin >> opcoes;

                            if (opcoes == 0) {
                                break;
                            }

                            if (opcoes != 1) {
                                throw std::invalid_argument("Opcao invalida. Digite novamente!");
                            }
                            
                        }
                        catch(std::invalid_argument &e) {
                            std::cerr << e.what() << std::endl;
                        }

                        switch(opcoes) {
                            case 0:
                                break;
                            case 1: 
                                std::cout << "Digite o indice da playlist que deseja acessar: " << std::endl;
                                std::cin >> opcoes;
                                opcoes--;
                                Playlist* playlist = Playlist::encontrar_playlist(artista->get_playlist_curtida(opcoes)->get_nome());
                                playlist->tocar_playlist(artista);
                        }
                    }
                }
                else {
                    std::cout << "Voce ainda nao tem nenhuma playlist curtida! :(" << std::endl;
                }
                std::cout << std::endl;
                break;
            case 8:
                std::cout << "Digite o nome da música: " << std::endl;
                std::cin.ignore();
                std::cin.getline(entrada_in, 100);
                entrada = entrada_in;
                try {
                    Musica* musica_procurada = Musica::encontrar_musica(entrada);
                    int escolher;
                    while(true){
                        std::cout << "O que deseja fazer? " << std::endl;
                        std::cout << "1 - Curtir música" << std::endl;
                        std::cout << "2 - Ouvir música" << std::endl;
                        std::cout << "3 - Descurtir música" << std::endl;
                        std::cout << "4 - Voltar" << std::endl;
                        std::cin >> escolher;
                        switch (escolher){
                            case 1:
                                artista->curtir_musica(musica_procurada);
                                break;
                            case 2:
                                musica_procurada->tocar_musica();
                                break;
                            case 3:
                                artista->descurtir_musica(musica_procurada);
                                break;
                            case 4:
                                break;
                            default:
                                std::cout << "Digite uma das opções listadas." << std::endl;
                        }

                        if (escolher == 4) {
                            break;
                        }
                    }
                } catch (std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
                break;
            case 9:
                std::cout << "Digite o nome do artista: " << std::endl;
                std::cin.ignore();
                std::cin.getline(entrada_in, 100);
                entrada = entrada_in;
                try {
                    Artista* artista_procurado = Artista::encontrar_artista(entrada);
                    int escolher;
                    while(true){
                        std::cout << "O que deseja fazer? " << std::endl;
                        std::cout << "1 - Curtir artista" << std::endl;
                        std::cout << "2 - Ver perfil do artista" << std::endl;
                        std::cout << "3 - Descurtir artista" << std::endl;
                        std::cout << "4 - Voltar" << std::endl;
                        std::cin >> escolher;

                        switch (escolher){
                            case 1:
                                artista->curtir_artista(artista_procurado);
                                break;
                            case 2:
                                artista_procurado->get_perfil()->exibir_usuario(artista);
                                break;
                            case 3:
                                artista->descurtir_artista(artista_procurado);
                                break;
                            case 4:
                                break;
                            default:
                                std::cout << "Digite uma das opções listadas." << std::endl;
                        }

                        if (escolher == 4) {
                            break;
                        }
                    }
                } catch (std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
                std::cout << std::endl;
                break;
            case 10:
                std::cout << "Digite o nome da playlist: " << std::endl;
                std::cin.ignore();
                std::cin.getline(entrada_in, 100);
                entrada = entrada_in;

                playlist = Playlist::encontrar_playlist(entrada);
                std::cout << playlist->get_nome() << " - by " << playlist->get_usuario()->get_nome() << std::endl;
                playlist->tocar_playlist(artista);

                while (true) {
                    int opcoes;

                    std::cout << "O que deseja?" << std::endl;
                    std::cout << "1 - Curtir playlist " << std::endl;
                    std::cout << "2 - Descurtir playlist " << std::endl;
                    std::cout << "0 - voltar " << std::endl;
                    std::cin >> opcoes;

                    if (opcoes == 0) {
                        break;
                    }

                    switch(opcoes) {
                        case 1:
                            artista->curtir_playlist(playlist);
                            break;
                        case 2: 
                            artista->descurtir_playlist(playlist);
                            break;
                    }
                }

                break;
            case 11:
                std::cout << "Digite o nome do usuário: " << std::endl;
                std::cin >> entrada;
                try {
                    Usuario* usuario_procurado = Usuario::encontrar_usuario(entrada);
                    usuario_procurado->get_perfil()->exibir_usuario(artista);
                } catch (std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
                break;
            case 12:
                artista->criar_playlist(artista);
                break;
            case 13:
                std::cout << "Essas são todas as músicas presentes no acervo do Comptify" << std::endl;
                std::cout << "Para escutar uma música, entre com o número dela." << std::endl;
                
                while(true){
                    Musica::get_musicas_cadastradas();
                    std::cout << "Qual música você quer escutar?" << std::endl;
                    std::cin >> indice;
                    Musica::get_musica_cadastrada(indice)->tocar_musica();

                    while(true) {
                        try {
                            std::cout << "Deseja curtir essa musica? (s/n)" << std::endl;
                            std::cin >> entrada;

                            if (entrada == "s" || entrada == "S") {
                                artista->curtir_musica(Musica::get_musica_cadastrada(indice));
                            }
                            else if (entrada != "n" || entrada != "N" || entrada != "s" || entrada != "S") {
                                throw std::invalid_argument("Entrada invalida. Digite Novamente!");
                            }

                            break;
                        }
                        catch(std::invalid_argument &e) {
                            std::cerr << "Erro: " << e.what() << std::endl;
                        }
                    }

                    while(true) {
                        try {
                            std::cout << "Quer ouvir outra música? (s/n)" << std::endl;
                            std::cin >> entrada;

                            if(entrada == "n" || entrada == "N"){
                                break;
                            }
                            else if(entrada == "s" || entrada == "S"){
                                break;
                            }
                            else {
                                throw std::invalid_argument("Entrada invalida. Digite Novamente");
                            }
                        }
                        catch(std::invalid_argument &e) {
                            std::cerr << "Erro: " << e.what() << std::endl;
                        }
                    }

                    if(entrada == "n" || entrada == "N"){
                        break;
                    }
                }
                break;
            case 14:
                std::cout << "Qual música você quer?" << std::endl;
                std::getline(std::cin, entrada);
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                try {
                    Musica* musica = Musica::encontrar_musica(entrada);
                    artista->definir_musica_perfil(musica);
                } catch (std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
                break;
            case 15:
                std::cout << "Digite o titulo da musica: " << std::endl;
                std::cin.ignore();
                std::cin.getline(titulo_, 100);
                
                titulo = titulo_;

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

                std::cout << "Digite o caminho da musica: " << std::endl;
                std::cin >> caminho;

                artista->publicar_musica(titulo, duracao_segundos, explicito, genero, artista, caminho);
                std::cout << "Musica publicada com sucesso!! " << std::endl;
                break;
            case 16:
                std::cout << "Digite o titulo do album: " << std::endl;

                std::cin.getline(titulo_, 100);
                titulo = titulo_;

                std::cout << "Digite o genero do album: " << std::endl;
                std::cin >> genero;

                artista->publicar_album(titulo, genero);

                std::cout << "Album publicado com sucesso!! " << std::endl;
                break;
            case 17:
                std::cout << "Suas músicas: " << std::endl;
                quantidade = artista->get_quant_musicas_publicadas();
                for (int i = 0; i < quantidade; i ++){
                    std::cout << artista->get_musica_publicada(i)->get_titulo() << std::endl;
                }
                break;
            case 18:
                std::cout << "Seus álbuns: " << std::endl;
                quantidade = artista->get_quant_albuns_publicados();
                for (int i = 0; i < quantidade; i++){
                    std::cout << artista->get_album_publicado(i)->get_titulo() << std::endl;
                }
                break;  
            default:
                std::cout << "Digite uma das opções listadas.\n";
        }
    }
}

void Controle::comptify(Usuario_Premium *premium){
    Playlist* playlist = nullptr;
    int opcao;
    int quantidade;
    while(true){
        std::cout << "0 - Sair" << std::endl;
        std::cout << "1 - Exibir perfil" << std::endl;
        std::cout << "2 - Alterar nome" << std::endl;
        std::cout << "3 - Alterar e-mail" << std::endl;
        std::cout << "4 - Músicas curtidas" << std::endl;
        std::cout << "5 - Artistas curtidos" << std::endl;
        std::cout << "6 - Suas playlists" << std::endl;
        std::cout << "7 - Playlists curtidas" << std::endl;
        std::cout << "8 - Buscar música" << std::endl;
        std::cout << "9 - Buscar artista" << std::endl;
        std::cout << "10 - Buscar playlist" << std::endl;
        std::cout << "11 - Buscar outro usuário" << std::endl;
        std::cout << "12 - Criar playlist" << std::endl;
        std::cout << "13 - Escutar músicas" << std::endl;
        std::cout << "14 - Definir música de perfil" << std::endl;

        std::cin >> opcao;
        std::cout << std::endl;

        std::string entrada;
        char entrada_in[100];
        int indice;
        switch (opcao){
            case 0:
                return;
            case 1:
                premium->get_perfil()->exibir_usuario(premium);
                break;
            case 2:
                std::cout << "Qual o novo nome de usuário?" << std::endl;
                std::cin >> entrada;
                premium->set_nome(entrada);
                break;
            case 3:
                std::cout << "Qual o novo e-mail?" << std::endl;
                std::cin >> entrada;
                premium->set_email(entrada);
                break;
            case 4:
                if (premium->get_quant_musicas_curtidas() > 0) {
                    std::cout << "Suas músicas curtidas: " << std::endl;
                    quantidade = premium->get_quant_musicas_curtidas();
                    for(int i=0; i<quantidade; i++){
                        std::cout << (i + 1) << "- " << premium->get_musica_curtida(i)->get_titulo() << " - by " << premium->get_musica_curtida(i)->get_artista()->get_nome() << std::endl;
                    }
                }
                else {
                    std::cout << "Voce ainda nao tem musicas curtidas! :(" << std::endl;
                }
                std::cout << std::endl;
                break;
            case 5:
                if (premium->get_quant_artistas_curtidos() > 0) {
                    std::cout << "Seus artistas curtidos: " << std::endl;
                    quantidade = premium->get_quant_artistas_curtidos();
                    for(int i=0; i<quantidade; i++){
                        std::cout << (i + 1) << "- " << premium->get_artista_curtido(i)->get_nome() << std::endl;
                    }
                }
                else {
                    std::cout << "Voce nao tem nenhum artista curtido! :(" << std::endl;
                }
                std::cout << std::endl;
                break;
            case 6:
                if (premium->get_quant_playlists() > 0) {
                    std::cout << "Suas playlists: " << std::endl;
                    quantidade = premium->get_quant_playlists();
                    for(int i=0; i<quantidade; i++){
                        std::cout << (i + 1) << "- "<< premium->get_playlist(i)->get_nome() << std::endl;
                    }

                    while (true) {
                        int opcoes;
                        try {
                            std::cout << "Deseja acessar alguma playlist?" << std::endl;
                            std::cout << "1 - SIM " << std::endl;
                            std::cout << "0 - NAO " << std::endl;
                            std::cin >> opcoes;

                            if (opcoes == 0) {
                                break;
                            }

                            if (opcoes != 1) {
                                throw std::invalid_argument("Opcao invalida. Digite novamente!");
                            }
                            
                        }
                        catch(std::invalid_argument &e) {
                            std::cerr << e.what() << std::endl;
                        }

                        switch(opcoes) {
                            case 0:
                                break;
                            case 1: 
                                std::cout << "Digite o indice da playlist que deseja acessar: " << std::endl;
                                std::cin >> opcoes;
                                opcoes--;
                                Playlist* playlist = Playlist::encontrar_playlist(premium->get_playlist(opcoes)->get_nome());
                                playlist->tocar_playlist(premium);
                        }
                    }
                }
                else {
                    std::cout << "Voce ainda nao tem nenhuma playlist! :(" << std::endl;
                }
                std::cout << std::endl;
                break;
            case 7:
                if (premium->get_quant_playlists_curtidas() > 0) {
                    std::cout << "Suas playlists curtidas: " << std::endl;
                    quantidade = premium->get_quant_playlists_curtidas();
                    for(int i=0; i<quantidade; i++){
                        std::cout << premium->get_playlist_curtida(i)->get_nome() << std::endl;
                    }

                    while (true) {
                        int opcoes;
                        try {
                            std::cout << "Deseja acessar alguma playlist?" << std::endl;
                            std::cout << "1 - SIM " << std::endl;
                            std::cout << "0 - NAO " << std::endl;
                            std::cin >> opcoes;

                            if (opcoes == 0) {
                                break;
                            }

                            if (opcoes != 1) {
                                throw std::invalid_argument("Opcao invalida. Digite novamente!");
                            }
                            
                        }
                        catch(std::invalid_argument &e) {
                            std::cerr << e.what() << std::endl;
                        }

                        switch(opcoes) {
                            case 0:
                                break;
                            case 1: 
                                std::cout << "Digite o indice da playlist que deseja acessar: " << std::endl;
                                std::cin >> opcoes;
                                opcoes--;
                                Playlist* playlist = Playlist::encontrar_playlist(premium->get_playlist_curtida(opcoes)->get_nome());
                                playlist->tocar_playlist(premium);
                        }
                    }
                }
                else {
                    std::cout << "Voce ainda nao tem nenhuma playlist curtida! :(" << std::endl;
                }
                std::cout << std::endl;
                break;
            case 8:
                std::cout << "Digite o nome da música: " << std::endl;
                std::cin.ignore();
                std::cin.getline(entrada_in, 100);
                entrada = entrada_in;

                try {
                    Musica* musica_procurada = Musica::encontrar_musica(entrada);
                    int escolher;
                    while(true){
                        std::cout << "O que deseja fazer? " << std::endl;
                        std::cout << "1 - Curtir música" << std::endl;
                        std::cout << "2 - Ouvir música" << std::endl;
                        std::cout << "3 - Descurtir música" << std::endl;
                        std::cout << "4 - Voltar" << std::endl;
                        std::cin >> escolher;
                        switch (escolher){
                            case 1:
                                premium->curtir_musica(musica_procurada);
                                break;
                            case 2:
                                musica_procurada->tocar_musica();
                                break;
                            case 3:
                                premium->descurtir_musica(musica_procurada);
                                break;
                            case 4:
                                break;
                            default:
                                std::cout << "Digite uma das opções listadas." << std::endl;
                        }

                        if (escolher == 4) {
                            break;
                        }
                    }
                } catch (std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
                break;
            case 9:
                std::cout << "Digite o nome do artista: " << std::endl;
                std::cin.ignore();
                std::cin.getline(entrada_in, 100);
                entrada = entrada_in;
                try {
                    Artista* artista_procurado = Artista::encontrar_artista(entrada);
                    int escolher;
                    while(true){
                        std::cout << "O que deseja fazer? " << std::endl;
                        std::cout << "1 - Curtir artista" << std::endl;
                        std::cout << "2 - Ver perfil do artista" << std::endl;
                        std::cout << "3 - Descurtir artista" << std::endl;
                        std::cout << "4 - Voltar" << std::endl;
                        std::cin >> escolher;

                        switch (escolher){
                            case 1:
                                premium->curtir_artista(artista_procurado);
                                break;
                            case 2:
                                artista_procurado->get_perfil()->exibir_usuario(premium);
                                break;
                            case 3:
                                premium->descurtir_artista(artista_procurado);
                                break;
                            case 4:
                                break;
                            default:
                                std::cout << "Digite uma das opções listadas." << std::endl;
                        }

                        if (escolher == 4) {
                            break;
                        }
                    }
                } catch (std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
                std::cout << std::endl;
                break;
            case 10:
                std::cout << "Digite o nome da playlist: " << std::endl;
                std::cin.ignore();
                std::cin.getline(entrada_in, 100);
                entrada = entrada_in;

                playlist = Playlist::encontrar_playlist(entrada);
                std::cout << playlist->get_nome() << " - by " << playlist->get_usuario()->get_nome() << std::endl;
                playlist->tocar_playlist(premium);

                while (true) {
                    int opcoes;

                    std::cout << "O que deseja?" << std::endl;
                    std::cout << "1 - Curtir playlist " << std::endl;
                    std::cout << "2 - Descurtir playlist " << std::endl;
                    std::cout << "0 - voltar " << std::endl;
                    std::cin >> opcoes;

                    if (opcoes == 0) {
                        break;
                    }

                    switch(opcoes) {
                        case 1:
                            premium->curtir_playlist(playlist);
                            break;
                        case 2: 
                            premium->descurtir_playlist(playlist);
                            break;
                    }
                }

                break;
            case 11:
                std::cout << "Digite o nome do usuário: " << std::endl;
                std::cin >> entrada;
                try {
                    Usuario* usuario_procurado = Usuario::encontrar_usuario(entrada);
                    usuario_procurado->get_perfil()->exibir_usuario(premium);
                } catch (std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
                break;
            case 12:
                premium->criar_playlist(premium);
                break;
            case 13:
                std::cout << "Essas são todas as músicas presentes no acervo do Comptify" << std::endl;
                std::cout << "Para escutar uma música, entre com o número dela." << std::endl;
                
                while(true){
                    Musica::get_musicas_cadastradas();
                    std::cout << "Qual música você quer escutar?" << std::endl;
                    std::cin >> indice;
                    Musica::get_musica_cadastrada(indice)->tocar_musica();

                    while(true) {
                        try {
                            std::cout << "Deseja curtir essa musica? (s/n)" << std::endl;
                            std::cin >> entrada;

                            if (entrada == "s" || entrada == "S") {
                                premium->curtir_musica(Musica::get_musica_cadastrada(indice));
                            }
                            else if (entrada != "n" || entrada != "N" || entrada != "s" || entrada != "S") {
                                throw std::invalid_argument("Entrada invalida. Digite Novamente!");
                            }

                            break;
                        }
                        catch(std::invalid_argument &e) {
                            std::cerr << "Erro: " << e.what() << std::endl;
                        }
                    }

                    while(true) {
                        try {
                            std::cout << "Quer ouvir outra música? (s/n)" << std::endl;
                            std::cin >> entrada;

                            if(entrada == "n" || entrada == "N"){
                                break;
                            }
                            else if(entrada == "s" || entrada == "S"){
                                break;
                            }
                            else {
                                throw std::invalid_argument("Entrada invalida. Digite Novamente");
                            }
                        }
                        catch(std::invalid_argument &e) {
                            std::cerr << "Erro: " << e.what() << std::endl;
                        }
                    }

                    if(entrada == "n" || entrada == "N"){
                        break;
                    }
                }
                break;
            case 14:
                std::cout << "Qual música você quer?" << std::endl;
                std::getline(std::cin, entrada);
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                try {
                    Musica* musica = Musica::encontrar_musica(entrada);
                    premium->definir_musica_perfil(musica);
                } catch (std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
                break;
            default:
                std::cout << "Digite uma das opções listadas.\n";
        }
    }
}

void Controle::comptify(Usuario *usuario){
    Playlist* playlist = nullptr;
    int opcao;
    int quantidade;
    while(true){
        std::cout << "0 - Sair" << std::endl;
        std::cout << "1 - Exibir perfil" << std::endl;
        std::cout << "2 - Alterar nome" << std::endl;
        std::cout << "3 - Alterar e-mail" << std::endl;
        std::cout << "4 - Músicas curtidas" << std::endl;
        std::cout << "5 - Artistas curtidos" << std::endl;
        std::cout << "6 - Suas playlists" << std::endl;
        std::cout << "7 - Playlists curtidas" << std::endl;
        std::cout << "8 - Buscar música" << std::endl;
        std::cout << "9 - Buscar artista" << std::endl;
        std::cout << "10 - Buscar playlist" << std::endl;
        std::cout << "11 - Buscar outro usuário" << std::endl;
        std::cout << "12 - Criar playlist" << std::endl;
        std::cout << "13 - Escutar músicas" << std::endl;
        
        std::cin >> opcao;
        std::cout << std::endl;
        char entrada_in[100];
        std::string entrada;
        int indice;
        switch (opcao){
            case 0:
                return;
            case 1:
                usuario->get_perfil()->exibir_usuario(usuario);
                break;
            case 2:
                std::cout << "Qual o novo nome de usuário?" << std::endl;
                std::cin >> entrada;
                usuario->set_nome(entrada);
                break;
            case 3:
                std::cout << "Qual o novo e-mail?" << std::endl;
                std::cin >> entrada;
                usuario->set_email(entrada);
                break;
            case 4:
                if (usuario->get_quant_musicas_curtidas() > 0) {
                    std::cout << "Suas músicas curtidas: " << std::endl;
                    quantidade = usuario->get_quant_musicas_curtidas();
                    for(int i=0; i<quantidade; i++){
                        std::cout << (i + 1) << "- " << usuario->get_musica_curtida(i)->get_titulo() << " - by " << usuario->get_musica_curtida(i)->get_artista()->get_nome() << std::endl;
                    }
                }
                else {
                    std::cout << "Voce ainda nao tem musicas curtidas! :(" << std::endl;
                }
                std::cout << std::endl;
                break;
            case 5:
                if (usuario->get_quant_artistas_curtidos() > 0) {
                    std::cout << "Seus artistas curtidos: " << std::endl;
                    quantidade = usuario->get_quant_artistas_curtidos();
                    for(int i=0; i<quantidade; i++){
                        std::cout << (i + 1) << "- " << usuario->get_artista_curtido(i)->get_nome() << std::endl;
                    }
                }
                else {
                    std::cout << "Voce nao tem nenhum artista curtido! :(" << std::endl;
                }
                std::cout << std::endl;
                break;
            case 6:
                if (usuario->get_quant_playlists() > 0) {
                    std::cout << "Suas playlists: " << std::endl;
                    quantidade = usuario->get_quant_playlists();
                    for(int i=0; i<quantidade; i++){
                        std::cout << (i + 1) << "- "<< usuario->get_playlist(i)->get_nome() << std::endl;
                    }

                    while (true) {
                        int opcoes;
                        try {
                            std::cout << "Deseja acessar alguma playlist?" << std::endl;
                            std::cout << "1 - SIM " << std::endl;
                            std::cout << "0 - NAO " << std::endl;
                            std::cin >> opcoes;

                            if (opcoes == 0) {
                                break;
                            }

                            if (opcoes != 1) {
                                throw std::invalid_argument("Opcao invalida. Digite novamente!");
                            }
                            
                        }
                        catch(std::invalid_argument &e) {
                            std::cerr << e.what() << std::endl;
                        }

                        switch(opcoes) {
                            case 0:
                                break;
                            case 1: 
                                std::cout << "Digite o indice da playlist que deseja acessar: " << std::endl;
                                std::cin >> opcoes;
                                opcoes--;
                                Playlist* playlist = Playlist::encontrar_playlist(usuario->get_playlist(opcoes)->get_nome());
                                playlist->tocar_playlist(usuario);
                        }
                    }
                }
                else {
                    std::cout << "Voce ainda nao tem nenhuma playlist! :(" << std::endl;
                }
                std::cout << std::endl;
                break;
            case 7:
                if (usuario->get_quant_playlists_curtidas() > 0) {
                    std::cout << "Suas playlists curtidas: " << std::endl;
                    quantidade = usuario->get_quant_playlists_curtidas();
                    for(int i=0; i<quantidade; i++){
                        std::cout << usuario->get_playlist_curtida(i)->get_nome() << std::endl;
                    }

                    while (true) {
                        int opcoes;
                        try {
                            std::cout << "Deseja acessar alguma playlist?" << std::endl;
                            std::cout << "1 - SIM " << std::endl;
                            std::cout << "0 - NAO " << std::endl;
                            std::cin >> opcoes;

                            if (opcoes == 0) {
                                break;
                            }

                            if (opcoes != 1) {
                                throw std::invalid_argument("Opcao invalida. Digite novamente!");
                            }
                            
                        }
                        catch(std::invalid_argument &e) {
                            std::cerr << e.what() << std::endl;
                        }

                        switch(opcoes) {
                            case 0:
                                break;
                            case 1: 
                                std::cout << "Digite o indice da playlist que deseja acessar: " << std::endl;
                                std::cin >> opcoes;
                                opcoes--;
                                Playlist* playlist = Playlist::encontrar_playlist(usuario->get_playlist_curtida(opcoes)->get_nome());
                                playlist->tocar_playlist(usuario);
                        }
                    }
                }
                else {
                    std::cout << "Voce ainda nao tem nenhuma playlist curtida! :(" << std::endl;
                }
                std::cout << std::endl;
                break;
            case 8:
                std::cout << "Digite o nome da música: " << std::endl;
                std::cin.ignore();
                std::cin.getline(entrada_in, 100);
                entrada = entrada_in;
                try {
                    Musica* musica_procurada = Musica::encontrar_musica(entrada);
                    int escolher;
                    while(true){
                        std::cout << "O que deseja fazer? " << std::endl;
                        std::cout << "1 - Curtir música" << std::endl;
                        std::cout << "2 - Ouvir música" << std::endl;
                        std::cout << "3 - Descurtir música" << std::endl;
                        std::cout << "4 - Voltar" << std::endl;
                        std::cin >> escolher;
                        switch (escolher){
                            case 1:
                                usuario->curtir_musica(musica_procurada);
                                break;
                            case 2:
                                musica_procurada->tocar_musica();
                                break;
                            case 3:
                                usuario->descurtir_musica(musica_procurada);
                                break;
                            case 4:
                                break;
                            default:
                                std::cout << "Digite uma das opções listadas." << std::endl;
                        }

                        if (escolher == 4) {
                            break;
                        }
                    }
                } catch (std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
                break;
            case 9:
                std::cout << "Digite o nome do artista: " << std::endl;
                std::cin.ignore();
                std::cin.getline(entrada_in, 100);
                entrada = entrada_in;
                try {
                    Artista* artista_procurado = Artista::encontrar_artista(entrada);
                    int escolher;
                    while(true){
                        std::cout << "O que deseja fazer? " << std::endl;
                        std::cout << "1 - Curtir artista" << std::endl;
                        std::cout << "2 - Ver perfil do artista" << std::endl;
                        std::cout << "3 - Descurtir artista" << std::endl;
                        std::cout << "4 - Voltar" << std::endl;
                        std::cin >> escolher;

                        switch (escolher){
                            case 1:
                                usuario->curtir_artista(artista_procurado);
                                break;
                            case 2:
                                artista_procurado->get_perfil()->exibir_usuario(artista_procurado);
                                break;
                            case 3:
                                usuario->descurtir_artista(artista_procurado);
                                break;
                            case 4:
                                break;
                            default:
                                std::cout << "Digite uma das opções listadas." << std::endl;
                        }

                        if (escolher == 4) {
                            break;
                        }
                    }
                } catch (std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
                std::cout << std::endl;
                break;
            case 10:
                std::cout << "Digite o nome da playlist: " << std::endl;
                std::cin.ignore();
                std::cin.getline(entrada_in, 100);
                entrada = entrada_in;

                playlist = Playlist::encontrar_playlist(entrada);
                std::cout << playlist->get_nome() << " - by " << playlist->get_usuario()->get_nome() << std::endl;
                playlist->tocar_playlist(usuario);

                while (true) {
                    int opcoes;

                    std::cout << "O que deseja?" << std::endl;
                    std::cout << "1 - Curtir playlist " << std::endl;
                    std::cout << "2 - Descurtir playlist " << std::endl;
                    std::cout << "0 - voltar " << std::endl;
                    std::cin >> opcoes;

                    if (opcoes == 0) {
                        break;
                    }

                    switch(opcoes) {
                        case 1:
                            usuario->curtir_playlist(playlist);
                            break;
                        case 2: 
                            usuario->descurtir_playlist(playlist);
                            break;
                    }
                }

                break;
            case 11:
                std::cout << "Digite o nome do usuário: " << std::endl;
                std::cin >> entrada;
                try {
                    Usuario* usuario_procurado = Usuario::encontrar_usuario(entrada);
                    usuario_procurado->get_perfil()->exibir_usuario(usuario);
                } catch (std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
                break;
            case 12:
                usuario->criar_playlist(usuario);
                break;
            case 13:
                std::cout << "Essas são todas as músicas presentes no acervo do Comptify" << std::endl;
                std::cout << "Para escutar uma música, entre com o número dela." << std::endl;
                
                while(true){
                    Musica::get_musicas_cadastradas();
                    std::cout << "Qual música você quer escutar?" << std::endl;
                    std::cin >> indice;
                    Musica::get_musica_cadastrada(indice)->tocar_musica();

                    while(true) {
                        try {
                            std::cout << "Deseja curtir essa musica? (s/n)" << std::endl;
                            std::cin >> entrada;

                            if (entrada == "s" || entrada == "S") {
                                usuario->curtir_musica(Musica::get_musica_cadastrada(indice));
                            }
                            else if (entrada != "n" || entrada != "N" || entrada != "s" || entrada != "S") {
                                throw std::invalid_argument("Entrada invalida. Digite Novamente!");
                            }

                            break;
                        }
                        catch(std::invalid_argument &e) {
                            std::cerr << "Erro: " << e.what() << std::endl;
                        }
                    }

                    while(true) {
                        try {
                            std::cout << "Quer ouvir outra música? (s/n)" << std::endl;
                            std::cin >> entrada;

                            if(entrada == "n" || entrada == "N"){
                                break;
                            }
                            else if(entrada == "s" || entrada == "S"){
                                break;
                            }
                            else {
                                throw std::invalid_argument("Entrada invalida. Digite Novamente");
                            }
                        }
                        catch(std::invalid_argument &e) {
                            std::cerr << "Erro: " << e.what() << std::endl;
                        }
                    }


                    if(entrada == "n" || entrada == "N"){
                        break;
                    }
                }
                break; 
            default:
                std::cout << "Digite uma das opções listadas.\n";
        }
    }
}