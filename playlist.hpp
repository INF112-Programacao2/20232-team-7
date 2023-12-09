#ifndef PLAYLIST_HPP_
#define PLAYLIST_HPP_
#include <string>
#include <vector>
#include "musica.hpp"

class Playlist {
    private:
        std::string _nome;
        std::vector<Musica*> _musicas;
        bool _visibilidade;
    public:
        Playlist(std::string nome);
        ~Playlist();

        //GETTERS
        std::string get_nome();
        bool get_visibilidade();
        int get_quant_musicas();
        Musica* get_musica(int posicao);
        void adicionar_musica(Musica* musica);
        void apagar_musica(int posicao);

};

#endif