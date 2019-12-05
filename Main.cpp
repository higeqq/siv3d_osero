#include <Siv3D.hpp>
void Waku() {
    int yoko = 100;
    int tate = 220;
    //　オセロの外枠
    Rect(220, 100, 400, 400).drawFrame(3, 0);
    //　横線の処理
    for(int i = 0; i < 8; i++) {
        yoko += 50;
        Line(225, yoko, 615, yoko).draw(4, Palette::White);
    }
    for(int s = 0; s < 8; s++) {
        tate += 50;
        Line(tate, 105, tate, 500).draw(4, Palette::White);
    }
}
void syoki() { Circle(380, 280, 15).draw(); }
void Main() {
    int count = 1;
    int color[8][8];
    int white = 1;
    int blue = 2;
    //    Rect x1(223,103,45,45);
    //    Rect x2(273,103,45,45);
    Array<Rect> x;
    Array<Circle> d;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            color[i][j] = 0;
            x << Rect(223 + 50 * j, 103 + 50 * i, 45, 45);
            d << Circle(245 + 50 * j, 125 + 50 * i, 15);
            //            blue << Circle(245 + 50 * j, 125 + 50 * i, 15);
        }
    }
    color[3][3] = 1;
    color[3][4] = 2;
    color[4][3] = 2;
    color[4][4] = 1;

    // jが縦　iが横

    while(System::Update()) {
        // カウントして、割ったあまりが1なら白と、2なら青と (coutn % 2 ==
        // 0なら白と)(count %2 == 1なら青とひ表示
        Waku();
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if(x[i + j * 8].leftClicked()) {
                    count++;

                    //　もしカウントが割り切れるなら白を描画、割り切れないならブルーを描画
                    if(count % 2 == 0) {
                        color[i][j] = white;

                        // j + 2 j + 1 j
                        //　j + 1 がwhiteに変わる

                        // 繰り返し処理
                        // 8回繰り返す
                        // はじめの 値がループするごとに一つ加わって繰り返す
                        //

                        if(color[i + 2][j] == white &&
                           color[i + 1][j] == blue) {
                            color[i + 1][j] = white;
                        }
                        if(color[i + 3][j] == white &&
                           color[i + 2][j] == blue && color[i + 1][j] == blue) {
                            color[i + 2][j] = white;
                            color[i + 1][j] = white;
                        }
                        if(color[i + 4][j] == white &&
                           color[i + 3][j] == blue && color[i + 2][j] == blue &&
                           color[i + 1][j] == blue) {
                            color[i + 3][j] = white;
                            color[i + 2][j] = white;
                            color[i + 1][j] = white;
                        }
                        if(color[i + 5][j] == white &&
                           color[i + 4][j] == blue && color[i + 3][j] == blue &&
                           color[i + 2][j] == blue && color[i + 1][j]) {
                            color[i + 4][j] = white;
                            color[i + 3][j] = white;
                            color[i + 2][j] = white;
                            color[i + 1][j] = white;
                        }
                        if(color[i + 6][j] == white &&
                           color[i + 5][j] == blue && color[i + 4][j] == blue &&
                           color[i + 3][j] == blue && color[i + 2][j] == blue &&
                           color[i + 1][j]) {
                            color[i + 5][j] = white;
                            color[i + 4][j] = white;
                            color[i + 3][j] = white;
                            color[i + 2][j] = white;
                            color[i + 1][j] = white;
                        }
                        if(color[i + 7][j] == white &&
                           color[i + 6][j] == blue && color[i + 5][j] == blue &&
                           color[i + 4][j] == blue && color[i + 3][j] == blue &&
                           color[i + 2][j] == blue && color[i + 1][j]) {
                            color[i + 6][j] = white;
                            color[i + 5][j] = white;
                            color[i + 4][j] = white;
                            color[i + 3][j] = white;
                            color[i + 2][j] = white;
                            color[i + 1][j] = white;
                        }
                        if(color[i - 2][j] == white &&
                           color[i - 1][j] == blue) {
                            color[i - 1][j] = white;
                        }
                        if(color[i - 3][j] == white &&
                           color[i - 2][j] == blue && color[i - 1][j] == blue) {
                            color[i - 2][j] = white;
                            color[i - 1][j] = white;
                        }
                        if(color[i - 4][j] == white &&
                           color[i - 3][j] == blue && color[i - 2][j] == blue &&
                           color[i - 1][j] == blue) {
                            color[i - 3][j] = white;
                            color[i - 2][j] = white;
                            color[i - 1][j] = white;
                        }
                        if(color[i - 5][j] == white &&
                           color[i - 4][j] == blue && color[i - 3][j] == blue &&
                           color[i - 2][j] == blue && color[i - 1][j]) {
                            color[i - 4][j] = white;
                            color[i - 3][j] = white;
                            color[i - 2][j] = white;
                            color[i - 1][j] = white;
                        }
                        if(color[i - 6][j] == white &&
                           color[i - 5][j] == blue && color[i - 4][j] == blue &&
                           color[i - 3][j] == blue && color[i - 2][j] == blue &&
                           color[i - 1][j]) {
                            color[i - 5][j] = white;
                            color[i - 4][j] = white;
                            color[i - 3][j] = white;
                            color[i - 2][j] = white;
                            color[i - 1][j] = white;
                        }
                        if(color[i - 7][j] == white &&
                           color[i - 6][j] == blue && color[i - 5][j] == blue &&
                           color[i - 4][j] == blue && color[i - 3][j] == blue &&
                           color[i - 2][j] == blue && color[i - 1][j]) {
                            color[i - 6][j] = white;
                            color[i - 5][j] = white;
                            color[i - 4][j] = white;
                            color[i - 3][j] = white;
                            color[i - 2][j] = white;
                            color[i - 1][j] = white;
                        }

                        if(color[i][j + 2] == white &&
                           color[i][j + 1] == blue) {
                            color[i][j + 1] = white;
                        }
                        if(color[i][j + 3] == white &&
                           color[i][j + 2] == blue && color[i][j + 1] == blue) {
                            color[i][j + 2] = white;
                            color[i][j + 1] = white;
                        }
                        if(color[i][j + 4] == white &&
                           color[i][j + 3] == blue && color[i][j + 2] == blue &&
                           color[i][j + 1] == blue) {
                            color[i][j + 3] = white;
                            color[i][j + 2] = white;
                            color[i][j + 1] = white;
                        }
                        if(color[i][j + 5] == white &&
                           color[i][j + 4] == blue && color[i][j + 3] == blue &&
                           color[i][j + 2] == blue && color[i][j + 1]) {
                            color[i][j + 4] = white;
                            color[i][j + 3] = white;
                            color[i][j + 2] = white;
                            color[i][j + 1] = white;
                        }
                        if(color[i][j + 6] == white &&
                           color[i][j + 5] == blue && color[i][j + 4] == blue &&
                           color[i][j + 3] == blue && color[i][j + 2] == blue &&
                           color[i][j + 1]) {
                            color[i][j + 5] = white;
                            color[i][j + 4] = white;
                            color[i][j + 3] = white;
                            color[i][j + 2] = white;
                            color[i][j + 1] = white;
                        }
                        if(color[i][j + 7] == white &&
                           color[i][j + 6] == blue && color[i][j + 5] == blue &&
                           color[i][j + 4] == blue && color[i][j + 3] == blue &&
                           color[i][j + 2] == blue && color[i][j + 1]) {
                            color[i][j + 6] = white;
                            color[i][j + 5] = white;
                            color[i][j + 4] = white;
                            color[i][j + 3] = white;
                            color[i][j + 2] = white;
                            color[i][j + 1] = white;
                        }

                        if(color[i][j - 2] == white &&
                           color[i][j - 1] == blue) {
                            color[i][j - 1] = white;
                        }
                        if(color[i][j - 3] == white &&
                           color[i][j - 2] == blue && color[i][j - 1] == blue) {
                            color[i][j - 2] = white;
                            color[i][j - 1] = white;
                        }
                        if(color[i][j - 4] == white &&
                           color[i][j - 3] == blue && color[i][j - 2] == blue &&
                           color[i][j - 1] == blue) {
                            color[i][j - 3] = white;
                            color[i][j - 2] = white;
                            color[i][j - 1] = white;
                        }
                        if(color[i][j - 5] == white &&
                           color[i][j - 4] == blue && color[i][j - 3] == blue &&
                           color[i][j - 2] == blue && color[i][j - 1] == blue) {
                            color[i][j - 4] = white;
                            color[i][j - 3] = white;
                            color[i][j - 2] = white;
                            color[i][j - 1] = white;
                        }
                        if(color[i][j - 6] == white &&
                           color[i][j - 5] == blue && color[i][j - 4] == blue &&
                           color[i][j - 3] == blue && color[i][j - 2] == blue &&
                           color[i][j - 1] == blue) {
                            color[i][j - 5] = white;
                            color[i][j - 4] = white;
                            color[i][j - 3] = white;
                            color[i][j - 2] = white;
                            color[i][j - 1] = white;
                        }
                        if(color[i][j - 7] == white &&
                           color[i][j - 6] == blue && color[i][j - 5] == blue &&
                           color[i][j - 4] == blue && color[i][j - 3] == blue &&
                           color[i][j - 2] == blue && color[i][j - 1] == blue) {
                            color[i][j - 6] = white;
                            color[i][j - 5] = white;
                            color[i][j - 4] = white;
                            color[i][j - 3] = white;
                            color[i][j - 2] = white;
                            color[i][j - 1] = white;
                        }

                        // 青のひっくり返す処理
                    } else {
                        color[i][j] = blue;
        
                        
                        if(color[i + 2][j] == blue &&
                           color[i + 1][j] == white) {
                            color[i + 1][j] = blue;
                        }
                        if(color[i + 3][j] == blue &&
                           color[i + 2][j] == white &&
                           color[i + 1][j] == white) {
                            color[i + 2][j] = blue;
                            color[i + 1][j] = blue;
                        }
                        if(color[i + 4][j] == blue &&
                           color[i + 3][j] == white &&
                           color[i + 2][j] == white &&
                           color[i + 1][j] == white) {
                            color[i + 3][j] = blue;
                            color[i + 2][j] = blue;
                            color[i + 1][j] = blue;
                        }
                        if(color[i + 5][j] == blue &&
                           color[i + 4][j] == white &&
                           color[i + 3][j] == white &&
                           color[i + 2][j] == white && color[i + 1][j]) {
                            color[i + 4][j] = blue;
                            color[i + 3][j] = blue;
                            color[i + 2][j] = blue;
                            color[i + 1][j] = blue;
                        }
                        if(color[i + 6][j] == blue &&
                           color[i + 5][j] == white &&
                           color[i + 4][j] == white &&
                           color[i + 3][j] == white &&
                           color[i + 2][j] == white && color[i + 1][j]) {
                            color[i + 5][j] = blue;
                            color[i + 4][j] = blue;
                            color[i + 3][j] = blue;
                            color[i + 2][j] = blue;
                            color[i + 1][j] = blue;
                        }
                        if(color[i + 7][j] == blue &&
                           color[i + 6][j] == white &&
                           color[i + 5][j] == white &&
                           color[i + 4][j] == white &&
                           color[i + 3][j] == white &&
                           color[i + 2][j] == white && color[i + 1][j]) {
                            color[i + 6][j] = blue;
                            color[i + 5][j] = blue;
                            color[i + 4][j] = blue;
                            color[i + 3][j] = blue;
                            color[i + 2][j] = blue;
                            color[i + 1][j] = blue;
                        }
                        if(color[i - 2][j] == blue &&
                           color[i - 1][j] == white) {
                            color[i - 1][j] = blue;
                        }
                        if(color[i - 3][j] == blue &&
                           color[i - 2][j] == white &&
                           color[i - 1][j] == white) {
                            color[i - 2][j] = blue;
                            color[i - 1][j] = blue;
                        }
                        if(color[i - 4][j] == blue &&
                           color[i - 3][j] == white &&
                           color[i - 2][j] == white &&
                           color[i - 1][j] == white) {
                            color[i - 3][j] = blue;
                            color[i - 2][j] = blue;
                            color[i - 1][j] = blue;
                        }
                        if(color[i - 5][j] == blue &&
                           color[i - 4][j] == white &&
                           color[i - 3][j] == white &&
                           color[i - 2][j] == white && color[i - 1][j]) {
                            color[i - 4][j] = blue;
                            color[i - 3][j] = blue;
                            color[i - 2][j] = blue;
                            color[i - 1][j] = blue;
                        }
                        if(color[i - 6][j] == blue &&
                           color[i - 5][j] == white &&
                           color[i - 4][j] == white &&
                           color[i - 3][j] == white &&
                           color[i - 2][j] == white && color[i - 1][j]) {
                            color[i - 5][j] = blue;
                            color[i - 4][j] = blue;
                            color[i - 3][j] = blue;
                            color[i - 2][j] = blue;
                            color[i - 1][j] = blue;
                        }
                        if(color[i - 7][j] == blue &&
                           color[i - 6][j] == white &&
                           color[i - 5][j] == white &&
                           color[i - 4][j] == white &&
                           color[i - 3][j] == white &&
                           color[i - 2][j] == white && color[i - 1][j]) {
                            color[i - 6][j] = blue;
                            color[i - 5][j] = blue;
                            color[i - 4][j] = blue;
                            color[i - 3][j] = blue;
                            color[i - 2][j] = blue;
                            color[i - 1][j] = blue;
                        }

                        // j + 3 j + 2 j + 1 j
                        // j + 2 j + 1がwhiteに変わる
                        if(color[i][j + 2] == blue &&
                            color[i][j + 1] == white) {
                              color[i][j + 1] = blue;
                        }

                        if(color[i][j + 3] == blue &&
                           color[i][j + 2] == white &&
                           color[i][j + 1] == white) {
                            color[i][j + 2] = blue;
                            color[i][j + 1] = blue;
                        }

                        //  j + 4 j + 3 j + 2 j + 1 j
                        //  j + 3 j + 3 j + 1がwhiteに変わる
                        if(color[i][j + 4] == blue &&
                           color[i][j + 3] == white &&
                           color[i][j + 2] == white &&
                           color[i][j + 1] == white) {
                            color[i][j + 3] = blue;
                            color[i][j + 2] = blue;
                            color[i][j + 1] = blue;
                        }

                        if(color[i][j + 5] == blue &&
                           color[i][j + 4] == white &&
                           color[i][j + 3] == white &&
                           color[i][j + 2] == white && color[i][j + 1]) {
                            color[i][j + 4] = blue;
                            color[i][j + 3] = blue;
                            color[i][j + 2] = blue;
                            color[i][j + 1] = blue;
                        }

                        if(color[i][j + 6] == blue &&
                           color[i][j + 5] == white &&
                           color[i][j + 4] == white &&
                           color[i][j + 3] == white &&
                           color[i][j + 2] == white && color[i][j + 1]) {
                            color[i][j + 5] = blue;
                            color[i][j + 4] = blue;
                            color[i][j + 3] = blue;
                            color[i][j + 2] = blue;
                            color[i][j + 1] = blue;
                        }
                        //
                        if(color[i][j + 7] == blue &&
                           color[i][j + 6] == white &&
                           color[i][j + 5] == white &&
                           color[i][j + 4] == white &&
                           color[i][j + 3] == white &&
                           color[i][j + 2] == white && color[i][j + 1]) {
                            color[i][j + 6] = blue;
                            color[i][j + 5] = blue;
                            color[i][j + 4] = blue;
                            color[i][j + 3] = blue;
                            color[i][j + 2] = blue;
                            color[i][j + 1] = blue;
                        }

                        // j - 1　がwhiteに変わる
                        if(color[i][j - 2] == blue &&
                           color[i][j - 1] == white) {
                            color[i][j - 1] = blue;
                        }

                        // j - 3 j -2 j -1 j
                        // j -2 j -1がwhiteに変わる
                        if(color[i][j - 3] == blue &&
                           color[i][j - 2] == white &&
                           color[i][j - 1] == white) {
                            color[i][j - 2] = blue;
                            color[i][j - 1] = blue;
                        }

                        //  j - 4 j - 3 j - 2 j - 1 j
                        //  j - 3 j - 3 j - 1がwhiteに変わる
                        if(color[i][j - 4] == blue &&
                           color[i][j - 3] == white &&
                           color[i][j - 2] == white &&
                           color[i][j - 1] == white) {
                            color[i][j - 3] = blue;
                            color[i][j - 2] = blue;
                            color[i][j - 1] = blue;
                        }

                        if(color[i][j - 5] == blue &&
                           color[i][j - 4] == white &&
                           color[i][j - 3] == white &&
                           color[i][j - 2] == white &&
                           color[i][j - 1] == white) {
                            color[i][j - 4] = blue;
                            color[i][j - 3] = blue;
                            color[i][j - 2] = blue;
                            color[i][j - 1] = blue;
                        }

                        if(color[i][j - 6] == blue &&
                           color[i][j - 5] == white &&
                           color[i][j - 4] == white &&
                           color[i][j - 3] == white &&
                           color[i][j - 2] == white &&
                           color[i][j - 1] == white) {
                            color[i][j - 5] = blue;
                            color[i][j - 4] = blue;
                            color[i][j - 3] = blue;
                            color[i][j - 2] = blue;
                            color[i][j - 1] = blue;
                        }
                        if(color[i][j - 7] == blue &&
                           color[i][j - 6] == white &&
                           color[i][j - 5] == white &&
                           color[i][j - 4] == white &&
                           color[i][j - 3] == white &&
                           color[i][j - 2] == white &&
                           color[i][j - 1] == white) {
                            color[i][j - 6] = blue;
                            color[i][j - 5] = blue;
                            color[i][j - 4] = blue;
                            color[i][j - 3] = blue;
                            color[i][j - 2] = blue;
                            color[i][j - 1] = blue;
                        }
                    }
                }
                if(color[i][j] == white) {
                    d[i + j * 8].draw();
                }
                if(color[i][j] == blue) {
                    d[i + j * 8].draw(Palette::Skyblue);
                }
            }
        }
    }
}
