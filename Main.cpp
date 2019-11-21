# include <Siv3D.hpp>


// 白の場合は1 水色の場合は1
int button = 0;
int saba = 0;
int asobi = 10 + 10 * saba;
int asobi2 = 10 + 10 * saba;

// 石の生成処理
int  block(int saba=1, int na = asobi, int na1 = asobi2) {
    if (button == 0)
    {
      Circle(asobi,asobi2, 15).draw(); //　buttonに1という数字を入れたら白を置く
    }
    else if (button == 1) // buttonに2という数字をを入れたら青を置く
    {
      Circle(asobi, asobi2, 15).draw(Palette::Skyblue); // 青の石
    }
    else
    {
    // 何も表示しない
    }
    return 0;
}

void Main() {
   
    while (System::Update())
    {
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
         // 初期の石の位置
//         Circle(395, 275, 15).draw();
//         Circle(445, 325, 15).draw();
//         Circle(445, 275, 15).draw(Palette::Skyblue);
//         Circle(395,325,15).draw(Palette::Skyblue);

        
        // やること
        // buttton に値を1か2か入れる
        //　変数sabaとsaba2に8までの値を指定できるようにする。
        //関数呼び出し
        
        //        block();
        
        
        
        
        
        
        
        }
    }


