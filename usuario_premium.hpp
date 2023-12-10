#ifndef USUARIO_PREMIUM_HPP
#define USUARIO_PREMIUM_HPP

#include <string>
#include <vector>

#include "usuario.hpp"
#include "musica.hpp"
#include "playlist.hpp"

class Usuario_Premium : public Usuario {
    protected:
        static std::vector<Usuario_Premium*> premium_cadastrados;
    public:
            Usuario_Premium(std::string email, std::string nome);
            ~Usuario_Premium();

            virtual void tocar_playlist(Playlist *playlist);       // Verificar se realmente será void.
            virtual void definir_musica_perfil(Musica *musica);

            static Usuario_Premium* encontrar_usuario(std::string nome);
};

#endif