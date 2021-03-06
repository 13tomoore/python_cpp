class Bouton
{
private:
	std::string couleur;
public:
    Bouton(std::string couleur);
    ~Bouton();
    std::string getCouleur();
    std::string appuyer();
};