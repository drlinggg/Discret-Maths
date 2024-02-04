#include <bits/stdc++.h>
#define fast std::cin.tie(0);std::ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll RBN = 1e9+7;
const ll RSN = -(1e9+7);
const double PI = 3.141592653589793;
//mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count()); ll gen(){return rnd()%100;}

struct Enigma {
    ull counter = 0;
    ull num_rotors;
    ull size_rotor = 26;
    ull* reflector;
    ull** rotors;

    void set_reflector(Enigma* enigma, ull *r) {
        for (int i = 0; i < enigma->size_rotor; ++i) {
            enigma->reflector[i] = r[i];
        }
    }

    void set_rotor(Enigma* enigma, int number, ull *rotor) {
        for (int i = 0; i < enigma->size_rotor; ++i) {
            enigma->rotors[number][i] = rotor[i];
        }
    }

    void e_free(Enigma* enigma) {
        for (int i = 0; i < enigma->num_rotors; ++i) {
            free(enigma->rotors[i]) ;
        }
        free(enigma->rotors);
        free(enigma->reflector);
        free(enigma);
    }
    int rotor_find(Enigma *enigma, int num, int code) {
        for (int i = 0; i < enigma->size_rotor; ++i) {
            if (enigma->rotors[num][i] == code) {
                return i;
            }
        }
    }

    void rotor_shift(Enigma *enigma, int num) {
        char temp = enigma->rotors[num][enigma->size_rotor-1];
        for (int i = enigma->size_rotor-1; i > 0; --i) {
            enigma->rotors[num][i] = enigma->rotors[num][i-1];
        }
        enigma->rotors[num][0] = temp;
    }

    int encrypt(Enigma* enigma, int code) {
        int new_code = code;
        for (int i = 0; i < enigma->num_rotors; ++i) {
            new_code = enigma->rotors[i][new_code];
        }
        new_code = enigma->reflector[new_code];
        for (int i = enigma->num_rotors-1; i >= 0; --i) {
            new_code = rotor_find(enigma, i, new_code);
        }
        enigma->counter+=1;
        enigma->rotor_shift(enigma,0);
        if (enigma->counter % 26 == 0) {
            rotor_shift(enigma,1);
        }
        if (enigma->counter % 676 == 0) {
            rotor_shift(enigma,2);
        }
        return new_code;
    }
};

Enigma* enigma_new(ull num_r) {
    Enigma* new_enigma = new Enigma;
    new_enigma->num_rotors = num_r;
    new_enigma->rotors = (ull**)malloc(sizeof(ull*)*num_r);
    for (int i = 0; i < num_r; ++i) {
        new_enigma->rotors[i] = (ull*)malloc(sizeof(ull)*new_enigma->size_rotor);
    }
    new_enigma->reflector = (ull*)malloc(sizeof(ull)*new_enigma->size_rotor);
    return new_enigma;
}

struct Encoder {
    int size_alph = 26;
    char* alph;

    void free(Encoder *encoder) {
        free(encoder);
    }

    int encode(Encoder* encoder, char ch) {
        for (int i = 0; i < encoder->size_alph; ++i) {
            if (encoder->alph[i] == ch) {
                return i;
            }
        }
    }

    int decode(Encoder *encoder, int code) {
        return encoder->alph[code];
    }

    void set_alphabet(Encoder *encoder, char *alphabet) {
        for (int i = 0; i < encoder->size_alph; ++i) {
            encoder->alph[i] = alphabet[i];
        }
    }
};

Encoder* encoder_new(int size) {
    Encoder* encoder = (Encoder*)malloc(sizeof(Encoder));
    encoder->size_alph = size;
    encoder->alph = (char*)malloc(sizeof(char)*size);
    return encoder;
}

signed main() {
    //fast;
    ull num_rotors = 3;
    ull reflector[26] = {25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    ull rotor[26] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
    ull rotor2[26] = {20, 21, 22, 23, 24, 25, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ull rotor3[26] = {7, 6, 5, 4, 3, 2, 1, 0, 24, 23, 22, 21, 20, 25, 8, 9, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10};
    ull *rotors[3] = {rotor, rotor2, rotor3};

    Enigma *enigma = enigma_new(num_rotors);
    enigma->set_reflector(enigma, reflector);
    for (int i = 0; i < num_rotors; ++i) {
        enigma->set_rotor(enigma, i, rotors[i]);
    }
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    Encoder* encoder = encoder_new(26);
    encoder->set_alphabet(encoder, alphabet);
    int enc_ch, dec_ch;
    char ch;
    while (cin >> ch) {
        if (ch == 1) {
            putchar('\n');
            break;
        }
        enc_ch = encoder->encode(encoder, ch);
        enc_ch = enigma->encrypt(enigma, enc_ch);
        dec_ch = encoder->decode(encoder, enc_ch);
        putchar(dec_ch);
    }
    enigma->e_free(enigma);
    encoder->free(encoder);
    return 0;
}
