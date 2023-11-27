#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#include <vector>
#include "musica.h"
#include "playlist.hpp"
#include "artista.hpp"

class Usuario {
    protected:
        std::string _nome_usuario;
        std::string _email;
        std::vector<Musica*> _musicas_curtidas;
        std::vector<Artista*> _artitas_curtidos;
        std::vector<Playlist*> _playlists_curtidas;
        std::vector<Playlist*> _playlists;
        Musica *_musica_perfil;
    public:
        Usuario(std::string email, std::string nome);
        ~Usuario();

        std::string get_nome();
        std::string get_email();
        int get_quant_musicas_curtidas();
        Musica* get_musica_curtida(int posicao);
        int get_quant_artistas_curtidos();
        Artista* get_artista_curtido(int posicao);
        int get_quant_playlists_curtidas();
        Playlist* get_playlist_curtida(int posicao);
        int get_quant_playlists();
        Playlist* get_playlist(int posicao);
        Musica* get_musica_perfil();

        void set_nome(std::string nome);
        void set_email(std::string email);

        void curtir_musica(Musica &musica);
        void curtir_playlist(Playlist &playlist);
        void curtir_artista(Artista &artista);
        virtual void tocar_playlist(Playlist &playlist);       // Verificar se realmente será void.
        virtual void definir_musica_perfil(Musica &musica);
};

#endif