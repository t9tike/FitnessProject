void Users(){ //käyttäjävalikko
  while (true){
    if (once == 1){
      tft.fillScreen(BLACK);
      Kello();
      tft.setTextSize(3);

      // Käyttäjä nimien haku muistikortilta
      letter = 0;
      Fitness = SD.open("NAME0");
      while (Fitness.available()) { // muistikortti on saatavilla
        nickname[0][letter] = Fitness.read();
        letter++;
      }
      Fitness.close();
      letter = 0;

      Fitness = SD.open("NAME1");
      while (Fitness.available()) { // muistikortti on saatavilla
        nickname[1][letter] = Fitness.read();
        letter++;
      }
      Fitness.close();
      letter = 0;

      Fitness = SD.open("NAME2");
      while (Fitness.available()) { // muistikortti on saatavilla
        nickname[2][letter] = Fitness.read();
        letter++;
      }
      Fitness.close();
      letter = 0;

      Fitness = SD.open("NAME3");
      while (Fitness.available()) { // muistikortti on saatavilla
        nickname[3][letter] = Fitness.read();
        letter++;
      }
      Fitness.close();
      letter = 0;

      Fitness = SD.open("NAME4");
      while (Fitness.available()) { // muistikortti on saatavilla
        nickname[4][letter] = Fitness.read();
        letter++;
      }
      Fitness.close();
      letter = 0;

      Fitness = SD.open("NAME5");
      while (Fitness.available()) { // muistikortti on saatavilla
        nickname[5][letter] = Fitness.read();
        letter++;
      }
      Fitness.close();
      letter = 0;

      Fitness = SD.open("NAME6");
      while (Fitness.available()) { // muistikortti on saatavilla
        nickname[6][letter] = Fitness.read();
        letter++;
      }
      Fitness.close();
      letter = 0;

      // käyttäjä valikko
      tft.drawRect(0,30,WIDTH,40,CYAN);
      tft.setCursor(10,40);
      if (nickname[0][7] == 'r' && nickname[0][2] == 'w') tft.setTextColor(LIGHTGREY, BLACK);
      else{
        tft.setTextColor(WHITE, BLACK);
        tft.fillRect(200,31,39,38,RED);
        for (int i=0; i<8; i++) tft.drawLine(210, 35+i, 230, 58+i, WHITE); //for looppi kauttaviivan piirtämiseen //X Y X Y
        for (int i=0; i<8; i++) tft.drawLine(230, 35+i, 210, 58+i, WHITE); 
      }
      tft.print(nickname[0]);
      
    
      tft.drawRect(0,70,WIDTH,40,CYAN);
      tft.setCursor(10,80);
      if (nickname[1][7] == 'r' && nickname[1][2] == 'w') tft.setTextColor(LIGHTGREY, BLACK);
      else{
        tft.setTextColor(WHITE, BLACK);
        tft.fillRect(200,71,39,38,RED);
        for (int i=0; i<8; i++) tft.drawLine(210, 75+i, 230, 98+i, WHITE); 
        for (int i=0; i<8; i++) tft.drawLine(230, 75+i, 210, 98+i, WHITE);
      }
      tft.print(nickname[1]);
      
      tft.drawRect(0,110,WIDTH,40,CYAN);
      tft.setCursor(10,120);
      if (nickname[2][7] == 'r' && nickname[2][2] == 'w') tft.setTextColor(LIGHTGREY, BLACK);
      else{
        tft.setTextColor(WHITE, BLACK);
        tft.fillRect(200,111,39,38,RED);
        for (int i=0; i<8; i++) tft.drawLine(210, 115+i, 230, 138+i, WHITE); 
        for (int i=0; i<8; i++) tft.drawLine(230, 115+i, 210, 138+i, WHITE);
      }
      tft.print(nickname[2]);
    
      tft.drawRect(0,150,WIDTH,40,CYAN);
      tft.setCursor(10,160);
      if (nickname[3][7] == 'r' && nickname[3][2] == 'w') tft.setTextColor(LIGHTGREY, BLACK);
      else{
        tft.setTextColor(WHITE, BLACK);
        tft.fillRect(200,151,39,38,RED);
        for (int i=0; i<8; i++) tft.drawLine(210, 155+i, 230, 178+i, WHITE); 
        for (int i=0; i<8; i++) tft.drawLine(230, 155+i, 210, 178+i, WHITE);
      }
      tft.print(nickname[3]);
    
      tft.drawRect(0,190,WIDTH,40,CYAN);
      tft.setCursor(10,200);
      if (nickname[4][7] == 'r' && nickname[4][2] == 'w') tft.setTextColor(LIGHTGREY, BLACK);
      else{
        tft.setTextColor(WHITE, BLACK);
        tft.fillRect(200,191,39,38,RED);
        for (int i=0; i<8; i++) tft.drawLine(210, 195+i, 230, 218+i, WHITE); 
        for (int i=0; i<8; i++) tft.drawLine(230, 195+i, 210, 218+i, WHITE);
      }
      tft.print(nickname[4]);
    
      tft.drawRect(0,230,WIDTH,40,CYAN);
      tft.setCursor(10,240);
      if (nickname[5][7] == 'r' && nickname[5][2] == 'w') tft.setTextColor(LIGHTGREY, BLACK);
      else{
        tft.setTextColor(WHITE, BLACK);
        tft.fillRect(200,231,39,38,RED);
        for (int i=0; i<8; i++) tft.drawLine(210, 235+i, 230, 258+i, WHITE); 
        for (int i=0; i<8; i++) tft.drawLine(230, 235+i, 210, 258+i, WHITE);
      }
      tft.print(nickname[5]);
    
      tft.drawRect(0,270,WIDTH,40,CYAN);
      tft.setCursor(10,280);
      if (nickname[6][7] == 'r' && nickname[6][2] == 'w') tft.setTextColor(LIGHTGREY, BLACK);
      else{
        tft.setTextColor(WHITE, BLACK);
        tft.fillRect(200,271,39,38,RED);
        for (int i=0; i<8; i++) tft.drawLine(210, 275+i, 230, 298+i, WHITE); 
        for (int i=0; i<8; i++) tft.drawLine(230, 275+i, 210, 298+i, WHITE);
      }
      tft.print(nickname[6]);
      
      once = 0;
    }
    Kello();
  
    TSPoint p = ts.getPoint();
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
  
    if (p.z > ts.pressureThreshhold){ //painalluksen voimakkuus > painetunnistus
      p.x = map(p.x, TS_MAXX, TS_MINX, 0, WIDTH); //ottaa pikselikoordinaatin x:lle
      p.y = map(p.y, TS_MAXY, TS_MINY, 0, HEIGHT);  //ottaa pikselikoordinaatin y:lle
  
      // käyttäjän valinta
      if (p.x>0 && p.x<200 && p.y>30 && p.y<70 && nickname[0][7] != 'r' && nickname[0][2] != 'w'){
        user = 0;
        once = 1;
        return;
      }

      if (p.x>0 && p.x<200 && p.y>70 && p.y<110 && nickname[1][7] != 'r' && nickname[1][2] != 'w'){
        user = 1;
        once = 1;
        return;
      }
  
      if (p.x>0 && p.x<200 && p.y>110 && p.y<150 && nickname[2][7] != 'r' && nickname[2][2] != 'w'){
        user = 2;
        once = 1;
        return;
      }
        
      if (p.x>0 && p.x<200 && p.y>150 && p.y<190 && nickname[3][7] != 'r' && nickname[3][2] != 'w'){
        user = 3;
        once = 1;
        return;
      }
      
      if (p.x>0 && p.x<200 && p.y>190 && p.y<230 && nickname[4][7] != 'r' && nickname[4][2] != 'w'){
        user = 4;
        once = 1;
        return;
      }
        
      if (p.x>0 && p.x<200 && p.y>230 && p.y<270 && nickname[5][7] != 'r' && nickname[5][2] != 'w'){
        user = 5;
        once = 1;
        return;
      }
  
      if (p.x>0 && p.x<200 && p.y>270 && p.y<310 && nickname[6][7] != 'r' && nickname[6][2] != 'w'){
        user = 6;
        once = 1;
        return;
      }
      
      //käyttäjän poistaminen
      if (p.x>200 && p.x<WIDTH && p.y>30 && p.y<70 && nickname[0][7] != 'r' && nickname[0][2] != 'w'){
        SD.remove("NAME0");
        SD.remove("USER0");
        Fitness = SD.open("NAME0", FILE_WRITE);
        Fitness.print(nickname2);
        Fitness.close();
        once = 1;
        continue;
      }
      
      if (p.x>200 && p.x<WIDTH && p.y>70 && p.y<110 && nickname[1][7] != 'r' && nickname[1][2] != 'w'){
        SD.remove("NAME1");
        SD.remove("USER1");
        Fitness = SD.open("NAME1", FILE_WRITE);
        Fitness.print(nickname2);
        Fitness.close();
        once = 1;
        continue;
      }
      if (p.x>200 && p.x<WIDTH && p.y>110 && p.y<150 && nickname[2][7] != 'r' && nickname[2][2] != 'w'){
        SD.remove("NAME2");
        SD.remove("USER2");
        Fitness = SD.open("NAME2", FILE_WRITE);
        Fitness.print(nickname2);
        Fitness.close();
        once = 1;
        continue;
      }
      
      if (p.x>200 && p.x<WIDTH && p.y>150 && p.y<190 && nickname[3][7] != 'r' && nickname[3][2] != 'w'){
        SD.remove("NAME3");
        SD.remove("USER3");
        Fitness = SD.open("NAME3", FILE_WRITE);
        Fitness.print(nickname2);
        Fitness.close();
        once = 1;
        continue;
      }
      
      if (p.x>200 && p.x<WIDTH && p.y>190 && p.y<230 && nickname[4][7] != 'r' && nickname[4][2] != 'w'){
        SD.remove("NAME4");
        SD.remove("USER4");
        Fitness = SD.open("NAME4", FILE_WRITE);
        Fitness.print(nickname2);
        Fitness.close();
        once = 1;
        continue;
      }
      
      if (p.x>200 && p.x<WIDTH && p.y>230 && p.y<270 && nickname[5][7] != 'r' && nickname[5][2] != 'w'){
        SD.remove("NAME5");
        SD.remove("USER5");
        Fitness = SD.open("NAME5", FILE_WRITE);
        Fitness.print(nickname2);
        Fitness.close();
        once = 1;
        continue;
      }
      
      if (p.x>200 && p.x<WIDTH && p.y>270 && p.y<310 && nickname[6][7] != 'r' && nickname[6][2] != 'w'){
        SD.remove("NAME6");
        SD.remove("USER6");
        Fitness = SD.open("NAME6", FILE_WRITE);
        Fitness.print(nickname2);
        Fitness.close();
        once = 1;
        continue;
      }
  
      // uusi käyttäjä nimi
      if (p.x>0 && p.x<WIDTH && p.y>30 && p.y<70 && nickname[0][7] == 'r' && nickname[0][2] == 'w'){
        for (int i=0; i<8; i++) nickname[0][i] = ' ';
        user = 0;
        letter = 0;
        once = 1;
        NewUser();
        SD.remove("NAME0");
        Fitness = SD.open("NAME0", FILE_WRITE);
        Fitness.print(nickname[0]);
        Fitness.close();
      }
  
      if (p.x>0 && p.x<WIDTH && p.y>70 && p.y<110 && nickname[1][7] == 'r' && nickname[1][2] == 'w'){
        for (int i=0; i<8; i++) nickname[1][i] = ' ';
        user = 1;
        letter = 0;
        once = 1;
        NewUser();
        SD.remove("NAME1");
        Fitness = SD.open("NAME1", FILE_WRITE);
        Fitness.print(nickname[1]);
        Fitness.close();
      }
  
      if (p.x>0 && p.x<WIDTH && p.y>110 && p.y<150 && nickname[2][7] == 'r' && nickname[2][2] == 'w'){
        for (int i=0; i<8; i++) nickname[2][i] = ' ';
        user = 2;
        letter = 0;
        once = 1;
        NewUser();
        SD.remove("NAME2");
        Fitness = SD.open("NAME2", FILE_WRITE);
        Fitness.print(nickname[2]);
        Fitness.close();
      }
        
      if (p.x>0 && p.x<WIDTH && p.y>150 && p.y<190 && nickname[3][7] == 'r' && nickname[3][2] == 'w'){
        for (int i=0; i<8; i++) nickname[3][i] = ' ';
        user = 3;
        letter = 0;
        once = 1;
        NewUser();
        SD.remove("NAME3");
        Fitness = SD.open("NAME3", FILE_WRITE);
        Fitness.print(nickname[3]);
        Fitness.close();
      }
      
      if (p.x>0 && p.x<WIDTH && p.y>190 && p.y<230 && nickname[4][7] == 'r' && nickname[4][2] == 'w'){
        for (int i=0; i<8; i++) nickname[4][i] = ' ';
        user = 4;
        letter = 0;
        once = 1;
        NewUser();
        SD.remove("NAME4");
        Fitness = SD.open("NAME4", FILE_WRITE);
        Fitness.print(nickname[4]);
        Fitness.close();
      }
        
      if (p.x>0 && p.x<WIDTH && p.y>230 && p.y<270 && nickname[5][7] == 'r' && nickname[5][2] == 'w'){
        for (int i=0; i<8; i++) nickname[5][i] = ' ';
        user = 5;
        letter = 0;
        once = 1;
        NewUser();
        SD.remove("NAME5");
        Fitness = SD.open("NAME5", FILE_WRITE);
        Fitness.print(nickname[5]);
        Fitness.close();
      }
  
      if (p.x>0 && p.x<WIDTH && p.y>270 && p.y<310 && nickname[6][7] == 'r' && nickname[6][2] == 'w'){
        for (int i=0; i<8; i++) nickname[6][i] = ' ';
        user = 6;
        letter = 0;
        once = 1;
        NewUser();
        SD.remove("NAME6");
        Fitness = SD.open("NAME6", FILE_WRITE);
        Fitness.print(nickname[6]);
        Fitness.close();
      }
    }
  }
}
