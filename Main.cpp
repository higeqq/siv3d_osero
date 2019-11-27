# include <Siv3D.hpp>
void Waku() {
        int yoko = 100;
        int tate = 220;
          //　オセロの外枠
        Rect(220, 100, 400, 400)
          .drawFrame(3, 0);
          //　横線の処理
        for (int i = 0; i < 8; i++)
        {
          yoko += 50;
          Line(225, yoko, 615, yoko).draw(4, Palette::White);
        }
        for (int s = 0; s < 8; s++)
        {
          tate += 50;
          Line(tate, 105, tate, 500).draw(4, Palette::White);
        }
}
//int test(int x = 245, int y = 125) {
     // この値に　+=50　をしていく
     // この値に　+=50　をしていく
//    Circle(x, y, 15).draw();
//    return 0;
//}

//int Sikaku(int x = 220, int y = 120) {
//          for (int ss = 0; ss < 8; ss++)
//          {
//            Rect(x, 60, 20, 20).draw();
//            x += 50;
//            Rect(180, y, 20, 20).draw();
//              y += 50;
//           }
//    return 0;
//}
void Main()
{
    while (System::Update())
    {
        Waku();
        
        
        
        }
    }

    

