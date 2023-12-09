#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

#include "usuario.hpp"
#include "usuario_premium.hpp"
#include "artista.hpp"
#include "musica.hpp"
#include "album.hpp"
#include "playlist.hpp"
#include "perfil.hpp"

int main() {
    std::vector<Usuario*> usuarios;
    std::vector<Usuario_Premium*> usuarios_premium;
    std::vector<Artista*> artistas;
 
    char option;

    while(true) {
        bool controller = true;
        while (true) {
            try {
                std::cout << "Escolha uma opção: " << std::endl;
                std::cout << "1- Criar novo usuario" << std::endl;
                std::cout << "2- Acessar Computify" << std::endl;
                std::cout << "x- Fechar programa" << std::endl;
                std::cin >> option;
                std::cout << std::endl;

                if (option != '1' && option != '2' && option != 'x' && option != 'X') {
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
        if (option == '1') {
            while (controller) {
                std::string nome_usuario;
                std::string email;

                while (true) {
                    try {
                        std::cout << "Qual tipo sera esse usuario? " << std::endl;
                        std::cout << "1- Gratuito" << std::endl;
                        std::cout << "2- Premium" << std::endl;
                        std::cout << "3- Artista" << std::endl;
                        std::cout << "x- Voltar" << std::endl;
                        std::cin >> option;
                        std::cout << std::endl;

                        if (option != '1' && option != '2' && option != '3' && option != 'x' && option != 'X') {
                            throw std::invalid_argument("Opcao invalida. Digite novamente!");
                        }
                        break;
                    }
                    catch(std::invalid_argument &e) {
                        std::cerr << "Erro: " << e.what() << std::endl;
                    }
                    std::cout << std::endl;
                }

                if (option == '1') {
                    std::cout << "Digite seu nome de usuario: " << std::endl;
                    std::cin >> nome_usuario;
                    std::cout << "Digite seu e-mail: " << std::endl;
                    std::cin >> email;

                    usuarios.push_back(new Usuario(email, nome_usuario));
                }
                else if (option == '2') {
                    std::cout << "Digite seu nome de usuario: " << std::endl;
                    std::cin >> nome_usuario;
                    std::cout << "Digite seu e-mail: " << std::endl;
                    std::cin >> email;

                    usuarios_premium.push_back(new Usuario_Premium(email, nome_usuario));
                    usuarios.push_back(usuarios_premium[usuarios_premium.size() - 1]);
                }
                else if (option == '3') {
                    std::cout << "Digite seu nome de usuario: " << std::endl;
                    std::cin >> nome_usuario;
                    std::cout << "Digite seu e-mail: " << std::endl;
                    std::cin >> email;

                    artistas.push_back(new Artista(email, nome_usuario));
                    usuarios_premium.push_back(artistas[artistas.size()]);
                    usuarios.push_back(artistas[artistas.size() - 1]);
                }
                else if (option == 'x' || option == 'X') {
                    option = '0';
                    break;
                }

                std::cout << "Usuario cadastrado com sucesso!!!" << std::endl;
                std::cout << std::endl;
                option = '0';
                controller = false;
            }
        }

        else if (option == '2') {
            while (controller) {
                if (usuarios.size() > 0) {
                    int cont = 0;
                    int position;
                    std::string email;

                    while (true) {
                        try {
                            cont = 0;
                            std::cout << "Digite seu e-mail: " << std::endl;
                            std::cin >> email;

                            for (int i = 0; i < usuarios.size(); i++) {
                                if (usuarios[i]->get_email() == email) {
                                    position = i;
                                    break;
                                }
                                else {
                                    cont++;
                                }
                            }

                            if (cont == usuarios.size()) {
                                throw std::invalid_argument("E-mail incorreto ou nao cadastrado. Digite novamente ou cadastre-se para utilizar o Computify! ;)");
                            }
                            break;

                        }
                        catch(std::invalid_argument &e ){
                            std::cerr << "Erro: " << e.what() << std::endl;
                            std::cout << std::endl;
                        }
                    }

                    std::cout << "Ola " << usuarios[position]->get_nome() << ", seja bem-vindo ao Computify!! :)" << std::endl;

                    std::cout << "O que deseja fazer hoje? " << std::endl;

                    controller = false;
                }
                else {
                    std::cerr << "Não ha usuarios cadastrados :(" << std::endl;
                    std::cerr << "Cadastre-se para utilizar o Computify! :D" << std::endl;
                    std::cout << std::endl;
                    controller = false;
                }
            }
        }

        else if (option == 'x' || option == 'X') {
            break;
        }

    }

}