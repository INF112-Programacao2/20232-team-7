#ifndef ALBUM_HPP_
#define ALBUM_HPP_

#include <string>
#include <vector>
#include "musica.hpp"

class Artista;

class Album{
    private:
        //DADOS
        std::string _titulo;
        Artista* _artista;
        std::vector<Musica*>_musicas;
        int _duracao;
        std::string _generos;
    public:
        //CONSTRUTOR
        Album(std::string titulo, Artista* artista, std::string generos);

        //SETTER
        void set_musica(Musica* musica);

        //GETTERS
        Musica* get_musica(int posicao);
        Artista* get_artista();
        std::string get_titulo();
        int get_quantidade();
        int get_duracao();
        std::string get_generos();
};

#endif