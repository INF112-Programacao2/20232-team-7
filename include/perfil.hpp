#ifndef PERFIL_HPP_
#define PERFIL_HPP_
#include <vector>
#include "usuario.hpp"

class Usuario;

class Perfil {
    private:
        //DADOS
        //COMPOSIÇÃO
        Usuario* _usuario;
        std::vector<Usuario*> _seguidores;
        std::vector<Usuario*> _seguindo;
    public:
        //CONSTRUTOR E DESTRUTOR
        Perfil(Usuario* usuario);
        ~Perfil();

        //GETTERS
        Usuario* get_usuario();
        int get_quant_seguidores();
        int get_quant_seguindo();

        //SETTERS
        void exibir_seguidores();
        void exibir_seguindo();
        void seguir(Usuario* usuario);
        void parar_seguir(Usuario* usuario);

        //MÉTODOS
        void tocar_musica_perfil();
        void exibir_musicas_curtidas(Usuario* usuario_visualizador);
        void exibir_artistas_curtidos(Usuario* usuario_visualizador);
        void exibir_playlist_curtidas(Usuario* usuario_visualizador);
        void exibir_playlists(Usuario* usuario_visualizador);
        void exibir_usuario(Usuario* usuario);
};

#endif