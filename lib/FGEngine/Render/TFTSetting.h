extern void setup_tft7735(void);

enum SHAPE{
  CIRCLE = 1,
  RECTANGLE
};

class Player{
    unsigned char xPos = 0;
    unsigned char yPos = 0;
    unsigned char shape = CIRCLE;
    unsigned char width = 10;
    unsigned char height = 10;
    unsigned char radius = 5;
    unsigned short color = TFT_RED;

  public: 
    void setPosition(unsigned char x_pos, unsigned char y_pos);
    void setColor(unsigned short input_color);
    void setShape(unsigned char input_shape);
    void setSize(unsigned char input_width, unsigned char input_height, unsigned char input_radius, ...);
    
    void addComponent();
};