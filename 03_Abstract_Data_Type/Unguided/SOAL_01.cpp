#include <iostream>

using namespace std;

/**
 * Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array
dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI
dengan rumus 0.3*uts+0.4*uas+0.3*tugas
 */

class Mahasiswa
{
private:
    string nama;
    string nim;
    double uts;
    double uas;
    double tugas;

public:
    void setNama(string nama)
    {
        this->nama = nama;
    }

    void setNim(string nim)
    {
        this->nim = nim;
    }

    void setUts(double uts)
    {
        this->uts = uts;
    }

    void setUas(double uas)
    {
        this->uas = uas;
    }

    void setTugas(double tugas)
    {
        this->tugas = tugas;
    }

    double getNilaiAkhir()
    {
        // output: The output should be 80 or 95.5 or 70.5
        return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
    }

    string getNama()
    {
        return nama;
    }

    string getNim()
    {
        return nim;
    }
};

void printAllMahasiswa(Mahasiswa mahasiswa[], int max_data)
{
    for (int i = 0; i < max_data; i++)
    {
        cout << "Nama: " << mahasiswa[i].getNama() << endl;
        cout << "NIM: " << mahasiswa[i].getNim() << endl;
        cout << "Nilai Akhir: " << mahasiswa[i].getNilaiAkhir() << endl;
    }
}

int main()
{

    int max_data;

    cout << "Masukkan jumlah data mahasiswa: ";
    cin >> max_data;

    if (max_data > 10)
    {
        cout << "Jumlah data mahasiswa tidak boleh lebih dari 10" << endl;
        return 0;
    }

    Mahasiswa mahasiswa[max_data];

    for (int i = 0; i < max_data; i++)
    {
        string nama, nim;
        double uts, uas, tugas;

        cout << "Masukkan nama mahasiswa: ";
        cin >> nama;
        mahasiswa[i].setNama(nama);

        cout << "Masukkan nim mahasiswa: ";
        cin >> nim;
        mahasiswa[i].setNim(nim);

        cout << "Masukkan nilai UTS mahasiswa: ";
        cin >> uts;
        mahasiswa[i].setUts(uts);

        cout << "Masukkan nilai UAS mahasiswa: ";
        cin >> uas;
        mahasiswa[i].setUas(uas);

        cout << "Masukkan nilai Tugas mahasiswa: ";
        cin >> tugas;
        mahasiswa[i].setTugas(tugas);

        cout << endl;
    }

    printAllMahasiswa(mahasiswa, max_data);

    return 0;
}