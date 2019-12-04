int emg1=A0;
int emg2=A1;
int val_1=0;
int val_2=0;

void setup() {
  pinMode(emg1,INPUT);
  pinMode(emg2,INPUT);
  Serial.begin(9600);
}

void loop() {
  val_1 = analogRead(emg1);
  val_2 = analogRead(emg2);
  String vaule1 = String(val_1);
  String vaule2 = String(val_2);
  String vaule3 = String(",");
  String vaule = String(vaule1 + vaule3 + vaule2);
  Serial.println(vaule);
  delay(50);
}
