class Vent{
  public:

  Vent::Vent(int ventOpenedPin, int ventClosedPin, int ventClosedPinStatus, int ventOpenedPinStatus, int enabledPin, int openPin, int closePin, int ventState, int buttonUpState, int buttonDownState){
    _ventOpenedPin = ventOpenedPin;
    _ventClosedPin = ventClosedPin;
    _ventOpenedPinStatus = ventOpenedPinStatus;
    _ventClosedPinStatus = ventClosedPinStatus;
    _openPin = openPin;
    _closePin = closePin;
    _enabledPin = enabledPin;
    _ventState = ventState;
    _buttonUpState = buttonUpState;
    _buttonDownState = buttonDownState; 
  }

  void begin(){
    pinMode(_enabledPin, OUTPUT);
    pinMode(_openPin, OUTPUT);
    pinMode(_closePin, OUTPUT);      
    pinMode(_ventOpenedPin, INPUT);
    pinMode(_ventClosedPin, INPUT);
    
    digitalWrite(_enabledPin, LOW);
    analogWrite(_openPin, 0);
    analogWrite(_closePin, 0);     
  }

  int getVentStatus(){
    _ventOpenedPinStatus = digitalRead(_ventOpenedPin);
    _ventClosedPinStatus = digitalRead(_ventClosedPin);
    
    if(_ventOpenedPinStatus == 0 && _ventClosedPinStatus == 1){
      _ventStatus = 0; // vent closed
    }    
    if(_ventOpenedPinStatus == 1 && _ventClosedPinStatus == 0){
      _ventStatus = 1; // vent open
    }
    if(_ventOpenedPinStatus == 0 && _ventClosedPinStatus == 0){
      _ventStatus = 2; // vent intermittent
    }
    if(_ventOpenedPinStatus == 1 && _ventClosedPinStatus == 1){
      _ventStatus = 3; // vent error
    }    
  return _ventStatus;
  }

  void openVent(double pwmSignal){
      digitalWrite(_enabledPin, HIGH);
      analogWrite(_openPin, pwmSignal);
      analogWrite(_closePin, 0);
  }
  void closeVent(double pwmSignal){
      digitalWrite(_enabledPin, HIGH);
      analogWrite(_openPin, 0);  
      analogWrite(_closePin, pwmSignal);
  }
  void stopVent(){
    digitalWrite(_enabledPin, LOW);    
    analogWrite(_openPin, 0);
    analogWrite(_closePin, 0);
  }


  private:
    int _ventOpenedPin;
    int _ventClosedPin; 
    int _ventStatus; 
    int _ventOpenedPinStatus;
    int _ventClosedPinStatus;
    int _enabledPin;
    int _openPin;
    int _closePin;   
    int _pwmSignal = 0;
    int _pwmMax = 150;  
    int _ventState;
    int _buttonUpState;
    int _buttonDownState; 
};
