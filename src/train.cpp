// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), countOp(0) {}

Train::~Train() {
  if (!first) return;
  Car* current = first->next;
  while (current != first) {
    Car* temporary = current;
    current = current->next;
    delete temporary;
  }
  delete first;
}

void Train::addCar(bool light) {
  Car* newCar = new Car(light);
  if (!first) {
    first = newCar;
    first->next = first;
    first->prev = first;
  } else {
    Car* lastCar = first->prev;
    lastCar->next = newCar;
    newCar->prev = lastCar;
    newCar->next = first;
    first->prev = newCar;
  }
}

int Train::getLength() {
  countOp = 0;
  if (!first) return 0;
  const Car* currentCar = first;
  bool hasLight = false;
  do {
    if (currentCar->light) {
      hasLight = true;
      break;
    }
    currentCar = currentCar->next;
  } while (currentCar != first);
  if (!hasLight) {
    first->light = true;
    const Car* walker = first->next;
    ++countOp;
    int length = 1;
    while (walker != first) {
      walker = walker->next;
      ++countOp;
      ++length;
    }
    for (int64_t i = 0; i < length; ++i) {
      walker = walker->prev;
      ++countOp;
    }
    first->light = false;
    return length;
  } else {
    const Car* walker = first->next;
    ++countOp;
    int64_t trainLength = 1;
    while (walker != first) {
      walker = walker->next;
      ++trainLength;
      ++countOp;
    }
    countOp += trainLength * trainLength;
    return trainLength;
  }
}
