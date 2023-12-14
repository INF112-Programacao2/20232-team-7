#ifndef PLAYLIST_HPP_
#define PLAYLIST_HPP_
#include <string>
#include <vector>
#include "musica.hpp"
#include "usuario.hpp"

class Usuario;

class Playlist {
    private:
        //DADOS
        static std::vector<Playlist*> playlists_cadastradas;
        Usuario* _usuario;
        std::string _nome;
        std::vector<Musica*> _musicas; //COMPOSIÇÃO
    public:
        //CONSTRUTOR E DESTRUTOR
        Playlist(std::string nome, Usuario* usuario);
        ~Playlist();

        //GETTERS
        std::string get_nome();
        Usuario* get_usuario();
        int get_quant_musicas();
        Musica* get_musica(int posicao);

        //MÉTODOS
        void adicionar_musica(Musica* musica);
        void apagar_musica(int posicao);
        static Playlist* encontrar_playlist(std::string nome);
        void tocar_playlist(Usuario *usuario);
};

#endif