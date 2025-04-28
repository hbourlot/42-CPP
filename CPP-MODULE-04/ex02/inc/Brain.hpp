#pragma once

#include <iostream>

class Brain {

    private:

        std::string _ideas[100];

    public:

        Brain();
        Brain(std::string idea);
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        ~Brain();


        std::string     getIdea(int idx) const;
        std::string*    getIdeas();
        void            setIdea(int idx, std::string idea);
        void            setIdeas(std::string idea);
};
