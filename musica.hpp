#include <string>

class Musica{
    private:
        std::string _titulo;
        int _segundos;
        static int _views;
        bool _explicito;
        std::string _generos;
    public:
        Musica(std::string titulo, int segundos, bool explicito, std::string generos);

        void set_titulo(std::string titulo);

        std::string get_titulo();

        int get_segundos();

        void set_views();

        static int get_views();

        bool get_explicito();
};