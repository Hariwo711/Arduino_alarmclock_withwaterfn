


void songsselect(){
  lcd.setCursor(0, 0);
  lcd.print("Select Melody:");
  lcd.setCursor(0,  1);
  lcd.print("> ");
  if(selectedsong==0){
    lcd.print("Default");
  }
  if(selectedsong==1){
    lcd.print("Nokia Ring");
  }
  if(selectedsong==2){
    lcd.print("Pacman Theme");
  }
  
}


void songplayer_nokia()
{
  int size = sizeof(nokia_durations) / sizeof(int);
    // if(digitalRead(buttonPin2)==1){
    //   noTone(BUZZER_PIN);
    //   selectedsong = 0;
    // }
  for (int note = 0; note < size; note++) {
    //to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / nokia_durations[note];
    // if(digitalRead(buttonPin2)==1){
    //   alarmonoroff = 0;
    // }
    tone(BUZZER_PIN, nokia_melody[note], duration);
    // if(digitalRead(buttonPin)==1){
    //   alarmonoroff = 0;
    // }

    //to distinguish the notes, set a minimum time between them.
    //the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);
    if(digitalRead(buttonPin2)==1){
      alarmonoroff=0;
      break;
    }
    // if()
    //stop the tone playing:
    noTone(BUZZER_PIN);

  }
}


void songplayer_pacman()
{
  int size = sizeof(pacman_durations) / sizeof(int);
    // if(digitalRead(buttonPin2)==1){
    //   noTone(BUZZER_PIN);
    //   selectedsong = 0;
    // }
  for (int note = 0; note < size; note++) {
    //to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / pacman_durations[note];
    // if(digitalRead(buttonPin2)==1){
    //   alarmonoroff = 0;
    // }
    tone(BUZZER_PIN, pacman_melody[note], duration);
    // if(digitalRead(buttonPin)==1){
    //   alarmonoroff = 0;
    // }

    //to distinguish the notes, set a minimum time between them.
    //the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);
    if(digitalRead(buttonPin2)==1){
      alarmonoroff=0;
      break;
    }
    // if()
    //stop the tone playing:
    noTone(BUZZER_PIN);

  }
}



// void songplayer_mario()
// {
//   int size = sizeof(mario_durations) / sizeof(int);
//     // if(digitalRead(buttonPin2)==1){
//     //   noTone(BUZZER_PIN);
//     //   selectedsong = 0;
//     // }
//   for (int note = 0; note < size; note++) {
//     //to calculate the note duration, take one second divided by the note type.
//     //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
//     int duration = 1000 / mario_durations[note];
//     // if(digitalRead(buttonPin2)==1){
//     //   alarmonoroff = 0;
//     // }
//     tone(BUZZER_PIN, mario_melody[note], duration);
//     // if(digitalRead(buttonPin)==1){
//     //   alarmonoroff = 0;
//     // }

//     //to distinguish the notes, set a minimum time between them.
//     //the note's duration + 30% seems to work well:
//     int pauseBetweenNotes = duration * 1.30;
//     delay(pauseBetweenNotes);
//     if(digitalRead(buttonPin3)==1){
//       alarmonoroff=0;
//       break;
//     }
//     // if()
//     //stop the tone playing:
//     noTone(BUZZER_PIN);

//   }
// }