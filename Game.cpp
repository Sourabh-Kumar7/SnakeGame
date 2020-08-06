#include<bits/stdc++.h>
using namespace std;

class Snake
{
  private:
      int x,y;
    
  public:
  void setup();
  void draw();
  void input();
  void logic();
  
  
};

int main()
{
  Snake s;
  s.setup();
  while(!gameOver)
  {
    s.draw();
    s.input();
    s.logic();
  }
  return 0;
}
