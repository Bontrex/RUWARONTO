#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std;

// Define obstacle shapes as relative coordinates (dy, dx)
const vector<vector<pair<int, int>>> obShapes = {
    {{0,0}},                               // 0: Normal block
    {{0,0}, {-1,0}, {0,1}},                // 1: L-shape right
    {{0,0}, {-1,0}, {0,-1}},               // 2: L-shape left
    {{0,0}, {-1,0}, {0,-1}, {-1,-1}},      // 3: 2x2 block
    {{0,0}, {-1,0}, {0,1}, {0,-1}},        // 4: Upside-down T
    {{-1,0}},                              // 5: Low bird
    {{-2,0}}                               // 6: High bird
};

struct ScoreRec {
    string name;
    int score;
};

// --- DATA HANDLING ---
void loadScores(vector<ScoreRec>& scores) {
    scores.clear();
    ifstream inf("hsname.txt"), isf("hsscore.txt");
    string n; int s;
    while (inf >> n && isf >> s) scores.push_back({n, s});
}

void saveScores(vector<ScoreRec>& scores) {
    ofstream outf("hsname.txt"), outs("hsscore.txt");
    for (auto& rec : scores) {
        outf << rec.name << "\n";
        outs << rec.score << "\n";
    }
}

void gameover(vector<ScoreRec>& scores, int newScore) {
    cout << "Game Over!\nEnter your name: ";
    string name;
    cin >> name;
    scores.push_back({name, newScore});
    
    // Sort descending and keep top 5
    sort(scores.begin(), scores.end(), [](const ScoreRec& a, const ScoreRec& b){ return a.score > b.score; });
    if (scores.size() > 5) scores.resize(5);
    
    saveScores(scores);
}

// --- GAME LOGIC ---
bool checkCollision(int px, int py, int twerk, int seedb[], bool active[], int bX[], int bY[]) {
    vector<pair<int, int>> playerPts = {{py, px}};
    if (twerk == 0) playerPts.push_back({py - 1, px}); // Standing takes 2 vertical blocks

    for (int i = 0; i < 3; i++) {
        if (!active[i]) continue;
        for (auto& pt : obShapes[seedb[i]]) {
            int obY = bY[i] + pt.first, obX = bX[i] + pt.second;
            for (auto& pPt : playerPts) {
                if (pPt.first == obY && pPt.second == obX) return true;
            }
        }
    }
    return false;
}

void drawMap(int x, int y, int twerk, int seedb[], bool active[], int bX[], int bY[], int score) {
    system("cls");
    cout << "Score: " << score << "\n";
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 50; j++) {
            bool drawn = false;
            // Draw Obstacles
            for (int b = 0; b < 3 && !drawn; b++) {
                if (!active[b]) continue;
                for (auto& pt : obShapes[seedb[b]]) {
                    if (i == bY[b] + pt.first && j == bX[b] + pt.second) {
                        cout << (seedb[b] >= 5 ? "W " : "T ");
                        drawn = true; break;
                    }
                }
            }
            if (drawn) continue;

            // Draw Player & Map borders
            if (i == y && j == x) cout << (twerk == 1 ? "d " : "D ");
            else if (i == y - 1 && j == x && twerk == 0) cout << "D ";
            else if (i == 0 || i == 9 || j == 0 || j == 49) cout << "# ";
            else if (i == 7) cout << "* ";
            else cout << "  ";
        }
        cout << "\n";
    }
    cout << (twerk == 0 ? "Press w to jump 2 blocks\nPress shift+w to jump 3 blocks\nPress s to toggle crouch\n" : "Press s to untoggle crouch\n");
}

bool updateFrame(int &y, int dy, int &score, int &mul, int x, int twerk, int seedb[], bool active[], int bX[], int bY[]) {
    for (int i = 0; i < 3; i++) if (active[i]) bX[i]--;
    y += dy;
    score += 10;
    mul = min(10, score / 250);
    
    if (checkCollision(x, y, twerk, seedb, active, bX, bY)) return true; // Collision occurred
    
    drawMap(x, y, twerk, seedb, active, bX, bY, score);
    Sleep(100 - 5 * mul);
    return false;
}

int main() {
    srand(time(0));
    vector<ScoreRec> highscores;
    int bX[3], bY[3], seedb[3];
    bool active[3];
    int menuState;

    while (true) {
        system("cls");
        loadScores(highscores);
        cout << "Welcome to Ruwarono\n1. Play\n2. Highscores\n0. Embrace Cowardice?\n>>";
        cin >> menuState;

        if (menuState == 0) break;

        if (menuState == 2) {
            system("cls");
            for (size_t i = 0; i < highscores.size(); i++) {
                cout << i + 1 << ". " << highscores[i].name << " " << highscores[i].score << "\n";
            }
            cout << "0. Exit\n>>";
            cin >> menuState;
            continue;
        }

        if (menuState == 1) {
            for (int i = 0; i < 3; i++) { bX[i] = -1; bY[i] = 6; active[i] = false; seedb[i] = 0; }
            int x = 5, y = 6, score = 0, mul = 0, twerk = 0, spawnTimer = 0;

            while (true) {
                // Spawn logic
                if (spawnTimer <= 0) {
                    for (int i = 0; i < 3; i++) {
                        if (!active[i]) {
                            bX[i] = 49; seedb[i] = rand() % 7; active[i] = true;
                            break;
                        }
                    }
                    spawnTimer = rand() % 10 + 7;
                }
                spawnTimer--;

                // Update frame (no jump)
                if (updateFrame(y, 0, score, mul, x, twerk, seedb, active, bX, bY)) {
                    gameover(highscores, score);
                    break;
                }

                // Despawn off-screen obstacles
                for (int i = 0; i < 3; i++) if (bX[i] < 0) active[i] = false;

                // Input handling
                if (kbhit()) {
                    char key = getch();
                    if (key == 's') twerk = (twerk == 0 ? 1 : 0);
                    
                    if ((key == 'w' || key == 'W') && twerk == 0) {
                        int jumpHeight = (key == 'W') ? 3 : 2;
                        bool died = false;
                        
                        // Going Up
                        for (int h = 0; h < jumpHeight; h++) {
                            if (updateFrame(y, -1, score, mul, x, twerk, seedb, active, bX, bY)) { died = true; break; }
                        }
                        // Going Down
                        for (int h = 0; h < jumpHeight && !died; h++) {
                            if (updateFrame(y, 1, score, mul, x, twerk, seedb, active, bX, bY)) died = true; 
                        }
                        if (died) { gameover(highscores, score); break; }
                    }
                }
            }
        }
    }
    return 0;
}