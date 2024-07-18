/* 09:32 15/03/2023 - change triggering comment */
#include "esp_comms.h"
#include "pindef.h"

namespace {
  class McuCommsSingleton {
  public:
    static McuComms& getInstance() {
      static McuComms instance;
      return instance;
    }
  private:
    McuCommsSingleton() = default;
    ~McuCommsSingleton() = default;
  };
}

void espCommsInit() {
  USART_ESP.begin(115200);

  // mcuComms.setDebugPort(&USART_ESP);
  McuCommsSingleton::getInstance().begin(USART_ESP);

  // Set callbacks
  McuCommsSingleton::getInstance().setProfileReceivedCallback(onProfileReceived);
  McuCommsSingleton::getInstance().setRemoteScalesWeightReceivedCallback(onRemoteScalesWeightReceived);
  McuCommsSingleton::getInstance().setRemoteScalesDisconnectedCallback(onRemoteScalesDisconnected);
}

void espCommsReadData() {
  McuCommsSingleton::getInstance().readDataAndTick();
}

volatile uint32_t sensorDataTimer = 0;
void espCommsSendSensorData(const SensorState& state, uint32_t frequency) {
  uint32_t now = millis();
  if (now - sensorDataTimer > frequency) {
    SensorStateSnapshot sensorSnapshot = SensorStateSnapshot{
      .brewActive = state.brewSwitchState,
      .steamActive = state.steamSwitchState,
      .scalesPresent = state.scalesPresent,
      .temperature = state.waterTemperature,
      .pressure = state.smoothedPressure,
      .pumpFlow = state.smoothedPumpFlow,
      .weightFlow = state.smoothedWeightFlow,
      .weight = state.weight,
      .waterLvl = state.waterLvl
    };
    McuCommsSingleton::getInstance().sendSensorStateSnapshot(sensorSnapshot);
    sensorDataTimer = now;
  }
}

volatile uint32_t shotDataTimer;
void espCommsSendShotData(ShotSnapshot& shotData, uint32_t frequency) {
  uint32_t now = millis();
  if (now - shotDataTimer > frequency) {
    McuCommsSingleton::getInstance().sendShotData(shotData);
    shotDataTimer = now;
  }
}

void espCommsSendTareScalesCommand() {
  McuCommsSingleton::getInstance().sendRemoteScalesTare();
}
