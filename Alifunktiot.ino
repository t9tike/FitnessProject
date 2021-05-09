void Kello(){             //kellon alifunktio
  aikaNyt = millis();     //tämänhetkinen aika

  if (aikaNyt>tapahtuma){         //jos aika suurempi kuin tapahtuma
    second++;                     //lisää sekunnin 
    tapahtuma=tapahtuma+1000;     //lisää tapahtumaa sekunnilla

    if (second==60){  //jos sekuntti on 59 lisää minuutin ja nollaa sekunnin
      minute++;
      second=0;

      if (minute==60){  //jos minuutti on 59 lisää tunnin ja nollaa minuutin
        hour++;
        minute=0;

        if (hour==24){  //jos tunnit 23 lisää päivän
          day++;
          hour=0;

          if (day==31){ //jos päivät 30 lisää kuukauden
            month++;
            day=1;

            if (month==13){ //jos kuukausi 12 lisää vuoden
              year++;
              month=1;
            }
          }
        }
      }
    }

    tft.setTextColor(GREEN, BLACK); //määrittää tekstin värin ja tekstin taustan värin
    tft.setTextSize(2); //määrittää tekstin koon
    tft.setCursor(7, 5);  //asettaa tekstin tiettyyn kohtaan näytöllä x ja y arvoilla
    
    if (hour < 10) tft.print("0");  //jos tuntimäärä on alle 10 lisää puuttuvan nolla eteen
    
    tft.print(hour);  //tulostaa tuntimäärän näytölle
    tft.print(".");   //tulostaa pisteen tunnin jälkeen
    
    if (minute < 10) tft.print("0");  
    
    tft.print(minute);
    tft.print(".");
    
    if (second < 10) tft.print("0");
    
    tft.print(second);
    tft.setCursor(115, 5);
    
    if (day < 10) tft.print("0");
    
    tft.print(day);
    tft.print(".");
    
    if (month < 10) tft.print("0");
    
    tft.print(month);
    tft.print(".");
    tft.print(year);

    if (hour == 0 && minute == 0 && second == 0){ // kaloreiden nollaaminen keskiyöllä
      SD.remove("USER0");
      SD.remove("USER1");
      SD.remove("USER2");
      SD.remove("USER3");
      SD.remove("USER4");
      SD.remove("USER5");
      SD.remove("USER6");
    }
  }
  
  Valo();
}

void GUI(){ //alkunäytön tulostus
  if (once == 1) {
    Kello();  //kutsuu kellon

    tft.setTextSize(3); 
    tft.setCursor(10, 30);
    tft.print("Nickname");

    tft.setTextSize(5);
    tft.setCursor(140, 120);
    tft.print(setti); //
    
    for (int i=0; i<3; i++) tft.drawLine(170, 155+i, 190, 115+i, RED); //for looppi kauttaviivan piirtämiseen
    
    tft.setCursor(200, 120);
    tft.print(3);
    
    tft.setTextSize(8);
    tft.setCursor(64, 195);
    tft.print(laskuri);
    
    for (int i=0; i<3; i++) tft.drawLine(60, 305+i, 180, 195+i, RED); //for looppi kauttaviivan piirtämiseen
    
    tft.setCursor(130, 250);
    
    if (tavoitenum == 1) tavoite = tavoitehyppy;
    else if (tavoitenum == 2) tavoite = tavoitevatsa;
    else if (tavoitenum == 3) tavoite = tavoitepunnerrus;
    else if (tavoitenum == 4) tavoite = tavoitekyykky;
    tft.print(tavoite);
    
    once = 0;
  }
}

void Return(){ //back näppäin ohjelmista poistumiseen
  TSPoint p = ts.getPoint();  //luodaan touchscreenin luokkaolio
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  
  if (p.z > ts.pressureThreshhold){ //jos painallus ylittää painemäärän
    laskuri = 0;
    once = 1;
  }
}

void Return2(){ //paluu näppäin ja failure musiikki
  TSPoint p = ts.getPoint();
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  
  if (p.z > ts.pressureThreshhold){
    laskuri = 0;
    once = 1;
    
    Sound(4); //soittaa failure äänen
    delay(300);
  }
}

void Setti(){ //sarjan funktio
  if (laskuri == tavoite){
    while (setti == 3){
      Kello(); 
      tft.fillRect(1,100,WIDTH,HEIGHT,BLACK); //piirtää laatikon alkaen x akselilta 1 toiseen reunaan, y akselilta 100 toiseen reunaan, täyttää laatikon mustalla
      tft.setTextColor(GREEN, BLACK);         //asettaa tekstin värin vihreäksi ja tekstin taustan mustaksi
      tft.setTextSize(10);                    //asettaa tekstin koon 10
      tft.setCursor(10, 120);                 //laittaa kursorin x akselilla 10 ja y akselilla 120
      tft.println("GG WP");                   //tulostaa gg wp
      
      if (once == 0){
        Sound(3); //soittaa victoryäänen
        if (tavoitenum == 1) tavoitehyppy = tavoitehyppy * 1.5;
        else if (tavoitenum == 2) tavoitevatsa = tavoitevatsa * 1.5;
        else if (tavoitenum == 3) tavoitepunnerrus = tavoitepunnerrus * 1.5;
        else if (tavoitenum == 4) tavoitekyykky = tavoitekyykky * 1.5;
        once = 2;
      }
      
      Return();
      if (once == 1) {
        setti = 0;
        break;
      }
    }

    if (setti != 0){  //jos settimäärä erisuuri kuin 0
      Sound(2); //soittaa taukoäänen
      setti++;  //päivittää settimäärän
      tft.setTextColor(GREEN, BLACK);
      tft.setTextSize(5);
      tft.setCursor(140, 120);
      tft.print(setti);

      laskuri = 0;
      tft.setTextColor(GREEN, BLACK);
      tft.setTextSize(8);
      tft.setCursor(64, 195);
      tft.print(laskuri);
  
      for (tauko; tauko>0; tauko--){  //tauon kesto
        Kello();
        tft.setTextColor(GREEN, YELLOW);
        tft.setTextSize(5);
        tft.fillRoundRect(20,100,80,80,100,YELLOW);
        
        if (tauko >= 10) tft.setCursor(30, 120);
        
        else if (tauko < 10)tft.setCursor(50, 120);
        
        tft.print(tauko);
        
        delay(1000);
        
        TSPoint p = ts.getPoint();
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        
        if (p.z > ts.pressureThreshhold){
          laskuri = 0;
          once = 1;
          break;
        }
      }
      tft.fillRoundRect(20,100,80,80,100,BLACK);
      tauko = 3;
      
      if (once != 1) Sound(1);
      
      else Sound(4);
      if (tavoitenum == 1) tavoitehyppy = tavoitehyppy * 0.5;
      else if (tavoitenum == 2) tavoitevatsa = tavoitevatsa * 0.5;
      else if (tavoitenum == 3) tavoitepunnerrus = tavoitepunnerrus * 0.5;
      else if (tavoitenum == 4) tavoitekyykky = tavoitekyykky * 0.5;
    }
  }
  delay(500);
}

void Valo(){
  valo = analogRead(valoPin);
  if (valo > 500) tft.invertDisplay(1);
  else if (valo < 500) tft.invertDisplay(0);
}

void Sound(int sound){  //summerin äänet
  if (sound == 1){  //ohjelman aloitusääni
    tone(tune, 3600); //hertsimäärä(pinni summerin soittamiseen ja hertsimäärä)
    delay(200);
    noTone(tune); //lopettaa piippauksen
  }
  
  if (sound == 2){  //taukoääni sarjojen välissä
    tone(tune, 3200, 150);
    delay(300);
    noTone(tune);
    tone(tune, 3200, 150);
    delay(150);
    noTone(tune);
  }
  
  if (sound == 3){//victory ääni
    for (int i = 0; i < 4; i++) { //for looppi voittoäänelle
      Kello();
      duration = 1000 / divide[i]; //soiton kesto / miten pitkään soitto kuuluu
      tone(tune, melody3[i], duration); 
      viive = duration * 1.30;  //kaunko kestää ennen seuraavaa ääntä
      delay(viive);
      noTone(tune);
    }
  }
  
  if (sound == 4){  //failure ääni
    for (int i = 0; i < 4; i++) {
      Kello();
      duration = 1000 / divide[i];
      tone(tune, melody4[i], duration);
      viive = duration * 1.30;
      delay(viive);
      noTone(tune);
    }
  }
}

void Kulma(){ //GY-61 kulman laskeminen
  valueX = analogRead(pinX);      
  valueY = analogRead(pinY);  
  valueZ = analogRead(pinZ);  
  
  kulmaX = 0.1453*valueX - 48.069;
  kulmaY = 0.144*valueY - 48.112;
  kulmaZ = 0.1496*valueZ - 49.483;
  kulma = sqrt(kulmaX*kulmaX + kulmaY*kulmaY + kulmaZ*kulmaZ);
}

void Kiihtyvyys(){ //kiihtyvyden laskukaava
  kiihtyvyysX = kulmaX;
  kiihtyvyysY = kulmaY;
  kiihtyvyysZ = kulmaZ;
  kiihtyvyys = kulma;
  
  kiihtyvyysX_Out = 0.05 * kiihtyvyysX + 0.95 * kiihtyvyysX_Out;  //IRR suodatin
  kiihtyvyysY_Out = 0.05 * kiihtyvyysY + 0.95 * kiihtyvyysY_Out;
  kiihtyvyysZ_Out = 0.05 * kiihtyvyysZ + 0.95 * kiihtyvyysZ_Out;
  kiihtyvyys_Out = 0.05 * kulma + 0.95 * kiihtyvyys_Out;
  
  kiihtyvyysX = kiihtyvyysX - kiihtyvyysX_Out;
  kiihtyvyysY = kiihtyvyysY - kiihtyvyysY_Out;
  kiihtyvyysZ = kiihtyvyysZ - kiihtyvyysZ_Out;
  kiihtyvyys = kiihtyvyys - kiihtyvyys_Out;
}
