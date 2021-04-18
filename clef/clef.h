class Clef
{
private:
	std::string privateKey;
    std::string publicKey;
public:
    Clef();
    ~Clef();
    void initialize(std::string number);
    std::string getPrivateKey();
    std::string getPublicKey();
};