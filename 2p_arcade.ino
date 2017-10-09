#include<Keyboard.h>;
void setup() {



Keyboard.begin();
/* on ouvre les pin et on ajoute un pullup virtuel sur chaques.
 *  j'ai défini vaguement ou je vais mapper mes touches de claiver
 */
//Player 1 joystick gauche, droite, haut et bas
pinMode(22, INPUT_PULLUP);
pinMode(23, INPUT_PULLUP);
pinMode(24, INPUT_PULLUP);
pinMode(25, INPUT_PULLUP);

//Player 1 A B X Y
pinMode(26, INPUT_PULLUP);
pinMode(27, INPUT_PULLUP);
pinMode(28, INPUT_PULLUP);
pinMode(29, INPUT_PULLUP);

//Player 2 gauche, droite, haut et bas
pinMode(30, INPUT_PULLUP);
pinMode(31, INPUT_PULLUP);
pinMode(32, INPUT_PULLUP);
pinMode(33, INPUT_PULLUP);

//Player 2 A B X Y
pinMode(34, INPUT_PULLUP);
pinMode(35, INPUT_PULLUP);
pinMode(36, INPUT_PULLUP);
pinMode(37, INPUT_PULLUP);

//Start
pinMode(38, INPUT_PULLUP);
//Select
pinMode(39, INPUT_PULLUP);

//P1 coin
pinMode(40, INPUT_PULLUP);
//P2 Coin
pinMode(41, INPUT_PULLUP);
//P1 l & r bumper
pinMode(42, INPUT_PULLUP);
pinMode(43, INPUT_PULLUP);
//P2 l & r bumper
pinMode(44, INPUT_PULLUP);
pinMode(45, INPUT_PULLUP);
}

void loop() {
/* deux options pour mes fonctions. première option c'est la 
 *  pin sur la carte arduino. Deuxième options c'est la touche 
 *  de clavier.
 *  il faut appeler la fonction pressed durant le loop pour
 *  que le programme écoute a l'infini les touche appuié.
 */

pressed(22, 216); //gauche
pressed(23, 215); //droite
pressed(24, 218); //haut
pressed(25, 217); //bas
pressed(26, 'z'); //A
pressed(27, 'x'); //B
pressed(28, 'c'); //X
pressed(29, 'v'); //Y

pressed(30, 'u'); //p2 gauche
pressed(31, 'h'); //p2 droite
pressed(32, 'k'); //p2 haut
pressed(33, 'j'); //p2 bas

pressed(34, 'b'); //p2 a
pressed(35, 'n'); //p2 b
pressed(36, 'm'); //p2 x
pressed(37, 'l'); //p2 y
pressed(38, 177); //escape
pressed(39, 176); //return anciennement right shift
pressed(40, 211); // page up
pressed(41, 32);  //space
pressed(42, 'r'); //p1 lbumper
pressed(43, 'f'); //p1 rbumper
pressed(44, 't'); //p2 lbumper
pressed(45, 'g'); //p2 rbumper
}

/*la fonction pressed assigne une pin à une lettre de clavier 
 *respectivement selon les variable X et Y. Aussi longtemps 
 *que le bouton est appuyé, on envoye la lettre à l'ordinateur.
 *Quand le bouton est relaché on arrete d'écrire la lettre.*/

void pressed(int x, char y){
//Faut envoyer des touches quand ya du courrant
  if(digitalRead(x)==LOW){
    Keyboard.press(y);  
  }
//faut arreter d'en envoyer quand on enleve le courrant
  if(digitalRead(x)==HIGH){
    Keyboard.release(y);
  }
  
}
