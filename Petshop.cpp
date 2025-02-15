#include <iostream>
using namespace std;

const int MAX_PRODUK = 100;

class PetShop
{
private:
    int id[MAX_PRODUK];
    string namaProduk[MAX_PRODUK];
    string kategoriProduk[MAX_PRODUK];
    int hargaProduk[MAX_PRODUK];
    int jumlahProduk;

public:
    PetShop()
    {
        jumlahProduk = 0;
    }

    ~PetShop()
    {
    }

    // Getter & Setter
    int getId(int index)
    {
        return id[index];
    }
    void setId(int index, int value)
    {
        id[index] = value;
    }

    string getNamaProduk(int index)
    {
        return namaProduk[index];
    }
    void setNamaProduk(int index, string value)
    {
        namaProduk[index] = value;
    }

    string getKategoriProduk(int index)
    {
        return kategoriProduk[index];
    }
    void setKategoriProduk(int index, string value)
    {
        kategoriProduk[index] = value;
    }

    int getHargaProduk(int index)
    {
        return hargaProduk[index];
    }
    void setHargaProduk(int index, int value)
    {
        hargaProduk[index] = value;
    }

    int getJumlahProduk()
    {
        return jumlahProduk;
    }

    // CRUD
    void tampilkanProduk()
    {
        if (jumlahProduk == 0)
        {
            cout << "Data kosong, tidak ada produk di PetShop!\n";
            return;
        }

        cout << "\nDaftar Produk PetShop:\n";
        for (int i = 0; i < jumlahProduk; i++)
        {
            cout << "ID: " << id[i]
                 << ", Nama: " << namaProduk[i]
                 << ", Kategori: " << kategoriProduk[i]
                 << ", Harga: " << hargaProduk[i] << endl;
        }
    }

    void tambahProduk()
    {
        if (jumlahProduk >= MAX_PRODUK)
        {
            cout << "PetShop sudah penuh, tidak bisa menambah produk lagi!\n";
            return;
        }

        int tempId, tempHarga;
        string tempNama, tempKategori;

        cout << "Masukkan ID: ";
        cin >> tempId;
        cin.ignore();

        // Cek apakah ID sudah ada
        for (int i = 0; i < jumlahProduk; i++)
        {
            if (getId(i) == tempId)
            {
                cout << "Produk dengan ID " << tempId << " sudah ada! Gagal menambahkan produk.\n";
                return;
            }
        }

        cout << "Masukkan Nama Produk: ";
        getline(cin, tempNama);

        cout << "Masukkan Kategori Produk: ";
        getline(cin, tempKategori);

        cout << "Masukkan Harga Produk: ";
        cin >> tempHarga;

        setId(jumlahProduk, tempId);
        setNamaProduk(jumlahProduk, tempNama);
        setKategoriProduk(jumlahProduk, tempKategori);
        setHargaProduk(jumlahProduk, tempHarga);

        jumlahProduk++;
        cout << "Produk berhasil ditambahkan!\n";
    }

    void editProduk()
    {
        if (jumlahProduk == 0)
        {
            cout << "Tidak ada produk untuk diedit!\n";
            return;
        }

        string nama;
        cin.ignore();
        cout << "Masukkan nama produk yang ingin diedit: ";
        getline(cin, nama);

        for (int i = 0; i < jumlahProduk; i++)
        {
            if (getNamaProduk(i) == nama)
            {
                int tempId, tempHarga;
                string tempNama, tempKategori;

                cout << "Masukkan ID baru: ";
                cin >> tempId;
                cin.ignore();

                cout << "Masukkan Nama Produk baru: ";
                getline(cin, tempNama);

                cout << "Masukkan Kategori Produk baru: ";
                getline(cin, tempKategori);

                cout << "Masukkan Harga Produk baru: ";
                cin >> tempHarga;

                setId(i, tempId);
                setNamaProduk(i, tempNama);
                setKategoriProduk(i, tempKategori);
                setHargaProduk(i, tempHarga);

                cout << "Produk berhasil diperbarui!\n";
                return;
            }
        }
        cout << "Produk tidak ditemukan!\n";
    }

    void hapusProduk()
    {
        if (jumlahProduk == 0)
        {
            cout << "Tidak ada produk untuk dihapus!\n";
            return;
        }

        string nama;
        cin.ignore();
        cout << "Masukkan nama produk yang ingin dihapus: ";
        getline(cin, nama);

        for (int i = 0; i < jumlahProduk; i++)
        {
            if (getNamaProduk(i) == nama)
            {
                for (int j = i; j < jumlahProduk - 1; j++)
                {
                    setId(j, getId(j + 1));
                    setNamaProduk(j, getNamaProduk(j + 1));
                    setKategoriProduk(j, getKategoriProduk(j + 1));
                    setHargaProduk(j, getHargaProduk(j + 1));
                }
                jumlahProduk--;
                cout << "Produk berhasil dihapus!\n";
                return;
            }
        }
        cout << "Produk tidak ditemukan!\n";
    }

    void cariProduk()
    {
        if (jumlahProduk == 0)
        {
            cout << "Tidak ada produk untuk dicari!\n";
            return;
        }

        string nama;
        cin.ignore();
        cout << "Masukkan nama produk yang dicari: ";
        getline(cin, nama);

        for (int i = 0; i < jumlahProduk; i++)
        {
            if (getNamaProduk(i) == nama)
            {
                cout << "Produk ditemukan!\n"
                     << "ID: " << getId(i)
                     << ", Kategori: " << getKategoriProduk(i)
                     << ", Harga: " << getHargaProduk(i) << endl;
                return;
            }
        }
        cout << "Produk tidak ditemukan!\n";
    }
};
