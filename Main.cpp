# include <Siv3D.hpp>

void Main() {
    while (System::Update())
    {
        int yoko = 100;
        int tate = 220;
        
        //　オセロの外枠
        Rect(220, 100, 400, 400)
            .drawFrame(3, 0);
        
        //　横線の処理
        for (int i = 0; i < 8; i++) {
            yoko += 50;
            
            Line(225, yoko, 615, yoko).draw(4, Palette::White);
        }
        
        for (int s = 0; s < 8; s++) {
            tate += 50;
            Line(tate, 105, tate, 500).draw(4, Palette::White);
        }
        
        
    }
}
