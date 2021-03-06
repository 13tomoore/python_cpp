#include <pybind11/pybind11.h>
#include "bouton.h"

char version[]="1.0";

Bouton::Bouton(std::string couleur){
    this->couleur = couleur;
}

Bouton::~Bouton(){
}

std::string getVersion() {
	return version;
}

std::string Bouton::getCouleur(){
    return this->couleur;
}

std::string Bouton::appuyer() {
  return "Pouet pouet pouet";
}

namespace py = pybind11;


PYBIND11_MODULE(bouton,greetings)
{
  greetings.doc() = "greeting_object 1.0";
  greetings.def("getVersion", &getVersion, "a function returning the version");
  
    py::class_<Bouton>(greetings, "Bouton", py::dynamic_attr())
        .def(py::init<std::string>())
        .def("getCouleur", &Bouton::getCouleur)
        .def("appuyer", &Bouton::appuyer);
}