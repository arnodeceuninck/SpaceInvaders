//
// Created by arno on 15/01/2020.
//

#include "SiExcecption.h"

#include <utility>

const char* spaceinvaders::exception::SiException::what() const noexcept { return problem.c_str(); }

spaceinvaders::exception::SiException::SiException(std::string problem) : problem(std::move(problem)) {}
