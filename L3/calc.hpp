#ifndef EECS_MANAGER_HPP
#define EECS_MANAGER_HPP

#include "scanner.hpp"
#include "grammar.hh"

namespace EECS
{
    class Manager
    {
        public:
            void parse(const char* filepath);
        private:
            EECS::Scanner * scanner = nullptr;
            EECS::Parser * parser = nullptr;
    };
}

#endif

