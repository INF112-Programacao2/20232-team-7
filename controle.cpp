#include <iostream>
#include <stdexcept>
#include <string>

#include "controle.hpp"
#include "usuario.hpp"
#include "usuario_premium.hpp"
#include "artista.hpp"

Controle::Controle(){}

void Controle::comptify(Artista *artista){
    int opcao;
    int quantidade;
    bool achei;
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
            case 0:
                return;
            case 1:
                artista->get_perfil()->exibir_usuario(artista);
                break;
            case 2:
                std::cout << "Qual o novo nome de usuário?" << std::endl;
                std::cin >> entrada;
                artista->set_nome(entrada);
                break;
            case 3:
                std::cout << "Qual o novo e-mail?" << std::endl;
                std::cin >> entrada;
                artista->set_email(entrada);
                break;
            case 4:
                if (artista->get_quant_musicas_curtidas() > 0) {
                    std::cout << "Suas músicas curtidas: " << std::endl;
                    quantidade = artista->get_quant_musicas_curtidas();
                    for(int i=0; i<quantidade; i++){
                        std::cout << artista->get_musica_curtida(i)->get_titulo() << " - by " << artista->get_musica_curtida(i)->get_artista()->get_nome() << std::endl;
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
                        std::cout << artista->get_artista_curtido(i)->get_nome() << std::endl;
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
                            int opcoes2;
                            case 0:
                                break;
                            case 1: 
                                std::cout << "Digite o indice da playlist que deseja acessar: " << std::endl;
                                std::cin >> opcoes;
                                opcoes--;

                                for (int i = 0; i < artista->get_playlist(opcoes)->get_quant_musicas();) {
                                    //Tocar musica enquanto
                                    std::cout << "Voce esta ouvindo: " << artista->get_playlist(opcoes)->get_musica(i)->get_titulo() << " - by " << artista->get_playlist(opcoes)->get_musica(i)->get_artista()->get_nome() << std::endl;
                                    std::cout << std::endl;

                                    std::cout << "1 - Curtir música" << std::endl;
                                    std::cout << "2 - Descurtir música" << std::endl;
                                    std::cout << "3 - Proxima musica" << std::endl;
                                    std::cout << "4 - Musica anterior" << std::endl;
                                    std::cout << "5 - Pausar" << std::endl;
                                    std::cout << "6 - Continuar" << std::endl;
                                    std::cout << "0 - Voltar ao menu inicial" << std::endl;
                                    std::cin >> opcoes2;

                                    switch(opcoes2) {
                                        case 0:
                                            break;
                                        case 1: 
                                            artista->curtir_musica(artista->get_playlist(opcoes)->get_musica(i));
                                            break;
                                        case 2:
                                            artista->descurtir_musica(artista->get_playlist(opcoes)->get_musica(i));
                                            break;
                                        case 3:
                                            if (i + 1 < artista->get_playlist(opcoes)->get_quant_musicas()) {
                                                i = i + 1;
                                            } 
                                            else {
                                                std::cout << "Você já está na última música da playlist." << std::endl;
                                            }
                                            break;
                                        case 4:
                                            if (i - 1 >= 0) {
                                                i = i - 1;
                                            } 
                                            else {
                                                std::cout << "Você já está na primeira música da playlist." << std::endl;
                                            }
                                            break;
                                        case 5:
                                            //Implementar pausar musica.
                                            break;
                                        case 6:
                                            //Implementar continuar musica.
                                            break;
                                    }

                                    if (opcoes2 == 0) {
                                        break;
                                    }
                                
                                }  
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
                }
                else {
                    std::cout << "Voce ainda nao tem nenhuma playlist curtida! :(" << std::endl;
                }
                std::cout << std::endl;
                break;
            case 8:
                std::cout << "Digite o nome da música: " << std::endl;
                std::cin >> entrada;
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
                                //artista->tocar_musica(musica_procurada);
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
                std::cin >> entrada;
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
                std::cin >> entrada;
                try {
                    Playlist* playlist = Playlist::encontrar_playlist(entrada);
                    int escolher;
                    while(true){
                        std::cout << "O que deseja fazer? " << std::endl;
                        std::cout << "1 - Curtir playlist" << std::endl;
                        std::cout << "2 - Escutar playlist" << std::endl;
                        std::cout << "3 - Descurtir playlist" << std::endl;
                        std::cout << "4 - Voltar" << std::endl;
                        std::cin >> escolher;

                        switch (escolher){
                            case 1:
                                artista->curtir_playlist(playlist);
                                break;
                            case 2:
                                artista->tocar_playlist(playlist);
                                break;
                            case 3:
                                artista->descurtir_playlist(playlist);
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
            case 11:
                std::cout << "Digite o nome do usuário: " << std::endl;
                std::cin >> entrada;
                try {
                    Usuario* usuario_procurado = Usuario::encontrar_usuario(entrada);
                    //usuario_procurado->exibir_perfil();
                } catch (std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
                break;
            case 12:
                artista->criar_playlist();
                break;
            case 13:
                std::cout << "Qual música você quer?" << std::endl;
                std::cin >> entrada;
                try {
                    Musica* musica = Musica::encontrar_musica(entrada);
                    artista->definir_musica_perfil(musica);
                } catch (std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
                break;
            case 14:
                artista->publicar_musica(artista);
                break;
            case 15:
                artista->publicar_album(artista);
                break;
            case 16:
                std::cout << "Suas músicas: " << std::endl;
                quantidade = artista->get_quant_musicas_publicadas();
                for (int i = 0; i < quantidade; i ++){
                    std::cout << artista->get_musica_publicada(i)->get_titulo() << std::endl;
                }
                break;
            case 17:
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

void Controle::comptify(Usuario_Premium* premium){
    int opcao;
    int quantidade;
    bool achei;

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
            case 0:
                std::cout << std::endl;
                return;
            case 1:
                premium->get_perfil()->exibir_usuario(premium);
                std::cout << std::endl;
                break;
            case 2:
                std::cout << "Qual o novo nome de usuário?" << std::endl;
                std::cin >> entrada;
                premium->set_nome(entrada);
                std::cout << std::endl;
                break;
            case 3:
                std::cout << "Qual o novo e-mail?" << std::endl;
                std::cin >> entrada;
                premium->set_email(entrada);
                std::cout << std::endl;
                break;
            case 4:
                if (premium->get_quant_musicas_curtidas() > 0) {
                    std::cout << "Suas músicas curtidas: " << std::endl;
                    quantidade = premium->get_quant_musicas_curtidas();
                    for(int i=0; i<quantidade; i++){
                        std::cout << premium->get_musica_curtida(i)->get_titulo() << " - by " << premium->get_musica_curtida(i)->get_artista()->get_nome() << std::endl;
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
                        std::cout << premium->get_artista_curtido(i)->get_nome() << std::endl;
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
                            int opcoes2;
                            case 0:
                                break;
                            case 1: 
                                std::cout << "Digite o indice da playlist que deseja acessar: " << std::endl;
                                std::cin >> opcoes;
                                opcoes--;

                                for (int i = 0; i < premium->get_playlist(opcoes)->get_quant_musicas();) {
                                    //Tocar musica enquanto
                                    std::cout << "Voce esta ouvindo: " << premium->get_playlist(opcoes)->get_musica(i)->get_titulo() << " - by " << premium->get_playlist(opcoes)->get_musica(i)->get_artista()->get_nome() << std::endl;
                                    std::cout << std::endl;

                                    std::cout << "1 - Curtir música" << std::endl;
                                    std::cout << "2 - Descurtir música" << std::endl;
                                    std::cout << "3 - Proxima musica" << std::endl;
                                    std::cout << "4 - Musica anterior" << std::endl;
                                    std::cout << "5 - Pausar" << std::endl;
                                    std::cout << "6 - Continuar" << std::endl;
                                    std::cout << "0 - Voltar ao menu inicial" << std::endl;
                                    std::cin >> opcoes2;

                                    switch(opcoes2) {
                                        case 0:
                                            break;
                                        case 1: 
                                            premium->curtir_musica(premium->get_playlist(opcoes)->get_musica(i));
                                            break;
                                        case 2:
                                            premium->descurtir_musica(premium->get_playlist(opcoes)->get_musica(i));
                                            break;
                                        case 3:
                                            if (i + 1 < premium->get_playlist(opcoes)->get_quant_musicas()) {
                                                i = i + 1;
                                            } 
                                            else {
                                                std::cout << "Você já está na última música da playlist." << std::endl;
                                            }
                                            break;
                                        case 4:
                                            if (i - 1 >= 0) {
                                                i = i - 1;
                                            } 
                                            else {
                                                std::cout << "Você já está na primeira música da playlist." << std::endl;
                                            }
                                            break;
                                        case 5:
                                            //Implementar pausar musica.
                                            break;
                                        case 6:
                                            //Implementar continuar musica.
                                            break;
                                    }

                                    if (opcoes2 == 0) {
                                        break;
                                    }
                                
                                }  
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
                }
                else {
                    std::cout << "Voce ainda nao tem nenhuma playlist curtida! :(" << std::endl;
                }
                std::cout << std::endl;
                break;
            case 8:
                std::cout << "Digite o nome da música: " << std::endl;
                std::cin >> entrada;
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
                                //premium->tocar_musica(musica_procurada);
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
                std::cout << std::endl;
                break;
            case 9:
                std::cout << "Digite o nome do Artista: " << std::endl;
                std::cin >> entrada;
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
                std::cin >> entrada;
                try {
                    Playlist* playlist = Playlist::encontrar_playlist(entrada);
                    int escolher;
                    while(true){
                        std::cout << "O que deseja fazer? " << std::endl;
                        std::cout << "1 - Curtir playlist" << std::endl;
                        std::cout << "2 - Escutar playlist" << std::endl;
                        std::cout << "3 - Descurtir playlist" << std::endl;
                        std::cout << "4 - Voltar" << std::endl;
                        std::cin >> escolher;

                        switch (escolher){
                            case 1:
                                premium->curtir_playlist(playlist);
                                break;
                            case 2:
                                premium->tocar_playlist(playlist);
                                break;
                            case 3:
                                premium->descurtir_playlist(playlist);
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
            case 11:
                std::cout << "Digite o nome do usuário: " << std::endl;
                std::cin >> entrada;
                try {
                    Usuario* usuario_procurado = Usuario::encontrar_usuario(entrada);
                    usuario_procurado->get_perfil()->exibir_usuario(premium);
                } catch (std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
                std::cout << std::endl;
                break;
            case 12:
                premium->criar_playlist();
                std::cout << std::endl;
                break;
            case 13:
                std::cout << "Qual música você quer?" << std::endl;
                std::cin >> entrada;
                try {
                    Musica* musica = Musica::encontrar_musica(entrada);
                    premium->definir_musica_perfil(musica);
                } catch (std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
                std::cout << std::endl;
                break;
            default:
                std::cout << "Digite uma das opções listadas.\n";
        }

    }
}

void Controle::comptify(Usuario* usuario){
    int opcao;
    int quantidade;
    bool achei;

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
            case 0:
                std::cout << std::endl;
                return;
            case 1:
                usuario->get_perfil()->exibir_usuario(usuario);
                std::cout << std::endl;
                break;
            case 2:
                std::cout << "Qual o novo nome de usuário?" << std::endl;
                std::cin >> entrada;
                usuario->set_nome(entrada);
                std::cout << std::endl;
                break;
            case 3:
                std::cout << "Qual o novo e-mail?" << std::endl;
                std::cin >> entrada;
                usuario->set_email(entrada);
                std::cout << std::endl;
                break;
            case 4:
                if (usuario->get_quant_musicas_curtidas() > 0) {
                    std::cout << "Suas músicas curtidas: " << std::endl;
                    quantidade = usuario->get_quant_musicas_curtidas();
                    for(int i=0; i<quantidade; i++){
                        std::cout << usuario->get_musica_curtida(i) << " - by " << usuario->get_musica_curtida(i)->get_artista()->get_nome() << std::endl;
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
                        std::cout << usuario->get_artista_curtido(i)->get_nome() << std::endl;
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
                            int opcoes2;
                            case 0:
                                break;
                            case 1: 
                                std::cout << "Digite o indice da playlist que deseja acessar: " << std::endl;
                                std::cin >> opcoes;
                                opcoes--;

                                for (int i = 0; i < usuario->get_playlist(opcoes)->get_quant_musicas();) {
                                    //Tocar musica enquanto
                                    std::cout << "Voce esta ouvindo: " << usuario->get_playlist(opcoes)->get_musica(i)->get_titulo() << " - by " << usuario->get_playlist(opcoes)->get_musica(i)->get_artista()->get_nome() << std::endl;
                                    std::cout << std::endl;

                                    std::cout << "1 - Curtir música" << std::endl;
                                    std::cout << "2 - Descurtir música" << std::endl;
                                    std::cout << "3 - Proxima musica" << std::endl;
                                    std::cout << "4 - Musica anterior" << std::endl;
                                    std::cout << "5 - Pausar" << std::endl;
                                    std::cout << "6 - Continuar" << std::endl;
                                    std::cout << "0 - Voltar ao menu inicial" << std::endl;
                                    std::cin >> opcoes2;

                                    switch(opcoes2) {
                                        case 0:
                                            break;
                                        case 1: 
                                            usuario->curtir_musica(usuario->get_playlist(opcoes)->get_musica(i));
                                            break;
                                        case 2:
                                            usuario->descurtir_musica(usuario->get_playlist(opcoes)->get_musica(i));
                                            break;
                                        case 3:
                                            if (i + 1 < usuario->get_playlist(opcoes)->get_quant_musicas()) {
                                                i = i + 1;
                                            } 
                                            else {
                                                std::cout << "Você já está na última música da playlist." << std::endl;
                                            }
                                            break;
                                        case 4:
                                            if (i - 1 >= 0) {
                                                i = i - 1;
                                            } 
                                            else {
                                                std::cout << "Você já está na primeira música da playlist." << std::endl;
                                            }
                                            break;
                                        case 5:
                                            //Implementar pausar musica.
                                            break;
                                        case 6:
                                            //Implementar continuar musica.
                                            break;
                                    }

                                    if (opcoes2 == 0) {
                                        break;
                                    }
                                
                                }  
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
                }
                else {
                    std::cout << "Voce ainda nao tem nenhuma playlist curtida! :(" << std::endl;
                }
                std::cout << std::endl;
                break;
            case 8:
                std::cout << "Digite o nome da música: " << std::endl;
                std::cin >> entrada;
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
                                //usuario->tocar_musica(musica_procurada);
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
                std::cout << std::endl;
                break;
            case 9:
                std::cout << "Digite o nome do usuario: " << std::endl;
                std::cin >> entrada;
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
                                artista_procurado->get_perfil()->exibir_usuario(usuario);
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
                std::cin >> entrada;
                try {
                    Playlist* playlist = Playlist::encontrar_playlist(entrada);
                    int escolher;
                    while(true){
                        std::cout << "O que deseja fazer? " << std::endl;
                        std::cout << "1 - Curtir playlist" << std::endl;
                        std::cout << "2 - Escutar playlist" << std::endl;
                        std::cout << "3 - Descurtir playlist" << std::endl;
                        std::cout << "4 - Voltar" << std::endl;
                        std::cin >> escolher;

                        switch (escolher){
                            case 1:
                                usuario->curtir_playlist(playlist);
                                break;
                            case 2:
                                //usuario->tocar_playlist(playlist);
                                break;
                            case 3:
                                usuario->descurtir_playlist(playlist);
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
            case 11:
                std::cout << "Digite o nome do usuário: " << std::endl;
                std::cin >> entrada;
                try {
                    Usuario* procurado = Usuario::encontrar_usuario(entrada);
                    procurado->get_perfil()->exibir_usuario(usuario);
                } catch (std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                }
                std::cout << std::endl;
                break;
            case 12:
                usuario->criar_playlist();
                std::cout << std::endl;
                break;
            default:
                std::cout << "Digite uma das opções listadas.\n";
        }
    }
}
