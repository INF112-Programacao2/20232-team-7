#ifndef ALBUM_HPP_
#define ALBUM_HPP_

#include <string>
#include <vector>
#include "musica.hpp"

class Artista;

class Album{
    private:
        std::string _titulo;
        Artista* _artista;
        std::vector<Musica*>_musicas;
        int _duracao;
        std::string _generos;
    public:
        Album(std::string titulo, Artista* artista, std::string generos);

        void set_musica(Musica* musica);

        Musica* get_musica(int posicao);

        Artista* get_artista();

        std::string get_titulo();

        int get_quantidade();

        // get_imagem

        int get_duracao();

        std::string get_generos();
};

#endif