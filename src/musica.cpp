#include <iostream>
#include <stdexcept>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../include/musica.hpp"
#include "../include/artista.hpp"

std::vector<Musica*> Musica::musicas_cadastradas;

Musica::Musica(std::string titulo, int segundos, bool explicito, std::string generos, Artista* artista, std::string caminho){
    _titulo = titulo;
    _segundos = segundos;
    _explicito = explicito;
    _generos = generos;
    _artista = artista;
    _caminho = caminho;
    musicas_cadastradas.push_back(this);
}

void Musica::set_titulo(std::string titulo){
    _titulo = titulo;
}

std::string Musica::get_titulo(){
    return _titulo;
}

Artista* Musica::get_artista() {
    return _artista;
}

int Musica::get_segundos(){
    return _segundos;
}

bool Musica::get_explicito(){
    return _explicito;
}

std::string Musica::get_caminho(){
    return _caminho;
}

Musica* Musica::encontrar_musica(std::string nome){
    int tamanho = musicas_cadastradas.size();
    for (int i = 0; i < tamanho; i++){
        if(nome == musicas_cadastradas[i]->get_titulo()){
            return musicas_cadastradas[i];
        }
    }
    
    throw std::invalid_argument("Esta música não está cadastrada");
}

void Musica::get_musicas_cadastradas(){
    int tamanho = musicas_cadastradas.size();
    for (int i = 0; i < tamanho; i++){
        std::cout << (i + 1) << "- " << musicas_cadastradas[i]->get_titulo() << " - by " << musicas_cadastradas[i]->get_artista()->get_nome() << std::endl;
    }
}

Musica* Musica::get_musica_cadastrada(int indice) {
    return musicas_cadastradas[indice - 1];
}

void Musica::tocar_musica(){
    sf::SoundBuffer musica;

        // Tente carregar o arquivo de áudio (substitua "caminho/do/arquivo.mp3" pelo caminho real do seu arquivo)
    if (!musica.loadFromFile(_caminho)) {
        throw std::runtime_error("Não foi possível carregar o arquivo de áudio");
    }
    sf::Sound som(musica);

    std::cout << std::endl;
    std::cout << "▕▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▏" << std::endl;
    std::cout << "  Tocando agora: " << this->get_titulo() << " - by " << this->get_artista()->get_nome() << std::endl;
    std::cout << std::endl;
    std::cout << "           ▄ █ ▄ █ ▄ ▄ █ ▄ █ ▄" << std::endl;
    std::cout << "           ●───────────────────" << std::endl;
    std::cout << "             ◄◄ ----▌▌----►►" << std::endl;
    std::cout << "▕▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▏" << std::endl;
    std::cout << std::endl;
    
    //toca o arquivo
    som.play();

    //mantém o programa em execução enquanto estiver tocando
    while (som.getStatus() == sf::Music::Playing) {
        char opcao;
        while(true){
            std::cout << "Deseja parar a música? (s) \n";
            std::cin >> opcao;

            if (opcao == 's' || opcao == 'S'){
                return;
            } else {
                std::cout << "Comando inválido.\n";
            }
        }
    }
}