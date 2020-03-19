#include <Siv3D.hpp>

int whiteCount = 0;
int blueCount = 0;
int count = 1;
int othelloStone[8][8];
double FILED[8][8];
int white = 1;
int blue = 2;
Array<Rect> cell;
Array<Circle> stone;
Array<Rect> WALL;
void Wall() {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) {
            WALL << Rect(220, 100 + 50 * i, 50 + 50 * j, 50).drawFrame(1, 0);
        }
}
void initialize() {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            othelloStone[i][j] = 0;
            cell << Rect(223 + 50 * j, 103 + 50 * i, 45, 45);
            stone << Circle(245 + 50 * j, 125 + 50 * i, 15);
        }
    }
    
    othelloStone[3][3] = white;
    othelloStone[3][4] = blue;
    othelloStone[4][3] = blue;
    othelloStone[4][4] = white;
}

void reverseWhite(int x, int y) {
    //　このnは青
    for(int n = 1; n <= 6; n++) {
        // n + 1が挟む先の白
        bool flag = othelloStone[x + n + 1][y] == white;
        for(int i = 1; i <= n; i++) {
            // ここは(color[][]&& == blue color[][] == blueの部分)
            flag &= othelloStone[x + i][y] == blue;
        }
        // trueの場合
        if(flag) {
            for(int i = 1; i <= n; i++) {
                //ここは前やったcolor[i + n][i + j] = white の部分
                othelloStone[x + i][y] = white;
            }
        }
    }
    
    for(int n = 1; n <= 6; n++) {
        bool flag = othelloStone[x - n - 1][y] == white;
        for(int i = 1; i <= n; i++) {
            flag &= othelloStone[x - i][y] == blue;
        }
        if(flag) {
            for(int i = 1; i <= n; i++) {
                othelloStone[x - i][y] = white;
            }
        }
    }
    
    for(int n = 1; n <= 6; n++) {
        bool flag = othelloStone[x][y + n + 1] == white;
        for(int i = 1; i <= n; i++) {
            
            flag &= othelloStone[x][y + i] == blue;
        }
        
        if(flag) {
            for(int i = 1; i <= n; i++) {
                othelloStone[x][y + i] = white;
            }
        }
    }
    
    for(int n = 1; n <= 6; n++) {
        bool flag = othelloStone[x][y - n - 1] == white;
        for(int i = 1; i <= n; i++) {
            flag &= othelloStone[x][y - i] == blue;
        }
        if(flag) {
            for(int i = 0; i <= n; i++) {
                othelloStone[x][y - i] = white;
            }
        }
    }
    
    for(int n = 0; n <= 6; n++) {
        bool flag = othelloStone[x + n + 1][y + 1] == white;
        for(int i = 1; i <= n; i++) {
            flag &= othelloStone[x][y + i] == blue;
        }
        if(flag) {
            for(int i = 1; i <= n; i++) {
                othelloStone[x + i][y + i] = white;
            }
        }
    }
    
    for(int n = 1; n < 6; n++) {
        bool flag = othelloStone[x - n - 1][y - n - 1] == white;
        for(int i = 1; i <= n; i++) {
            flag &= othelloStone[x - i][y - i] == blue;
        }
        if(flag) {
            for(int i = 1; i <= n; i++) {
                othelloStone[x - i][y - i] = white;
            }
        }
    }
    //下に石があった場合の右ななめ
    for(int n = 1; n < 6; n++) {
        bool flag = othelloStone[x + n + 1][y + n + 1] == white;
        for(int i = 1; i <= n; i++) {
            flag &= othelloStone[x + i][y + i] == blue;
        }
        if(flag) {
            for(int i = 1; i <= n; i++) {
                othelloStone[x + i][y + i] = white;
            }
        }
    }
    // 左斜めの処理
    for(int n = 1; n <= 6; n++) {
        bool flag = othelloStone[x + n + 1][y - n - 1] == white;
        for(int i = 1; i <= n; i++) {
            flag &= othelloStone[x + i][y - i] == blue;
        }
        if(flag) {
            for(int i = 1; i <= n; i++) {
                othelloStone[x + i][y - i] = white;
            }
        }
    }
    
    for(int n = 1; n <= 6; n++) {
        bool flag = othelloStone[x - n - 1][y + n + 1] == white;
        for(int i = 1; i <= n; i++) {
            flag &= othelloStone[x - i][y + i] == blue;
        }
        if(flag) {
            for(int i = 1; i <= n; i++) {
                othelloStone[x - i][y + i] = white;
            }
        }
    }
}

void reverseBlue(int x, int y) {
    for(int n = 1; n <= 6; n++) {
        bool flag = othelloStone[x + n + 1][y] == blue;
        for(int i = 1; i <= n; i++) {
            flag &= othelloStone[x + i][y] == white;
        }
        if(flag) {
            for(int i = 1; i <= n; i++) {
                othelloStone[x + i][y] = blue;
            }
        }
    }
    
    for(int n = 1; n <= 6; n++) {
        bool flag = othelloStone[x - n - 1][y] == blue;
        for(int i = 1; i <= n; i++) {
            flag &= othelloStone[x - i][y] == white;
        }
        if(flag) {
            for(int i = 1; i <= n; i++) {
                othelloStone[x - i][y] = blue;
            }
        }
    }
    
    for(int n = 1; n <= 6; n++) {
        bool flag = othelloStone[x][y + n + 1] == blue;
        for(int i = 1; i <= n; i++) {
            
            flag &= othelloStone[x][y + i] == white;
        }
        
        if(flag) {
            for(int i = 1; i <= n; i++) {
                
                othelloStone[x][y + i] = blue;
            }
        }
    }
    
    for(int n = 1; n <= 6; n++) {
        bool flag = othelloStone[x][y - n - 1] == blue;
        for(int i = 1; i <= n; i++) {
            flag &= othelloStone[x][y - i] == white;
        }
        if(flag) {
            for(int i = 0; i <= n; i++) {
                othelloStone[x][y - i] = blue;
            }
        }
    }
    
    for(int n = 0; n <= 6; n++) {
        bool flag = othelloStone[x + n + 1][y + 1] == blue;
        for(int i = 1; i <= n; i++) {
            flag &= othelloStone[x][y + i] == white;
        }
        if(flag) {
            for(int i = 1; i <= n; i++) {
                othelloStone[x + i][y + i] = blue;
            }
        }
    }
    
    for(int n = 1; n < 6; n++) {
        bool flag = othelloStone[x - n - 1][y - n - 1] == blue;
        for(int i = 1; i <= n; i++) {
            flag &= othelloStone[x - i][y - i] == white;
        }
        if(flag) {
            for(int i = 1; i <= n; i++) {
                othelloStone[x - i][y - i] = blue;
            }
        }
    }
    
    for(int n = 1; n < 6; n++) {
        bool flag = othelloStone[x + n + 1][y + n + 1] == blue;
        for(int i = 1; i <= n; i++) {
            flag &= othelloStone[x + i][y + i] == white;
        }
        if(flag) {
            for(int i = 1; i <= n; i++) {
                othelloStone[x + i][y + i] = blue;
            }
        }
    }
    
    for(int n = 1; n <= 6; n++) {
        bool flag = othelloStone[x + n + 1][y - n - 1] == blue;
        for(int i = 1; i <= n; i++) {
            flag &= othelloStone[x + i][y - i] == white;
        }
        if(flag) {
            for(int i = 1; i <= n; i++) {
                othelloStone[x + i][y - i] = blue;
            }
        }
    }
    
    for(int n = 1; n <= 6; n++) {
        bool flag = othelloStone[x - n - 1][y + n + 1] == blue;
        for(int i = 1; i <= n; i++) {
            flag &= othelloStone[x - i][y + i] == white;
        }
        if(flag) {
            for(int i = 1; i <= n; i++) {
                othelloStone[x - i][y + i] = blue;
            }
        }
    }
}

void Main() {
    initialize();
    while(System::Update()) {
        // カウントして、割ったあまりが1なら白と、2なら青と (coutn % 2 ==
        // 0なら白と)(count %2 == 1なら青とひ表示o
        Wall();
        for (int x = 0; x < 8; x++)
            for (int y = 0; y < 8; y++) {
                if (cell[x + y * 8].leftClicked()) {
                    // 重ねておけないように
                    if (othelloStone[x][y] == white && othelloStone[x][y] == white ) break;
                    if (othelloStone[x][y] == blue && othelloStone[x][y] == blue ) break;
                    
                    //　ターン変更
                    count++;
                    //　もしカウントが割り切れるなら白を描画、割り切れないならブルーを描画
                    if (count % 2 == 0) {
                        othelloStone[x][y] = white;
                        reverseWhite(x, y);
                    } else {
                        othelloStone[x][y] = blue;
                        reverseBlue(x, y);
                    }
                }
                if (othelloStone[x][y] == white) stone[x + y * 8].draw();
                if (othelloStone[x][y] == blue) stone[x + y * 8].draw(Palette::Skyblue);
            }
    }
}
