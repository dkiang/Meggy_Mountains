/*
  Meggy_Mountains.ino
 
 Scrolling landscape for The Meggy Jr Simplified Library (MJSL)
  from the Meggy Jr RGB library for Arduino
   
 Scroll mountains randomly.
   
   
 
 Version 1.25 - 12/2/2008
 Copyright (c) 2008 Windell H. Oskay.  All right reserved.
 http://www.evilmadscientist.com/
 
 This library is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this library.  If not, see <http://www.gnu.org/licenses/>.
 	  
 */

 
 
 
 

/*
 * Adapted from "Blink,"  The basic Arduino example.  
 * http://www.arduino.cc/en/Tutorial/Blink
 */

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

int mountains[8] = {0, 0, 0, 0, 0, 0, 0, 0}; // Create initial array with all zeros.
int SLOPE = 3; // This determines how much the elevation changes between columns.
int MAXHEIGHT = 4; // This determines the maximum height of the mountains.

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
}

void loop()                     // run over and over again
{
  DrawMountains();
  UpdateMountains();
  DisplaySlate();
  delay(100);
  ClearSlate();
}

void DrawMountains()
{
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < mountains[i]; j++)
    {
      DrawPx(i,j,Green);
    }
  }
}

void UpdateMountains()
{
  for (int i = 0; i < 7; i++) // copy everything to the right
  {
    mountains[i] = mountains[i+1];
  }
  // look at the last amount and create a new slope no more than two high.
  int lastHeight = mountains[7];
  int newHeight = random(SLOPE); // generate an elevation change
  if (random(10) > 4) // Half the time
    mountains[7] += newHeight; // add 
  else
    mountains[7] -= newHeight; // or subtract
  if (mountains[7] > MAXHEIGHT) // correct for out of bounds errors
    mountains[7] = MAXHEIGHT;
  if (mountains[7] < 0)
    mountains[7] = 0;
}

/*
void UpdateMountains()
{
  for (int i = 0; i < 7; i++) // copy everything to the right
  {
    mountains[i] = mountains[i+1];
  }
  mountains[7] = random(8);
  if (mountains[7] > 7) // correct for out of bounds errors
    mountains[7] = 7;
  if (mountains[7] < 0)
    mountains[7] = 0;
}
*/
