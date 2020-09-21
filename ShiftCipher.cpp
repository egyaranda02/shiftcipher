/*
	Nama        : Ahmad Egy Aranda
	NPM         : 140810180043
    Kelas       : A
	Deskripsi   : Shift Cipher
*/
#include<iostream> //header untuk menampilkan main
#include<string.h>

using namespace std;

void enkripsi(){
    string plainteks, cipherteks;
    int i, k;
    char c;
    
    cout << "Input Pesan: ";
    cin.ignore(); getline (cin, plainteks);
    cout << "Masukan Kunci Pergeseran (K) : "; cin >> k;
    
    for (i=0; i < plainteks.length(); i++) 
    {
        c = plainteks[i];
        if (isalpha(c))
        {
            c = toupper(c);//dijadikan kapital
            c = c - 65; // Dikonvert dari ascii ke indeks alphabet [0-25]
            c = (c + k) % 26; //Rumus enkripsi
            c = c + 65; //Dikembalikan ke ascii alphabet
        }
        cipherteks = cipherteks + c;
    }
    cout << "Hasil Enkripsi : " << cipherteks <<endl; // cetak cipherteks
}

void dekripsi(){
    string plainteks, cipherteks;
    int i, k;
    char c;
    
    cout << "Ketikan cipherteks : ";
    cin.ignore(); getline (cin, cipherteks);
    cout << "Masukan Kunci Pergeseran (K) : "; cin >> k;
    
    for (i=0; i<cipherteks.length(); i++)
    {
        c = cipherteks[i];
        if (isalpha(c)) // hanya memproses alpabet
        {
            c = toupper(c); // ubah karakter ke huruf besar
            c = c - 65; // Konvert dari ascii ke indeks alphabet[0-25]
            if (c - k < 0) // Rumus untuk hasil negatif
                c = 26 + (c - k);
            else
                c = (c - k) % 26;
            c = c + 65; // Konvert dari indeks alphabet ke ascii

        }
        plainteks = plainteks + c;
    }
    cout << "Hasil Dekripsi : " << plainteks <<endl; // cetak plainteks
}

int main (){ 
    int pil;
    bool stop;
    stop = false;
    
    while (!stop) 
    {
        cout << "Menu : " <<endl;
        cout << "1. Enkripsi Pesan " <<endl;
        cout << "2. Dekripsi Pesan" <<endl;
        cout << "3. Exit " <<endl;
        cout << "Pilih menu : "; cin >> pil;
        switch(pil){
            case 1 : 
			enkripsi();
			break;
            case 2 : 
			dekripsi();
			break;
            case 3 : 
			stop = true;
			break;
        }
    }
}//end