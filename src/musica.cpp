#include <iostream>
#include <stdexcept>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../include/musica.hpp"
#include "../include/artista.hpp"

//vector static que vai guardar todas as músicas que forem cadastrados
std::vector<Musica*> Musica::musicas_cadastradas;

Musica::Musica(std::string titulo, int segundos, bool explicito, std::string generos, Artista* artista, std::string caminho){
    //atribui os dados
    _titulo = titulo;
    _segundos = segundos;
    _explicito = explicito;
    _generos = generos;
    _artista = artista;
    _caminho = "./media/"+caminho;
    musicas_cadastradas.push_back(this); //insere a música no vector static
}

void Musica::set_titulo(std::string titulo){
    _titulo = titulo; //altera o título
}

std::string Musica::get_titulo(){
    return _titulo; //retorna o título
}

Artista* Musica::get_artista() {
    return _artista; //retorna o artista
}

int Musica::get_segundos(){
    return _segundos; //retorna a duração
}

bool Musica::get_explicito(){
    return _explicito; //retorna se a música tem conteúdo explícito
}

std::string Musica::get_caminho(){
    return _caminho; //retorna o caminho de onde o arquivo da música está armazenado
}

Musica* Musica::encontrar_musica(std::string nome){
    //verifica se uma música está cadastrada no sistema a partir do nome dado
    int tamanho = musicas_cadastradas.size();
    for (int i = 0; i < tamanho; i++){
        if(nome == musicas_cadastradas[i]->get_titulo()){
            return musicas_cadastradas[i];
        }
    }
    
    throw std::invalid_argument("Esta música não está cadastrada");
}

void Musica::get_musicas_cadastradas(){
    //retorna todas as músicas que já foram cadastradas
    int tamanho = musicas_cadastradas.size();
    for (int i = 0; i < tamanho; i++){
        std::cout << (i + 1) << "- " << musicas_cadastradas[i]->get_titulo() << " - by " << musicas_cadastradas[i]->get_artista()->get_nome() << std::endl;
    }
}

Musica* Musica::get_musica_cadastrada(int indice) {
    return musicas_cadastradas[indice - 1]; //retorna uma música selecionada pelo usuário
}

void Musica::tocar_musica(){
    //função que faz o áudio tocar com a biblioteca SFML
    sf::SoundBuffer musica;

    if (!musica.loadFromFile(_caminho)) { //verifica se foi possível abrir o caminho
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
        if (!som.getStatus() == sf::Music::Playing){ //para quando a musica para
            return;
        }
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