#include "Arduino.h"

#include "BLEDevice.h"

#define DEFAULT_ADVERTISING_INTERVAL 100
#define DEFAULT_CONNECTABLE          true

BLEDevice::BLEDevice() :
  _eventListener(NULL),
  _advertisingInterval(DEFAULT_ADVERTISING_INTERVAL),
  _minimumConnectionInterval(0),
  _maximumConnectionInterval(0),
  _connectable(DEFAULT_CONNECTABLE),
  _bondStore(NULL)
{
}

BLEDevice::~BLEDevice() {
}

void BLEDevice::setEventListener(BLEDeviceEventListener* eventListener) {
  this->_eventListener = eventListener;
}

void BLEDevice::setAdvertisingInterval(unsigned short advertisingInterval) {
  this->_advertisingInterval = advertisingInterval;
}

void BLEDevice::setConnectionInterval(unsigned short minimumConnectionInterval, unsigned short maximumConnectionInterval) {
  if (maximumConnectionInterval < minimumConnectionInterval) {
    maximumConnectionInterval = minimumConnectionInterval;
  }

  this->_minimumConnectionInterval = minimumConnectionInterval;
  this->_maximumConnectionInterval = maximumConnectionInterval;
}

void BLEDevice::setConnectable(bool connectable) {
  this->_connectable = connectable;
}

void BLEDevice::setBondStore(BLEBondStore& bondStore) {
  this->_bondStore = &bondStore;
}
