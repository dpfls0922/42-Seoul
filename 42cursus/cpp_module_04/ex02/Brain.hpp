#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(std::string idea);
        Brain(Brain const &obj);
        Brain &operator=(Brain const &obj);
        ~Brain();

        std::string getIdea(int index) const;
        void setIdea(int index, std::string str);
};

#endif