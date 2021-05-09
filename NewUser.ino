void NewUser(){ //uuden käyttäjän luonti
  if (once == 1){ //näppäimistön luonti
    Fitness.close();
    tft.setTextColor(GREEN, BLACK);
    tft.fillScreen(BLACK);
    keypadspace = 7;
    
    for(int j=0; j<10; j++){
      tft.drawRect(keypadspace,200,17,20,CYAN);
      tft.setCursor(keypadspace+3,200+3);
      tft.setTextSize(2);
      tft.setTextColor(GREEN);
      tft.print(kirjain[j]);
      keypadspace += 24;
    }
    
    keypadspace = 19;
    for(int j=10; j<19; j++){
      tft.drawRect(keypadspace,224,17,20,CYAN);
      tft.setCursor(keypadspace+3,224+3);
      tft.setTextSize(2);
      tft.setTextColor(GREEN);
      tft.print(kirjain[j]);
      keypadspace += 24;
    }
    
    keypadspace = 43;
    for(int j=19; j<26; j++){
      tft.drawRect(keypadspace,248,17,20,CYAN);
      tft.setCursor(keypadspace+3,248+3);
      tft.setTextSize(2);
      tft.setTextColor(GREEN);
      tft.print(kirjain[j]);
      keypadspace += 24;
    }  
    
    tft.drawRect(0,272,240,40,CYAN);
    tft.setTextSize(3);
    tft.setCursor(80,280);
    tft.print("ENTER");
  
    tft.setCursor(10, 60);
    once = 0;
  }

  while (true){ //kirjaimen valinta
    Valo();
    TSPoint p = ts.getPoint();
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    
    if (p.z > ts.pressureThreshhold){
      p.x = map(p.x, TS_MAXX, TS_MINX, 0, WIDTH);
      p.y = map(p.y, TS_MAXY, TS_MINY, 0, HEIGHT);
        
  
      if (p.x>7 && p.x<24 && p.y>200 && p.y<220){
        tft.print("Q");
        nickname[user][letter] = 'Q';
        letter++;
        delay(300);
      }
      
      if (p.x>31 && p.x<48 && p.y>200 && p.y<220){
        tft.print("W");
        nickname[user][letter] = 'W';
        letter++;
        delay(300);
      }
      
      if (p.x>55 &&p.x<72 && p.y>200 && p.y<220){
        tft.print("E");
        nickname[user][letter] = 'E';
        letter++;
        delay(300);
      }
      
      if (p.x>79 && p.x<96 && p.y>200 && p.y<224){
        tft.print("R");
        nickname[user][letter] = 'R';
        letter++;
        delay(300);
      }
      
      if (p.x>103 && p.x<120 && p.y>200 && p.y<220){
        tft.print("T");
        nickname[user][letter] = 'T';
        letter++;
        delay(300);
      }
      
      if (p.x>127 && p.x<144 && p.y>200 && p.y<220){
        tft.print("Y");
        nickname[user][letter] = 'Y';
        letter++;
        delay(300);
      }
      
      if (p.x>151 && p.x<168 && p.y>200 && p.y<220){
        tft.print("U");
        nickname[user][letter] = 'U';
        letter++;
        delay(300);
      }
      
      if (p.x>175 && p.x<192 && p.y>200 && p.y<220){
        tft.print("I");
        nickname[user][letter] = 'I';
        letter++;
        delay(300);
      }
      
      if (p.x>199 && p.x<223 && p.y>200 && p.y<220){
        tft.print("O");
        nickname[user][letter] = 'O';
        letter++;
        delay(300);
      }
      
      if (p.x>223 && p.x<240 && p.y>200 && p.y<220){
        tft.print("P");
        nickname[user][letter] = 'P';
        letter++;
        delay(300);
      }
      
      if (p.x>19 && p.x<36 && p.y>224 && p.y<244){
        tft.print("A");
        nickname[user][letter] = 'A';
        letter++;
        delay(300);
      }
      
      if (p.x>43 && p.x<60 && p.y>224 && p.y<244){
        tft.print("S");
        nickname[user][letter] = 'S';
        letter++;
        delay(300);
      }
      
      if (p.x>67 && p.x<84 && p.y>224 && p.y<244){
        tft.print("D");
        nickname[user][letter] = 'D';
        letter++;
        delay(300);
      }
      
      if (p.x>91 && p.x<108 && p.y>224 && p.y<244){
        tft.print("F");
        nickname[user][letter] = 'F';
        letter++;
        delay(300);
      }
      
      if (p.x>115 && p.x<132 && p.y>224 && p.y<244){
        tft.print("G");
        nickname[user][letter] = 'G';
        letter++;
        delay(300);
      }
      
      if (p.x>139 && p.x<156 && p.y>224 && p.y<244){
        tft.print("H");
        nickname[user][letter] = 'H';
        letter++;
        delay(300);
      }
      
      if (p.x>163 && p.x<180 && p.y>224 && p.y<244){
        tft.print("J");
        nickname[user][letter] = 'J';
        letter++;
        delay(300);
      }
      
      if (p.x>187 && p.x<204 && p.y>224 && p.y<244){
        tft.print("K");
        nickname[user][letter] = 'K';
        letter++;
        delay(300);
      }
      
      if (p.x>211 && p.x<228 && p.y>224 && p.y<244){
        tft.print("L");
        nickname[user][letter] = 'L';
        letter++;
        delay(300);
      }
      
      if (p.x>43 && p.x<60 && p.y>248 && p.y<268){
        tft.print("Z");
        nickname[user][letter] = 'Z';
        letter++;
        delay(300);
      }
      
      if (p.x>67 && p.x<84 && p.y>248 && p.y<268){
        tft.print("X");
        nickname[user][letter] = 'X';
        letter++;
        delay(300);
      }
      
      if (p.x>91 && p.x<108 && p.y>248 && p.y<268){
        tft.print("C");
        nickname[user][letter] = 'C';
        letter++;
        delay(300);
      }
      
      if (p.x>115 && p.x<132 && p.y>248 && p.y<268){
        tft.print("V");
        nickname[user][letter] = 'V';
        letter++;
        delay(300);
      }
      
      if (p.x>139 && p.x<156 && p.y>248 && p.y<268){
        tft.print("B");
        nickname[user][letter] = 'B';
        letter++;
        delay(300);
      }
      
      if (p.x>163 && p.x<180 && p.y>248 && p.y<268){
        tft.print("N");
        nickname[user][letter] = 'N';
        letter++;
        delay(300);
      }
       
      if (p.x>187 && p.x<204 && p.y>248 && p.y<268){
        tft.print("M");
        nickname[user][letter] = 'M';
        letter++;
        delay(300);
      }
        
      if (p.x>0 && p.x<WIDTH && p.y>280 && p.y<HEIGHT){
        once = 1;
        return;
      }
    }
    if (letter == 8) letter = 0;
  }
}
