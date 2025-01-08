#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

void checkcol(int seedb[3],bool active[3],int x,int y,int buildingX[3], int buildingY[3],int &menu1,int twerk){
    if(twerk==1){
        for (int i = 0; i < 3; i++) {
            if(active[i]){
                if(seedb[i]==0){
                    if (x == buildingX[i] && y == buildingY[i]) { // logic nya jika building yang aktif posisinya == x dan y player, artinya terjadi kolisi lalu mati
                        menu1=5;
                    }
                }
                else if(seedb[i]==1){
                    if ((y == buildingY[i] && x==buildingX[i]) || (y == buildingY[i]-1 && x==buildingX[i])) {
                        menu1=5;
                    }
                    if((y == buildingY[i] && x==buildingX[i]+1) || (y == buildingY[i] && x == buildingX[i])){
                        menu1=5;
                    }
                }
                else if(seedb[i]==2){
                    if((x == buildingX[i] && y == buildingY[i]-1) || (x==buildingX[i] && y==buildingY[i])) {
                        menu1=5;
                    }
                    if((y == buildingY[i] && x==buildingX[i]-1) || (y == buildingY[i] && x==buildingX[i])){
                        menu1=5;
                    }
                }
                else if(seedb[i]==3){
                    if ((y == buildingY[i] || y == buildingY[i]-1) && (x == buildingX[i] || x==buildingX[i]-1) ) {
                        menu1=5;
                    }
                }
                else if(seedb[i]==4){
                    if((x == buildingX[i] && y == buildingY[i]-1) && (x==buildingX[i] && y==buildingY[i])){
                        menu1=5;
                    }
                    if((x == buildingX[i]+1 && y == buildingY[i])||(x == buildingX[i]-1 && y == buildingY[i])||(x == buildingX[i] && y == buildingY[i])){
                        menu1=5;
                    }
                }
                else if(seedb[i]==5){
                    if(x==buildingX[i] && y==buildingY[i]-1){
                        menu1=5;
                    }
                }
                else if(seedb[i]==6){
                    if(x==buildingX[i] && y==buildingY[i]-2){
                        menu1=5;
                    }
                }
            }
        }
    }
    else if(twerk==0){
        for (int i = 0; i < 3; i++) {
            if(active[i]){
                if(seedb[i]==0){
                    if ((x == buildingX[i] && y == buildingY[i])||(x == buildingX[i] && y == buildingY[i])) { // logic nya jika building yang aktif posisinya == x dan y player, artinya terjadi kolisi lalu mati
                        menu1=5;
                    }
                }
                else if(seedb[i]==1){
                    if (((y == buildingY[i] && x==buildingX[i]) || (y == buildingY[i]-1 && x==buildingX[i])) || ((y-1 == buildingY[i] && x==buildingX[i]) || (y-1 == buildingY[i]-1 && x==buildingX[i]))) {
                        menu1=5;
                    }
                    if(((y == buildingY[i] && x==buildingX[i]+1) || (y == buildingY[i] && x == buildingX[i])) || ((y-1 == buildingY[i] && x==buildingX[i]+1) || (y-1 == buildingY[i] && x == buildingX[i]))){
                        menu1=5;
                    }
                }
                else if(seedb[i]==2){
                    if(((x == buildingX[i] && y == buildingY[i]-1) || (x==buildingX[i] && y==buildingY[i])) || ((x == buildingX[i] && y-1 == buildingY[i]-1) || (x==buildingX[i] && y-1==buildingY[i]))) {
                        menu1=5;
                    }
                    if(((y == buildingY[i] && x==buildingX[i]-1) || (y == buildingY[i] && x==buildingX[i])) || ((y-1 == buildingY[i] && x==buildingX[i]-1) || (y-1 == buildingY[i] && x==buildingX[i]))){
                        menu1=5;
                    }
                }
                else if(seedb[i]==3){
                    if (((y == buildingY[i] || y == buildingY[i]-1) && (x == buildingX[i] || x==buildingX[i]-1)) || ((y-1 == buildingY[i] || y-1 == buildingY[i]-1) && (x == buildingX[i] || x==buildingX[i]-1))) {
                        menu1=5;
                    }
                }
                else if(seedb[i]==4){
                    if(((x == buildingX[i] && y == buildingY[i]-1) && (x==buildingX[i] && y==buildingY[i])) || ((x == buildingX[i] && y-1 == buildingY[i]-1) && (x==buildingX[i] && y-1==buildingY[i]))){
                        menu1=5;
                    }
                    if(((x == buildingX[i]+1 && y == buildingY[i])||(x == buildingX[i]-1 && y == buildingY[i])||(x == buildingX[i] && y == buildingY[i])) || ((x == buildingX[i]+1 && y-1 == buildingY[i])||(x == buildingX[i]-1 && y-1 == buildingY[i])||(x == buildingX[i] && y-1 == buildingY[i]))){
                        menu1=5;
                    }
                }
                else if(seedb[i]==5){
                    if((x==buildingX[i] && y==buildingY[i]-1) || (x==buildingX[i] && y-1==buildingY[i]-1)){
                        menu1=5;
                    }
                }
                else if(seedb[i]==6){
                    if((x==buildingX[i] && y==buildingY[i]-2) || (x==buildingX[i] && y-1==buildingY[i]-2)){
                        menu1=5;
                    }
                }
            }
        }
    }
}

int main()
{
    srand(time(0));
    fstream inf,outf;
    const int MAX_BUILDINGS = 3; // tau lah ini apa, klo di ganti, juga di ganti array nya buat buildingX dan Y
    int buildingX[MAX_BUILDINGS] = {-1, -1, -1}; // biar building nya spawn di luar screen
    int buildingY[MAX_BUILDINGS] = {6, 6, 6}; //buat pastiin building nya spawn di array ke 6 (ground level)
    bool active[MAX_BUILDINGS] = {false, false, false}; // buat cari tau klo ada atau gk di screen sudah ada brp building yang nyala
    int seedb[MAX_BUILDINGS]={0,0,0};
    vector <string> hsname;
    vector <string> hsscore;
    vector <int> intscore;
    string name, tempscore,tempname,lines;
    int x = 5, y = 6,score=0,menu1,tempscore2,menu2,mul=0,twerk=0;
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
        hsname.clear();
        hsscore.clear();
        intscore.clear();
    while(true){
        for(int i=0;i<3;i++){
            buildingX[i] = -1; // biar building nya spawn di luar screen
            buildingY[i] = 6; //buat pastiin building nya spawn di array ke 6 (ground level)
            active[i] = false; // buat cari tau klo ada atau gk di screen sudah ada brp building yang nyala
            seedb[i]=0;
        }
        system("cls");
        score=0;
        mul=0;
        hsname.clear();
        hsscore.clear();
        intscore.clear();
        inf.open("hsname.txt",ios::in);
        while(getline(inf,lines)){
            hsname.push_back(lines);
        }
        inf.close();
        inf.open("hsscore.txt",ios::in);
        while(getline(inf,lines)){
            hsscore.push_back(lines);
        }
        inf.close();
        for(int i=0;i<hsscore.size();i++){
            tempscore=hsscore[i];
            stringstream(tempscore)>>tempscore2;
            intscore.push_back(tempscore2);
        }
        cout<<"Welcome to Ruwarono"<<endl<<"1. Play"<<endl<<"2. Highscores"<<endl<<"0. Embrace Cowardice?"<<endl;
        do{
            cout<<">>";
            cin>>menu1;
        }while(menu1>2||menu1<0);
        int spawnTimer = 0;
        while (menu1==1) {
            y=6;
            system("cls");
            for(int i=0;i<MAX_BUILDINGS;i++){
                if(!active[i]){
                    seedb[i]=rand()%7;
                }
            }
            checkcol(seedb,active,x,y,buildingX,buildingY,menu1,twerk);
            if(menu1==5){
                cout << "Game Over!" << endl<<"Enter your name: ";
                cin>>name;
                hsname.push_back(name);
                intscore.push_back(score);
                stringstream ss;
                ss<<score;
                tempname=ss.str();
                hsscore.push_back(tempname);
                for(int i=0;i<intscore.size();i++){
                    for(int j=0;j<intscore.size();j++){
                        if(intscore[i]>intscore[j]){
                            tempscore2=intscore[i];
                            tempscore=hsscore[i];
                            tempname=hsname[i];
                            intscore[i]=intscore[j];
                            hsscore[i]=hsscore[j];
                            hsname[i]=hsname[j];
                            intscore[j]=tempscore2;
                            hsscore[j]=tempscore;
                            hsname[j]=tempname;
                        }
                    }
                }
                if(intscore.size()>5){
                    intscore.erase(intscore.begin()+5);
                    hsscore.erase(hsscore.begin()+5);
                    hsname.erase(hsname.begin()+5);
                }
                outf.open("hsname.txt",ios::out);
                for(int i=0;i<hsname.size();i++){
                    outf<<hsname[i]<<endl;
                }
                outf.close();
                outf.open("hsscore.txt",ios::out);
                for(int i=0;i<intscore.size();i++){
                    outf<<intscore[i]<<endl;
                }
                outf.close();
                menu1=7;
                break;
            }
            if (spawnTimer == 0) {
                for (int i = 0; i < MAX_BUILDINGS; i++) {
                    if (!active[i]) {
                        buildingX[i] = 49;// biar spawn nya di ujung kanan screen
                        active[i] = true; // merubah building nya dari false jadi true
                        break;
                    }
                }
                spawnTimer = rand() % 10 + 7; // ini lebih kyk buat yang memberi jarak biar building nya tidak terlalu dekat
            }
                        // jadi building nya spawn diantara 5 - 15 frame setelah building sebelumnya
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
            score+=10;
            if(mul<10){
                mul=score/250;
            }
            cout<<"Score: "<<score<<endl;
            for (int i = 0; i < 10; i++) { //untuk bagian ini agak bingungin, tapi tak jelasin ae
                for (int j = 0; j < 50; j++) { // jadi 2 for loop ini itu buat nge scan semua map nya
                    bool isBuilding = false; // kali di tile (i,j) tidak ada building, maka isbuilding=false
                    for (int b = 0; b < MAX_BUILDINGS; b++) {
                        if(seedb[b]==0){
                            if (active[b] && i == buildingY[b] && j == buildingX[b]) {
                                cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                isBuilding = true; // isbuilding di set true
                                break; // stop loop nya karena kita sudah nemu building nya
                            }
                        }
                        else if(seedb[b]==1){
                            if (active[b] && (i == buildingY[b] || i == buildingY[b]-1) && j==buildingX[b] ) {
                                cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                isBuilding = true; // isbuilding di set true
                                break; // stop loop nya karena kita sudah nemu building nya
                            }
                            if(active[b] && (j == buildingX[b] || j==buildingX[b]+1) && i == buildingY[b]){
                                cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                isBuilding = true; // isbuilding di set true
                                break; // stop loop nya karena kita sudah nemu building nya
                            }
                        }
                        else if(seedb[b]==2){
                            if (active[b] && (i == buildingY[b] || i == buildingY[b]-1) && j==buildingX[b] ) {
                                cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                isBuilding = true; // isbuilding di set true
                                break; // stop loop nya karena kita sudah nemu building nya
                            }
                            if(active[b] && (j == buildingX[b] || j==buildingX[b]-1) && i == buildingY[b]){
                                cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                isBuilding = true; // isbuilding di set true
                                break; // stop loop nya karena kita sudah nemu building nya
                            }
                        }
                        else if(seedb[b]==3){
                            if (active[b] && (i == buildingY[b] || i == buildingY[b]-1) && (j == buildingX[b] || j==buildingX[b]-1) ) {
                                cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                isBuilding = true; // isbuilding di set true
                                break; // stop loop nya karena kita sudah nemu building nya
                            }
                        }
                        else if(seedb[b]==4){
                            if(active[b]&&(i == buildingY[b] || i == buildingY[b]-1) && j==buildingX[b]){
                                cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                isBuilding = true; // isbuilding di set true
                                break; // stop loop nya karena kita sudah nemu building nya
                            }
                            if(active[b] && (j == buildingX[b] || j==buildingX[b]+1 || j==buildingX[b]-1) && i == buildingY[b]){
                                cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                isBuilding = true; // isbuilding di set true
                                break; // stop loop nya karena kita sudah nemu building nya
                            }
                        }
                        else if(seedb[b]==5){
                            if(active[b]&& i==buildingY[b]-1 && j==buildingX[b]){
                                cout<<"W ";
                                isBuilding=true;
                                break;
                            }
                        }
                        else if(seedb[b]==6){
                            if(active[b]&& i==buildingY[b]-2 && j==buildingX[b]){
                                cout<<"W ";
                                isBuilding=true;
                                break;
                            }
                        }
                        // <IMPORTANT> perbedaan isBuilding sama active itu, active nge cek klo building active di game itu, di mana isBuilding nge cek klo building aktif di posisi itu
                        //             jadi kurang lebih isBuilding itu lebih kayak temp
                    }
                    if (isBuilding) continue;

                    if (i == y && j == x && twerk==1) {
                        cout<<"d ";
                    }
                    else if((i==y-1|| i==y)&& j==x && twerk==0){
                        cout<<"D ";
                    }
                    else {
                        cout << maps[i][j] << " ";
                    }
                }
                cout << endl;
            }
            if(twerk==0){
                cout<<"Press w to jump 2 blocks"<<endl<<"Press shift+w to jump 3 blocks"<<endl<<"Press s to toggle crouch";
            }
            else if(twerk==1){
                cout<<"Press s to untoggle crouch";
            }
            Sleep(100-5*mul);

            if (kbhit()) {
                key = getch();
                if (key == 'w' && twerk==0) { // renderin for making the player go up
                    for (int h = 0; h < 2; h++) {
                        system("cls");
                        for (int i = 0; i < MAX_BUILDINGS; i++) {
                            if (active[i]) buildingX[i]--;
                        }

                        y--; //buat player lompat
                        score+=10;
                        if(mul<10){
                            mul=score/250;
                        }
                        checkcol(seedb,active,x,y,buildingX,buildingY,menu1,twerk);
                        if(menu1==5){
                            cout << "Game Over!" << endl<<"Enter your name: ";
                            cin>>name;
                            hsname.push_back(name);
                            intscore.push_back(score);
                            stringstream ss;
                            ss<<score;
                            tempname=ss.str();
                            hsscore.push_back(tempname);
                            for(int i=0;i<intscore.size();i++){
                                for(int j=0;j<intscore.size();j++){
                                    if(intscore[i]>intscore[j]){
                                        tempscore2=intscore[i];
                                        tempscore=hsscore[i];
                                        tempname=hsname[i];
                                        intscore[i]=intscore[j];
                                        hsscore[i]=hsscore[j];
                                        hsname[i]=hsname[j];
                                        intscore[j]=tempscore2;
                                        hsscore[j]=tempscore;
                                        hsname[j]=tempname;
                                    }
                                }
                            }
                            if(intscore.size()>5){
                                intscore.erase(intscore.begin()+5);
                                hsscore.erase(hsscore.begin()+5);
                                hsname.erase(hsname.begin()+5);
                            }
                            outf.open("hsname.txt",ios::out);
                            for(int i=0;i<hsname.size();i++){
                                outf<<hsname[i]<<endl;
                            }
                            outf.close();
                            outf.open("hsscore.txt",ios::out);
                            for(int i=0;i<intscore.size();i++){
                                outf<<intscore[i]<<endl;
                            }
                            outf.close();
                            menu1=7;
                            break;
                        }
                        cout<<"Score: "<<score<<endl;
                        for (int i = 0; i < 10; i++) {
                            for (int j = 0; j < 50; j++) {
                                bool isBuilding = false;
                                for (int b = 0; b < MAX_BUILDINGS; b++) {
                                    if(seedb[b]==0){
                                        if (active[b] && i == buildingY[b] && j == buildingX[b]) {
                                            cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                            isBuilding = true; // isbuilding di set true
                                            break; // stop loop nya karena kita sudah nemu building nya
                                        }
                                    }
                                    else if(seedb[b]==1){
                                        if (active[b] && (i == buildingY[b] || i == buildingY[b]-1) && j==buildingX[b] ) {
                                            cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                            isBuilding = true; // isbuilding di set true
                                            break; // stop loop nya karena kita sudah nemu building nya
                                        }
                                        if(active[b] && (j == buildingX[b] || j==buildingX[b]+1) && i == buildingY[b]){
                                            cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                            isBuilding = true; // isbuilding di set true
                                            break; // stop loop nya karena kita sudah nemu building nya
                                        }
                                    }
                                    else if(seedb[b]==2){
                                        if (active[b] && (i == buildingY[b] || i == buildingY[b]-1) && j==buildingX[b] ) {
                                            cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                            isBuilding = true; // isbuilding di set true
                                            break; // stop loop nya karena kita sudah nemu building nya
                                        }
                                        if(active[b] && (j == buildingX[b] || j==buildingX[b]-1) && i == buildingY[b]){
                                            cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                            isBuilding = true; // isbuilding di set true
                                            break; // stop loop nya karena kita sudah nemu building nya
                                        }
                                    }
                                    else if(seedb[b]==3){
                                        if (active[b] && (i == buildingY[b] || i == buildingY[b]-1) && (j == buildingX[b] || j==buildingX[b]-1) ) {
                                            cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                            isBuilding = true; // isbuilding di set true
                                            break; // stop loop nya karena kita sudah nemu building nya
                                        }
                                    }
                                    else if(seedb[b]==4){
                                        if(active[b]&&(i == buildingY[b] || i == buildingY[b]-1) && j==buildingX[b]){
                                            cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                            isBuilding = true; // isbuilding di set true
                                            break; // stop loop nya karena kita sudah nemu building nya
                                        }
                                        if(active[b] && (j == buildingX[b] || j==buildingX[b]+1 || j==buildingX[b]-1) && i == buildingY[b]){
                                            cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                            isBuilding = true; // isbuilding di set true
                                            break; // stop loop nya karena kita sudah nemu building nya
                                        }
                                    }
                                    else if(seedb[b]==5){
                                        if(active[b]&& i==buildingY[b]-1 && j==buildingX[b]){
                                            cout<<"W ";
                                            isBuilding=true;
                                            break;
                                        }
                                    }
                                    else if(seedb[b]==6){
                                        if(active[b]&& i==buildingY[b]-2 && j==buildingX[b]){
                                            cout<<"W ";
                                            isBuilding=true;
                                            break;
                                        }
                                    }
                                }
                                if (isBuilding) continue;

                                if (i == y && j == x && twerk==1) {
                                    cout<<"d ";
                                }
                                else if((i==y-1|| i==y)&& j==x && twerk==0){
                                    cout<<"D ";
                                }
                                else {
                                    cout << maps[i][j] << " ";
                                }
                            }
                            cout<<endl;
                        }
                        if(twerk==0){
                            cout<<"Press w to jump 2 blocks"<<endl<<"Press shift+w to jump 3 blocks"<<endl<<"Press s to toggle crouch";
                        }
                        else if(twerk==1){
                            cout<<"Press s to untoggle crouch";
                        }
                        Sleep(100-5*mul);
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
                        score+=10;
                        if(mul<10){
                            mul=score/250;
                        }
                        checkcol(seedb,active,x,y,buildingX,buildingY,menu1,twerk);
                        if(menu1==5){
                            cout << "Game Over!" << endl<<"Enter your name: ";
                            cin>>name;
                            hsname.push_back(name);
                            intscore.push_back(score);
                            stringstream ss;
                            ss<<score;
                            tempname=ss.str();
                            hsscore.push_back(tempname);
                            for(int i=0;i<intscore.size();i++){
                                for(int j=0;j<intscore.size();j++){
                                    if(intscore[i]>intscore[j]){
                                        tempscore2=intscore[i];
                                        tempscore=hsscore[i];
                                        tempname=hsname[i];
                                        intscore[i]=intscore[j];
                                        hsscore[i]=hsscore[j];
                                        hsname[i]=hsname[j];
                                        intscore[j]=tempscore2;
                                        hsscore[j]=tempscore;
                                        hsname[j]=tempname;
                                    }
                                }
                            }
                            if(intscore.size()>5){
                                intscore.erase(intscore.begin()+5);
                                hsscore.erase(hsscore.begin()+5);
                                hsname.erase(hsname.begin()+5);
                            }
                            outf.open("hsname.txt",ios::out);
                            for(int i=0;i<hsname.size();i++){
                                outf<<hsname[i]<<endl;
                            }
                            outf.close();
                            outf.open("hsscore.txt",ios::out);
                            for(int i=0;i<intscore.size();i++){
                                outf<<intscore[i]<<endl;
                            }
                            outf.close();
                            menu1=7;
                            break;
                        }
                        cout<<"Score: "<<score<<endl;
                        for (int i = 0; i < 10; i++) {
                            for (int j = 0; j < 50; j++) {
                                bool isBuilding = false;
                                for (int b = 0; b < MAX_BUILDINGS; b++) {
                                    if(seedb[b]==0){
                                        if (active[b] && i == buildingY[b] && j == buildingX[b]) {
                                            cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                            isBuilding = true; // isbuilding di set true
                                            break; // stop loop nya karena kita sudah nemu building nya
                                        }
                                    }
                                    else if(seedb[b]==1){
                                        if (active[b] && (i == buildingY[b] || i == buildingY[b]-1) && j==buildingX[b] ) {
                                            cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                            isBuilding = true; // isbuilding di set true
                                            break; // stop loop nya karena kita sudah nemu building nya
                                        }
                                        if(active[b] && (j == buildingX[b] || j==buildingX[b]+1) && i == buildingY[b]){
                                            cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                            isBuilding = true; // isbuilding di set true
                                            break; // stop loop nya karena kita sudah nemu building nya
                                        }
                                    }
                                    else if(seedb[b]==2){
                                        if (active[b] && (i == buildingY[b] || i == buildingY[b]-1) && j==buildingX[b] ) {
                                            cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                            isBuilding = true; // isbuilding di set true
                                            break; // stop loop nya karena kita sudah nemu building nya
                                        }
                                        if(active[b] && (j == buildingX[b] || j==buildingX[b]-1) && i == buildingY[b]){
                                            cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                            isBuilding = true; // isbuilding di set true
                                            break; // stop loop nya karena kita sudah nemu building nya
                                        }
                                    }
                                    else if(seedb[b]==3){
                                        if (active[b] && (i == buildingY[b] || i == buildingY[b]-1) && (j == buildingX[b] || j==buildingX[b]-1) ) {
                                            cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                            isBuilding = true; // isbuilding di set true
                                            break; // stop loop nya karena kita sudah nemu building nya
                                        }
                                    }
                                    else if(seedb[b]==4){
                                        if(active[b]&&(i == buildingY[b] || i == buildingY[b]-1) && j==buildingX[b]){
                                            cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                            isBuilding = true; // isbuilding di set true
                                            break; // stop loop nya karena kita sudah nemu building nya
                                        }
                                        if(active[b] && (j == buildingX[b] || j==buildingX[b]+1 || j==buildingX[b]-1) && i == buildingY[b]){
                                            cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                            isBuilding = true; // isbuilding di set true
                                            break; // stop loop nya karena kita sudah nemu building nya
                                        }
                                    }
                                    else if(seedb[b]==5){
                                        if(active[b]&& i==buildingY[b]-1 && j==buildingX[b]){
                                            cout<<"W ";
                                            isBuilding=true;
                                            break;
                                        }
                                    }
                                    else if(seedb[b]==6){
                                        if(active[b]&& i==buildingY[b]-2 && j==buildingX[b]){
                                            cout<<"W ";
                                            isBuilding=true;
                                            break;
                                        }
                                    }
                                }
                                if (isBuilding) continue;

                                if (i == y && j == x && twerk==1) {
                                    cout<<"d ";
                                }
                                else if((i==y-1|| i==y)&& j==x && twerk==0){
                                    cout<<"D ";
                                }
                                else {
                                    cout << maps[i][j] << " ";
                                }
                            }
                            cout<<endl;
                        }
                        if(twerk==0){
                            cout<<"Press w to jump 2 blocks"<<endl<<"Press shift+w to jump 3 blocks"<<endl<<"Press s to toggle crouch";
                        }
                        else if(twerk==1){
                            cout<<"Press s to untoggle crouch";
                        }
                        Sleep(100-5*mul);
                    }
                }
                if (key == 'W' && twerk==0) { // renderin for making the player go up
                    for (int h = 0; h < 3; h++) {
                        system("cls");
                        for (int i = 0; i < MAX_BUILDINGS; i++) {
                            if (active[i]) buildingX[i]--;
                        }

                        y--; //buat player lompat
                        score+=10;
                        if(mul<10){
                            mul=score/250;
                        }
                        checkcol(seedb,active,x,y,buildingX,buildingY,menu1,twerk);
                        if(menu1==5){
                            cout << "Game Over!" << endl<<"Enter your name: ";
                            cin>>name;
                            hsname.push_back(name);
                            intscore.push_back(score);
                            stringstream ss;
                            ss<<score;
                            tempname=ss.str();
                            hsscore.push_back(tempname);
                            for(int i=0;i<intscore.size();i++){
                                for(int j=0;j<intscore.size();j++){
                                    if(intscore[i]>intscore[j]){
                                        tempscore2=intscore[i];
                                        tempscore=hsscore[i];
                                        tempname=hsname[i];
                                        intscore[i]=intscore[j];
                                        hsscore[i]=hsscore[j];
                                        hsname[i]=hsname[j];
                                        intscore[j]=tempscore2;
                                        hsscore[j]=tempscore;
                                        hsname[j]=tempname;
                                    }
                                }
                            }
                            if(intscore.size()>5){
                                intscore.erase(intscore.begin()+5);
                                hsscore.erase(hsscore.begin()+5);
                                hsname.erase(hsname.begin()+5);
                            }
                            outf.open("hsname.txt",ios::out);
                            for(int i=0;i<hsname.size();i++){
                                outf<<hsname[i]<<endl;
                            }
                            outf.close();
                            outf.open("hsscore.txt",ios::out);
                            for(int i=0;i<intscore.size();i++){
                                outf<<intscore[i]<<endl;
                            }
                            outf.close();
                            menu1=7;
                            break;
                        }
                        cout<<"Score: "<<score<<endl;
                        for (int i = 0; i < 10; i++) {
                            for (int j = 0; j < 50; j++) {
                                bool isBuilding = false;
                                for (int b = 0; b < MAX_BUILDINGS; b++) {
                                    if(seedb[b]==0){
                                        if (active[b] && i == buildingY[b] && j == buildingX[b]) {
                                            cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                            isBuilding = true; // isbuilding di set true
                                            break; // stop loop nya karena kita sudah nemu building nya
                                        }
                                    }
                                    else if(seedb[b]==1){
                                        if (active[b] && (i == buildingY[b] || i == buildingY[b]-1) && j==buildingX[b] ) {
                                            cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                            isBuilding = true; // isbuilding di set true
                                            break; // stop loop nya karena kita sudah nemu building nya
                                        }
                                        if(active[b] && (j == buildingX[b] || j==buildingX[b]+1) && i == buildingY[b]){
                                            cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                            isBuilding = true; // isbuilding di set true
                                            break; // stop loop nya karena kita sudah nemu building nya
                                        }
                                    }
                                    else if(seedb[b]==2){
                                        if (active[b] && (i == buildingY[b] || i == buildingY[b]-1) && j==buildingX[b] ) {
                                            cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                            isBuilding = true; // isbuilding di set true
                                            break; // stop loop nya karena kita sudah nemu building nya
                                        }
                                        if(active[b] && (j == buildingX[b] || j==buildingX[b]-1) && i == buildingY[b]){
                                            cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                            isBuilding = true; // isbuilding di set true
                                            break; // stop loop nya karena kita sudah nemu building nya
                                        }
                                    }
                                    else if(seedb[b]==3){
                                        if (active[b] && (i == buildingY[b] || i == buildingY[b]-1) && (j == buildingX[b] || j==buildingX[b]-1) ) {
                                            cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                            isBuilding = true; // isbuilding di set true
                                            break; // stop loop nya karena kita sudah nemu building nya
                                        }
                                    }
                                    else if(seedb[b]==4){
                                        if(active[b]&&(i == buildingY[b] || i == buildingY[b]-1) && j==buildingX[b]){
                                            cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                            isBuilding = true; // isbuilding di set true
                                            break; // stop loop nya karena kita sudah nemu building nya
                                        }
                                        if(active[b] && (j == buildingX[b] || j==buildingX[b]+1 || j==buildingX[b]-1) && i == buildingY[b]){
                                            cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                            isBuilding = true; // isbuilding di set true
                                            break; // stop loop nya karena kita sudah nemu building nya
                                        }
                                    }
                                    else if(seedb[b]==5){
                                        if(active[b]&& i==buildingY[b]-1 && j==buildingX[b]){
                                            cout<<"W ";
                                            isBuilding=true;
                                            break;
                                        }
                                    }
                                    else if(seedb[b]==6){
                                        if(active[b]&& i==buildingY[b]-2 && j==buildingX[b]){
                                            cout<<"W ";
                                            isBuilding=true;
                                            break;
                                        }
                                    }
                                }
                                if (isBuilding) continue;

                                if (i == y && j == x && twerk==1) {
                                    cout<<"d ";
                                }
                                else if((i==y-1|| i==y)&& j==x && twerk==0){
                                    cout<<"D ";
                                }
                                else {
                                    cout << maps[i][j] << " ";
                                }
                            }
                            cout<<endl;
                        }
                        if(twerk==0){
                            cout<<"Press w to jump 2 blocks"<<endl<<"Press shift+w to jump 3 blocks"<<endl<<"Press s to toggle crouch";
                        }
                        else if(twerk==1){
                            cout<<"Press s to untoggle crouch";
                        }
                        Sleep(100-5*mul);
                    }
                    // <IMPORTANT><IMPORTANT><IMPORTANT><IMPORTANT><IMPORTANT><IMPORTANT><IMPORTANT><IMPORTANT>
                    // klo km blm notice kita ada 3 kyk ginian di code nya, yang pertama funsinya untuk render map sebelum input
                    // yang kedua untuk render map setelah press w dan player ke ata, yang ketiga untuk render map saat player nya ke bawah
                    // klo kita cm ada satu tok, nanti player nya antara gk bisa gerak, atau code nya rusak
                    // bisa seh pake satu tapi perlu pake function
                    // THIS IS WHAT WE MUST GO THROUGH IF WE DON'T USE FUNTION BEN, LIFE COULD HAVE BEEN A LOT SIMPLER

                    for (int h = 0; h < 3; h++) {
                        system("cls");
                        for (int i = 0; i < MAX_BUILDINGS; i++) {
                            if (active[i]) buildingX[i]--; // rendering for makking the player go down
                        }

                        y++;
                        score+=10;
                        if(mul<10){
                            mul=score/250;
                        }
                        checkcol(seedb,active,x,y,buildingX,buildingY,menu1,twerk);
                        if(menu1==5){
                            cout << "Game Over!" << endl<<"Enter your name: ";
                            cin>>name;
                            hsname.push_back(name);
                            intscore.push_back(score);
                            stringstream ss;
                            ss<<score;
                            tempname=ss.str();
                            hsscore.push_back(tempname);
                            for(int i=0;i<intscore.size();i++){
                                for(int j=0;j<intscore.size();j++){
                                    if(intscore[i]>intscore[j]){
                                        tempscore2=intscore[i];
                                        tempscore=hsscore[i];
                                        tempname=hsname[i];
                                        intscore[i]=intscore[j];
                                        hsscore[i]=hsscore[j];
                                        hsname[i]=hsname[j];
                                        intscore[j]=tempscore2;
                                        hsscore[j]=tempscore;
                                        hsname[j]=tempname;
                                    }
                                }
                            }
                            if(intscore.size()>5){
                                intscore.erase(intscore.begin()+5);
                                hsscore.erase(hsscore.begin()+5);
                                hsname.erase(hsname.begin()+5);
                            }
                            outf.open("hsname.txt",ios::out);
                            for(int i=0;i<hsname.size();i++){
                                outf<<hsname[i]<<endl;
                            }
                            outf.close();
                            outf.open("hsscore.txt",ios::out);
                            for(int i=0;i<intscore.size();i++){
                                outf<<intscore[i]<<endl;
                            }
                            outf.close();
                            menu1=7;
                            break;
                        }
                        cout<<"Score: "<<score<<endl;
                        for (int i = 0; i < 10; i++) {
                            for (int j = 0; j < 50; j++) {
                                bool isBuilding = false;
                                for (int b = 0; b < MAX_BUILDINGS; b++) {
                                    if(seedb[b]==0){
                                        if (active[b] && i == buildingY[b] && j == buildingX[b]) {
                                            cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                            isBuilding = true; // isbuilding di set true
                                            break; // stop loop nya karena kita sudah nemu building nya
                                        }
                                    }
                                    else if(seedb[b]==1){
                                        if (active[b] && (i == buildingY[b] || i == buildingY[b]-1) && j==buildingX[b] ) {
                                            cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                            isBuilding = true; // isbuilding di set true
                                            break; // stop loop nya karena kita sudah nemu building nya
                                        }
                                        if(active[b] && (j == buildingX[b] || j==buildingX[b]+1) && i == buildingY[b]){
                                            cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                            isBuilding = true; // isbuilding di set true
                                            break; // stop loop nya karena kita sudah nemu building nya
                                        }
                                    }
                                    else if(seedb[b]==2){
                                        if (active[b] && (i == buildingY[b] || i == buildingY[b]-1) && j==buildingX[b] ) {
                                            cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                            isBuilding = true; // isbuilding di set true
                                            break; // stop loop nya karena kita sudah nemu building nya
                                        }
                                        if(active[b] && (j == buildingX[b] || j==buildingX[b]-1) && i == buildingY[b]){
                                            cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                            isBuilding = true; // isbuilding di set true
                                            break; // stop loop nya karena kita sudah nemu building nya
                                        }
                                    }
                                    else if(seedb[b]==3){
                                        if (active[b] && (i == buildingY[b] || i == buildingY[b]-1) && (j == buildingX[b] || j==buildingX[b]-1) ) {
                                            cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                            isBuilding = true; // isbuilding di set true
                                            break; // stop loop nya karena kita sudah nemu building nya
                                        }
                                    }
                                    else if(seedb[b]==4){
                                        if(active[b]&&(i == buildingY[b] || i == buildingY[b]-1) && j==buildingX[b]){
                                            cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                            isBuilding = true; // isbuilding di set true
                                            break; // stop loop nya karena kita sudah nemu building nya
                                        }
                                        if(active[b] && (j == buildingX[b] || j==buildingX[b]+1 || j==buildingX[b]-1) && i == buildingY[b]){
                                            cout << "T "; // kalau ada building maka akan di gambar sebuah building
                                            isBuilding = true; // isbuilding di set true
                                            break; // stop loop nya karena kita sudah nemu building nya
                                        }
                                    }
                                    else if(seedb[b]==5){
                                        if(active[b]&& i==buildingY[b]-1 && j==buildingX[b]){
                                            cout<<"W ";
                                            isBuilding=true;
                                            break;
                                        }
                                    }
                                    else if(seedb[b]==6){
                                        if(active[b]&& i==buildingY[b]-2 && j==buildingX[b]){
                                            cout<<"W ";
                                            isBuilding=true;
                                            break;
                                        }
                                    }
                                }
                                if (isBuilding) continue;

                                if (i == y && j == x && twerk==1) {
                                    cout<<"d ";
                                }
                                else if((i==y-1|| i==y)&& j==x && twerk==0){
                                    cout<<"D ";
                                }
                                else {
                                    cout << maps[i][j] << " ";
                                }
                            }
                            cout<<endl;
                        }
                        if(twerk==0){
                            cout<<"Press w to jump 2 blocks"<<endl<<"Press shift+w to jump 3 blocks"<<endl<<"Press s to toggle crouch";
                        }
                        else if(twerk==1){
                            cout<<"Press s to untoggle crouch";
                        }
                        Sleep(100-5*mul);
                    }
                }
                if(key=='s' && twerk==0){
                    twerk=1;
                }
                else if(key=='s' && twerk==1){
                    twerk=0;
                }
            }
        }
        while(menu1==2){
            system("cls");
            for(int i=0;i<intscore.size();i++){
                cout<<i+1<<". "<<hsname[i]<<" "<<intscore[i]<<endl;
            }
            cout<<"0. Exit"<<endl;
            do{
                cout<<">>";
                cin>>menu2;
            }while(menu2!=0);
            if(menu2==0){
                menu1=7;
            }
        }
        if(menu1==0){
            break;
        }
    }

    return 0;
}
