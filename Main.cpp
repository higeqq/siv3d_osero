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

void user_change() { Circle(300, 150, 40).draw(); }

void Main() {
    int color[8][8];
    //    int i2 = 0;
    //    Rect x1(223,103,45,45);
    //    Rect x2(273,103,45,45);
    Array<Rect> x;
    Array<Circle> d;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            color[i][j] = 0;
            x << Rect(223 + 50 * j, 103 + 50 * i, 45, 45);
            d << Circle(245 + 50 * j, 125 + 50 * i, 15);
        }
    }

    //    Circle d(245,125,15);
    //    Circle d2(295,125,15);
    while(System::Update()) {
        Waku();

        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if(x[i + j * 8].leftClicked()) {
                    color[i][j] = 1;
                }
                if(color[i][j] == 1) {
                    d[i + j * 8].draw();
                }
            }
        }
    }
}
