#ifndef PERFIL_HPP_
#define PERFIL_HPP_
#include <vector>
#include "usuario.hpp"

class Perfil {
    private:
        Usuario* _usuario;
        std::vector<Usuario*> _seguidores;
        std::vector<Usuario*> _seguindo;
    public:
        Perfil(Usuario* usuario);
        ~Perfil();

        Usuario* get_usuario();
        int get_quant_seguidores();
        int get_quant_seguindo();

        void exibir_seguidores();
        void exibir_seguindo();
        void seguir(Usuario* usuario);
        void parar_seguir(Usuario* usuario);

        void tocar_musica_perfil();
        void exibir_musicas_curtidas();
        void exibir_artistas_curtidos();
        void exibir_playlist_curtidas();
        void exibir_playlists();
        void exibir_usuario();
};

#endif