#ifndef USUARIO_PREMIUM_HPP
#define USUARIO_PREMIUM_HPP

#include <string>
#include <vector>

#include "usuario.hpp"
#include "musica.hpp"
#include "playlist.hpp"

class Usuario_Premium : public Usuario {
    protected: //para que a classe filha artista tenha acesso
        //DADOS
        static std::vector<Usuario_Premium*> premium_cadastrados;
        Musica *_musica_perfil;
    public:
        //CONSTRUTOR E DESTRUTOR
        Usuario_Premium(std::string email, std::string nome);
        ~Usuario_Premium();

        //GETTER
        Musica* get_musica_perfil();

        //MÉTODOS
        virtual void definir_musica_perfil(Musica *musica);
        static Usuario_Premium* encontrar_usuario(std::string nome);
};

#endif