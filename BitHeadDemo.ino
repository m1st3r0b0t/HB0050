#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

void setup() 
{
  tft.init();
  tft.setRotation(3);
}

void loop() 
{
  BitHead2LCD();
  while(1);
}

void BitHead2LCD() //Brute-force TFT bit blit of the HackerBoxes mascot BitHead
{
char *bithead[] = {
"00000000000000000000000000000000000000000000000000001111111111111111111110000000000000000000000000000000000000000000000000000000000",
"00000000000000000000000000000000000000000000000111111111111111111111111111111110000000000000000000000000000000000000000000000000000",
"00000000000000000000000000000000000000000001111111111111111111111111111111111111111000000000000000000000000000000000000000000000000",
"00000000000000000000000000000000000000001111111111111111111111111111111111111111111111100000000000000000000000000000000000000000000",
"00000000000000000000000000000000000001111111111111111111111111111111111111111111111111111100000000000000000000000000000000000000000",
"00000000000000000000000000000000000111111111111111111111111111111111111111111111111111111111100000000000000000000000000000000000000",
"00000000000000000000000000000000011111111111111111111100000000000000000000000111111111111111111000000000000000000000000000000000000",
"00000000000000000000000000000001111111111111111110000000000000000000000000000000011111111111111110000000000000000000000000000000000",
"00000000000000000000000000000111111111111111100011110000011100000001110000001110000011111111111111100000000000000000000000000000000",
"00000000000000000000000000001111111111111111000111111000011110000011111000011110000011111111111111111000000000000000000000000000000",
"00000000000000000000000000111111111111110011000110011100001110000111001100000110000011001111111111111110000000000000000000000000000",
"00000000000000000000000001111111111111100011101110001100000110000110001100000110000111001110111111111111000000000000000000000000000",
"00000000000000000000000011111111111101100011101100001100001110000110001100000110000110000110011111111111110000000000000000000000000",
"00000000000000000000000111111111110001100011101100001100001110000110001100000110000110000110000111111111111000000000000000000000000",
"00000000000000000000001111111111100001100011101110001100000110000110001100000110000111001110000111111111111100000000000000000000000",
"00000000000000000000011111111111100001110011000110011100000110000110001100000110000011001100000111111111111110000000000000000000000",
"00000000000000000000111111111111111000111111000111111000111111100011111000011111100011111100011111111111111111000000000000000000000",
"00000000000000000001111111111111111000011110000011110000111111100001111000011111100001111000011111100111111111100000000000000000000",
"00000000000000000011111111110000000000000000000000000000000000000000000000000000000000000000000000000011111111110000000000000000000",
"00000000000000000111111111100000000000000000000000000000000000000000000000000000000000000000000000000001111111111000000000000000000",
"00000000000000001111111111100001111000001111100001111000000111000000111110000111110000111100000011110000111111111100000000000000000",
"00000000000000001111111111100001111000011101110001111000001111000001110110001110111000111100000111111000011111111110000000000000000",
"00000000000000011111111101110000011000011000110000011000000011000001100011001100011000001100001110011100001111111110000000000000000",
"00000000000000111111111000110000011000011000110000011000000011000001100011001100011000001100001110001100001111111111000000000000000",
"00000000000000111111111000110000011000011000111000011000000011000001100011001100011000001100001100001100001111111111100000000000000",
"00000000000001111111111000110000011000011000110000011000000011000001100011001100011000001100001100001100001111111111100000000000000",
"00000000000001111111111000110000011000011000110000011000000011000001100011001100011000001100001110011100000101111111110000000000000",
"00000000000011111111011001100000111000011101110000011000000011100001110111001110111000001100000110011000001110111111110000000000000",
"00000000000011111110011111100011111110001111100001111110001111111000111110000111110000111111000111111000111111111111111000000000000",
"00000000000111111110000111000001111100000111000000111100000111110000011100000011100000111110000001100000011111011111111000000000000",
"00000000000111111100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001111111100000000000",
"00000000001111111000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001111111100000000000",
"00000000001111111000111110000111110000011100000011100000011111000011111000011110000001111000001111000001111000001111111110000000000",
"00000000001111110001111111000111111000111100000011100000111111100011111100011110000011111100001111000001111000001111111110000000000",
"00000000011111110001100011001110011000001100000001100000110001100110001100000110000011001110000011000000011000000011111110000000000",
"00000000011111100001100011001100011000001100000001100000110001100110001100000110000111000110000011000000011000000011111111000000000",
"00000000011111100001100011001100011100001100000001100000110001100110001110000110000111000110000011000000011000000011111111000000000",
"00000000111111100001100011001100011100001100000001100000110001100110001100000110000111000110000011000000011000000011111111000000000",
"00000000111111100001100011001100011000001100000001100000110001100110001100000110000111000110000011000000011000000011111111100000000",
"00000000111111100001110111001110011000001100000001110000111011100111011100000110000011001100000111000000011000000011111111100000000",
"00000000111111111000111110000111110000111111000111111100011111000011111000011111100011111100011111110001111110001111111111100000000",
"00000001111111110000011100000011100000111111000011111000001110000001110000011111100000111000001111100001111100001111111111100000000",
"00000001111110000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011111100000000",
"00000001111110000011000000001000000001000000001000000000100000000100000001100000000100000000110000000010000000010000011111110000000",
"00000001111100001111100001111000000111110000111100000111100000111100000011111000011111000011111000011110000001110000001111110000000",
"00000001111100001101110000111000001110111000111100000111100000011100000111011000111011100011011100011110000001110000011111110000000",
"00000011111100011100110000011000001100011000001100000001100000001100000110001100110001100110001100000110000000110000011111110000000",
"00000011111100011000111000011000001100011000001100000001100000001100001110001100110001100110001110000110000000110000011111110000000",
"00000011111100011000111000011000011100011000001100000001100000001100001110001100110001100110001110000110000000110000011111110000000",
"00000011111000011000111000011000001100011000001100000001100000001100001110001100110001100110001110000110000000110000011111111000000",
"00000011111000011100110000011000001100011000001100000001100000001100000110001100110001100110001100000110000000110000011111111000000",
"00000011111100001101110000011100001110111000011100000001110000001110000111011100111011100111011100000111000000111000011111111000000",
"00000011111110001111100001111110000111110001111111000111111000111111000011111000011111000011111000011111100011111110001111111000000",
"00000011111000000011000000000000000011000000000000000000000000000000000001100000001100000000110000000000000000000000000111111000000",
"00000011111000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111111000000",
"00000011111001110000001110000001111000001111000000110000000111000000111000000011000000011100000011100000011100000001100111111000000",
"00000111110011111000011110000011111100011111100001111000001111000001111110001111000001111110000111100000111111000111100011111000000",
"00000111110110011100000110000111001100011001100000111000000011000011100110000011000001100111000001100001110011000001100011111000000",
"00000111111110001100000110000110001110111000110000011000000011000011000110000011000001100011000001100001100011000001100011111000000",
"00000111111110001100000110000110001110110000110000011000000011000011000111000011000011100011000001100001100011100001100011111000000",
"00000111111110001100000110000110001110110000110000011000000011000011000111000011000011100011000001100001100011100001100011111000000",
"00000111111110001100000110000110001110111000110000011000000011000011000111000011000001100011000001100001100011000001100011111000000",
"00000111110110001100000110000111001100011001110000011000000011000011100110000011000001100111000001100001110011000001100011111000000",
"00000111110111111000011111100011111100011111100011111100001111110001111110001111110001111110000111111000111111000111111111111000000",
"00000111110011111000011111100001111000001111000011111110001111110000111100001111110000111100001111111000011110000111111111111000000",
"00000111110000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011111000000",
"00000111110000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111111000000",
"00000111110000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111111000000",
"00000111110000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111111000000",
"00000111111000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111111000000",
"00000111111000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111111000000",
"00000111111000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111111000000",
"00000111111000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111111000000",
"00000111111000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111111000000",
"00000111111000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001111110000000",
"00000111111000000010000000000000000111111100000000000000000000000000000000000000000000000000000000000000000000000000001111110000000",
"00000011111100000110000000000001111111111111110000000000000000000000000000000000011111111111111000000000000000100000001111110000000",
"00000011111100001110000000000111111111111111111100000000000000000000000000000001111111111111111111000000000001100000001111110000000",
"00000011111100001110000000011111111111111111111111000000000000000000000000000111111111111111111111110000000001100000011111110000000",
"00000011111100001100000000111111111111111111111111100000000000000000000000001111111111111111111111111100000001110000011111110000000",
"00000011111100011100000001111111111111111111111111110000000000000000000000011111111111111111111111111110000001110000011111100000000",
"00000011111110011100000011111111111111111111111111111000000000000000000000111111111111111111111111111111000001110000011111100000000",
"00000011111110011000000111111111111111111111111111111100000000000000000001111111111111111111111111111111100001110000111111100000000",
"00000011111110011000001111111111111111111111111111111110000000000000000001111111111111111111111111111111110001111000111111100000000",
"00000011111111011000011111111111111111111111111111111110000000000000000001111111111111111111111111111111110001111000111111100000000",
"00000011111111111000011111111111111111111111111111111111000000000000000001111111111111111111111111111111111001111001111111000000000",
"00000001111111111000111111111111111111111111111111111111000000000000000011111111111111111111111111111111111001111001111111000000000",
"00000001111111110000111111111111111111111111111111111111000000000000000011111111111111111111111111111111111101111011111111000000000",
"00000001111111110000111111111111111111111111111111111111000000000000000011111111111111111111111111111111111101111011111110000000000",
"00000001111111110001111111111111111111111111111111111110000000000000000001111111111111111111111111111111111100111111111110000000000",
"00000001111111110001111111111111111111111111111111111110000000000000000001111111111111111111111111111111111100111111111110000000000",
"00000001111111110000111111111111111111111111111111111100000000000000000001111111111111111111111111111111111100111111111100000000000",
"00000000111111100000111111111111111111111111111111111000000000000000000001111111111111111111111111111111111100111111111100000000000",
"00000000111111100000111111111111111111111111111111110000000000000000000001111111111111111111111111111111111100011111111100000000000",
"00000000111111100000111111111111111111111111111111100000000000000000000000111111111111111111111111111111111100011111111000000000000",
"00000000111111100000011111111111111111111111111111100000000000000000000000111111111111111111111111111111111000011111111000000000000",
"00000000111111100000011111111111111111111111111110000000000000000000000000011111111111111111111111111111111000001111110000000000000",
"00000000111111100000001111111111111111111111111100000000000000000000000000001111111111111111111111111111111000001111110000000000000",
"00000000111111100000000111111111111111111111111000000000000000000000000000000111111111111111111111111111110000001111111000000000000",
"00000000111111100000000111111111111111111111110000000000000000000000000000000011111111111111111111111111100000000111111000000000000",
"00000000111111100000000011111111111111111111000000000000000000100000000000000001111111111111111111111111100000000111111100000000000",
"00000000111111100000000001111111111111111100000000000000000100110000000000000000011111111111111111111111000000000011111100000000000",
"00000000111111100000000000111111111111110000000000000000000110110000000000000000000111111111111111111100000000000011111110000000000",
"00000000111111100000000000011111111110000000000000000000001110111000000000000000000001111111111111110000000000000001111110000000000",
"00000000111111100000000000001110000000000000000000000000001110111100000000000000000000000111111110000000000000000001111110000000000",
"00000000111111100000000000000000000000000000000000000000011110111100000000000000000000000000000000000000000000000000111110000000000",
"00000000111111110000000000000000000000000000000000000000011110111110000000000000000000000000000000000000000000000000111110000000000",
"00000000011111110000000000000000000000000000000000000000111110111110000000000000000000000000000000000000000000000001111110000000000",
"00000000011111110000000000000000000000000000000000000000111110111110000000000000000000000000000000000000000000000001111110000000000",
"00000000001111111000000000000000000000000000000000000001111110111111000000000000000000000000000000000000000000000011111110000000000",
"00000000001111111000000000000000000000000000000000000001111111111111000000000000000000000000000000000000000000000011111100000000000",
"00000000000111111100000000000000000000000000000000000011111110111111000000000000000000000000000000000000000000000111111100000000000",
"00000000000111111110000000000000000000000000000000000011111110111111000000000000000000000000000000000000000000001111111000000000000",
"00000000000011111111000000000000000000000000000000000011111110111111000000000000000000000000000000000000000000011111111000000000000",
"00000000000001111111110000000000001100000000000000000011111100111111000000000000000000000000000110000000000000111111110000000000000",
"00000000000000111111111111111111111110000000000000000011111100111111000000000000000000000000011111000000000001111111110000000000000",
"00000000000000011111111111111111111110000000000000000011111100111111000000000000000000000001111111100000000011111111100000000000000",
"00000000000000001111111111111111111111000000000000000011111000111111000000000000000000000011111111111100011111111111000000000000000",
"00000000000000000111111111111111111111000000000000000011110000011111000000000000000000000111111111111111111111111110000000000000000",
"00000000000000000001111111111111111111000000000000000001100000001111000000000000000000000111111111111111111111111100000000000000000",
"00000000000000000000111111111111111111000000000000000000000000000110000000000000000000001111111111111111111111111000000000000000000",
"00000000000000000000001111111111111111000000000000000000000000000000000000000000000000011111110111111111111111110000000000000000000",
"00000000000000000000000011111100011111000000000000000000000000000000000000000000000000011111100000111111111111000000000000000000000",
"00000000000000000000000000000000011111000110000000000000000000000000000000000000000000011111100000000001110000000000000000000000000",
"00000000000000000000000000000000011111101111000000000000000000000000000000000000000000111111100000000000000000000000000000000000000",
"00000000000000000000000000000000011111101111011100000000000000000000000000000011000000111111000000000000000000000000000000000000000",
"00000000000000000000000000000000011111101111111100001000000000100000001000000111000000111111000000000000000000000000000000000000000",
"00000000000000000000000000000000011111101111111100011100000001100000011100000111000000111111000000000000000000000000000000000000000",
"00000000000000000000000000000000011111111111111100011110000001100000011110000111000000111111000000000000000000000000000000000000000",
"00000000000000000000000000000000011111111110111100011110000011100000011110000111000000111111000000000000000000000000000000000000000",
"00000000000000000000000000000000011111111110111100011110000011100000011110000111000000111110000000000000000000000000000000000000000",
"00000000000000000000000000000000011111111100111100011110000011100000011110000111000000111110000000000000000000000000000000000000000",
"00000000000000000000000000000000011111111100111100011110000011100000011110000111000011111110000000000000000000000000000000000000000",
"00000000000000000000000000000000011111111100111000011110000011100000011110000111100111111110000000000000000000000000000000000000000",
"00000000000000000000000000000000001111111100111000011110000011100000011110000111100111111110000000000000000000000000000000000000000",
"00000000000000000000000000000000001111111100111000011110000011100000001110000111101111111110000000000000000000000000000000000000000",
"00000000000000000000000000000000000111111110111000011110000011100000001110000111111111111110000000000000000000000000000000000000000",
"00000000000000000000000000000000000111111111111000001110000011100000001110000011111111111100000000000000000000000000000000000000000",
"00000000000000000000000000000000000011111111111000001110000011100000001110000011111111111100000000000000000000000000000000000000000",
"00000000000000000000000000000000000001111111111110011110000011110000001111000111111111111000000000000000000000000000000000000000000",
"00000000000000000000000000000000000000111111111111111110000011110000011111111111111111111000000000000000000000000000000000000000000",
"00000000000000000000000000000000000000011111111111111110000111111111111111111111111111110000000000000000000000000000000000000000000",
"00000000000000000000000000000000000000000111111111111111111111111111111111111111111111000000000000000000000000000000000000000000000",
"00000000000000000000000000000000000000000011111111111111111111111111111111111111111110000000000000000000000000000000000000000000000",
"00000000000000000000000000000000000000000000011111111111111111111111111111111111111000000000000000000000000000000000000000000000000",
"00000000000000000000000000000000000000000000000001111111111111111111111111111111000000000000000000000000000000000000000000000000000",
"00000000000000000000000000000000000000000000000000000000111110011111111100000000000000000000000000000000000000000000000000000000000"};

const int bithead_width = 131;
const int bithead_height = 147;
    
  tft.fillScreen(ILI9341_BLACK);
  tft.setCursor(0, 0);
  tft.setTextColor(ILI9341_CYAN);
  tft.setTextSize(4);
  tft.println(" HackerBoxes");

  for (int y=0; y < bithead_height; y++)
  {
    for (int x=0; x < bithead_width; x++)
    {
      if (bithead[y][x] == '1')
      { 
        tft.drawPixel(x+100, y+55, ILI9341_YELLOW);
      }
    }
  }
}