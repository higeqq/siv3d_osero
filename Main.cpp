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
    Array<Rect> cell;
    Array<Circle> d;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            color[i][j] = 0;
            cell << Rect(223 + 50 * j, 103 + 50 * i, 45, 45);
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
        for(int x = 0; x < 8; x++) {
            for(int y = 0; y < 8; y++) {
                if(cell[x + y * 8].leftClicked()) {
                    count++;
                    
                    //　もしカウントが割り切れるなら白を描画、割り切れないならブルーを描画
                    if(count % 2 == 0) {
                        color[x][y] = white;
                        for (int n = 1; n <= 6; n ++) {
                            bool flag =color[x + n + 1][y] == white;
                            for(int l = 1; l <= n; l ++) {
                            flag &=color[x + l][y] == blue;
                            }
                            for (int l = 1; l <= n; l ++) {
                                if (flag) {
                                    color[x + l][y] = white;
                                }
                            }
                        }

                        


                      
                    } else {
                        color[x][y] = blue;
        
                    }
                }
                if(color[x][y] == white) {
                    d[x + y * 8].draw();
                }
                if(color[x][y] == blue) {
                    d[x + y * 8].draw(Palette::Skyblue);
                }
            }
        }
    }
}
