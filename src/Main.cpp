#include <Siv3D.hpp>

int test_c = 0;
int white_c = 0;
int blue_c = 0;
int count = 1;
int color[8][8];
double FILED[8][8];
int white = 1;
int blue = 2;
Rect result_btn(650, 200, 35, 35);
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
            color[i][j] = 0;
            cell << Rect(223 + 50 * j, 103 + 50 * i, 45, 45);
            stone << Circle(245 + 50 * j, 125 + 50 * i, 15);
        }
    }

    color[3][3] = white;
    color[3][4] = blue;
    color[4][3] = blue;
    color[4][4] = white;
}

void reverse_white(int x, int y) {
    //　このnは青
    for(int n = 1; n <= 6; n++) {
        // n + 1が挟む先の白
        bool flag = color[x + n + 1][y] == white;
        for(int i = 1; i <= n; i++) {
            // ここは(color[][]&& == blue color[][] == blueの部分)
            flag &= color[x + i][y] == blue;
        }
        // trueの場合
        if(flag) {
            for(int i = 1; i <= n; i++) {
                //ここは前やったcolor[i + n][i + j] = white の部分
                color[x + i][y] = white;
            }
        }
    }

    for(int n = 1; n <= 6; n++) {
        bool flag = color[x - n - 1][y] == white;
        for(int i = 1; i <= n; i++) {
            flag &= color[x - i][y] == blue;
        }
        if(flag) {
            for(int i = 1; i <= n; i++) {
                color[x - i][y] = white;
            }
        }
    }

    for(int n = 1; n <= 6; n++) {
        bool flag = color[x][y + n + 1] == white;
        for(int i = 1; i <= n; i++) {

            flag &= color[x][y + i] == blue;
        }

        if(flag) {
            for(int i = 1; i <= n; i++) {
                color[x][y + i] = white;
            }
        }
    }

    for(int n = 1; n <= 6; n++) {
        bool flag = color[x][y - n - 1] == white;
        for(int i = 1; i <= n; i++) {
            flag &= color[x][y - i] == blue;
        }
        if(flag) {
            for(int i = 0; i <= n; i++) {
                color[x][y - i] = white;
            }
        }
    }

    for(int n = 0; n <= 6; n++) {
        bool flag = color[x + n + 1][y + 1] == white;
        for(int i = 1; i <= n; i++) {
            flag &= color[x][y + i] == blue;
        }
        if(flag) {
            for(int i = 1; i <= n; i++) {
                color[x + i][y + i] = white;
            }
        }
    }

    for(int n = 1; n < 6; n++) {
        bool flag = color[x - n - 1][y - n - 1] == white;
        for(int i = 1; i <= n; i++) {
            flag &= color[x - i][y - i] == blue;
        }
        if(flag) {
            for(int i = 1; i <= n; i++) {
                color[x - i][y - i] = white;
            }
        }
    }
    //下に石があった場合の右ななめ
    for(int n = 1; n < 6; n++) {
        bool flag = color[x + n + 1][y + n + 1] == white;
        for(int i = 1; i <= n; i++) {
            flag &= color[x + i][y + i] == blue;
        }
        if(flag) {
            for(int i = 1; i <= n; i++) {
                color[x + i][y + i] = white;
            }
        }
    }
    // 左斜めの処理
    for(int n = 1; n <= 6; n++) {
        bool flag = color[x + n + 1][y - n - 1] == white;
        for(int i = 1; i <= n; i++) {
            flag &= color[x + i][y - i] == blue;
        }
        if(flag) {
            for(int i = 1; i <= n; i++) {
                color[x + i][y - i] = white;
            }
        }
    }

    for(int n = 1; n <= 6; n++) {
        bool flag = color[x - n - 1][y + n + 1] == white;
        for(int i = 1; i <= n; i++) {
            flag &= color[x - i][y + i] == blue;
        }
        if(flag) {
            for(int i = 1; i <= n; i++) {
                color[x - i][y + i] = white;
            }
        }
    }
}

void reverse_blue(int x, int y) {
    for(int n = 1; n <= 6; n++) {
        bool flag = color[x + n + 1][y] == blue;
        for(int i = 1; i <= n; i++) {
            flag &= color[x + i][y] == white;
        }
        if(flag) {
            for(int i = 1; i <= n; i++) {
                color[x + i][y] = blue;
            }
        }
    }

    for(int n = 1; n <= 6; n++) {
        bool flag = color[x - n - 1][y] == blue;
        for(int i = 1; i <= n; i++) {
            flag &= color[x - i][y] == white;
        }
        if(flag) {
            for(int i = 1; i <= n; i++) {
                color[x - i][y] = blue;
            }
        }
    }

    for(int n = 1; n <= 6; n++) {
        bool flag = color[x][y + n + 1] == blue;
        for(int i = 1; i <= n; i++) {

            flag &= color[x][y + i] == white;
        }

        if(flag) {
            for(int i = 1; i <= n; i++) {

                color[x][y + i] = blue;
            }
        }
    }

    for(int n = 1; n <= 6; n++) {
        bool flag = color[x][y - n - 1] == blue;
        for(int i = 1; i <= n; i++) {
            flag &= color[x][y - i] == white;
        }
        if(flag) {
            for(int i = 0; i <= n; i++) {
                color[x][y - i] = blue;
            }
        }
    }

    for(int n = 0; n <= 6; n++) {
        bool flag = color[x + n + 1][y + 1] == blue;
        for(int i = 1; i <= n; i++) {
            flag &= color[x][y + i] == white;
        }
        if(flag) {
            for(int i = 1; i <= n; i++) {
                color[x + i][y + i] = blue;
            }
        }
    }

    for(int n = 1; n < 6; n++) {
        bool flag = color[x - n - 1][y - n - 1] == blue;
        for(int i = 1; i <= n; i++) {
            flag &= color[x - i][y - i] == white;
        }
        if(flag) {
            for(int i = 1; i <= n; i++) {
                color[x - i][y - i] = blue;
            }
        }
    }

    for(int n = 1; n < 6; n++) {
        bool flag = color[x + n + 1][y + n + 1] == blue;
        for(int i = 1; i <= n; i++) {
            flag &= color[x + i][y + i] == white;
        }
        if(flag) {
            for(int i = 1; i <= n; i++) {
                color[x + i][y + i] = blue;
            }
        }
    }

    for(int n = 1; n <= 6; n++) {
        bool flag = color[x + n + 1][y - n - 1] == blue;
        for(int i = 1; i <= n; i++) {
            flag &= color[x + i][y - i] == white;
        }
        if(flag) {
            for(int i = 1; i <= n; i++) {
                color[x + i][y - i] = blue;
            }
        }
    }

    for(int n = 1; n <= 6; n++) {
        bool flag = color[x - n - 1][y + n + 1] == blue;
        for(int i = 1; i <= n; i++) {
            flag &= color[x - i][y + i] == white;
        }
        if(flag) {
            for(int i = 1; i <= n; i++) {
                color[x - i][y + i] = blue;
            }
        }
    }
}

void Main() {
    initialize();
    const Font font(50);
    while(System::Update()) {
        // カウントして、割ったあまりが1なら白と、2なら青と (coutn % 2 ==
        // 0なら白と)(count %2 == 1なら青とひ表示o
        Wall();
        result_btn.draw();
        for(int x = 0; x < 8; x++) {
            for(int y = 0; y < 8; y++) {
                if(cell[x + y * 8].leftClicked()) {
                    count++;
                    //　もしカウントが割り切れるなら白を描画、割り切れないならブルーを描画
                    if(count % 2 == 0) {
                        color[x][y] = white;
                        reverse_white(x, y);
                    } else {
                        color[x][y] = blue;
                        reverse_blue(x, y);
                    }
                }
                if(color[x][y] == white) {
                    stone[x + y * 8].draw();
                }
                if(color[x][y] == blue) {
                    stone[x + y * 8].draw(Palette::Skyblue);
                }
            }
        }

        if(result_btn.leftClicked()) {
            test_c = 1;
            white_c = 0;
            blue_c = 0;
            for(int x = 0; x < 8; x++) {
                for(int y = 0; y < 8; y++) {
                    if(color[x][y] == 1) {
                        white_c++;
                    } else if(color[x][y] == 2)
                        blue_c++;
                }
            }
        }
        if(test_c == 1) {

            if(white_c < blue_c) {
                font(U"青の勝利です").draw(20, 20);
            } else if(white_c > blue_c) {
                font(U"白の勝利です").draw(20, 20);
            } else {
                font(U"引き分けです").draw(20, 20);
            }
        }
    }
}
