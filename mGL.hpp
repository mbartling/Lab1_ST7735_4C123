#define ST7735_LCD_WIDTH  128
#define ST7735_LCD_HEIGHT 160

const float x_maxf_c 128.0;
const float y_maxf_c 160.0;

const float x_maxf  256.0;
const float y_maxf  320.0;
const float x_minf -256.0;
const float y_minf -320.0;

class Point{
private:
  float x, y;

public:
  Point(float x, float y): _x(x), _y(y){}
  Point();
  ~Point();

  Point(const Point& that) { copy(that);}

  Point& operator=(const Point& rhs){
    if(this != &rhs) copy(rhs);
    return *this;
  }

private:
  copy(const Point& that){
    x = that.x;
    y = that.y;
  }
};

class Line{
private:
  Point p1, p2;
  uint8_t r,g,b;
public:
  Line();
  Line(Point p1, Point p2): p1(p1), p2(p2){
    r = g = b = 0;
  }

  
};
