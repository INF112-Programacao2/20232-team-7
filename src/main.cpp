#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "../include/usuario.hpp"
#include "../include/usuario_premium.hpp"
#include "../include/artista.hpp"
#include "../include/musica.hpp"
#include "../include/album.hpp"
#include "../include/playlist.hpp"
#include "../include/perfil.hpp"
#include "../include/controle.hpp"

int main() {
    std::vector<Usuario*> usuarios;
    std::vector<Usuario_Premium*> usuarios_premium;
    std::vector<Artista*> artistas;
    Controle comptify;
 
    char opcao;
    int tamanho = 0;

    while(true) {
        bool controle = true;
        while (true) {
            try {
                std::cout << "Escolha uma opção: " << std::endl;
                std::cout << "1- Criar novo usuario" << std::endl;
                std::cout << "2- Acessar Computify" << std::endl;
                std::cout << "x- Fechar programa" << std::endl;
                std::cin >> opcao;
                std::cout << std::endl;

                if (opcao != '1' && opcao != '2' && opcao != 'x' && opcao != 'X') {
                    throw std::invalid_argument("Opcao invalida. Digite novamente!");
                }
                break;
            }
            catch(std::invalid_argument &e) {
                std::cerr << "Erro: " << e.what() << std::endl;
                std::cout << std::endl;
            }
        }

        // Menu de criação de usuarios.
        if (opcao == '1') {
            while (controle) {
                std::string nome_usuario;
                std::string email;

                while (true) {
                    try {
                        std::cout << "Qual tipo sera esse usuario? " << std::endl;
                        std::cout << "1- Gratuito" << std::endl;
                        std::cout << "2- Premium" << std::endl;
                        std::cout << "3- Artista" << std::endl;
                        std::cout << "x- Voltar" << std::endl;
                        std::cin >> opcao;
                        std::cout << std::endl;

                        if (opcao != '1' && opcao != '2' && opcao != '3' && opcao != 'x' && opcao != 'X') {
                            throw std::invalid_argument("Opcao invalida. Digite novamente!");
                        }
                        break;
                    }
                    catch(std::invalid_argument &e) {
                        std::cerr << "Erro: " << e.what() << std::endl;
                    }
                    std::cout << std::endl;
                }

                if (opcao == '1') {
                    std::cout << "Digite seu nome de usuario: " << std::endl;
                    std::cin >> nome_usuario;
                    std::cout << "Digite seu e-mail: " << std::endl;
                    std::cin >> email;
                    usuarios.push_back(new Usuario(email, nome_usuario));
                }
                else if (opcao == '2') {
                    std::cout << "Digite seu nome de usuario: " << std::endl;
                    std::cin >> nome_usuario;
                    std::cout << "Digite seu e-mail: " << std::endl;
                    std::cin >> email;
                    usuarios_premium.push_back(new Usuario_Premium(email, nome_usuario));
                    usuarios.push_back(usuarios_premium[usuarios_premium.size() - 1]);
                }
                else if (opcao == '3') {
                    std::cout << "Digite seu nome de usuario: " << std::endl;
                    std::cin >> nome_usuario;
                    std::cout << "Digite seu e-mail: " << std::endl;
                    std::cin >> email;
                    artistas.push_back(new Artista(email, nome_usuario));
                    usuarios_premium.push_back(artistas[artistas.size()]);
                    usuarios.push_back(artistas[artistas.size() - 1]);
                }
                else if (opcao == 'x' || opcao == 'X') {
                    opcao = '0';
                    break;
                }

                std::cout << "Usuario cadastrado com sucesso!!!" << std::endl;
                std::cout << std::endl;
                opcao = '0';
                controle = false;
            }
        }

        else if (opcao == '2') {
            while (controle) {
                if (usuarios.size() > 0) {
                    int cont = 0;
                    int posicao;
                    std::string email;

                    while (true) {
                        try {
                            cont = 0;
                            std::cout << "Digite seu e-mail: " << std::endl;
                            std::cin >> email;

                            tamanho = usuarios.size();
                            for (int i = 0; i < tamanho; i++) {
                                if (usuarios[i]->get_email() == email) {
                                    posicao = i;
                                    break;
                                }
                                else {
                                    cont++;
                                }
                            }

                            if (cont == tamanho) {
                                throw std::invalid_argument("E-mail incorreto ou nao cadastrado. Digite novamente ou cadastre-se para utilizar o Computify! ;)");
                            }
                            break;

                        }
                        catch(std::invalid_argument &e ){
                            std::cerr << "Erro: " << e.what() << std::endl;
                            std::cout << std::endl;
                        }
                    }

                    std::cout << "Ola " << usuarios[posicao]->get_nome() << ", seja bem-vindo ao Computify!! :)" << std::endl;

                    std::cout << "O que deseja fazer hoje? " << std::endl;
                    
                    if (usuarios[posicao]->get_artista()){
                        comptify.comptify((Artista*) usuarios[posicao]);
                    } else if (usuarios[posicao]->get_premium()){
                        comptify.comptify((Usuario_Premium*) usuarios[posicao]);
                    } else {
                        comptify.comptify(usuarios[posicao]);
                    }
                    controle = false;
                }
                else {
                    std::cerr << "Não ha usuarios cadastrados :(" << std::endl;
                    std::cerr << "Cadastre-se para utilizar o Computify! :D" << std::endl;
                    std::cout << std::endl;
                    controle = false;
                }
            }
        }

        else if (opcao == 'x' || opcao == 'X') {
            break;
        }

    }

}