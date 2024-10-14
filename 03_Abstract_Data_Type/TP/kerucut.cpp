#include "iostream"

using namespace std;

class Kerucut
{
private:
    float jari_jari;
    float tinggi;

public:
    Kerucut(float jari_jari, float tinggi)
    {
        this->jari_jari = jari_jari;
        this->tinggi = tinggi;
    }

    float volume()
    {
        return 3.14 * jari_jari * jari_jari * tinggi / 3;
    }
};

int main()
{
    Kerucut kerucut(5, 10);
    cout << "Volume kerucut adalah: " << kerucut.volume() << endl;
    return 0;
}
