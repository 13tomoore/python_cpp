#include <pybind11/pybind11.h>
#include "clef.h"

char version[]="1.0";

Clef::Clef(){
}

Clef::~Clef(){
}

void Clef::initialize(std::string number){
    this->privateKey=number;
}

std::string getVersion() {
	return version;
}

std::string Clef::getPrivateKey(){
    return this->privateKey;
}

std::string Clef::getPublicKey(){
    return this->publicKey;
}

namespace py = pybind11;


PYBIND11_MODULE(clef,greetings)
{
  greetings.doc() = "greeting_object 1.0";
  greetings.def("getVersion", &getVersion, "a function returning the version");
  
    py::class_<Clef>(greetings, "Clef", py::dynamic_attr())
        .def(py::init())
        .def("initialize", &Clef::initialize)
        .def("getPrivateKey", &Clef::getPrivateKey)
        .def("getPublicKey", &Clef::getPublicKey);
}