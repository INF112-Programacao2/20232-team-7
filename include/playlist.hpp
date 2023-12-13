#ifndef PLAYLIST_HPP_
#define PLAYLIST_HPP_
#include <string>
#include <vector>
#include "../include/musica.hpp"
#include "../include/usuario.hpp"

class Usuario;

class Playlist {
    private:
        static std::vector<Playlist*> playlists_cadastradas;
        Usuario* _usuario;
        std::string _nome;
        std::vector<Musica*> _musicas;
        bool _visibilidade;
    public:
        Playlist(std::string nome, Usuario* usuario);
        ~Playlist();

        //GETTERS
        std::string get_nome();
        Usuario* get_usuario();
        bool get_visibilidade();
        int get_quant_musicas();
        Musica* get_musica(int posicao);
        void adicionar_musica(Musica* musica);
        void apagar_musica(int posicao);
        static Playlist* encontrar_playlist(std::string nome);
        void tocar_playlist(Usuario *usuario);
};

#endif