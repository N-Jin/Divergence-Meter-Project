/*  GPLv3 License
*  
*  	Copyright (c) Divergence Meter Project by waicool20
*  	
*  This program is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*  
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*  
*  You should have received a copy of the GNU General Public License
*  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "divergenceEditMode.h"

#include <stdint.h>

#include "../DivergenceMeter.h"
#include "../settings.h"
#include "../constants.h"
#include "../util/display.h"

/* Variables */

uint8_t currentTube = 0;

/* Divergence Edit Mode */

void divergenceEditMode_run() {
  if (justEnteredMode[DIVERGENCE_EDIT_MODE]) {
    currentTube = 0;
    display.tube[TUBE1] = 0;
    display.tube[TUBE2] = BLANK;
    display.tube[TUBE3] = BLANK;
    display.tube[TUBE4] = BLANK;
    display.tube[TUBE5] = BLANK;
    display.tube[TUBE6] = BLANK;
    display.tube[TUBE7] = BLANK;
    display.tube[TUBE8] = BLANK;
    display_update();
    justEnteredMode[DIVERGENCE_EDIT_MODE] = false;
  }

  if (buttonIsPressed[BUTTON2]) {
    if (display.tube[currentTube] == BLANK) {
      display.tube[currentTube] = 9;
    } else if (display.tube[currentTube] > 0) {
      display.tube[currentTube]--;
    }
    display_update();
    DivergenceMeter_delayCS(s2cs(0.2));
  } else if (buttonIsPressed[BUTTON3]) {
    if (display.tube[currentTube] < 9) {
      display.tube[currentTube]++;
    } else if (display.tube[currentTube] == 9) {
      display.tube[currentTube] = BLANK;
    }
    display_update();
    DivergenceMeter_delayCS(s2cs(0.2));
  }

  if (buttonShortPressed[BUTTON4]) {
    if (currentTube < 7) {
      if (currentTube == TUBE1) {
        display.tube[TUBE2] = RDP;
        currentTube = TUBE3;  //SKIP TUBE2
      } else {
        currentTube++;
      }
      display.tube[currentTube] = 0;
      display_update();
    } else {
      currentTube = 0;
      DivergenceMeter_switchMode(DIVERGENCE_MODE);
      display_saveState();
      DivergenceMeter_rollWorldLine(false);
      display_restoreState();
      display_update();
    }
    DivergenceMeter_delayCS(s2cs(0.2));
  } else if (buttonShortPressed[BUTTON5]) {
    if (currentTube > 0) {
      display.tube[currentTube] = BLANK;
      if (currentTube == TUBE3) {
        currentTube = 1;
      } else {
        currentTube--;
      }
      display_update();
    }
    DivergenceMeter_delayCS(s2cs(0.2));
  }
}