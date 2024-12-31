#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

using namespace std;

int main()
{
    srand(time(0));

    const int MAX_BUILDINGS = 3; // tau lah ini apa, klo di ganti, juga di ganti array nya buat buildingX dan Y
    int buildingX[MAX_BUILDINGS] = {-1, -1, -1}; // biar building nya spawn di luar screen
    int buildingY[MAX_BUILDINGS] = {6, 6, 6}; //buat pastiin building nya spawn di array ke 6 (ground level)
    bool active[MAX_BUILDINGS] = {false, false, false}; // buat cari tau klo ada atau gk di screen sudah ada brp building yang nyala

    int x = 5, y = 6;
    char key;
    string maps[10][50] = { // map (no shit)
        {"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"},
        {"#"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","#"},
        {"#"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","#"},
        {"#"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","#"},
        {"#"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","#"},
        {"#"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","#"},
        {"#"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","#"},
        {"#","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","#"},
        {"#"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","#"},
        {"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"},
    };

    int spawnTimer = 0;
    while (true) {
        system("cls");

        for (int i = 0; i < MAX_BUILDINGS; i++) {
            if (active[i] && x == buildingX[i] && y == buildingY[i]) { // logic nya jika building yang aktif posisinya == x dan y player, artinya terjadi kolisi lalu mati
                cout << "Game Over!" << endl;
                return 0;
            }
        }

        if (spawnTimer == 0) {
            for (int i = 0; i < MAX_BUILDINGS; i++) {
                if (!active[i]) {
                    buildingX[i] = 49;// biar spawn nya di ujung kanan screen
                    active[i] = true; // merubah building nya dari false jadi true
                    break;
                }
            }
            spawnTimer = rand() % 10 + 5; // ini lebih kyk buat yang memberi jarak biar building nya tidak terlalu dekat
        }                                 // jadi building nya spawn diantara 5 - 15 frame setelah building sebelumnya
        spawnTimer--; // misal spawntimer randomizer nya 7 frame, spawntimer-- gunanya adalah tiap frame akan dikurang 1 value spawn timernya
                      // dan selama spawntimer!=0, game akan selalu melewati line 46
                      // saat sudah 7 frame lewat, maka value nya jadi 0, kalau gitu line 46 bisa di jalankan lagi

        for (int i = 0; i < MAX_BUILDINGS; i++) {
            if (active[i]) {
                buildingX[i]--; // gerakin building nya ke kanan tiap frame
                if (buildingX[i] < 0) {
                    active[i] = false; // kalau building sudah off screen, maka di anggap offline
                }
            }
        }
        // yg di bawah ini adalah kode buat gambar map nya
        for (int i = 0; i < 10; i++) { //untuk bagian ini agak bingungin, tapi tak jelasin ae
            for (int j = 0; j < 50; j++) { // jadi 2 for loop ini itu buat nge scan semua map nya
                bool isBuilding = false; // kali di tile (i,j) tidak ada building, maka isbuilding=false
                for (int b = 0; b < MAX_BUILDINGS; b++) {
                    if (active[b] && i == buildingY[b] && j == buildingX[b]) {
                        cout << "# "; // kalau ada building maka akan di gambar sebuah building
                        isBuilding = true; // isbuilding di set true
                        break; // stop loop nya karena kita sudah nemu building nya
                    }
                    // <IMPORTANT> perbedaan isBuilding sama active itu, active nge cek klo building active di game itu, di mana isBuilding nge cek klo building aktif di posisi itu
                    //             jadi kurang lebih isBuilding itu lebih kayak temp
                }
                if (isBuilding) continue;

                if (i == y && j == x) {
                    cout << "@ "; //jika scanner menemukan x dan y player, maka player akan di gambar
                } else {
                    cout << maps[i][j] << " "; // kalau tidak ada building atau player, maka di gambar background
                }
            }
            cout << endl;
        }

        Sleep(100);

        if (kbhit()) {
            key = getch();
            if (key == 'w' || key == 24) { // renderin for making the player go up
                for (int h = 0; h < 2; h++) {
                    system("cls");
                    for (int i = 0; i < MAX_BUILDINGS; i++) {
                        if (active[i]) buildingX[i]--;
                    }

                    y--; //buat player lompat
                    for (int i = 0; i < 10; i++) {
                        for (int j = 0; j < 50; j++) {
                            bool isBuilding = false;
                            for (int b = 0; b < MAX_BUILDINGS; b++) {
                                if (active[b] && i == buildingY[b] && j == buildingX[b]) {
                                    cout << "# ";
                                    isBuilding = true;
                                    break;
                                }
                            }
                            if (isBuilding) continue;

                            if (i == y && j == x) {
                                cout << "@ ";
                            } else {
                                cout << maps[i][j] << " ";
                            }
                        }
                        cout << endl;
                    }
                    Sleep(100);
                }
                // <IMPORTANT><IMPORTANT><IMPORTANT><IMPORTANT><IMPORTANT><IMPORTANT><IMPORTANT><IMPORTANT>
                // klo km blm notice kita ada 3 kyk ginian di code nya, yang pertama funsinya untuk render map sebelum input
                // yang kedua untuk render map setelah press w dan player ke ata, yang ketiga untuk render map saat player nya ke bawah
                // klo kita cm ada satu tok, nanti player nya antara gk bisa gerak, atau code nya rusak
                // bisa seh pake satu tapi perlu pake function
                // THIS IS WHAT WE MUST GO THROUGH IF WE DON'T USE FUNTION BEN, LIFE COULD HAVE BEEN A LOT SIMPLER

                for (int h = 0; h < 2; h++) {
                    system("cls");
                    for (int i = 0; i < MAX_BUILDINGS; i++) {
                        if (active[i]) buildingX[i]--; // rendering for makking the player go down
                    }

                    y++;
                    for (int i = 0; i < 10; i++) {
                        for (int j = 0; j < 50; j++) {
                            bool isBuilding = false;
                            for (int b = 0; b < MAX_BUILDINGS; b++) {
                                if (active[b] && i == buildingY[b] && j == buildingX[b]) {
                                    cout << "# ";
                                    isBuilding = true;
                                    break;
                                }
                            }
                            if (isBuilding) continue;

                            if (i == y && j == x) {
                                cout << "@ ";
                            } else {
                                cout << maps[i][j] << " ";
                            }
                        }
                        cout << endl;
                    }
                    Sleep(100);
                }
            }
        }
    }

    return 0;
}
