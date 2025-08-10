#pragma once

class Vao {
    public:
        Vao(const char* buffer);
        ~Vao();
        const int getID() const {return ID; };

    private:
        unsigned int ID;

};
