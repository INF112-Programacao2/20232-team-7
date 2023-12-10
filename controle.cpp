#include <iostream>
#include <stdexcept>
#include <string>
#include "controle.hpp"

Controle::Controle(){}

void Controle::comptify(Artista *artista){
    char opcao;
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
        std::cout << "13 - Definir música de perfil" << std::endl;
        std::cout << "14 - Publicar música" << std::endl;
        std::cout << "15 - Publicar álbum" << std::endl;
        std::cout << "16 - Minhas músicas" << std::endl;
        std::cout << "17 - Meus álbuns" << std::endl;

        std::cin >> opcao;
        std::cout << std::endl;

        std::string entrada;
        switch (opcao){
            case '0':
                return;
            case '1':
                artista->exibir_perfil();
            case '2':
                std::cout << "Qual o novo nome de usuário?" << std::endl;
                std::cin >> entrada;
                artista->set_nome(entrada);
            case '3':
                std::cout << "Qual o novo e-mail?" << std::endl;
                std::cin >> entrada;
                artista->set_email(entrada);
            case '4':
                std::cout << "Suas músicas curtidas: " << std::endl;
                int quantidade = artista->get_quant_musicas_curtidas();
                for(int i=0; i<quantidade; i++){
                    std::cout << artista->get_musica_curtida(i) << std::endl;
                }
            case '5':
                std::cout << "Seus artitas curtidos: " << std::endl;
                int quantidade = artista->get_quant_artistas_curtidos();
                for(int i=0; i<quantidade; i++){
                    std::cout << artista->get_artista_curtido(i) << std::endl;
                }
            case '6':
                std::cout << "Suas playlists: " << std::endl;
                int quantidade = artista->get_quant_playlists();
                for(int i=0; i<quantidade; i++){
                    std::cout << artista->get_playlist(i) << std::endl;
                }
            case '7':
                std::cout << "Suas playlists curtidas: " << std::endl;
                int quantidade = artista->get_quant_playlists_curtidas();
                for(int i=0; i<quantidade; i++){
                    std::cout << artista->get_playlist_curtida(i) << std::endl;
                }
            case '8':
                std::cout << "Digite o nome da música: " << std::endl;
                std::cin >> entrada;
                try {
                    Musica* musica_procurada = Musica::encontrar_musica(entrada);
                    char escolher;
                    while(true){
                        std::cout << "O que deseja fazer? " << std::endl;
                        std::cout << "1 - Curtir música" << std::endl;
                        std::cout << "2 - Ouvir música" << std::endl;
                        std::cout << "3 - Descurtir música" << std::endl;
                        std::cout << "4 - Voltar" << std::endl;
                        std::cin >> escolher;

                        switch (escolher){
                            case '1':
                                artista->curtir_musica(musica_procurada);
                            case '2':
                                artista->tocar_musica(musica_procurada);
                            case '3':
                                artista->descurtir_musica(musica_procurada);
                            case '4':
                                break;
                            default:
                                std::cout << "Digite uma das opções listadas." << std::endl;
                        }
                    }
                } catch (std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
            case '9':
                std::cout << "Digite o nome do artista: " << std::endl;
                std::cin >> entrada;
                try {
                    Artista* artista_procurado = Artista::encontrar_artista(entrada);
                    char escolher;
                    while(true){
                        std::cout << "O que deseja fazer? " << std::endl;
                        std::cout << "1 - Curtir artista" << std::endl;
                        std::cout << "2 - Ver perfil do artista" << std::endl;
                        std::cout << "3 - Descurtir artista" << std::endl;
                        std::cout << "4 - Voltar" << std::endl;
                        std::cin >> escolher;

                        switch (escolher){
                            case '1':
                                artista->curtir_artista(artista_procurado);
                            case '2':
                                artista->exibir_perfil(artista_procurado);
                            case '3':
                                artista->descurtir_artista(artista_procurado);
                            case '4':
                                break;
                            default:
                                std::cout << "Digite uma das opções listadas." << std::endl;
                        }
                    }
                } catch (std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
            case '10':
                std::cout << "Digite o nome da playlist: " << std::endl;
                std::cin >> entrada;
                try {
                    Playlist* playlist = Playlist::encontrar_playlist(entrada);
                    char escolher;
                    while(true){
                        std::cout << "O que deseja fazer? " << std::endl;
                        std::cout << "1 - Curtir playlist" << std::endl;
                        std::cout << "2 - Escutar playlist" << std::endl;
                        std::cout << "3 - Descurtir playlist" << std::endl;
                        std::cout << "4 - Voltar" << std::endl;
                        std::cin >> escolher;

                        switch (escolher){
                            case '1':
                                artista->curtir_playlist(playlist);
                            case '2':
                                artista->tocar_playlist(playlist);
                            case '3':
                                artista->descurtir_playlist(playlist);
                            case '4':
                                break;
                            default:
                                std::cout << "Digite uma das opções listadas." << std::endl;
                        }
                    }
                } catch (std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
            case '11':
                std::cout << "Digite o nome do usuário: " << std::endl;
                std::cin >> entrada;
                try {
                    Usuario* usuario_procurado = Usuario::encontrar_usuario(entrada);
                    usuario_procurado->exibir_perfil();
                } catch (std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
            case '12':
                artista->criar_playlist();
                
            case '13':
                std::cout << "Qual música você quer?" << std::endl;
                std::cin >> entrada;
                try {
                    Musica* musica = Musica::encontrar_musica(entrada);
                    artista->definir_musica_perfil(musica);
                } catch (std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
            case '14':
                artista->publicar_musica();
            case '15':
                artista->publicar_album();
            case '16':
                std::cout << "Suas músicas: " << std::endl;
                int quantidade = artista->get_quant_musicas_publicadas();
                for (int i = 0; i < quantidade; i ++){
                    artista->get_musica_publicada(i);
                }
            case '17':
                std::cout << "Seus álbuns: " << std::endl;
                int quantidade = artista->get_quant_albuns_publicados();
                for (int i = 0; i < quantidade; i++){
                    artista->get_album_publicados(i);
                }    
            default:
                std::cout << "Digite uma das opções listadas.\n";
        }

    }
}

void Controle::comptify(Usuario_Premium* premium){
    char opcao;
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
        std::cout << "13 - Definir música de perfil" << std::endl;

        std::cin >> opcao;
        std::cout << std::endl;

        std::string entrada;
        switch (opcao){
            case '0':
                return;
            case '1':
                premium->exibir_perfil();
            case '2':
                std::cout << "Qual o novo nome de usuário?" << std::endl;
                std::cin >> entrada;
                premium->set_nome(entrada);
            case '3':
                std::cout << "Qual o novo e-mail?" << std::endl;
                std::cin >> entrada;
                premium->set_email(entrada);
            case '4':
                std::cout << "Suas músicas curtidas: " << std::endl;
                int quantidade = premium->get_quant_musicas_curtidas();
                for(int i=0; i<quantidade; i++){
                    std::cout << premium->get_musica_curtida(i) << std::endl;
                }
            case '5':
                std::cout << "Seus artitas curtidos: " << std::endl;
                int quantidade = premium->get_quant_artistas_curtidos();
                for(int i=0; i<quantidade; i++){
                    std::cout << premium->get_artista_curtido(i) << std::endl;
                }
            case '6':
                std::cout << "Suas playlists: " << std::endl;
                int quantidade = premium->get_quant_playlists();
                for(int i=0; i<quantidade; i++){
                    std::cout << premium->get_playlist(i) << std::endl;
                }
            case '7':
                std::cout << "Suas playlists curtidas: " << std::endl;
                int quantidade = premium->get_quant_playlists_curtidas();
                for(int i=0; i<quantidade; i++){
                    std::cout << premium->get_playlist_curtida(i) << std::endl;
                }
            case '8':
                std::cout << "Digite o nome da música: " << std::endl;
                std::cin >> entrada;
                try {
                    Musica* musica_procurada = Musica::encontrar_musica(entrada);
                    char escolher;
                    while(true){
                        std::cout << "O que deseja fazer? " << std::endl;
                        std::cout << "1 - Curtir música" << std::endl;
                        std::cout << "2 - Ouvir música" << std::endl;
                        std::cout << "3 - Descurtir música" << std::endl;
                        std::cout << "4 - Voltar" << std::endl;
                        std::cin >> escolher;

                        switch (escolher){
                            case '1':
                                premium->curtir_musica(musica_procurada);
                            case '2':
                                premium->tocar_musica(musica_procurada);
                            case '3':
                                premium->descurtir_musica(musica_procurada);
                            case '4':
                                break;
                            default:
                                std::cout << "Digite uma das opções listadas." << std::endl;
                        }
                    }
                } catch (std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
            case '9':
                std::cout << "Digite o nome do premium: " << std::endl;
                std::cin >> entrada;
                try {
                    Artista* artista_procurado = Artista::encontrar_artista(entrada);
                    char escolher;
                    while(true){
                        std::cout << "O que deseja fazer? " << std::endl;
                        std::cout << "1 - Curtir artista" << std::endl;
                        std::cout << "2 - Ver perfil do artista" << std::endl;
                        std::cout << "3 - Descurtir artista" << std::endl;
                        std::cout << "4 - Voltar" << std::endl;
                        std::cin >> escolher;

                        switch (escolher){
                            case '1':
                                premium->curtir_artista(artista_procurado);
                            case '2':
                                premium->exibir_perfil(artista_procurado);
                            case '3':
                                premium->descurtir_artista(artista_procurado);
                            case '4':
                                break;
                            default:
                                std::cout << "Digite uma das opções listadas." << std::endl;
                        }
                    }
                } catch (std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
            case '10':
                std::cout << "Digite o nome da playlist: " << std::endl;
                std::cin >> entrada;
                try {
                    Playlist* playlist = Playlist::encontrar_playlist(entrada);
                    char escolher;
                    while(true){
                        std::cout << "O que deseja fazer? " << std::endl;
                        std::cout << "1 - Curtir playlist" << std::endl;
                        std::cout << "2 - Escutar playlist" << std::endl;
                        std::cout << "3 - Descurtir playlist" << std::endl;
                        std::cout << "4 - Voltar" << std::endl;
                        std::cin >> escolher;

                        switch (escolher){
                            case '1':
                                premium->curtir_playlist(playlist);
                            case '2':
                                premium->tocar_playlist(playlist);
                            case '3':
                                premium->descurtir_playlist(playlist);
                            case '4':
                                break;
                            default:
                                std::cout << "Digite uma das opções listadas." << std::endl;
                        }
                    }
                } catch (std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
            case '11':
                std::cout << "Digite o nome do usuário: " << std::endl;
                std::cin >> entrada;
                try {
                    Usuario* usuario_procurado = Usuario::encontrar_usuario(entrada);
                    usuario_procurado->exibir_perfil();
                } catch (std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
            case '12':
                premium->criar_playlist();
                
            case '13':
                std::cout << "Qual música você quer?" << std::endl;
                std::cin >> entrada;
                try {
                    Musica* musica = Musica::encontrar_musica(entrada);
                    premium->definir_musica_perfil(musica);
                } catch (std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
            default:
                std::cout << "Digite uma das opções listadas.\n";
        }

    }
}

void Controle::comptify(Usuario* Usuario){
    char opcao;
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

        std::cin >> opcao;
        std::cout << std::endl;

        std::string entrada;
        switch (opcao){
            case '0':
                return;
            case '1':
                usuario->exibir_perfil();
            case '2':
                std::cout << "Qual o novo nome de usuário?" << std::endl;
                std::cin >> entrada;
                usuario->set_nome(entrada);
            case '3':
                std::cout << "Qual o novo e-mail?" << std::endl;
                std::cin >> entrada;
                usuario->set_email(entrada);
            case '4':
                std::cout << "Suas músicas curtidas: " << std::endl;
                int quantidade = usuario->get_quant_musicas_curtidas();
                for(int i=0; i<quantidade; i++){
                    std::cout << usuario->get_musica_curtida(i) << std::endl;
                }
            case '5':
                std::cout << "Seus artitas curtidos: " << std::endl;
                int quantidade = usuario->get_quant_artistas_curtidos();
                for(int i=0; i<quantidade; i++){
                    std::cout << usuario->get_artista_curtido(i) << std::endl;
                }
            case '6':
                std::cout << "Suas playlists: " << std::endl;
                int quantidade = usuario->get_quant_playlists();
                for(int i=0; i<quantidade; i++){
                    std::cout << usuario->get_playlist(i) << std::endl;
                }
            case '7':
                std::cout << "Suas playlists curtidas: " << std::endl;
                int quantidade = usuario->get_quant_playlists_curtidas();
                for(int i=0; i<quantidade; i++){
                    std::cout << usuario->get_playlist_curtida(i) << std::endl;
                }
            case '8':
                std::cout << "Digite o nome da música: " << std::endl;
                std::cin >> entrada;
                try {
                    Musica* musica_procurada = Musica::encontrar_musica(entrada);
                    char escolher;
                    while(true){
                        std::cout << "O que deseja fazer? " << std::endl;
                        std::cout << "1 - Curtir música" << std::endl;
                        std::cout << "2 - Ouvir música" << std::endl;
                        std::cout << "3 - Descurtir música" << std::endl;
                        std::cout << "4 - Voltar" << std::endl;
                        std::cin >> escolher;

                        switch (escolher){
                            case '1':
                                usuario->curtir_musica(musica_procurada);
                            case '2':
                                usuario->tocar_musica(musica_procurada);
                            case '3':
                                usuario->descurtir_musica(musica_procurada);
                            case '4':
                                break;
                            default:
                                std::cout << "Digite uma das opções listadas." << std::endl;
                        }
                    }
                } catch (std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
            case '9':
                std::cout << "Digite o nome do usuario: " << std::endl;
                std::cin >> entrada;
                try {
                    Artista* artista_procurado = Artista::encontrar_artista(entrada);
                    char escolher;
                    while(true){
                        std::cout << "O que deseja fazer? " << std::endl;
                        std::cout << "1 - Curtir artista" << std::endl;
                        std::cout << "2 - Ver perfil do artista" << std::endl;
                        std::cout << "3 - Descurtir artista" << std::endl;
                        std::cout << "4 - Voltar" << std::endl;
                        std::cin >> escolher;

                        switch (escolher){
                            case '1':
                                usuario->curtir_artista(artista_procurado);
                            case '2':
                                usuario->exibir_perfil(artista_procurado);
                            case '3':
                                usuario->descurtir_artista(artista_procurado);
                            case '4':
                                break;
                            default:
                                std::cout << "Digite uma das opções listadas." << std::endl;
                        }
                    }
                } catch (std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
            case '10':
                std::cout << "Digite o nome da playlist: " << std::endl;
                std::cin >> entrada;
                try {
                    Playlist* playlist = Playlist::encontrar_playlist(entrada);
                    char escolher;
                    while(true){
                        std::cout << "O que deseja fazer? " << std::endl;
                        std::cout << "1 - Curtir playlist" << std::endl;
                        std::cout << "2 - Escutar playlist" << std::endl;
                        std::cout << "3 - Descurtir playlist" << std::endl;
                        std::cout << "4 - Voltar" << std::endl;
                        std::cin >> escolher;

                        switch (escolher){
                            case '1':
                                usuario->curtir_playlist(playlist);
                            case '2':
                                usuario->tocar_playlist(playlist);
                            case '3':
                                usuario->descurtir_playlist(playlist);
                            case '4':
                                break;
                            default:
                                std::cout << "Digite uma das opções listadas." << std::endl;
                        }
                    }
                } catch (std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
            case '11':
                std::cout << "Digite o nome do usuário: " << std::endl;
                std::cin >> entrada;
                try {
                    Usuario* procurado = Usuario::encontrar_usuario(entrada);
                    procurado->exibir_perfil();
                } catch (std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
            case '12':
                usuario->criar_playlist();
            default:
                std::cout << "Digite uma das opções listadas.\n";
        }

    }
}
