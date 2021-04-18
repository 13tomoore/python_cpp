#include <pybind11/pybind11.h>
#include "clef.h"
#include "uECC.h"

char version[]="1.0";

Clef::Clef(){
}

Clef::~Clef(){
}

void Clef::initialize(std::string number){
    this->privateKey = number;
    /// Le code qui suit fonctionne sous Windows mais je n'arrive pas à l'appeler en module Python
	const uint8_t* inputPrivateKey = reinterpret_cast<const uint8_t*>(this->privateKey.c_str());
	const int tailleClefPublique=uECC_curve_public_key_size(uECC_secp256k1());
	uint8_t *outputPublicKey = new uint8_t(tailleClefPublique);
	uECC_compute_public_key(inputPrivateKey, outputPublicKey, uECC_secp256k1());
	this->publicKey=std::string(outputPublicKey, outputPublicKey + tailleClefPublique);
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