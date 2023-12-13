#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#include <vector>

#include "perfil.hpp"
#include "musica.hpp"
#include "playlist.hpp"

class Artista;
class Usuario_Premium;
class Perfil;
class Playlist;

class Usuario {
    protected:
        static std::vector<Usuario*> usuarios_cadastrados;
        std::string _nome_usuario;
        Perfil* _perfil;
        std::string _email;
        bool _premium;
        bool _artista;
        std::vector<Musica*> _musicas_curtidas;
        std::vector<Artista*> _artistas_curtidos;
        std::vector<Playlist*> _playlists_curtidas;
        std::vector<Playlist*> _playlists;
    public:
        Usuario(std::string email, std::string nome);
        ~Usuario();

        std::string get_nome(); //
        std::string get_email(); //
        bool get_premium();
        bool get_artista();
        int get_quant_musicas_curtidas();  //
        Musica* get_musica_curtida(int posicao);  //
        int get_quant_artistas_curtidos();  //
        Artista* get_artista_curtido(int posicao); //
        int get_quant_playlists_curtidas();  //
        Playlist* get_playlist_curtida(int posicao); //
        int get_quant_playlists();  //
        Playlist* get_playlist(int posicao);

        void set_nome(std::string nome);  //
        void set_email(std::string email);  //

        Perfil* get_perfil();
        Usuario_Premium* retorna_premium();

        void curtir_musica(Musica *musica); //
        void descurtir_musica(Musica *musica);

        void curtir_playlist(Playlist *playlist); //
        void descurtir_playlist(Playlist *playlist);

        void curtir_artista(Artista *artista); //
        void descurtir_artista(Artista *artista);

        void criar_playlist(Usuario* usuario);

        static Usuario* encontrar_usuario(std::string nome);
};

#endif